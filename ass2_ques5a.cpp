#include <iostream>
using namespace std;

class Diagonal {
    int *A;   // store diagonal elements
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for(int i=0;i<n;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i==j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i==j) return A[i-1];
        return 0;
    }
    void display() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i==j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
    ~Diagonal() { delete []A; }
};