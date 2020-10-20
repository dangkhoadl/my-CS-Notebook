
// O(n^3)
vector<vector<int>> matrixMul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    assert(A.size() > 0 and B.size() > 0 and A[0].size() == B.size());
    vector<vector<int>> C(A.size(), vector<int>(B[0].size(), 0));
    for(int i=0; i<A.size(); ++i)
        for(int k=0; k<B.size(); ++k)
            for(int j=0; j<B[0].size();++j) {
                C[i][j] += (A[i][k] * B[k][j]); 
            }
    return C;
}

// O(n^3 * log(k))
vector<vector<int>> matrixPow(const vector<vector<int>> &A, int k) {
    if(k == 0) {
        vector<vector<int>> C(A.size(), vector<int>(A.size(), 0));
        for(int i=0; i < A.size(); ++i) C[i][i] = 1;
        return C;
    }
    if(k == 1) return A;
    
    vector<vector<int>> C = matrixPow(A, k/2);
    C = matrixMul(C, C);
    if(k%2 == 1) return matrixMul(C,A);
    return C;
}
