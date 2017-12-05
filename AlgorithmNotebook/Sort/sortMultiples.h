
// Sort multiple vectors

int randInt(int a, int b) {
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}
int partition(vector<int> &a, vector<int> &b, int left, int right) { // Add vectors
    int p = randInt(left, right+1);

    // Swap
    swap(a[left], a[p]);
    swap(b[left], b[p]);

    int pivot = a[left];

    int i = left + 1;
    int j = left + 1;
    for( ; i <= right; ++i) {
        if(a[i] <= pivot) {         // Conditions
            // Swap
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            ++j;
        }
    }

    --j;
    // Swap
    swap(a[left], a[j]);
    swap(b[left], b[j]);
    return j;
}
void quicksort(vector<int> &a, vector<int> &b, int left, int right) { // Add vectors
    stack<int> S;
    S.push(left);
    S.push(right);

    while(!S.empty()) {
        // Pop h and l
        right = S.top(); S.pop();
        left = S.top(); S.pop();
 
        int p = partition(a,b,left,right);      // Add vectors

        if(p-1 > left) {
            S.push(left);
            S.push(p-1);
        }
 
        if (p+1 < right) {
            S.push(p+1);
            S.push(right);
        }
    }
}
