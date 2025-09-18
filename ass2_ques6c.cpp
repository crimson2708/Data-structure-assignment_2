#include <iostream>
using namespace std;

#define MAX 100

struct SparseMatrix {
    int data[MAX][3];
    int size;
};

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

// Multiplication
SparseMatrix multiply(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix product;
    if (a.data[0][1] != b.data[0][0]) {
        cout << "Multiplication not possible!\n";
        product.size = 0;
        return product;
    }

    SparseMatrix bt = transpose(b);
    int k = 1;
    product.data[0][0] = a.data[0][0];
    product.data[0][1] = b.data[0][1];

    for (int i = 0; i < a.data[0][0]; i++) {
        for (int j = 0; j < b.data[0][1]; j++) {
            int sum = 0;
            for (int x = 1; x <= a.size; x++) {
                if (a.data[x][0] == i) {
                    for (int y = 1; y <= bt.size; y++) {
                        if (bt.data[y][0] == j && bt.data[y][1] == a.data[x][1]) {
                            sum += a.data[x][2] * bt.data[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                product.data[k][0] = i;
                product.data[k][1] = j;
                product.data[k][2] = sum;
                k++;
            }
        }
    }
    product.data[0][2] = k - 1;
    product.size = k - 1;
    return product;
}

int main() {
    int elementsA[2][3] = {{0, 0, 1}, {1, 1, 2}};
    int elementsB[2][3] = {{0, 0, 3}, {1, 1, 4}};

    SparseMatrix A, B, P;
    createSparse(A, 2, 2, elementsA, 2);
    createSparse(B, 2, 2, elementsB, 2);

    cout << "Matrix A:\n"; display(A);
    cout << "\nMatrix B:\n"; display(B);

    cout << "\nA * B:\n";
    P = multiply(A, B);
    display(P);

    return 0;
}