#ifndef SORTS_H
#define SORTS_H

// Header file for sorting algorithms.
#include <vector>

int InsertionSort(std::vector<int>& input);

int ShellSort(std::vector<int>& input);

int HeapSort(std::vector<int>& in);

int MergeSort(std::vector<int>& in);
// merge helper funcs
int mergeSort(std::vector<int>& in, std::vector<int>& temp, int left, int right);
int merge(std::vector<int>& in, std::vector<int>& temp, int leftpos, int rightpos, int rightend);

int QuickSort(std::vector<int>& in);
int quickSort(std::vector<int>& in, int left, int right);
int median3(std::vector<int>& in, int left, int right);
void swap(std::vector<int>& in, int a, int b);
#endif
