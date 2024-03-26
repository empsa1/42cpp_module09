#include "../includes/PMergeMe.hpp"
#define SUCESS_ON_EXIT 0
#define FAILURE_ON_EXIT 1;

int inputParser(char* expression)
{
    std::cout << expression << std::endl;
    return SUCESS_ON_EXIT;
}

int main(int argc, char **argv)
{
    if (argc == 2 && inputParser(argv[1]) != -1)
    {
        try
        {
            PMergeMe p;
            p.fordJonhsonDeque(std::string(argv[1]));
            p.fordJonhsonVector(std::string(argv[1]));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return SUCESS_ON_EXIT; 
    }
    std::cout << RED << INVALID_ARGUMENTS << RESET << std::endl;
    return FAILURE_ON_EXIT;
}