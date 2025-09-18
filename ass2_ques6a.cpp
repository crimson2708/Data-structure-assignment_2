#include <iostream>
using namespace std;

#define MAX 100

struct SparseMatrix {
    int data[MAX][3];  // row, col, value
    int size;          // number of non-zero elements
};

// Function to create sparse matrix
void createSparse(SparseMatrix &s, int rows, int cols, int elements[][3], int num) {
    s.data[0][0] = rows;
    s.data[0][1] = cols;
    s.data[0][2] = num;
    for (int i = 0; i < num; i++) {
        s.data[i + 1][0] = elements[i][0];
        s.data[i + 1][1] = elements[i][1];
        s.data[i + 1][2] = elements[i][2];
    }
    s.size = num;
}

// Display sparse matrix triplet
void display(const SparseMatrix &s) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= s.size; i++) {
        cout << s.data[i][0] << "   " << s.data[i][1] << "   " << s.data[i][2] << endl;
    }
}

// Transpose
SparseMatrix transpose(const SparseMatrix &s) {
    SparseMatrix t;
    int rows = s.data[0][1], cols = s.data[0][0], num = s.data[0][2];
    t.data[0][0] = rows;
    t.data[0][1] = cols;
    t.data[0][2] = num;

    int k = 1;
    for (int c = 0; c < rows; c++) {
        for (int i = 1; i <= num; i++) {
            if (s.data[i][1] == c) {
                t.data[k][0] = s.data[i][1];
                t.data[k][1] = s.data[i][0];
                t.data[k][2] = s.data[i][2];
                k++;
            }
        }
    }
    t.size = num;
    return t;
}

int main() {
    int elements[4][3] = {{0, 0, 3}, {0, 3, 5}, {1, 1, 7}, {2, 2, 9}};
    SparseMatrix A, T;
    createSparse(A, 3, 4, elements, 4);

    cout << "Matrix A:\n";
    display(A);

    cout << "\nTranspose of A:\n";
    T = transpose(A);
    display(T);

    return 0;
}