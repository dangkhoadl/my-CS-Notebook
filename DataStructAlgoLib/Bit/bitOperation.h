
#define isOn(S, j) (S & (1 << j))       //To check if the j-th item of the set is on. 
#define setBit(S, j) (S |= (1 << j))    //To set/turn on the j-th item (0-based indexing) of the set.
#define clearBit(S, j) (S &= ~(1 << j)) //To clear/turn oﬀ the j-th item of the set.
#define toggleBit(S, j) (S ^= (1 << j)) //To toggle (ﬂip the status of) the j-th item of the set.
#define lowBit(S) (S & (-S))            //To get the value of the least signiﬁcant bit that is on (ﬁrst from the right).
#define setAll(S, n) (S = (1 << n) - 1) //To turn on all bits in a set of size n.

#define modulo(S, N) ((S) & (N - 1))
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
