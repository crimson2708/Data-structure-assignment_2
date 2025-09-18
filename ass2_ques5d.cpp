class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n=n;
        A = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i<=j) A[(i-1)*n - (i-1)*(i-2)/2 + (j-i)] = x;
    }
    int get(int i, int j) {
        if (i<=j) return A[(i-1)*n - (i-1)*(i-2)/2 + (j-i)];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
    ~UpperTriangular(){ delete []A; }
};