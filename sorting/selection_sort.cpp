#include<iostream>

void selection_sort(int data[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[minIndex]) {
				minIndex = j;
			}
		}
		std::swap(data[minIndex], data[i]);
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
	
	selection_sort(data, n);
	
	std::cout << "Sorted data: ";
	print_data(data, n);
}
