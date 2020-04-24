#include<iostream>

void insertion_sort(int data[], int n) {
	for (int i = 1; i < n; i++) {
	    int num = data[i];
	    int j = i - 1;
	    
	    while(j >= 0 && data[j] > num) {
	        data[j + 1] = data[j];
	        j--;
	    }
	    
	    data[j + 1] = num;
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
	
	insertion_sort(data, n);
	
	std::cout << "Sorted data: ";
	print_data(data, n);
}
