// arithmetic progression: Cap so cong
//[a,b], n:number of elements -> sum = n(a+b)/2
//Ex: 3,7,11,15 -> a = 3, b = 15, n = 4
// -> sum = 4*(3+15)/2 = 36
//Ex: 1,2,3,4,5,6 
//	-> sum = 6*(1+6) / 2 = 21
int arithmeticProgression(int a, int b, int n) {
	return n * (a + b) / 2;
}

// geometric progression: Cap so nhan
//[a,b], q: ratio -> sum = (bq-a) / (q-1)
//Ex: 3,6,12,24 -> a = 3, b = 24, q = 2
// -> sum = (24*2 - 3) / (2-1) = 45
int geometricProgression(int a, int b, int q) {
	return (b*q - a) / (q - 1);
}
