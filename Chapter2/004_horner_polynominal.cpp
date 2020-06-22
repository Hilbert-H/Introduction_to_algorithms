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
float HornerPolynominal(const std::vector<T> &data, T x){
	T result = x;
	for (int i = data.size() - 1; i >= 0; --i)
	{
		result = result * data[i] + data[i - 1];
	}
	return result;
}

int main(){
	using namespace std;
	vector<float> data = {1.23, 0.43, 6.24, 0.34, 0.13, 9.13, 9.12, 5.01};
	cout << "Polynominal Coefficents:" << endl;
	ArrayShow(data);

	float x = 1.0;
	cout << "P(" << x << ") = " 
		 << HornerPolynominal(data, x) << endl;

	return 0;
}