#include <iostream>
#include "matrix.hpp"

void MatrixShow(const Matrix& m, int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            std::cout << m(i, j);
            if (j != n - 1) std::cout << '\t';
            else std::cout << std::endl;
        }
}

Matrix MatrixPart(const Matrix& M, int x1, int x2, int y1, int y2){
    Matrix subM(x2 - x1 + 1, y2 - y1 + 1);
    for (int i = x1; i <= x2; ++i)
        for (int j = y1; j <= y2; ++j)
            subM(i - x1, j - y1) = M(i, j);

    return subM;
}

Matrix MatrixMerge(const Matrix& M1, const Matrix& M2, const Matrix& M3, const Matrix& M4, unsigned n){
    Matrix merge_matrix(2 * n, 2 * n);
    for (int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            merge_matrix(i, j) = M1(i, j);
            merge_matrix(i, n + j) = M2(i, j);
            merge_matrix(n + i, j) = M3(i, j);
            merge_matrix(n + i, n + j) = M4(i, j);
        }
    return merge_matrix;
}

Matrix StrassenMatrixMultiply(const Matrix& A, const Matrix& B, int n){
    if (n == 1){
        Matrix m(1, 1);
        m(0, 0) = A(0, 0) * B(0, 0);
        return m;
    };
    Matrix A11((n+1)/2, (n+1)/2), A12((n+1)/2, (n+1)/2), A21((n+1)/2, (n+1)/2), A22((n+1)/2, (n+1)/2);
    Matrix B11((n+1)/2, (n+1)/2), B12((n+1)/2, (n+1)/2), B21((n+1)/2, (n+1)/2), B22((n+1)/2, (n+1)/2);
    int flag = 0;
    if (n % 2 == 1)
    {
        Matrix A_new(n + 1, n + 1), B_new(n + 1, n + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j){
                A_new(i, j) = A(i, j);
                B_new(i, j) = B(i, j);
            }
        for (int i = 0; i < n; i++){
            A_new(i ,n) = 0;
            A_new(n, i) = 0;
            B_new(i ,n) = 0;
            B_new(n, i) = 0;
        }
        A_new(n, n) = 1;
        B_new(n, n) = 1;
        n += 1;
        flag = 1;
        A11 = MatrixPart(A_new, 0, n / 2 - 1, 0, n / 2 - 1);
        A12 = MatrixPart(A_new, 0, n / 2 - 1, n / 2, n - 1);
        A21 = MatrixPart(A_new, n / 2, n - 1, 0, n / 2 - 1);
        A22 = MatrixPart(A_new, n / 2, n - 1, n / 2, n - 1);
        B11 = MatrixPart(B_new, 0, n / 2 - 1, 0, n / 2 - 1);
        B12 = MatrixPart(B_new, 0, n / 2 - 1, n / 2, n - 1);
        B21 = MatrixPart(B_new, n / 2, n - 1, 0, n / 2 - 1);
        B22 = MatrixPart(B_new, n / 2, n - 1, n / 2, n - 1);
    }
    else{
        A11 = MatrixPart(A, 0, n / 2 - 1, 0, n / 2 - 1);
        A12 = MatrixPart(A, 0, n / 2 - 1, n / 2, n - 1);
        A21 = MatrixPart(A, n / 2, n - 1, 0, n / 2 - 1);
        A22 = MatrixPart(A, n / 2, n - 1, n / 2, n - 1);
        B11 = MatrixPart(B, 0, n / 2 - 1, 0, n / 2 - 1);
        B12 = MatrixPart(B, 0, n / 2 - 1, n / 2, n - 1);
        B21 = MatrixPart(B, n / 2, n - 1, 0, n / 2 - 1);
        B22 = MatrixPart(B, n / 2, n - 1, n / 2, n - 1);
    }

    Matrix S1 = B12 - B22;
    Matrix S2 = A11 + A12;
    Matrix S3 = A21 + A22;
    Matrix S4 = B21 - B11;
    Matrix S5 = A11 + A22;
    Matrix S6 = B11 + B22;
    Matrix S7 = A12 - A22;
    Matrix S8 = B21 + B22;
    Matrix S9 = A11 - A21;
    Matrix S10 = B11 + B12;

    Matrix P1 = StrassenMatrixMultiply(A11, S1, n / 2);
    Matrix P2 = StrassenMatrixMultiply(S2, B22, n / 2);
    Matrix P3 = StrassenMatrixMultiply(S3, B11, n / 2);
    Matrix P4 = StrassenMatrixMultiply(A22, S4, n / 2);
    Matrix P5 = StrassenMatrixMultiply(S5, S6, n / 2);
    Matrix P6 = StrassenMatrixMultiply(S7, S8, n / 2);
    Matrix P7 = StrassenMatrixMultiply(S9, S10, n / 2);

    Matrix C11 = P5 + P4 - P2 + P6;
    Matrix C12 = P1 + P2;
    Matrix C21 = P3 + P4;
    Matrix C22 = P5 + P1 - P3 - P7;

    if (flag == 1)
    	return MatrixPart(MatrixMerge(C11, C12, C21, C22, n / 2), 0, n - 2, 0, n - 2);
    else
    	return MatrixMerge(C11, C12, C21, C22, n / 2);
}

int main(){
    using namespace std;
    Matrix m1(5, 5), m2(5, 5);
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            m1(i, j) = i + j;
            m2(i, j) = 5 - i + 2 * j;
        }
    cout << "m1:" << endl;
    MatrixShow(m1, 5);
    cout << "m2:" << endl;
    MatrixShow(m2, 5);
    Matrix m3 = StrassenMatrixMultiply(m1, m2, 5);
    cout << "m3:" << endl;
    MatrixShow(m3, 5);
}










