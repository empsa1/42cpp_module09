#include "../includes/PMergeMe.hpp"

void insertionSort(std::vector<int>& vec, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= left && vec[j] > key) {
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
    for (int i = 0; i < n1; ++i)
        L.push_back(vec[left + i]);
    for (int j = 0; j < n2; ++j)
        R.push_back(vec[middle + 1 + j]);

    int i = 0, j = 0, k = left;
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








void insertionSort(std::deque<int>& dq, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
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
    for (int i = 0; i < n1; ++i)
        L.push_back(dq[left + i]);
    for (int j = 0; j < n2; ++j)
        R.push_back(dq[middle + 1 + j]);

    int i = 0, j = 0, k = left;
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

void PMergeMe::fordJonhsonDeque(const std::string& expression)
{
    int i = -1;
    while (expression[++i] != '\0')
        deque.push_back(atoi(&expression[i]));


    std::cout << GREEN << "Before:   " << expression << RESET << std::endl;
    clock_t start = clock();
    mergeInsertSort(deque, 0, deque.size() - 1);
    clock_t end = clock();


    double sortTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << GREEN << "After:    " << RESET;
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
        std::cout << GREEN << *it << " " << RESET;
    std::cout << std::endl;
    std::cout << CYAN << "Time to process a range of " << deque.size() << " with std::deque<int> STL container : " << sortTime << RESET << std::endl;
    
}



void PMergeMe::fordJonhsonVector(const std::string& expression)
{
    int i = -1;
    while (expression[++i] != '\0')
        vector.push_back(atoi(&expression[i]));


    std::cout << GREEN << "Before:   " << expression << RESET << std::endl;
    clock_t start = clock();
    mergeInsertSort(vector, 0, vector.size() - 1);
    clock_t end = clock();


    double sortTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << GREEN << "After:    " << RESET;
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        std::cout << GREEN << *it << " " << RESET;
    std::cout << std::endl;
    std::cout << CYAN << "Time to process a range of " << vector.size() << " with std::vector<int> STL container : " << sortTime << RESET << std::endl;
}

PMergeMe::PMergeMe()
{
    
}

PMergeMe::~PMergeMe()
{

}