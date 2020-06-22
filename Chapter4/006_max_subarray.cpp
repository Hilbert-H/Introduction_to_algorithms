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
std::tuple <int, int, T> MaxCrossingSubarray(const std::vector<T> &data, int low, int mid, int high){
	T left_sum = std::numeric_limits<T>::min();
	T right_sum = std::numeric_limits<T>::min();
	int max_left = mid;
	int max_right = mid + 1;
	T sum = 0;

	for (int i = mid; i >= low; --i)
	{
		sum += data[i];
		if (left_sum < sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	sum = 0;
	for (int i = mid + 1; i <= high; ++i)
	{
		sum += data[i];
		if (right_sum < sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}	

	return std::make_tuple(max_left, max_right, left_sum + right_sum);

}

template <typename T>
std::tuple <int, int, T> MaxSubarray(const std::vector<T> data, int low, int high){
	if (data.size() == 0) return std::make_tuple(0, 0, 0);
	if (low == high) return std::make_tuple(low, high, data[low]);

	int mid = (low + high) / 2;
	std::tuple <int, int, T> ret_left, ret_right, ret_cross;

	ret_left = MaxSubarray(data, low, mid);
	ret_right = MaxSubarray(data, mid + 1, high);
	ret_cross = MaxCrossingSubarray(data, low, mid, high);

	if (std::get<2>(ret_left) >= std::get<2>(ret_right) and std::get<2>(ret_left) >= std::get<2>(ret_cross))
		return ret_left;
	else if (std::get<2>(ret_right) >= std::get<2>(ret_left) and std::get<2>(ret_right) >= std::get<2>(ret_cross))
		return ret_right;
	else
		return ret_cross;
}


int main(){
	using namespace std;
	vector<float> data = {1.23, -0.43, -6.24, 0.34, 0.13, 9.13, -9.12, 5.01};
	cout << "Data:" << endl;
	ArrayShow(data);

	tuple <int, int, float> max_subarray = MaxSubarray(data, 0, data.size() - 1);
	cout << "Maximum subarray is " << get<0>(max_subarray);
	cout << "th to " << get<1>(max_subarray) << "th, and sum is ";
	cout << std::get<2>(max_subarray) << endl;

}












