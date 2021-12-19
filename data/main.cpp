#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::endl;

using std::rand;
using std::srand;
using std::time;

void printArr(int arr[], int max) {
	for (int i = 0; i < max; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n" << endl;
	return;
}

void initArr(int arr[], int max) {
	srand(time(NULL));
	for (int i=0; i < max; i++) {
		arr[i] = rand() % max;
	}
}

// adapted code from https://www.geeksforgeeks.org/iterative-quick-sort/
void sortArr(int arr[], int max) {
	int l = 0;
	int h = max-1;

	 // Create an auxiliary stack
    int stack[h - l + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
 
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
		int x = arr[h];
   		int i = (l - 1);
 
		for (int j = l; j <= h - 1; j++) {
		    if (arr[j] <= x) {
		        i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
		    }
    	}
		int temp = arr[i+1];
		arr[i+1] = arr[h];
		arr[h] = temp;

        int p = i + 1;
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main() {

	int max = 10;
	int arr[max];

	initArr(arr, max);
	printArr(arr, max);

	sortArr(arr, max);
	
	printArr(arr, max);
		
	return 0;
}
