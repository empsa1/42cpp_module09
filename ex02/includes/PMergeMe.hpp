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

class PMergeMe {
    private:
        std::vector<int>    vector;
        std::deque<int>     deque;
        void mergeSort();
        void insertSort();
        void merge();

    public:
        PMergeMe();
        ~PMergeMe();
        void fordJonhsonDeque(const std::string& expression);
        void fordJonhsonVector(const std::string& expression);
};


#endif