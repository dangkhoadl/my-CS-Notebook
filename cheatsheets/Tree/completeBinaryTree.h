

/*------------ Complete binary tree index ---------------- */

/*---- start with Node 0 -----*/
int parent(int i) {
    return (i-1) / 2;
}
int leftChild(int i) {  // Odd
    return (2*i + 1);
}
int rightChild(int i) { // Even
    return (2*i + 2);
}

/*---- start with Node 1 -----*/
int parent(int i) {
    return i/2;
}
int leftChild(int i) { // Even
    return 2*i;
}
int rightChild(int i) { // Odd
    return 2*i + 1;
}
