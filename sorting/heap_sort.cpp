#include<iostream>
#include "../heaps/heap.h"

void Heap :: sort() {
    for (int i = length; i > 1; i--) {
        std::swap(heap[1], heap[i]);
        length--;
        heapify(1);
    }
}

int* Heap :: getHeap() {
    return &heap[1];
}

int print_data(int data[], int n) {
    for (int i = 0; i < n; i++)
	    std::cout << data[i] << " ";
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "Enter number of elements" << std::endl;
	std::cin >> n;

	int data[n];
	for (int i = 0; i < n; i++) {
		std::cout << "Enter element #" << i + 1 << ": ";
		std::cin >> data[i];
	}

	std::cout << "\nInput data: ";
	print_data(data, n);

	Heap heap(data, n, "max");
	heap.sort();

	std::cout << "Sorted data: ";
	print_data(heap.getHeap(), n);
}
