

// Check if sqrt(n) is an integer
// Ex   isPerfectSquare(16) = 1, isPerfectSquare(81) = 1
//      isPerfectSquare(15) = 0, isPerfectSquare(6) = 0
int isPerfectSquare(int n) {
    int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
        return 0;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8) {
        int t = (int) floor( sqrt((double) n) + 0.5 );
        return t*t == n;
    }
    return 0;
}
