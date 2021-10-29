// Time Complexity: O(m^2 n)

/*
    [1 1] [x1] = [3]
    [2 3] [x2]   [7]

    GaussianElimination({
        {1.0, 1.0},
        {2.0, 3.0}},
            {3.0, 7.0});
    = [2 1]
*/
pair<int, vector<double>> solve_gaussian_elimination(
        const vector<vector<double>> &A,
        const vector<double> &b,
        double EPS=(double)1e-9) {
    // Solve Ax = b
    // returns (ans, x)
    //      ans: the number of solutions of the system ( 0,1, or INF(2) )
    //      x: solution if unique
    int n = (int) A.size();
    assert(n > 0 && n == b.size());
    int m = A[0].size();

    // Concat U = (A,b)
    vector<vector<double>> U(A);
    for(int i=0; i<n; ++i) U[i].push_back(b[i]);

    // Init where: Identicate col swapped
    vector<int> where(m, -1);

    for (int col=0, row=0; col<m && row<n; ++col) {
        // Select row idx that U[idx][col] max
        int idx = row;
        for (int i=row; i<n; ++i) {
            if(abs(U[i][col]) > abs(U[idx][col])) {
                idx = i;
            }
        }

        if (abs(U[idx][col]) < EPS) continue;

        // Swap row: idx <-> row
        where[col] = row;
        for(int j=col; j<=m; ++j) {
            swap(U[idx][j], U[row][j]);
        }

        // Gaussian eliminate
        for (int i=0; i<n; ++i) {
            if (i != row) {
                double c = U[i][col] / U[row][col];
                for (int j=col; j<=m; ++j) {
                    U[i][j] -= U[row][j] * c;
                }
            }
        }

        // Next row
        row += 1;
    }

    // Init x
    vector<double> x(m, 0.0);

    // Solve equation Ux=b for an upper triangular matrix U
    for(int j=0; j<m; ++j) {
        if (where[j] != -1) {
            x[j] = U[where[j]][m] / U[where[j]][j];
        }
    }
    for(int i=0; i<n; ++i) {
        double sum = 0;
        for(int j=0; j<m; ++j) {
            sum += x[j] * U[i][j];
        }

        // No solutions
        if(abs(sum - U[i][m]) > EPS) return {0, vector<double>()};
    }

    // inf solutions
    for (int j=0; j<m; ++j) {
        if(where[j] == -1) return {2, vector<double>()};
    }

    // 1 solution
    return {1, x};
}
