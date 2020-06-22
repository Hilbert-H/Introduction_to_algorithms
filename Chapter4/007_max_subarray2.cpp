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
std::tuple <int, int, T> MaxSubarray(const std::vector<T> &data){
	if (data.size() == 0) return std::make_tuple(0, 0, 0);
	int beg = 0;
	int end = 0;
	T sum = data[0];
	for (int j = 0; j < data.size() - 1; ++j)
	{
		for (int i = 0; i <= j + 1; ++i)
		{
			T sum_temp = 0;
			for (int k = i; k <= j+1; ++k)
			{
				sum_temp += data[k];
			}
			if (sum_temp > sum)
			{
				sum = sum_temp;
				beg = i;
				end = j + 1;
			}
		}
	}
	return std::make_tuple(beg, end, sum);
}

int main(){
	using namespace std;
	vector<float> data = {1.23, -0.43, -6.24, 0.34, 0.13, 9.13, -9.12, 5.01};
	cout << "Data:" << endl;
	ArrayShow(data);

	tuple <int, int, float> max_subarray = MaxSubarray(data);
	cout << "Maximum subarray is " << get<0>(max_subarray);
	cout << "th to " << get<1>(max_subarray) << "th, and sum is ";
	cout << std::get<2>(max_subarray) << endl;

}