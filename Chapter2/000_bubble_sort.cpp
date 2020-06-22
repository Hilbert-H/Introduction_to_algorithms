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
void BubbleSort(std::vector<T> &data){
	for (int i = 0; i < data.size() - 1; ++i)
	{
		for (int j = i + 1; j < data.size(); ++j)
		{
			if (data[i] > data[j])
			{
				T temp = data[i];
				data[i] = data[j];
				data[j] = temp; 
			}
		}
	}
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	cout << "Before Sort:" << endl;
	ArrayShow(data);

	BubbleSort(data);
	cout << "After Sort:" << endl;
	ArrayShow(data);

	return 0;
}