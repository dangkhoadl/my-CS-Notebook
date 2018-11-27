

// m = # inequalities, n = #variables
// F = objective function (max)
// C[0..m-1] = constraints equations:
//    sum( C[i][j] * X[j] ) <= C[i][n]
// Return: 
//    -INF if infeasible(No solution)
//     INF if unbounded
//     return f_max otherwise
class Simplex {
private:
    int m, n;
    vector<vector<double>> C;
    vector<double> F;

    vector<vector<double>> A;
    vector<double> X;
    vector<int> basis;
    vector<int> out;
    const double EPSS = 1e-9;
    const double INF = 1.0/0.0;
private:
    void pivot(int a, int b) { 
        int i,j;
        for(i=0; i<=m; ++i) 
            if(i != a) 
                for(j=0; j<=n; ++j)
                    if (j != b) 
                        A[i][j] -= A[a][j] * A[i][b] / A[a][b];

        for(j=0; j<=n; ++j) 
            if(j != b) 
                A[a][j] /= A[a][b];

        for(i=0; i<=m; ++i)
            if(i != a) 
                A[i][b] = -A[i][b]/A[a][b]; 

        A[a][b] = 1.0/A[a][b];
        swap(basis[a], out[b]);
    }
public:
    Simplex(
        const vector<vector<double>> &C,
        const vector<double> F): 
            C(C), F(F) {
        this->m = this->C.size();
        this->n = this->C[0].size()-1;

        this->A.assign(this->m+1, vector<double>(this->n+1, 0.0));
        this->X.assign(this->n, 0.0);
        this->basis.assign(this->m+1, 0);
        this->out.assign(this->n+1, 0);
    }
    double maxOptimize() { 
        // i,ii are row indexes; j,jj are column indexes
        int i,ii,j,jj; 
        for(i=1; i<=m; ++i) 
            for(j=0; j<=n; ++j) 
                A[i][j] = C[i-1][j];

        for(j=0; j<=n-1; ++j) 
            A[0][j] = -F[j];

        for(i=0; i<=m; ++i)
            basis[i] = -i;

        for(j=0; j<=n; ++j) 
            out[j] = j;

        while(true) {
            for(i=ii=1; i<=m; ++i) 
                if(A[i][n]<A[ii][n] || (A[i][n]==A[ii][n] && basis[i] < basis[ii])) 
                    ii=i;

            if(A[ii][n] >= -EPSS) 
                break;

            for(j=jj=0; j<n; ++j)
                if(A[ii][j] < A[ii][jj]-EPSS || (A[ii][j] < A[ii][jj]-EPSS && out[i] < out[j])) 
                    jj=j;

            if(A[ii][jj] >= -EPSS)
                return -INF;
            pivot(ii,jj); 
        }

        while(true) {
            for(j=jj=0; j<n; ++j) 
                if(A[0][j] < A[0][jj] || (A[0][j] == A[0][jj] && out[j] < out[jj]))
                    jj=j;

            if(A[0][jj] > -EPSS) 
                break;

            for(i=1, ii=0; i<=m; ++i)
                if((A[i][jj] > EPSS) && 
                        (!ii || (A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]-EPSS) ||
                    ((A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj] + EPSS) && (basis[i] < basis[ii]))))
                    ii=i;

            if(A[ii][jj] <= EPSS) 
                return INF; 
            pivot(ii,jj);
        }

        for(j=0; j<n; ++j)
            X[j] = 0.0;
        for(i=1; i<=m; ++i) 
            if(basis[i] >= 0) 
                X[basis[i]] = A[i][n]; 
        return A[0][n]; 
    }
    vector<double> getX() {
        return this->X;
    }
};
