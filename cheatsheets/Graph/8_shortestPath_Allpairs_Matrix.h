

/*      V:          adjacency matrix of Graph G
*       V^n:        minimum length of a path of n edges
*           Eg: G = 6 vertices
*               V = 
*                   inf inf inf 4   inf inf
*                   2   inf inf inf 1   2
*                   inf 4   inf inf inf inf
*                   inf 1   inf inf inf inf
*                   inf inf inf inf inf inf
*                   inf inf 3   inf 2   inf
*
*               V^4 = 
*                   inf inf 10  11  9 inf
*                   9   inf inf inf 8 9
*                   inf 11  inf inf inf inf
*                   inf 8   inf inf inf inf
*                   inf inf inf inf inf inf
*                   inf inf 12  13  11   inf
*
*               minimum length of a path of 4 edges from node 2 to
*               node 5 = V^4[2][5] = 8. Eg:  2 → 1 → 4 → 2 → 5
*/


// const long long inf = 9187201950435737471;
// O(n^3)
vector<vector<int>> matrixMul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    assert(A.size() > 0 and B.size() > 0 and A[0].size() == B.size());
    vector<vector<int>> C(A.size(), vector<int>(B[0].size(), inf));
    for(int i=0; i<A.size(); ++i)
        for(int k=0; k<B.size(); ++k)
            for(int j=0; j<B[0].size();++j) {
                if(A[i][k] >= inf || B[k][j] >= inf)
                    C[i][j] = min(C[i][j], inf);
                else {
                    C[i][j] = min(C[i][j], A[i][k] + B[k][j]); 
                }
            }
    return C;
}

// O(n^3 * log(k))
vector<vector<int>> matrixPow(const vector<vector<int>> &A, int k) {
    assert(A.size() > 0 and A.size() == A[0].size() and k > 0);
    if(k == 1) 
        return A;

    vector<vector<int>> C = matrixPow(A, k/2);
    C = matrixMul(C, C);
    if(k & 1)
        return matrixMul(C,A);
    return C;
}
