class LowerTriangular {
    int *A;
    int n;
public:
    LowerTriangular(int n) {
        this->n=n;
        A = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) A[i]=0;
    }
    void set(int i, int j, int x) {
        if (i>=j) A[i*(i-1)/2 + (j-1)] = x;
    }
    int get(int i, int j) {
        if (i>=j) return A[i*(i-1)/2 + (j-1)];
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
    ~LowerTriangular(){ delete []A; }
};