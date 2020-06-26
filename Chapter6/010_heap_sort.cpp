#include <iostream>
#include <vector>

#define PARENT(i) ((i - 1) >> 1)
#define LEFT(i) ((i << 1) + 1)
#define RIGHT(i) ((i << 1) + 2)

template <typename T>
void ArrayShow(const std::vector<T> &data){
	std::cout << '\t';
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i];
		if (i == data.size() - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}
}

template <typename T>
void MaxHeapIFY(std::vector<T>& A, int heap_size, int i){
	if (i >= heap_size / 2) return;

	int l = LEFT(i);
	int r = (RIGHT(i) != heap_size ? RIGHT(i) : l);
	if (A[i] >= A[l] && A[i] >= A[r]) return;

	int largest = r;
	if (A[l] >= A[r]) largest = l;
	T temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	MaxHeapIFY(A, heap_size, largest);
}

template <typename T>
void BulidMaxHeap(std::vector<T>& A){
	for (int i = A.size() / 2; i >= 0; --i)
		MaxHeapIFY(A, A.size(), i);
}

template <typename T>
void HeapSort(std::vector<T>& A){
	int heap_size = A.size();
	BulidMaxHeap(A);
	for (int i = heap_size - 1; i > 0; --i)
	{
		T temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		--heap_size;
		MaxHeapIFY(A, heap_size, 0);
	}
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	cout << "Before Sort:" << endl;
	ArrayShow(data);

	HeapSort(data);
	cout << "After Sort:" << endl;
	ArrayShow(data);

	return 0;
}

















