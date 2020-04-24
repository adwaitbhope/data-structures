#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "heap.h"

class PriorityQueue: public Heap {
    public:
        PriorityQueue(int* heap, int length);
        void insert(int data);
        int getMax();
        int extractMax();
};

#endif
