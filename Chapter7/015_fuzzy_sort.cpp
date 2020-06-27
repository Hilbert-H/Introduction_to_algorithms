#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

template <typename T>
class node
{
public:
	node();
	node(T b, T e) : beg(b), end(e) {}
	node(const node<T>& n){
		beg = n.beg;
		end = n.end;
	};
	~node() = default;
	bool operator < (const node<T>& rhs) {return end < rhs.beg;}
	bool operator > (const node<T>& rhs) {return beg > rhs.beg;}
	bool operator == (const node<T>& rhs) {
		return end == rhs.beg;
	}
	template <typename TT> 
	friend std::ostream &operator << (std::ostream& os, const node<TT>& item);
private:
	T beg;
	T end;
};

template <typename T>
std::ostream &operator << (std::ostream& os, const node<T>& item){
	os << "[" << item.beg << ", " << item.end << "]";
	return os;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// no change with 014_quick_sort2.cpp

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
std::tuple<int, int> Pratition(std::vector<T>& A, int p, int r){
	T x = A[r];
	int i = p - 1;
	int t = p;
	for (int j = p; j < r; ++j){
		if (A[j] < x){
			Swap(A[++i], A[j]);
			++t;
		}
		else if (A[j] == x){
			Swap(A[++t], A[j]);
		}
	}
	Swap(A[t], A[r]);

	return std::make_tuple(i + 1, t);
}

template <typename T>
std::tuple<int, int> RandomPartition(std::vector<T>& A, int p, int r){
	srand((unsigned)time(NULL) + rand());
	int i = rand() % (r - p + 1) + p;
	Swap(A[r], A[i]);
	return Pratition(A, p, r);
}

template <typename T>
void RandomQuickSort(std::vector<T>& A, int p, int r){
	if (p < r){
		std::tuple<int, int> t = RandomPartition(A, p, r);
		RandomQuickSort(A, p, std::get<0>(t) - 1);
		RandomQuickSort(A, std::get<1>(t) + 1, r);
	}
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

int main(){
	using namespace std;
	vector<node<float>> data = {{0, 0.5}, {10, 10.5}, {3, 3.1}, {-2, -1.9}, {6, 6.2}, {2.7, 3.3}, {2.8, 3.2}};
	// vector<node<float>> data = {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {7, 8}};
	cout << "Before Sort:" << endl;
	ArrayShow(data);

	RandomQuickSort(data, 0, data.size() - 1);
	cout << "After Sort:" << endl;
	ArrayShow(data);

	return 0;
}





























