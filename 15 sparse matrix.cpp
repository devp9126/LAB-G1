#include <iostream>
using namespace std;

int main() {
    // Define a 4x5 sparse matrix
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int numRows = 4;
    int numCols = 5;
    int size = 0; // Number of non-zero elements

    // Count the number of non-zero elements in the sparse matrix
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    // Create a compact matrix to store non-zero elements
    int compactMatrix[3][size];

    int k = 0; // Counter for compact matrix column

    // Populate the compact matrix with row index, column index, and non-zero values
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i; // Row index
                compactMatrix[1][k] = j; // Column index
                compactMatrix[2][k] = sparseMatrix[i][j]; // Non-zero value
                k++;
            }
        }
    }

    // Print the compact matrix
    cout << "Compact Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            cout << compactMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
