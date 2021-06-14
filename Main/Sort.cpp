#include <iostream>
using namespace std;

const int SIZE = 15;
int L[SIZE] = { 10, 4, 7, 1, -2, 12, 28, 66, 9, 3, 5, 7, 6, 21, 11 };


void print_data()
{
	for(int i = 0; i < SIZE; i++)
		cout << " " << L[i] << " ";
	cout << endl;
}

void heap_sort(element a[], int n) {
	int i;
	HeapType h;

	init(&h);

	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i]);
	}

	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(&h);
	}
}

void main()
{
	cout << "Input Data : ";
	print_data();
	
	/* sort the elements of array L[] in ascending order */
	sort();
	
	cout << "\n\nSorted Data : ";
	print_data();

}
