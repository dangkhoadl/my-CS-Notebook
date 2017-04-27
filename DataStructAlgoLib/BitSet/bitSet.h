// Basic Operation:
//		Init set:						x = 0
//		Add element k to set:			x |= (1 << k)
//		Remove element k out of set:	x &= ~(1 << k)
//		(bool) Check if k is in set:	x & (1 << k)

// Set Operations:
//		Union:							z = x | y
//		Intersection:					z = a | b
//		Complement:						y = ~x
//		Diference:						z = x & (~y)

// Builtin function:
//		__builtin_clz(x) : the number of zeros at the beginning of the number
//		__builtin_ctz(x) : the number of zeros at the end of the number
//		__builtin_popcount(x) : the number of ones in the number
//		__builtin_parity(x) : the parity(even or odd) of the number of ones

void printSet(int set,int maxSize) {
	for (int i = 0; i < maxSize; ++i)
		if (set & (1 << i))
			cout << i << ' ';
	cout << endl;
}
