// Set : s = {0,1,2}
//        All subsets (2^n):     {}, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
//        C(n,2):                {1,2}, {0,2}, {0,1}
//        All permu (n!):        {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//        P(n,2):                {1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}


/*-------------------------- O(2^n) ------------------*/
// n -> 2^n
// {1,2,5} -> {}, {1}, {2}, {1,2}, {5}, {1,5}, {2,5}, {1,2,5}
vector<int> subset;
void iterate_subsets(int idx, const vector<int> &A) {
    if(idx == A.size()) {
        // Process subset
        
        return;
    }

    // Add A[i]
    subset.push_back(A[idx]);
    iterate_subsets(idx+1, A);
    subset.pop_back();

    // Not add A[i]
    iterate_subsets(idx+1, A);
}


/*-------------------------- O(2^n) -----------------------*/
// n -> nCk
// {5,4,2}, k=2 --> {5,4}, {5,2}, {4,2}
vector<int> combination;
void iterate_combinations(int idx, const vector<int> &A, int k) {
    if(combination.size() == k) {
        // Process combination

        return;
    }
    if(idx == A.size()) return;

    // Add A[i]
    combination.push_back(A[idx]);
    iterate_combinations(idx+1, A, k);
    combination.pop_back();

    // Not add A[i]
    iterate_combinations(idx+1, A, k);
}


/*---------------------------------------------------------*/
// {2,3,5} -> {2,3,5}, {2,5,3}, {3,2,5}, {3,5,2}, {5,2,3}, {5,3,2}
vector<vector<int>> get_all_permutation(const vector<int> &myset) {
    vector<vector<int>> permutations;
    vector<int> p(myset);
    do {
        // each permu stored in p
        permutations.push_back(p);
    } while(next_permutation(p.begin(), p.end()));

    return permutations;
}
