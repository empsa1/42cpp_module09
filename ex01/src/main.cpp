#include "../includes/RPN.hpp"
#define SUCESS_ON_EXIT 0
#define FAILURE_ON_EXIT -1
#define IS_VALID_INPUT 11
#define RPN_ARRAY   "0123456789-+/*"


int inputParser(char *expression)
{
    int i = -1;
    int counter = 0;
    std::string temp;
    while (expression[++i] != '\0')
    {
        if (std::isdigit(expression[i]))
            counter++;
        if (std::isdigit(expression[i]) && std::isdigit(expression[i + 1]))
        {
            std::cout << RED << "Error: Invalid input around: " << expression[i] << expression[i + 1] << std::endl << "Input numbers cannot be greater or equal to 10" << RESET << std:: endl;
            std::cout << "irst" << std::endl;
            return FAILURE_ON_EXIT;
        }
    }
    i = -1;
    while (expression[++i] != '\0')
    {
        if (std::isspace(expression[i]))
            continue ;
        else
            temp.append(&expression[i], 1);
    }
    if (temp.find_first_not_of(RPN_ARRAY) != std::string::npos)
    {
        std::cout << RED << "Error: Invalid characters found inside argument!" << RESET << std::endl;
        return FAILURE_ON_EXIT;
    }
    if (counter < 2)
    {
        std::cout << RED << "Error: Too few arguments!" << RESET << std::endl;
        return FAILURE_ON_EXIT;
    }
    return IS_VALID_INPUT;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (inputParser(argv[1]) != -1)
        {
            try
            {
                RPN(std::string(argv[1]));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            return SUCESS_ON_EXIT;
        }
    }
    else
        std::cout << RED << INVALID_ARGUMENTS << RESET << std::endl;
    return FAILURE_ON_EXIT;
}