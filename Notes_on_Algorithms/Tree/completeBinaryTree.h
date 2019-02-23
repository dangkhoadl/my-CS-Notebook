

/*------------ Complete binary tree as arrays ---------------- */

// start with Node 0
int parent(int i) {
    return floor((double)(i-1) / 2);
}
int leftChild(int i) {
    return (2*i + 1);
}
int rightChild(int i) {
    return (2*i + 2);
}

// start with Node 1
int parent(int i) {
    return floor((double)i/2);
}
int leftChild(int i) {
    return 2*i;
}
int rightChild(int i) {
    return 2*i + 1;
}
