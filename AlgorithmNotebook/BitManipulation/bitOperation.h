
#define isOn(x, k) (x & (1 << k))       //To check if the k-th item of the set is on. 
#define setBit(x, k) (x |= (1 << k))    //To set/turn on the k-th item (0-based indexing) of the set.
#define clearBit(x, k) (x &= ~(1 << k)) //To clear/turn off the k-th item of the set.
#define toggleBit(x, k) (x ^= (1 << k)) //To toggle (ﬂip the status of) the k-th item of the set.
#define lowBit(x) (x & (-x))            //To get the value of the least signiﬁcant bit that is on (ﬁrst from the right).
#define setAll(x, n) (x = (1 << n) - 1) //To turn on all bits in a set of size n.

#define powerOf2(k) (1<<k) 				// 2^k or total number of subset of k-element set
#define modulo(x, N) ((x) & (N - 1))
#define isPowerOfTwo(x) (!(x & (x - 1)))
#define nearestPowerOfTwo(x) ((int)pow(2.0, (int)((log((double)x) / log(2.0)) + 0.5)))
#define turnOffLastBit(x) ((x) & (x - 1))
#define turnOnLastZero(x) ((x) | (x + 1))
#define turnOffLastConsecutiveBits(x) ((x) & (x + 1))
#define turnOnLastConsecutiveZeroes(x) ((x) | (x - 1))

//int
__builtin_clz(x) : the number of zeros at the beginning of the number
__builtin_ctz(x) : the number of zeros at the end of the number
__builtin_popcount(x) : the number of ones in the number
__builtin_parity(x) : the parity(even or odd) of the number of ones

// long long
__builtin_clzll(x) : the number of zeros at the beginning of the number
__builtin_ctzll(x) : the number of zeros at the end of the number
__builtin_popcountll(x) : the number of ones in the number
__builtin_parityll(x) : the parity(even or odd) of the number of ones
