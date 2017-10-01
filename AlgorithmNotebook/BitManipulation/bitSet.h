

// Basic Operation:
//      All subsets of a n-element set {0,1,...,n-1}            [0 : 2^n-1]     [0 : (1<<n)-1]
//      Init set:                                               x = 0
//      Add element k to set:                                   x |= (1 << k)
//      Remove element k out of set:                            x &= ~(1 << k)
//      (bool) Check if k is in set:                            x & (1 << k)
vector<int> listSetElements(int x) {
    if(x == 1)
        return {0};
    if(x == 2)
        return {1};

    vector<int> res;
    for(int k = 0; k <= x/2; ++k) {
        if(x & (1<<k))
            res.pb(k);
    }
    return res;
}
void printBin(int x) {
    cerr << x << " = " << bitset<32>(x).to_string() << endl;
}

// Set Operations:
//      Union:                                              z = x | y
//      Intersection:                                       z = a | b
//      Complement:                                         y = ~x
//      Diference (x\y):                                    z = x & (~y)

// Builtin function:
//      __builtin_clz(x) : the number of zeros at the beginning of the number
//      __builtin_ctz(x) : the number of zeros at the end of the number
//      __builtin_popcount(x) : the number of ones in the number
//      __builtin_parity(x) : the parity(even or odd) of the number of ones
