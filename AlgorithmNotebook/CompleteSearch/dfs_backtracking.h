
/*_____________________ multiple Solutions ___________________________*/
dfs(n):
    if found an optimal solution:
        print or add sol to a list

    for val = 1 to all val possible:
        if all constraints == valid:
            add(val)
            dfs(n+1);
            remove(val)

// Example: Print all permu of a string
// Driver:
//     dfs(0);
string s = " ABCD";
void dfs(int x) {
    if(x == sz(s)-1) {
        cout << s << endl;
        return;
    }

    FOR(y,x+1,sz(s)) {
        swap(s[x+1], s[y]);
        dfs(x+1);
        swap(s[x+1], s[y]);
    }
}

/*_____________________ 1 Solution ___________________________*/
bool dfs(n):
    if found an optimal solution:
        return true

    for val = 1 to all val possible:
        if all constraints == valid:
            add(val)
            if dfs(n+1) == true:
                return true
            remove(val)
    return false

// Example: N-Queen
// Driver:
//     ms(a,false); 
//     dfs(1);
bool a[100][100];
int N = 8;
bool isSafe(int r, int c) {
    int r_, c_;
    // Check left
    r_ = r;
    c_ = c;
    while(c_ >= 1) {
        if(a[r_][c_])
            return false;
        --c_;
    } 
    
    // Check diag up-left
    r_ = r;
    c_ = c;
    while(r_ >= 1 && c_ >= 1) {
        if(a[r_][c_])
            return false;
        --r_;
        --c_;
    }
    // Check diag down-left
    r_ = r;
    c_ = c;
    while(r_ <= N && c_ >= 1) {
        if(a[r_][c_])
            return false;
        ++r_;
        --c_;
    }
    return true;
}
bool dfs(int c) {
    if(c == N+1)
        return true;
    FOR(r,1,N+1) {
        if(isSafe(r,c)) {
            a[r][c] = true;
            if(dfs(c+1))
                return true;
            a[r][c] = false; 
        }
    }
    return false;
}
