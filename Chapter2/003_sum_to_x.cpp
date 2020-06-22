#include <iostream>
#include <vector>
#include<float.h>

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
void Merge(std::vector<T> &data, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<T> L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; ++i) L[i] = data[p + i];
	for (int i = 0; i < n2; ++i) R[i] = data[q + i + 1];
	L[n1] = FLT_MAX;
	R[n2] = FLT_MAX;

	int j = 0;
	int k = 0;
	for (int i = p; i <= r; ++i)
	{
		if (L[j] < R[k]) data[i] = L[j++];
		else data[i] = R[k++];
	}
}

template <typename T>
void MergeSort(std::vector<T> &data, int p, int r){
	if (r > p){
		int q = (p + r) / 2;
		MergeSort(data, p, q);
		MergeSort(data, q + 1, r);
		Merge(data, p, q, r);
	}
}

template <typename T>
std::tuple <bool, int, int> SumToX(std::vector<T> &data, float x){
	if (data.size() <= 1) return std::make_tuple(false, 0, 0);
	int i = 0;
	int j = data.size() - 1;
	while (i < j){
		if (data[i] + data[j] == x) return std::make_tuple(true, i, j);
		if (data[i] + data[j] < x) ++i;
		else --j;
	}
	return std::make_tuple(false, 0, 0);
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};

	MergeSort(data, 0, 7);
	float x = data[3] + data[6];
	tuple <bool, int, int> result = SumToX(data, x);
	if (std::get<0>(result) == false) cout << "no result!";
	else{
		cout << "result: " << endl << '\t';
		cout << data[std::get<1>(result)] << " + " << data[std::get<2>(result)] << " = " << x << endl;
	}

	return 0;
}













