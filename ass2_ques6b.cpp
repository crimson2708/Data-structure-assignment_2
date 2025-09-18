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

// Addition
SparseMatrix add(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix sum;
    if (a.data[0][0] != b.data[0][0] || a.data[0][1] != b.data[0][1]) {
        cout << "Addition not possible!\n";
        sum.size = 0;
        return sum;
    }

    int i = 1, j = 1, k = 1;
    sum.data[0][0] = a.data[0][0];
    sum.data[0][1] = a.data[0][1];

    while (i <= a.size && j <= b.size) {
        if (a.data[i][0] < b.data[j][0] ||
           (a.data[i][0] == b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            sum.data[k][0] = a.data[i][0];
            sum.data[k][1] = a.data[i][1];
            sum.data[k][2] = a.data[i][2];
            i++; k++;
        } else if (b.data[j][0] < a.data[i][0] ||
                  (b.data[j][0] == a.data[i][0] && b.data[j][1] < a.data[i][1])) {
            sum.data[k][0] = b.data[j][0];
            sum.data[k][1] = b.data[j][1];
            sum.data[k][2] = b.data[j][2];
            j++; k++;
        } else {
            int v = a.data[i][2] + b.data[j][2];
            if (v != 0) {
                sum.data[k][0] = a.data[i][0];
                sum.data[k][1] = a.data[i][1];
                sum.data[k][2] = v;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a.size) {
        sum.data[k][0] = a.data[i][0];
        sum.data[k][1] = a.data[i][1];
        sum.data[k][2] = a.data[i][2];
        i++; k++;
    }
    while (j <= b.size) {
        sum.data[k][0] = b.data[j][0];
        sum.data[k][1] = b.data[j][1];
        sum.data[k][2] = b.data[j][2];
        j++; k++;
    }
    sum.data[0][2] = k - 1;
    sum.size = k - 1;
    return sum;
}

int main() {
    int elementsA[4][3] = {{0, 0, 3}, {0, 3, 5}, {1, 1, 7}, {2, 2, 9}};
    int elementsB[4][3] = {{0, 0, 2}, {0, 3, 4}, {1, 1, 6}, {2, 2, 8}};

    SparseMatrix A, B, C;
    createSparse(A, 3, 4, elementsA, 4);
    createSparse(B, 3, 4, elementsB, 4);

    cout << "Matrix A:\n"; display(A);
    cout << "\nMatrix B:\n"; display(B);

    cout << "\nA + B:\n";
    C = add(A, B);
    display(C);

    return 0;
}