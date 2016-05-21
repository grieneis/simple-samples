#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <vector>


class myHeap {
    public:
        myHeap();
        ~myHeap();
        void insert(int in);
        int pop(void);
        void print(void);
    private:
        std::vector<int> data;
};

#endif
