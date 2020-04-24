#include <iostream>

void bubble_sort(int data[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (data[i] < data[j]) {
				std::swap(data[i], data[j]);
			}
		}
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
	
	bubble_sort(data, n);
	
	std::cout << "Sorted data: ";
	print_data(data, n);
}
