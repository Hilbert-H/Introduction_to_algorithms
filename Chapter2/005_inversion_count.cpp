#include <iostream>
#include <vector>

template <typename T>
int InversionCount(std::vector<T>& data, int start, int end){
	if (start >= end) return 0;

	std::vector<T> copy(data);
	int mid = (start + end) / 2;
	int left = InversionCount(data, start, mid);
	int right = InversionCount(data, mid + 1, end);

	int p = mid;
	int q = end;
	int index = end;
	int count = 0;

	while (p >= start and q > mid){
		if (data[p] > data[q])
		{
			copy[index--] = data[p--];
			count += q - mid;
		}
		else
		{
			copy[index--] = data[q--];
		}
	}
	while (p >= start) copy[index--] = data[p--];
	while (q > mid) copy[index--] = data[q--];
	data = copy;

	return left + right + count;
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	cout << "There are " 
		 << InversionCount(data, 0, data.size() - 1)
		 << " inversions" << endl;
}










