#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
void swap(int* arr, int k) {
	int temp = arr[k + 1];
	arr[k + 1] = arr[k];
	arr[k] = temp;
}

void bubble_sort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j);
			}
		}
	}
}
void quick_sort(int* arr, int first, int last)

{
	if (first < last)
	{	
		
		int left = first, right = last, middle = arr[(left + right) / 2];
		do
		{
			while (arr[left] < middle) left++;
			while (arr[right] > middle) right--;
			if (left <= right)
			{
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);
		quick_sort(arr, first, right);
		quick_sort(arr, left, last);
	}
}

void rand_arr(FILE * file, int n) {
	for (int i = 0; i < n; i++) fprintf(file, "%d ", rand() % n);

}

void shaker_sort(int* arr, int n) {
	int counter = 0;
	int leftMark = 1;
	int rightMark = n - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--) {
			if (arr[i - 1] > arr[i]) {
				swap(arr, i - 1);
			}
		}
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(arr, i - 1);
			}
			counter++;
		}
		rightMark--;

	}
}


int main()
{	
	FILE * file = fopen("input.txt", "r");
	long long int counter = 0;
	const int N = 100000;
	int choice;
	int arr[N];
	if (file == NULL) {
		puts("File error");
		return 0;
	}
	for (int i = 0; i < N; i++) {
		fscanf(file, "%d", &arr[i]); 
	};
	fclose(file);
	std::cout << "Choice sorting algorithm: \n";
	std::cout << "1. Quick sort \n";
	std::cout << "2. Bubble sort: \n";
	std::cout << "3. Shaker sort: \n";
	std::cin >> choice;

	switch (choice) {
	case 1: quick_sort(arr, 0, N - 1); break;
	case 2: bubble_sort(arr, N); break;
	case 3: shaker_sort(arr, N); break;
	default : quick_sort(arr, 0, N - 1); break;
	}

}
