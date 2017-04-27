
#define isOn(S, k) (S & (1 << k))       //To check if the k-th item of the set is on. 
#define setBit(S, k) (S |= (1 << k))    //To set/turn on the k-th item (0-based indexing) of the set.
#define clearBit(S, k) (S &= ~(1 << k)) //To clear/turn oﬀ the k-th item of the set.
#define toggleBit(S, k) (S ^= (1 << k)) //To toggle (ﬂip the status of) the k-th item of the set.
#define lowBit(S) (S & (-S))            //To get the value of the least signiﬁcant bit that is on (ﬁrst from the right).
#define setAll(S, n) (S = (1 << n) - 1) //To turn on all bits in a set of size n.

#define modulo(S, N) ((S) & (N - 1))
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
