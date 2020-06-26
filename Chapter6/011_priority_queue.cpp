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

/////////////////////////////////////////////////
/////////////////////////////////////////////////

template <typename T>
T HeapMax(std::vector<T>& A){
	return A[0];
}

template <typename T>
T HeapExtractMax(std::vector<T>& A){
	T max = A[0];
	A[0] = A.back();
	A.pop_back();
	MaxHeapIFY(A, A.size(), 0);

	return max;
}

template <typename T>
void HeapIncreaseKey(std::vector<T>& A, int i, T key){
	while(i > 0 && A[PARENT(i)] < key){
		A[i] = A[PARENT(i)];
		i = PARENT(i);
	}
	A[i] = key;
}

template <typename T>
void MaxheapInsert(std::vector<T>& A, T key){
	A.push_back(std::numeric_limits<T>::min());
	HeapIncreaseKey(A, A.size() - 1, key);
}


template <typename T>
void HeapDelete(std::vector<T>& A, int i){
	A[i] = std::numeric_limits<T>::min();
	MaxHeapIFY(A, A.size(), i);
	A.pop_back();
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	BulidMaxHeap(data);
	cout << "Original Heap:" << endl;
	ArrayShow(data);

	cout << "Max of the heap: " << HeapMax(data) <<endl;

	float num = 10.0;
	HeapIncreaseKey(data, 5, num);
	cout << "Heap increase data[5] to 10.0: " << endl;
	ArrayShow(data);

	MaxheapInsert(data, ++num);
	cout << "Insert max heap 11.0:" << endl;
	ArrayShow(data);

	HeapDelete(data, 3);
	cout << "Delete 3th data:" << endl;
	ArrayShow(data);
}















