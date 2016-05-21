#include "datastructs.h"
#include <iostream>
#include "utils.h"


myHeap::myHeap()
{
    // constructor stub
    data.push_back(0);  // put dummy int into spot 0
}

myHeap::~myHeap()
{
    // destructor stub
}

void myHeap::insert(int in)
{
    // insert new data into the heap
    
    // add an extra spot to the vector
    data.push_back(0);  // this is dummy data that will get overwritten
    
    int hole = data.size() - 1;
    for (; (hole > 1 && data.at(hole/2) > in); hole /= 2){
        data.at(hole) = data.at(hole/2);
    }
    data.at(hole) = in;
}

int myHeap::pop(void)
{
    // remove the min value from the heap

    int out = data.at(1);
    data.at(1) = data.at(data.size()-1);  // put the end data in front to perc. down
    int tmp = data.at(1);
    data.pop_back(); // decrease the size of the array
    
    //std::cout << "Popped: " << out << ", new front: " << tmp << ", size: " << data.size() << std::endl;
    if (data.size() <= 1){ return out;}
    
    int child;
    int hole = 1;
    for (; hole*2 <= (data.size()-1); hole = child){
        child = hole*2;
        
        if (child < (data.size()-2)) {      
            if (data.at(child) > data.at(child+1)) {
                child++;
            }
        }
        if (tmp > data.at(child)) {
            //std::cout << "Swapping " << data.at(child) << " Up." << std::endl;
            data.at(hole) = data.at(child);
        } else{
            break;
        }
        print();
    }
    data.at(hole) = tmp;

    return out;
}

void myHeap::print(void)
{
    // print out the heap
    std::cout << "Heap: ";
    printVec(data);
}
