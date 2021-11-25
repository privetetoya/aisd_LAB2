#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
int binarySearch(int* array, int size, int key) { //  the array in which we are looking for an element , size is size of array, key is target value.
	int left = 0, right = size - 1, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key) left = mid;
		else if (array[mid] < key) right = mid;
	}
	if (array[mid] != key)return -1;
	else return mid;
}

void qSort(int* array, int left, int right) { // Quicksort
	int mid = (left + right) / 2;
	int l = left, r = right;
	while (l <= r) {
		while (array[l] < array[mid])l++;
		while (array[r] > array[mid])r--;
		if (l <= r) {
			swap(array[l], array[r]);
			l++;
			r--;
		}
		if (left < r)qSort(array, left, r);
		if (right > l)qSort(array, l, right);
	}
}


void insertionSort(int* array, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
			int tmp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = tmp;
		}
		//cout << array[i] << " ";
	}
}

void bogoSort(int* array, int size) { //Bogosort
	while (true) {
		bool flag = true;
		for (int i = 1; i < size && flag; i++) if (array[i - 1] > array[i])flag = false;
		if (flag) return;

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < size; i++) swap(array[i], array[rand() % size]);
	}
}

void countingSort(char* array, int size) { //Countingsort
	const int NUMBER_OF_CHAR = 256;
	int* counting_array = new int [NUMBER_OF_CHAR]; //array of all char values from zeros
	for (int i = 0; i < size; i++) //counting values in the passed array
		counting_array[(int)(unsigned char)array[i]]++;
	for (int i = 0, j = 0; j < NUMBER_OF_CHAR; j++) // forming a sorted array
		for (int k = 0; k < counting_array[j]; k++)
			array[i++] = (char)(unsigned char)j;
}

void timeTest(int size, int max_value) {
	//time_t start1, end1, start2, end2;
	int* array1 = new int[size];
	int* array2 = new int[size];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < size; i++)array1[i] = array2[i] = rand() % max_value;

	auto start1 = chrono::high_resolution_clock::now();
	qSort(array1, 0, size - 1);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<float> t1 = end1 - start1;

	auto start2 = chrono::high_resolution_clock::now();
	insertionSort(array2, size);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> t2 = end2 - start2;

	cout << "qSort with " << size << " numbers and max value " << max_value << " spend " << t1.count() << "seconds\n";
	cout << "insertionSort with " << size << " numbers and max value " << max_value << " spend " << t2.count() << "seconds\n";

	delete[] array1;
	delete[] array2;
}

int main() {
	timeTest(1000, 5000);
	system("pause");
}