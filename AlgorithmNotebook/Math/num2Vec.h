
// convert n --> vector<int>

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
