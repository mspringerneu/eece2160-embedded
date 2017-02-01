/*
 *  Project:    HW #1, Problem # 2
 *  Author:     Matthew Springer
 *  Date:       January 30, 2017
 *  Purpose:    Write a program that produces the transpose of a 3x3 matrix
 */

#include <iostream>

using namespace std;

/*
 *  Function:   NewMatrix3x3
 *  Input:      None
 *  Output:     int ** Matrix3x3
 *  Purpose:    Generates an empty 3x3 matrix of integers
 */
int ** NewMatrix3x3() {
  int ** Matrix3x3 = new int*[3];
  Matrix3x3[0] = new int[3];
  Matrix3x3[1] = new int[3];
  Matrix3x3[2] = new int[3];
  return Matrix3x3;
}

/*
 *  Function:   InitMatrix
 *  Input:      int** matrix, int rows (number of rows), int columns (number of columns)
 *  Output:     None
 *  Purpose:    Sets a matrix's values to numerically-ordered integers (row-wise)
 */
void  InitMatrix(int** matrix, int rows, int columns) {
  int counter = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[j][i] = counter++;
    }
  }
}

/*
 *  Function:   NewMatrix
 *  Input:      int rows (number of rows), int columns (number of columns)
 *  Output:     int ** Matrix (new integer matrix of size rows x columns)
 *  Purpose:    Generates an empty matrix of size rows x columns
 */
int ** NewMatrix(int rows, int columns) {
  int ** MatrixRxC = new int*[columns];
  for (int i = 0; i < columns; i++) {
    MatrixRxC[i] = new int[rows];
  }
  return MatrixRxC;
}

/*
 *  Function:   DuplicateMatrix
 *  Input:      int ** MatrixIn, int rows (number of rows), int columns (number of columns)
 *  Output:     int ** MatrixOut, (new integer matrix of size rows x columns)
 *  Purpose:    Generates an empty matrix of size rows x columns
 */
int ** DuplicateMatrix(int ** matrix, int rows, int columns) {
  int ** DupMat = new int*[columns];
  for (int i = 0; i < columns; i++) {
    DupMat[i] = new int[rows];
    for (int j = 0; j < rows; j++) {
      DupMat[i][j] = matrix[i][j];
    }
  }
  return DupMat;
}

/*
 *  Function:   DeleteMatrix
 *  Input:      int** matrix, int columns (number of columns)
 *  Output:     None
 *  Purpose:    Deallocates memory for dynamically-generated matrix with a given number of columns
 */
void DeleteMatrix(int ** matrix, int columns) {
  for (int i = 0; i < columns; i++) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

/*
 *  Function:   PrintMatrix
 *  Input:      int** matrix, int rows (number of rows), int columns (number of columns)
 *  Output:     None
 *  Purpose:    Prints a given matrix of size rows x columns
 */
void PrintMatrix(int** matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    cout << endl << "\t|\t";
    for (int j = 0; j < columns; j++) {
      cout << matrix[j][i] << "\t";
    }
    cout << "|" << endl;
  }
}

/*
 *  Function:   IndexTranspose
 *  Input:      int** matrix, int rows (number of rows), int columns (number of columns)
 *  Output:     None
 *  Purpose:    Mutates a given Matrix to its transpose, using array indices
 */
void IndexTranspose(int ** matrix, int rows, int columns) {
  int ** copyMat = DuplicateMatrix(matrix, rows, columns);
  DeleteMatrix(matrix, columns);
  matrix = NewMatrix(columns, rows);
  //int ** transpose = NewMatrix(columns, rows);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      matrix[j][i] = copyMat[i][j];
    }
  }
}

/*
 *  Function:   PointerTranspose
 *  Input:      int** matrix, int rows (number of rows), int columns (number of columns)
 *  Output:     None
 *  Purpose:    Mutates a given Matrix to its transpose, using pointers
 */
void PointerTranspose(int ** matrix, int rows, int columns) {
  int ** copyMat = DuplicateMatrix(matrix, rows, columns);
  DeleteMatrix(matrix, columns);
  matrix = NewMatrix(columns, rows);
  //int ** transpose = NewMatrix(columns, rows);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      *(*(matrix+j) + i) = *(*(copyMat+i) + j);
    }
  }
}

int main() {
  int rows, cols;
  rows = 3;
  cols = 3;
  int** mat = NewMatrix(rows,cols);
  int ** transpose;
  InitMatrix(mat, rows, cols);
  cout << "Initial Matrix: " << endl;
  PrintMatrix(mat, rows, cols);
  IndexTranspose(mat, rows, cols);
  cout << "Transposed Matrix using indices: " << endl;
  PrintMatrix(mat, cols, rows);
  PointerTranspose(mat, rows, cols);
  cout << "Transpose of Transposed Matrix using pointers: " << endl;
  PrintMatrix(mat, cols, rows);
  //PrintMatrix(transpose, cols, rows);
  
  return 0;
}
