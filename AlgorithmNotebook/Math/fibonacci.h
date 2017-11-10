
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long fibo(long long n) {
    if(n <= 1)
        return n;
    if(n == 2)
        return 1;

    int f_1 = 1, f_2 = 0, f = 0;
    for (int i = 2; i <= n; ++i) {
        f = f_1 + f_2;
        f_2 = f_1;
        f_1 = f;
    }
    return f;
}

// F(0) + F(1) + F(2) + ... + F(n) = F(n+2) - 1
