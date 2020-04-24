#include<iostream>
#include "heap.h"

void Heap :: buildHeap() {
    for (int i = length / 2; i > 0; i--) {
        heapify(i);
    }
}

void Heap :: heapify(int index) {
    int left = FIRST_CHILD(index);
    int right = SECOND_CHILD(index);
    int selected = index;

    if (type.compare("min") == 0) {
        if (left <= length && heap[left] < heap[index]) {
            selected = left;
        }
        if (right <= length && heap[right] < heap[left] && heap[right] < heap[index]) {
            selected = right;
        }
    } else {
        if (left <= length && heap[left] > heap[index]) {
            selected = left;
        }
        if (right <= length && heap[right] > heap[left] && heap[right] > heap[index]) {
            selected = right;
        }
    }

    if (type.compare("min") == 0) {
        if (heap[selected] < heap[index]) {
            std::swap(heap[index], heap[selected]);
            heapify(selected);
        }
    } else {
        if (heap[selected] > heap[index]) {
            std::swap(heap[index], heap[selected]);
            heapify(selected);
        }
    }
}

Heap :: Heap(int* heap, int length, std::string type="min") {
    this -> heap = new int[100];
    for(int i = 0; i < length; i++) {
        this -> heap[i + 1] = heap[i];
    }
    this -> length = length;
    this -> type = type;
    buildHeap();
}

int Heap :: extractTop() {
    std::swap(heap[1], heap[length]);
    length--;
    heapify(1);
    return heap[length + 1];
}

void Heap :: print() {
    for (int i = 1; i <= length; i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}
