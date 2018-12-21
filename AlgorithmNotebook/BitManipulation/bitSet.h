

/* Maximum elements is 31 (0-30) 
        Note: Use C++ biset if > 30 elements
*/


// set x - element k in x:
//      All subsets of a n-element set {0,1,...,n-1}            [0 : 2^n-1]     [0 : (1<<n)-1]
//      Init set empty:                                         x = 0
//      Init set full:                                          x = -1
//      Add element k to set:                                   x |= (1 << k)
//      Remove element k out of set:                            x &= ~(1 << k)
//      (bool) Check if k is in set:                            x & (1 << k)
//      return x size                                           __builtin_popcount(x)

// Set Operations set z, set x, set y:
//      Union:                                              z = x | y
//      Intersection:                                       z = x & y
//      Complement:                                         y = ~x
//      Diference (x\y):                                    z = x & (~y)
vector<int> bitSetToSet(int x) {
    vector<int> res;
    int k = 0;
    for(int i = 1; i <= x; i <<= 1, ++k) {
        if(x & i)
            res.push_back(k);
    }
    return res;
}

// Builtin function:
//      __builtin_clz(x) : the number of zeros at the beginning of the number
//      __builtin_ctz(x) : the number of zeros at the end of the number
//      __builtin_popcount(x) : the number of ones in the number
//      __builtin_parity(x) : the parity(even or odd) of the number of ones
uint32_t popcount(uint32_t i) {
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}



#define isOn(x, k) (x & (1 << k))       //To check if the k-th item of the set is on. 
#define setBit(x, k) (x |= (1 << k))    //To set/turn on the k-th item (0-based indexing) of the set.
#define clearBit(x, k) (x &= ~(1 << k)) //To clear/turn off the k-th item of the set.
#define toggleBit(x, k) (x ^= (1 << k)) //To toggle (ﬂip the status of) the k-th item of the set.
#define lowBit(x) (x & (-x))            //To get the value of the least signiﬁcant bit that is on (ﬁrst from the right).
#define setAll(x, n) (x = (1 << n) - 1) //To turn on all bits in a set of size n.

#define isOdd(x) (x & 1)
#define isEven(x) !(x & 1)
#define powerOf2(k) (1<<k)              // 2^k or total number of subset of k-element set
#define isPowerOfTwo(x) (!(x & (x - 1)))
#define nearestPowerOfTwo(x) ((int)pow(2.0, (int)((log((double)x) / log(2.0)) + 0.5)))
#define turnOffLastBit(x) ((x) & (x - 1))
#define turnOnLastZero(x) ((x) | (x + 1))
#define turnOffLastConsecutiveBits(x) ((x) & (x + 1))
#define turnOnLastConsecutiveZeroes(x) ((x) | (x - 1))

void printBin(int x) {
    cerr << x << " = " << bitset<32>(x).to_string() << endl;
}
