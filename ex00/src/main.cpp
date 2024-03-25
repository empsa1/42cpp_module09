#include "../includes/BitcoinExchange.hpp"
#define SUCESS_ON_EXIT 0
#define FAILURE_ON_EXIT -1
#define ITS_TXT 3;
#define ITS_CSV 4;

int ft_strlen(char *file)
{
    int counter = 0;
    while (*file++)
        counter++;
    return counter;
}

int inputParser(char* file)
{
    int temp = ft_strlen(file);
    int i = temp;
    int j = -1;
    char txt[5] = "txt."; //reversed to ease comparison
    char csv[5] = "vsc."; //reversed to ease comparison
    int comparer = 0;
    while (file[--i] == txt[++j] && j >= 0 && i >= 0)
        comparer++;
    if (comparer == 4)
        return ITS_TXT;
    comparer = 0;
    i = temp;
    j = -1;
    while (file[--i] == csv[++j] && j >= 0 && i >= 0)
        comparer++;
    if (comparer == 4)
        return ITS_CSV;
   return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && inputParser(argv[1]) != 0)
    {
        try
        {
            BitcoinExchange be(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        return SUCESS_ON_EXIT; 
    }
    std::cout << RED << CANT_OPEN_FILE << RESET << std::endl;
    return FAILURE_ON_EXIT;
}