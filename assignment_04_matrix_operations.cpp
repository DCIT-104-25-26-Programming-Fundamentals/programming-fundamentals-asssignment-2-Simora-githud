// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

void addMatrices(int A[10][10], int B[10][10], int rows, int cols)
{
    int sum[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

void multiplyMatrices(int A[10][10], int B[10][10], int rowsA, int colsA, int colsB)
{
    int product[10][10];

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nProduct of Matrices:\n";
    displayMatrix(product, rowsA, colsB);
}

int main()
{
    int choice;

    cout << "Matrix Operations\n";
    cout << "1. Transpose Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int rows, cols;
        int matrix[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        transposeMatrix(matrix, rows, cols);
    }
    else if (choice == 2)
    {
        int rows, cols;
        int A[10][10], B[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter first matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }

        cout << "\nEnter second matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }

        addMatrices(A, B, rows, cols);
    }
    else if (choice == 3)
    {
        int rowsA, colsA, rowsB, colsB;
        int A[10][10], B[10][10];

        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB)
        {
            cout << "Matrix multiplication is not possible." << endl;
            return 0;
        }

        cout << "\nEnter Matrix A:\n";
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }

        cout << "\nEnter Matrix B:\n";
        for (int i = 0; i < rowsB; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }

        multiplyMatrices(A, B, rowsA, colsA, colsB);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}