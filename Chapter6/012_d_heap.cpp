#include <iostream>
#include <vector>

#define PARENT(i, d) ((i - 1) / d)
#define SON(i, j, d) (i * d + j + 1)

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
void MaxHeapIFY(std::vector<T>& A, int d, int heap_size, int i){
	if (i > (heap_size - 2) / d) return;

	int largest = i;
	int j = 0;
	while(SON(i, j, d) != heap_size && j < d){
		if (A[SON(i, j, d)] > A[largest]) largest = SON(i, j, d);
		++j;
	}
	if (largest == i) return;
	T temp = A[i];
	A[i] =A[largest];
	A[largest] = temp;
	MaxHeapIFY(A, d, heap_size, largest);
}


template <typename T>
void BulidMaxHeap(std::vector<T>& A, int d){
	for (int i = (A.size() - 2) / d; i >= 0; --i)
		MaxHeapIFY(A, d, A.size(), i);
}

template <typename T>
T ExtractMax(std::vector<T>& A, int d){
	T max = A[0];
	A[0] = A.back();
	A.pop_back();
	MaxHeapIFY(A, d, A.size(), 0);

	return max;
}

template <typename T>
void IncreaseKey(std::vector<T>& A, int d, int i, T key){
	while(i > 0 && A[PARENT(i, d)] < key){
		A[i] = A[PARENT(i, d)];
		i = PARENT(i, d);
	}
	A[i] = key;
}

template <typename T>
void MaxInsert(std::vector<T>& A, int d, T key){
	A.push_back(std::numeric_limits<T>::min());
	IncreaseKey(A, d, A.size() - 1, key);
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01, 1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01, 1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	BulidMaxHeap(data, 3);
	cout << "Build Max Heap:" << endl;
	ArrayShow(data);

	float max = ExtractMax(data, 3);
	cout << "After Extract Max:" << endl;
	ArrayShow(data);

	float num = 10.0;
	IncreaseKey(data, 3, 5, num);
	cout << "Heap increase data[5] to 10.0: " << endl;
	ArrayShow(data);

	MaxInsert(data, 3, ++num);
	cout << "Insert max heap 11.0:" << endl;
	ArrayShow(data);
}



























