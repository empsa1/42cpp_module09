#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include "Utils.hpp"
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <limits>
#include <cmath>
#include <cfloat>
#include <climits>

#define database "dbs/data.csv"

class ImpossibleConversionException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED IMPOSSIBLE_CONVERSION RESET;
        }
};

class DatabaseEmptyException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED DATABASE_EMPTY RESET;
        }
};

class CouldNotOpenFileException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED CANT_OPEN_FILE RESET;
        }
};

class BitcoinExchange
{
    private:
        char* filename;
        BitcoinExchange();
    public:
        BitcoinExchange(char *filename);
        ~BitcoinExchange();
        static int toInt(std::string &string);
        static double toDouble(std::string &string);
        static bool isDouble(const std::string &str);
        static bool isInt(const std::string &str);
        double search_closest_lower(std::string date);
};

#endif