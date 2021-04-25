// Notes: current implementation only for integer lnum >= 0

typedef vector<long long> lnum;
const long long base = 1000*1000*1000;

// string -> lnum
lnum str_2_lnum(const string &s) {
    lnum a;
    for (long long i=(long long)s.length(); i>0; i-=9) {
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    }

    // remove lead 0: 0459595
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

// lnum -> string
string lnum_2_str(const lnum &a) {
    string res = "";
    a.empty() ? res = "0" : res = to_string(a.back());
    for (long long i=(long long)a.size()-2; i>=0; --i)
        res += to_string(a[i]);
    return res;
}

/*---------------------- Ops ----------------------*/

// c = a + b
lnum add_lnum(const lnum &a,const lnum &b) {
    lnum c(a);
    long long carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == c.size())
            c.push_back (0);
        c[i] += carry + (i < b.size() ? b[i] : 0);
        carry = c[i] >= base;
        if (carry)  
            c[i] -= base;
    }
    return c;
}

// c = a - b
lnum sub_lnum(const lnum &a, const lnum &b) {
    lnum c(a);
    long long carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
        c[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = c[i] < 0;
        if (carry)  c[i] += base;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

// c = a * b
lnum mul_lnum(const lnum &a, const lnum &b) {
    lnum c (a.size()+b.size());
    for (size_t i=0; i<a.size(); ++i)
        for (long long j=0, carry=0; j<(long long)b.size() || carry; ++j) {
            long long cur = c[i+j] + a[i] * 1ll * (j < (long long)b.size() ? b[j] : 0) + carry;
            c[i+j] = (long long)(cur % base);
            carry = (long long)(cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

// c = (lnum)a / (int)b, (rem = remainder)
lnum div_lnum(const lnum &a, long long b, long long &rem) {
    lnum c(a);
    rem = 0;
    for (long long i=(long long)c.size()-1; i>=0; --i) {
        long long cur = c[i] + rem * 1ll * base;
        c[i] = (long long)(cur / b);
        rem = (long long)(cur % b);
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}
