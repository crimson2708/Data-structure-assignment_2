
class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n=n;
        A = new int[3*n-2]; // store 3 diagonals
        for(int i=0;i<3*n-2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i-j==0) A[i-1] = x;                // main diagonal
        else if (i-j==1) A[n+i-2] = x;         // lower diagonal
        else if (i-j==-1) A[2*n+i-2] = x;      // upper diagonal
    }
    int get(int i, int j) {
        if (i-j==0) return A[i-1];
        else if (i-j==1) return A[n+i-2];
        else if (i-j==-1) return A[2*n+i-2];
        else return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    ~TriDiagonal(){ delete []A; }
};