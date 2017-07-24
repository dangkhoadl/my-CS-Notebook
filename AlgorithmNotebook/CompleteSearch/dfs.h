
// for state that depend on father state. (Usually permu)

void explore(int x, int y) {
    if() {
    	// Stop condition

        return;
    }

    int x_, y_;
    x_ = ;
    y_ = ;
    // operations (pre)
    explore(x_,y_);
    // operations (post)
}
void dfs() {
    explore(0,0);
}



// Example print all permu of a string
string s = " ABCD";
void explore(int x, int y) {
    if(x == sz(s)-1 && y == sz(s)-1) {
        cout << s << endl;
        return;
    }

    int x_;
    x_ = x+1;
    FOR(y_,x+1,sz(s)) {
        swap(s[x_], s[y_]);
        explore(x_,y_);
        swap(s[x_], s[y_]);
    }
}
void dfs() {
    explore(0,0);
}
