
/***************************************************** GCD ***********************************/
// gcd(8,12) = 4
//   8 = 2*2*2
//   12 = 2*2*3
//      => gcd(8,12) = 2*2 = 4

// Recursive GCD
int gcd(int a, int b) {
    assert(a >= 0 and b >= 0 and a + b > 0);
    if (b == 0)  return a;
    return gcd(b, a%b);
}

// Non recursive GCD
int gcd(int a, int b) {
    assert(a >= 0 and b >= 0 and a + b > 0);

    while(a>0 and b>0) {
        if(a >= b) a %= b;
        else b %= a; 
    }
    return max(a,b);
}


/***************************************************** LCM ***********************************/
// lcm(12,18) = 36
//    12 = 2*2*3
//    18 = 2*3*3
//       => lcm(12,18) = 2*2*3*3 = 36

int lcm(int a, int b) {
    assert(a > 0 and b > 0);
    return b*a / gcd(a, b);
}


/***************************************************** Extended GCD ***********************************/
// Extended GCD: return [d,x,y]
//      d = gcd(a,b)
//      x,y: d = ax + by
//          Note: a > b
vector<int> extendedGCD(int a, int b) {
    assert(a >= b and b >= 0 and a + b > 0);

    if(b == 0)
        return {a,1,0};

    vector<int> dpq = extendedGCD(b, a%b);
    int x = dpq[2];
    int y = dpq[1] - dpq[2] * (a/b);

    assert(a % dpq[0] == 0 and b % dpq[0] == 0);
    assert(dpq[0] == a * x + b * y);
    return {dpq[0],x,y};
}
