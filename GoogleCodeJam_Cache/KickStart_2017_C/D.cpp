
// https://codejam.withgoogle.com/codejam/contest/4344486/dashboard#s=p3

int Min, Max, Mean, Median;
ll readInput() {
    sii(Min,Max); sii(Mean, Median);
    return 0;
}


bool checkOdd(int n) {
    int X = n*Mean - Min - Max - Median;
    int a = (n-3)/2 * (Min + Median);
    int b = (n-3)/2 * (Median + Max);
    if(a <= X && X <= b)
        return true;
    return false;
}
bool checkEven(int n) {
    int X = n*Mean - Min - Max - 2*Median;
    int a = (n-4)/2 * (Min + Median);
    int b = (n-4)/2 * (Median + Max);
    if(a <= X && X <= b)
        return true;
    return false;
}
set<int> checkOne;
int sol() {
    //Case: impossible
    if(Max < Min || Median < Min || Median > Max || Mean < Min || Mean > Max)
        return -1;
    //Check 1
    if(Min == Max) {
        checkOne.clear();
        checkOne.insert(Min);
        checkOne.insert(Max);
        checkOne.insert(Median);
        checkOne.insert(Mean);
        if(sz(checkOne) == 1)
            return 1;
        return -1;
    }
    //Check 2
    if(Min + Max == 2*Median && Min + Max == 2*Mean)
        return 2;
    FOR(n,3,200000+1) {
        if(n & 1) {
            if(checkOdd(n))
                return n;
        }
        else {
            if(checkEven(n))
                return n;
        }
    }
    return -1;
}


ll solve() {
    return sol();
}
