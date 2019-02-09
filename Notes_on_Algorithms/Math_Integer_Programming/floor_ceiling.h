

// floor(m/n)
int floor_(int m, int n) {
    assert(n != 0);

    int a = (m-n)/n+1;
    while((m-n) < n*a) --a;
    ++a;

    int b = m/n-1;
    while(n*b <= m) ++b;
    --b;

    if(a == b)
        return a;
    assert(1==0);
}


// ceil(m/n)
int ceil_(int m, int n) {
    assert(n != 0);

    int a = m/n+1;
    while(m <= n*a) --a;
    ++a;

    int b = (m+n)/n-1;
    while(n*b < (m+n)) ++b;
    --b;

    if(a==b)
        return a;
    assert(1==0);
}
