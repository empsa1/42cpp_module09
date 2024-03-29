#include "../includes/PmergeMe.hpp"

//CONSTRUCTORS
PmergeMe::PmergeMe()
{
    
}

PmergeMe::~PmergeMe()
{

}

//APLIED ALGORTIHM FOR VECTOR MERGE INSERT SORT
void insertionSort(std::vector<int>& vec, int left, int right) {
    int i = left;
    while (++i <= right)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void merge(std::vector<int>& vec, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<int> L, R;
    int i = -1;
    while (++i < n1)
        L.push_back(vec[left + i]);
    int j = -1;
    while (++j < n2)
        R.push_back(vec[middle + 1 + j]);
    i = 0; 
    j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            vec[k++] = L[i++];
        else
            vec[k++] = R[j++];
    }
    while (i < n1)
        vec[k++] = L[i++];
    while (j < n2)
        vec[k++] = R[j++];
}

void mergeInsertSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= 10) {
            insertionSort(vec, left, right);
        } else {
            int middle = left + (right - left) / 2;
            mergeInsertSort(vec, left, middle);
            mergeInsertSort(vec, middle + 1, right);
            merge(vec, left, middle, right);
        }
    }
}

//APLIED ALGORITHM FOR DEQUE MERGE INSERT SORT
void insertionSort(std::deque<int>& dq, int left, int right) {
    int i = left;
    while (++i <= right)
    {
        int key = dq[i];
        int j = i - 1;
        while (j >= left && dq[j] > key) {
            dq[j + 1] = dq[j];
            --j;    
        }
        dq[j + 1] = key;
    }
}

void merge(std::deque<int>& dq, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::deque<int> L, R;
    int i = -1;
    while (++i < n1)
        L.push_back(dq[left + i]);
    int j = -1;
    while (++j < n2)
        R.push_back(dq[middle + 1 + j]);
    i = 0;
    j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            dq[k++] = L[i++];
        else
            dq[k++] = R[j++];
    }
    while (i < n1)
        dq[k++] = L[i++];
    while (j < n2)
        dq[k++] = R[j++];
}

void mergeInsertSort(std::deque<int>& dq, int left, int right) {
    if (left < right) {
        if (right - left + 1 <= 10) {
            insertionSort(dq, left, right);
        } else {
            int middle = left + (right - left) / 2;
            mergeInsertSort(dq, left, middle);
            mergeInsertSort(dq, middle + 1, right);
            merge(dq, left, middle, right);
        }
    }
}


//UTILS FOR THE EXERCISE
bool isInt(const std::string str)
{
    return (str.find_first_not_of(INT_ARRAY) == std::string::npos);
}

void PmergeMe::printDeque()
{
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
        std::cout << GREEN << *it << " " << RESET;
    std::cout << std::endl;
}

void    PmergeMe::printVector()
{
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        std::cout << GREEN << *it << " " << RESET;
    std::cout << std::endl;
}


//CALLERS FOR THE DIFFERENT CONTAINERS
void PmergeMe::fordJonhsonDeque(char** expression)
{
    clock_t start = clock();
    int i = 0;
    while (expression[++i] != '\0')
    {
        if (isInt(std::string(expression[i])) == false)
            throw IllegallNumberException();
        int toAdd = atoi(expression[i]);
        if (toAdd < 0)
            throw IllegallNumberException();
        deque.push_back(toAdd);
    }
    std::cout << GREEN << "Before:   " << RESET;
    printDeque();
    mergeInsertSort(deque, 0, deque.size() - 1);
    clock_t end = clock();
    double sortTime = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << GREEN << "After:    " << RESET;
    printDeque();
    std::cout << CYAN << "Time to process a range of " << deque.size() << " elements with std::deque<int> STL container : " << std::fixed << std::setprecision(ADJUSTABLE_TIME_DECI) << sortTime << " us" << RESET << std::endl; 
}

void PmergeMe::fordJonhsonVector(char** expression)
{
    clock_t start = clock();
    int i = 0;
    while (expression[++i] != '\0')
    {
        if (isInt(std::string(expression[i])) == false)
            throw IllegallNumberException();
        int toAdd = atoi(expression[i]);
        if (toAdd < 0)
            throw IllegallNumberException();
        vector.push_back(toAdd);
    }
    std::cout << GREEN << "Before:   " << RESET;
    printVector();
    mergeInsertSort(vector, 0, vector.size() - 1);
    clock_t end = clock();
    double sortTime = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << GREEN << "After:    " << RESET;
    printVector();
    std::cout << CYAN << "Time to process a range of " << vector.size() << " elements with std::vector<int> STL container : " << std::fixed << std::setprecision(ADJUSTABLE_TIME_DECI) << sortTime << " us" << RESET << std::endl;
}