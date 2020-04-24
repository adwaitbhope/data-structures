#ifndef HEAP_H
#define HEAP_H

#define PARENT(x) (x / 2)
#define FIRST_CHILD(x) (x * 2)
#define SECOND_CHILD(x) (x * 2 + 1)

class Heap {

    protected:
        int* heap;
        int length;
        std::string type;

        void buildHeap();
        void heapify(int index);

    public:
        Heap(int* heap, int length, std::string type);
        int extractTop();
        int* getHeap();
        void print();
        void sort();

};

#endif
