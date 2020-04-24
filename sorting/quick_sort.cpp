#include <iostream>
#include <string.h>

void quick_sort(int a[], int left, int right) {
	if (left < right) {
		int i = left, j = right + 1, pivot = a[left];
		do {
			do {
				i++;
			} while (a[i] < pivot);
			
			do {
				j--;
			} while (a[j] > pivot);
			
			if (i < j) {
				std::swap(a[i], a[j]);
			}
			
		} while (i < j);
		
		std::swap(a[left], a[j]);
		
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);
	}
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
	
	quick_sort(data, n);
	
	std::cout << "Sorted data: ";
	print_data(data, n);
}
