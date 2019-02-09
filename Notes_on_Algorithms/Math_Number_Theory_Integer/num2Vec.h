

// 1234 -> [1,2,3,4]
vector<int> num2Vec(int num) {
    vector<int> numV;
    int a = 0;
    while(num) {
        a = num % 10;
        num /= 10;
        numV.push_back(a);
    }
    reverse(numV.begin(), numV.end());
    return numV;
}

// 1234 -> [0]4 [1]3 [2]2 [3]1
//      1*10^3 + 2*10^2 + 3*10^1 + 4*10^0 
vector<int> num_to_poly(int num) {
        vector<int> numV;
        int a = 0;
        while(num) {
            a = num % 10;
            num /= 10;
            numV.push_back(a);
        }
        return numV;
    }
int poly_to_num(const vector<int> &poly){
    int num = 0;
    vector<int> powr(poly.size(), 1);
    for(int i=1; i<poly.size(); ++i) {
        powr[i] = powr[i-1]*10;
    }

    for(int i=0; i<poly.size(); ++i) {
        num += (poly[i] * powr[i]);
    }
    return num;
}

