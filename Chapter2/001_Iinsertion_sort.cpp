#include <iostream>
#include <vector>

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
void InsertionSort(std::vector<T> &data){
	for (int i = 1; i < data.size(); ++i)
	{
		T key = data[i];
		int j = i - 1;
		while (data[j] > key and j >= 0)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = key;
	}
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	cout << "Before Sort:" << endl;
	ArrayShow(data);

	InsertionSort(data);
	cout << "After Sort:" << endl;
	ArrayShow(data);

	return 0;
}