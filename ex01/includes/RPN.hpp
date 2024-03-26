#ifndef RPN_HPP
# define RPN_HPP

#include "Utils.hpp"
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
#include <stack>

class DivisionByZeroException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED DIVISION_BY_ZERO RESET;
        }
};

class IllegallOperatorNumbersException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED INVALID_OPERATOR_COUNT RESET;
        }
};

class RPN
{
    private:
        std::stack<int> stack;
        RPN();
    public:
        ~RPN();
        RPN(const std::string& expression);
};

#endif
