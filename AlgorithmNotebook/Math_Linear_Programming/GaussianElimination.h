

/*
    [1 1] [x1] = [3]
    [2 3] [x2]   [7]

    GaussianElimination({
        {1.0, 1.0},
        {2.0, 3.0}}, 
            {3.0, 7.0});
    = [2 1]
*/

vector<double> GaussianElimination(const vector<vector<double>> &M, const vector<double> &y) {
    assert(M.size() == M[0].size());
    assert(M.size() == y.size());

    // matrix rank
    int n = y.size();
    if(n == 0)
        return vector<double>();

    // Make Single matrix
    vector<vector<double>> A(M);
    for(int r=0; r<n; ++r)
        A[r].push_back(y[r]);

    for(int r=0; r<n; ++r) { 
        // Search for maximum in column
        double maxEl = abs(A[r][r]);
        int maxRow = r;
        for(int r_=r+1; r_<n; ++r_) { 
            if (abs(A[r_][r]) > maxEl) {
                maxEl = abs(A[r_][r]);
                maxRow = r_;
            }
        }

        // Swap maximum row with current row (column by column)
        for(int c=r; c<n+1; ++c) {
            double tmp = A[maxRow][c];
            A[maxRow][c] = A[r][c];
            A[r][c] = tmp;
        }

        // Make all rows below this one 0 in current column
        for(int r_=r+1; r_<n; ++r_) { 
            double c = -A[r_][r]/A[r][r];
            for(int j=r; j<n+1; ++j) { 
                if (r==j)
                    A[r_][j] = 0;
                else
                    A[r_][j] += c * A[r][j];
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n, 0);
    for (int r=n-1; r>-1; --r) { 
        x[r] = A[r][n] / A[r][r];
        for(int r_=r-1; r_>-1; --r_)
            A[r_][n] -= A[r_][r] * x[r];
    }

    return x;
}
