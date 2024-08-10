#include <iostream>
#include <vector>
using namespace std;

int determinant(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;
    vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));
    for (int col = 0; col < n; ++col) {
        for (int i = 1; i < n; ++i) {
            int subCol = 0;
            for (int j = 0; j < n; ++j) {
                if (j == col) continue;
                submatrix[i - 1][subCol++] = matrix[i][j];
            }
        }
        int minorDet = determinant(submatrix);
        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * minorDet;
    }
    return det;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    if (n <= 0) {
        cout << "Matrix size must be a positive integer." << endl;
        return 1;
    }
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    int det = determinant(matrix);
    cout << "The determinant of the matrix is: " << det << endl;
    return 0;
}
