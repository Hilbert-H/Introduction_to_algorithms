#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

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
void Swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
int Pratition(std::vector<T>& A, int p, int r){
	T x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
		if (A[j] <= x)
			Swap(A[++i], A[j]);
	Swap(A[i + 1], A[r]);

	return i + 1;
}

template <typename T>
int RandomPartition(std::vector<T>& A, int p, int r){
	srand((unsigned)time(NULL) + rand());
	int i = rand() % (r - p + 1) + p;
	Swap(A[r], A[i]);
	return Pratition(A, p, r);
}

template <typename T>
void RandomQuickSort(std::vector<T>& A, int p, int r){
	if (p < r){
		int q = RandomPartition(A, p, r);
		RandomQuickSort(A, p, q - 1);
		RandomQuickSort(A, q + 1, r);
	}
}


int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	// std::vector<float> data(100000, 1.0);
	cout << "Before Sort:" << endl;
	ArrayShow(data);

	RandomQuickSort(data, 0, data.size() - 1);
	cout << "After Sort:" << endl;
	ArrayShow(data);

	return 0;
}






















