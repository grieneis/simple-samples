#include <iostream>
#include <vector>
#include <cstdlib>
#include "sorts.h"
#include "utils.h"

// Main function for testing out different algorithms / data structures
int main(void)
{
    std::cout << "This is my main function." << std::endl;
    /*
    int arr[] = {10,5,2,6,3,11,19,8};
    std::vector<int> usort(arr,arr+sizeof(arr)/sizeof(int));
    */
    int numElems = 100;
    std::vector<int> usort;
    for (int k=0; k<numElems; k++){
        usort.push_back( (rand() % 100) + 1);
    }
    
    std::cout << "Unsorted: ";
    printVec(usort);
    
    //InsertionSort(usort);
    //ShellSort(usort);
    //HeapSort(usort);
    //MergeSort(usort);
    QuickSort(usort);    
    std::cout << "Sorted: ";
    printVec(usort);

    return 0;
}
