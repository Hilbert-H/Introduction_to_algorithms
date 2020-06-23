
#ifndef matrix_hpp
#define matrix_hpp

class Matrix {
public:
  Matrix(unsigned rows, unsigned cols);
  double& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  double  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs
  Matrix operator+ (const Matrix& m);
  Matrix operator- (const Matrix& m);
  // ...
 ~Matrix();                              // Destructor
  Matrix(const Matrix& m);               // Copy constructor
  Matrix& operator= (const Matrix& m);   // Assignment operator
  // ...
private:
  unsigned rows_, cols_;
  double* data_;
};
inline
Matrix::Matrix(unsigned rows, unsigned cols)
  : rows_ (rows)
  , cols_ (cols)
//, data_ ← initialized below after the if...throw statement
{
  if (rows == 0 || cols == 0)
    throw ("Matrix constructor has 0 size");
  data_ = new double[rows * cols];
}
inline
Matrix::~Matrix()
{
  delete[] data_;
}

Matrix::Matrix(const Matrix& m){
    rows_ = m.rows_;
    cols_ = m.cols_;
    for (unsigned i = 0; i < rows_; ++i)
        for (unsigned j = 0; j < cols_; ++j)
            data_[cols_ * i + j] = m(i, j);
}

inline
double& Matrix::operator() (unsigned row, unsigned col)
{
  if (row >= rows_ || col >= cols_)
    throw ("Matrix subscript out of bounds");
  return data_[cols_*row + col];
}
inline
double Matrix::operator() (unsigned row, unsigned col) const
{
  if (row >= rows_ || col >= cols_)
    throw ("const Matrix subscript out of bounds");
  return data_[cols_*row + col];
}

Matrix& Matrix::operator= (const Matrix& m){
    rows_ = m.rows_;
    cols_ = m.cols_;
    for (unsigned i = 0; i < rows_; ++i)
        for (unsigned j = 0; j < cols_; ++j)
            data_[cols_ * i + j] = m(i, j);
    return *this;
}

Matrix Matrix::operator+ (const Matrix& m){
    Matrix sum(m.rows_, m.cols_);
    for (unsigned i = 0; i < rows_; ++i)
        for (unsigned j = 0; j < cols_; ++j)
            sum(i, j) = m(i, j) + data_[cols_ * i + j];
    return sum;
}

Matrix Matrix::operator- (const Matrix& m){
    Matrix sum(m.rows_, m.cols_);
    for (unsigned i = 0; i < rows_; ++i)
        for (unsigned j = 0; j < cols_; ++j)
            sum(i, j) = data_[cols_ * i + j] - m(i, j);
    return sum;
}


#endif





