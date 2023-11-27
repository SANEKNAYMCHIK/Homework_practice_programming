#include <iostream>
#include <ctime>
#define SORTSTAT 

template <typename T>
void BubbleSort(T M[], int size) {

#ifdef SORTSTAT
	clock_t ticktok = clock();
#endif

	for (int step = 1; step < size; ++step) {
		bool isSorted = true;
		for (int i = size - 1; i >= step; --i) {
			if (M[i] < M[i - 1]) {
				std::swap(M[i], M[i - 1]);
				isSorted = false;
			}
		}
		if (isSorted) {
			break;
		}
	}

#ifdef SORTSTAT
	ticktok = clock() - ticktok;
	std::cout << "tics " << ticktok << std::endl;
#endif
}


template <typename T>
void ChooseSort(T M[], int size) {

#ifdef SORTSTAT
	clock_t ticktok = clock();
#endif

	for (int step = 0; step < size; ++step) {
		int minimumIndex = step;
		for (int i = minimumIndex + 1; i < size; ++i) {
			if (M[i] < M[minimumIndex]) {
				minimumIndex = i;
			}
		}
		if (step < minimumIndex) {
			std::swap(M[step], M[minimumIndex]);
		}
	}

#ifdef SORTSTAT
	ticktok = clock() - ticktok;
	std::cout << "tics " << ticktok << std::endl;
#endif
}


template <typename T>
void printArray(T M[], int n, const char *str) {
	std::cout << str;
	for (int i = 0; i < n; ++i) {
		std::cout << " " << M[i];
	}
	std::cout << std::endl;
}

void randomArray(int M[], int n) {
	for (int i = 0; i < n; ++i) {
		M[i] = rand() % 9000 + 1000;
	}
}

void sortedArray(int M[], int n) {
	for (int i = 0; i < n; ++i) {
		M[i] = i + 1;
	}
}

void reversedArray(int M[], int n) {
	for (int i = 0; i < n; ++i) {
		M[i] = n - i ;
	}
}

void constArray(int M[], int n) {
	for (int i = 0; i < n; ++i) {
		M[i] = 1;
	}
}


template <typename T>
bool isSorted(T M[], int size) {
	for (int i = 1; i < size; ++i) {
		if (M[i] < M[i - 1]) {
			return false;
		}
	}
	return true;
}

void sortArray( void (*sorter)(int [], int),
				int A[], int size,
				const char * arrayname) {
	std::cout << "-- Array: " << arrayname << std::endl;
	if (size < 25) printArray(A, size, "Before: ");
	sorter(A, size);
	if (size < 25) printArray(A, size, "After:  ");
	if (!isSorted(A, size))
		std::cout << "ERROR: not sorted!" << std::endl;
}

void tester(void (*sorter)(int[], int),
			const char* name,
			const int* randArray, int size) {
	std::cout << "\n=========== Method: " << name << "===========\n";
	int* A = new int[size];
	sortedArray(A, size);
	sortArray(sorter, A, size, "Sorted: ");

	reversedArray(A, size);
	sortArray(sorter, A, size, "Reversed: ");

	constArray(A, size);
	sortArray(sorter, A, size, "Constants: ");
	
	for (int i = 0; i < size; ++i) A[i] = randArray[i];
	sortArray(sorter, A, size, "Random: ");

	delete[] A;
}

int main() {
	int N;
	do {
		std::cout << "Array size: ";
		std::cin >> N;
	} while (N < 1);
	int *M = new int[N];
	randomArray(M, N);
	tester(BubbleSort, "Bubble sorting", M, N);
	tester(ChooseSort, "Choose sorting", M, N);

	delete[] M;
	return 0;
}