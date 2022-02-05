#include "Matrix.h"

//Constructor method
Matrix::Matrix(uint rows, uint cols)  : rows(rows), cols(cols), values(new double *[rows]) {
  //initializing variables
  this->rows = rows;
  this->cols = cols;

  //initializing an array
  makeArray();

  //Initialize all elements to 0
  for(uint i = 0; i < rows; ++i) {
    for(uint j = 0; j < cols; ++j) {
      this->values[i][j] = 0.0;
    }
  }
  
} // constructor

//Constructor that makes a copy of the passed array
Matrix::Matrix(double** values, int w, int h) {

  //making copy with for loop
  for ( double i=0; i < w; i++) {
    for (double j = 0; j < h; ++j) {
      this->values[w][h] = j;
    }
  }
} //copy constructor

//copy constructor
Matrix::Matrix(const Matrix & m) {

  //assign values to the rows and cols variable from 'm'
  this->rows = m.numRows();  
  this->cols = m.numCols();  

  //after we assign variables we make the array
  makeArray();  

  //looop to copy information to the allocated array
  for(uint i = 0; i < rows; ++i) {  
    for(uint j = 0; j < cols; ++j) {  
      this->values[i][j] = m.at(i,j);  
    }  
  }  
} //copy constructor

//Destructor of Matrix Class
Matrix::~Matrix() {

  //for loop to delete the values in the array
for (uint i = 0; i < rows; i++) {
  delete[] values[i];
}
delete[] values;
}

//Add method with parameter type double
Matrix Matrix::add(double s) const {

  //creating a temporary Matrix
Matrix tempValues(this->rows, this->cols);

//for loop that acts to trasnfer the information to the temp array
for (uint i = 0; i < this->rows; i++) {
  for (uint j = 0; j < this->cols; j++) {
    tempValues.at(i, j) = this->at(i, j) + s;
  }

 }

 return tempValues;

}

//This function peforms addition on this matrix and another matrix when the dimensions are the same.                                                                 
Matrix Matrix::add(const Matrix & m) const {

  //check the size of the two arrays are the same                                                                                                                    
  if (this->rows == m.numRows() && this->cols == m.numCols()) {                                                                                                    

    //if so we create temp class of Matrix                                                                                                                           
    Matrix tempValues(this->rows, this->cols);

    //for loop to add the values of the arrays at the same positions                                                                                                 
    for (uint i = 0; i < this->rows; i++) {
      for (uint j = 0; j < this->cols; j++) {
        tempValues.at(i, j) = this->at(i, j) + m.at(i, j);
      }
    }

return tempValues;

}                                                                                                                                                                  

else {                                                                                                                                                             

  //else if they're not the same size then just return a copy Values                                                                                                 
Matrix sameExist(*this);                                                                                                                                           

return sameExist;                                                                                                                                                  

}                                                                                                                                                                  

}


/*Implemmentation of subtract method with parameter type double*/
//This methos performans suntraction on this matric and another matrix
Matrix Matrix::subtract(double s) const {

  //Creating temp array
Matrix tempValues(this->rows, this->cols);

//for loop to subjtract the values at the positions
for (uint i = 0; i < this->rows; i++) {

for (uint j = 0; j < this->cols; j++) {

tempValues.at(i, j) = this->at(i, j) - s;

}

}

return tempValues;

}

//This method performs subtractation on  another matrix from this matrix when both dimensions are the same
Matrix Matrix::subtract(const Matrix & m) const {

  //checking if dimensions are same
if (this->rows == m.numRows() && this->cols == m.numCols()) {

  //creating temporary
Matrix tempValues(this->rows, this->cols);

//for loop to subtract values
for (uint i = 0; i < this->rows; i++) {

for (uint j = 0; j < this->cols; j++) {

tempValues.at(i, j) = this->at(i, j) - m.at(i, j);

}

}

return tempValues;

}

else {
  //else if return copy of calling Values
Matrix sameExist(*this);

return sameExist;

}

}

//Multiply method
Matrix Matrix::multiply(double s) const {

  //Creatign a temporary to hold the new values
Matrix tempMatrix(this->rows, this->cols);

//for loop to perform the operation and add the values to the temp array
for (uint i = 0; i < this->rows; i++) {

for (uint j = 0; j < this->cols; j++) {

tempMatrix.at(i, j) = this->at(i, j) * s;

}

}

return tempMatrix;

}

//Multiply method matrix by another matrix
//if numCols() of the first == numRows() of the second.
//if does not exist, returns copy of calling matrix.
Matrix Matrix::multiply(const Matrix & m) const {

  //checking to see if the number of cols is equal to the number of rows in the Matrix
if (this->cols == m.numRows()) {

  //if so creates a temporary matrix to hold the values after the operation
Matrix tempValues(this->rows, m.numCols());

//creating variable to hold the sum of the procedures
double sum;

//for loop to loop the matrixs and perform teh operations
for (uint i = 0; i < tempValues.numRows(); i++) {

for (uint j = 0; j < tempValues.numCols(); j++) {

sum = 0;

//multiplying 
for (uint k = 0; k < this->cols; k++) {

sum += this->at(i, k) * m.at(k, j);

}

//giving the said position(i,j) the product
tempValues.at(i, j) = sum;

}

}

return tempValues;

}

else {
  //else if return copy of calling Values
Matrix sameExist(*this);

return sameExist;

}

}

/*Implementation of divide method with parameters as type double*/
Matrix Matrix::divide(double s) const {

  //if cant equal 0 because you cant divide by 0
if (s != 0) {

  //creating a temporary array
Matrix tempValues(this->rows, this->cols);

//for loop to loop through both array to perform the operations
for (uint i = 0; i < this->rows; i++) {
  for (uint j = 0; j < this->cols; j++) {
    tempValues.at(i, j) = this->at(i, j) / s;
}

}

return tempValues;

}

else {

Matrix sameExist(*this);

return sameExist;

}

}

//t method transpotition
Matrix Matrix::t() const {

  //creating a temporary array
Matrix tempValues(this->cols, this->rows);

//for loop transpositioning the values in the arrays
for (uint i = 0; i < tempValues.numRows(); i++) {

for (uint j = 0; j < tempValues.numCols(); j++) {

tempValues.at(i, j) = this->at(j, i);

}

}

return tempValues;

} // transposition of this matrix

/*numRows method*/
const uint Matrix::numRows() const {

  // returns the number of rows
  return this->rows;

}

/*numCols method*/
const uint Matrix::numCols() const {

  // returns the number of cols
  return this->cols;

}

// at method which will set get/set element at row/col
double & Matrix::at(uint row, uint col) {

return this->values[row][col];

}

const double & Matrix::at(uint row, uint col) const {

return this->values[row][col];

}
