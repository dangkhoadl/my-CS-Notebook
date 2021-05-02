// Set : s = {0,1,2}
//        All subsets (2^n):     {}, {0}, {1}, {2}, {0,1}, {0,2}, {1,2}, {0,1,2}
//        C(n,2):                {1,2}, {0,2}, {0,1}
//        All permu (n!):        {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
//        P(n,2):                {1,2}, {2,1}, {0,2}, {2,0}, {0,1}, {1,0}


/*-------------------------- O(2^n) ------------------*/
// n -> 2^n
// {1,2,5} -> {}, {1}, {2}, {1,2}, {5}, {1,5}, {2,5}, {1,2,5}
vector<vector<int>> get_all_subset(const vector<int> &myset) {
    vector<vector<int>> subsets;
    vector<int> empty;
    subsets.push_back(empty);

    for(int i=0; i < myset.size(); ++i) {
        vector<vector<int>> subsetTemp = subsets;

        for(int j=0; j < subsetTemp.size(); ++j)
            subsetTemp[j].push_back( myset[i] );

        for(int j=0; j < subsetTemp.size(); ++j)
            subsets.push_back( subsetTemp[j] );
    }
    return subsets;
}


/*-------------------------- O(2^n) -----------------------*/
// n -> nCk
// {5,4,2}, k=2 --> {5,4}, {5,2}, {4,2}
vector<vector<int>> get_all_combination(const vector<int> &myset, int k) {
    vector<vector<int>> subsets;
    vector<int> empty;
    subsets.push_back(empty);

    for(int i=0; i < myset.size(); ++i) {
        vector<vector<int>> subsetTemp = subsets;

        for(int j=0; j < subsetTemp.size(); ++j) 
            subsetTemp[j].push_back( myset[i] );

        for(int j=0; j < subsetTemp.size(); ++j)
            subsets.push_back( subsetTemp[j] );
    }

    vector<vector<int>> combinations;
    for(int i=0; i<subsets.size(); ++i)
        if(subsets[i].size() == k)
            combinations.push_back(subsets[i]);

    return combinations;
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
