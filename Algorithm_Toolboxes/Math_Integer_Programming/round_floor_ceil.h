

// round(m/n): Consider m,n < 0
int round_(const int m, const int n) {
    return ((m < 0) ^ (n < 0)) ? ((m - n/2)/n) : ((m + n/2)/n);
}


/*----
Notes:
    m >= 0 && n > 0
-----*/

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


/*----
Notes:
    if consider m<0 || n<0:
-----*/

// floor(m/n)
int floor_all(int m, int n) {
    int ans = 0;
    if(x<0 && y>0)
        ans = -ceil_(-x,y);
    else if(x>0 && y<0)
        ans = -ceil_(x,-y);
    else if(x<0 && y<0)
        ans = floor_(-x,-y);
    else
        ans = floor_(x,y);
    return ans;
}

// ceil(m/n)
int ceil_all(int m, int n) {
    int ans = 0;
    if(x<0 && y>0)
        ans = -floor_(-x,y);
    else if(x>0 && y<0)
        ans = -floor_(x,-y);
    else if(x<0 && y<0)
        ans = ceil_(-x,-y);
    else
        ans = ceil_(x,y);
    return ans;
}
