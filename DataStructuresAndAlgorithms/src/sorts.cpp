#include "sorts.h"

#include <iostream>
#include <cmath>

#include "datastructs.h"
#include "utils.h"

// compute an insertion sort on the given vector
int InsertionSort(std::vector<int>& in)
{
    // go through the vector starting with the second element
    for (int k=1; k<in.size(); k++){
        int j=k;
        int tmp = in.at(k);
        // move everything forwards until we hit something smaller than
        // the current value, then store new value there
        for (j=k; (j>0 && in.at(j-1) > tmp); j--){
            in.at(j) = in.at(j-1);
        }
        in.at(j) = tmp;
        std::cout << "Iter " << k << ", ";
        printVec(in);
    }
    
    return 0;
}


// compute a ShellSort on the given vector
int ShellSort(std::vector<int>& in)
{
    // shell sort uses a set of increments
    // it sorts in these increments
    int start = log(in.size()+1)/log(2);
    
    for (int n= start; n>0; n--){
        int gap = pow(2,n)-1;
    
        for (int k=gap; k<in.size(); k++){
            int j=k;
            int tmp = in.at(k);
            // move everything forwards until we hit something smaller than
            // the current value, then store new value there
            for (j=k; (j>=gap && in.at(j-gap) > tmp); j-=gap){
                in.at(j) = in.at(j-gap);
            }
            in.at(j) = tmp;
        }
        std::cout << "Gap " << gap << ", ";
        printVec(in);
    }
    
    return 0;
}

// compute a heap sort
int HeapSort(std::vector<int>& in)
{
    // first, create a binary heap
    myHeap heap;
    // next, add all of the elements to it
    for (int k=0; k<in.size(); k++){
        heap.insert(in.at(k));
        heap.print();
    }
    // then, pop off the top elements
    for (int k=0; k<in.size(); k++){
        in.at(k) = heap.pop();
        heap.print();
    }

    return 0;
}

// compute a merge sort
int MergeSort(std::vector<int>& in)
{
    // use a recursive divide-and-conquer technique
    std::vector<int> tmp(in);
    
    mergeSort(in,tmp,0,(in.size()-1));

    return 0;
}


int mergeSort(std::vector<int>& in, std::vector<int>& temp, int left, int right)
{
    if (left < right) {
        int cen = (left+right)/2;
        mergeSort(in, temp, left,cen);
        mergeSort(in, temp, cen+1,right);
        merge(in,temp,left,cen+1,right);
        printVec(in);
    }
    return 0;
}

int merge(std::vector<int>& in, std::vector<int>& temp, int leftpos, int rightpos, int rightend)
{
    // merge the two sections together
    int leftend = rightpos-1;
    int temppos = leftpos;
    int numElems = rightend - leftpos + 1;
    
    while (leftpos <= leftend && rightpos <= rightend){
        if (in.at(leftpos) < in.at(rightpos)){
            temp.at(temppos) = in.at(leftpos);
            leftpos++;
        } else {
            temp.at(temppos) = in.at(rightpos);
            rightpos++;
        }
        temppos++;
    }
    // finish off left array if anything is left
    while (leftpos <= leftend){
        temp.at(temppos) = in.at(leftpos);
        leftpos++;
        temppos++;
    }
    // finish off the right array
    while (rightpos <= rightend){
        temp.at(temppos) = in.at(rightpos);
        rightpos++;
        temppos++;
    }
    
    // copy the data from the temp array back into the main array
    for (int i=0; i<numElems; i++, rightend--){
        in.at(rightend) = temp.at(rightend);
    }

    return 0;
}


int QuickSort(std::vector<int>& in)
{
    // execute a quicksort here
    quickSort(in,0,in.size()-1);
}

// recursive function to call
int quickSort(std::vector<int>& in, int left, int right)
{
    int CUTOFF = 3;
    
    if (left + CUTOFF <= right){
        int pivot = median3(in,left,right);
        
        // now partition the data left and right
        int i = left;
        int j = right - 1;
        for (;;){ // loop until done
            while(in.at(++i) < pivot){}
            while(in.at(--j) > pivot){}
            if ( i < j){
                swap(in,i,j);
            } else {
                break;
            }
        }
        swap(in,i, right-1);
        //std::cout << " Pivot: " << pivot << std::endl;
        printVec(in);
        
        quickSort(in,left,i-1);
        quickSort(in,i+1,right);
    } else {
        std::vector<int> tv;
        for (int k=left; k<=right; k++){
            tv.push_back(in.at(k));
        }
        InsertionSort(tv);
        for (int k=left; k<=right; k++){
            in.at(k) = tv.at(k-left);
        }
    }

    return 0;
}

int median3(std::vector<int>& in, int left, int right)
{
    // find the median of start, end, middle values
    
    // if everything is ok
    int center = (left+right)/2;
    //std::cout << "L: " << in.at(left) << ", C: " << in.at(center) << ", R: " << in.at(right) << std::endl;
    if (in.at(left) > in.at(center)) swap(in,left,center);
    if (in.at(left) > in.at(right)) swap(in,left,right);
    if (in.at(center) > in.at(right)) swap(in,center,right);
    swap(in,center,right-1);
    //std::cout << "L: " << in.at(left) << ", C: " << in.at(center) << ", R: " << in.at(right) << std::endl;
    return in.at(right-1);
}    
    
void swap(std::vector<int>& in, int a, int b)
{
    int tp = in.at(a);
    in.at(a) = in.at(b);
    in.at(b) = tp;
}
    
