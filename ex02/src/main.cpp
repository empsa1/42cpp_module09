#include "../includes/PmergeMe.hpp"
#define SUCESS_ON_EXIT 0
#define FAILURE_ON_EXIT 1;

int inputParser(char* expression)
{
    (void)expression[0];
    return SUCESS_ON_EXIT;
}


// ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')


int main(int argc, char **argv)
{
    if (argc >= 2 && inputParser(argv[1]) != -1)
    {
        try
        {
            PmergeMe p;
            p.fordJonhsonDeque(argv);
            p.fordJonhsonVector(argv);
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