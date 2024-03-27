#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

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
#include <vector>
#include <deque>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

class IllegallNumberException : public std::exception {
    public:
        virtual const char* what() const throw()
        {
            return RED "Error: Illegal Number was used" RESET;
        }
};

class PmergeMe {
    private:
        std::vector<int>    vector;
        std::deque<int>     deque;
        void mergeSort();
        void insertSort();
        void merge();
        PmergeMe(PmergeMe const &that);
        PmergeMe &operator=(PmergeMe const &that);
    public:
        PmergeMe();
        ~PmergeMe();
        void fordJonhsonDeque(char ** expression);
        void printVector();
        void printDeque();
        void fordJonhsonVector(char ** expression);
};


#endif