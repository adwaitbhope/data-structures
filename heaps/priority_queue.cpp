#include<iostream>
#include "priority_queue.h"

PriorityQueue :: PriorityQueue(int* heap, int length):Heap(heap, length, "max") {

}

void PriorityQueue :: insert(int data) {
    heap[++length] = data;
    for (int i = length; i > 1; ) {
        if (heap[PARENT(i)] < heap[i]) {
            std::swap(heap[PARENT(i)], heap[i]);
            i = PARENT(i);
        }
    }
}

int PriorityQueue :: getMax() {
    if (length > 0) {
        return heap[1];
    }
    return 0;
}

int PriorityQueue :: extractMax() {
    if (length > 0) {
       return extractTop();
    }
    return 0;
}

int main() {

    int data[] = {6, 1, 5, 2, 8, 3, 7, 4, 9};
    PriorityQueue pqueue(data, 9);

    int choice, input;
    bool end = false;
    
    while (!end) {
    
        std::cout << "\nMenu:\n\t1. Insert a job\n\t2. Get max\n\t3. Extraxt max\n\t4. Exit\nChoice: ";
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                std::cout << "Enter priority: ";
                std::cin >> input;
                pqueue.insert(input);
                std::cout << "Inserted a new job!" << std::endl;
                break;
                
            case 2:
                std::cout << "The max value is " << pqueue.getMax() << std::endl;
                break;
                
            case 3:
                std::cout << "The extracted max value is " << pqueue.extractMax() << std::endl;
                break;
                
            default:
                end = true;
        
        }
    
    }
    
}
