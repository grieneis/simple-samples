// utility functions
#include <iostream>
#include <vector>
#include "utils.h"

int printVec(std::vector<int> & in)
{
    std::cout << " Vec: ";
    for (int k=0; k<in.size(); k++){
        std::cout << in.at(k) << ", ";
    }   
    std::cout << std::endl;
}
