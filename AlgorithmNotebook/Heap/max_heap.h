

/*----------------------------------- MAX HEAP -----------------------------------------------------------------*/
struct MaxHeap {
public:
    std::vector<int> H;
    int size;
public:
    MaxHeap() : H(), size(0) {}
    MaxHeap(std::vector<int> A) : H(A), size(A.size()) {}
    int parent(int i) {
        return floor((double)(i-1) / 2);
    }
    int leftChild(int i) {
        return (2*i + 1);
    }
    int rightChild(int i) {
        return (2*i + 2);
    }
    void siftUp(int i) {
        while (i > 0 && H[parent(i)] < H[i]) {
            std::swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }
    void siftDown(int i) {
        int maxIndex = i;

        int l = leftChild(i);
        if (l < size && H[l] > H[maxIndex])
            maxIndex = l;

        int r = rightChild(i);
        if (r < size && H[r] > H[maxIndex])
            maxIndex = r;

        if (maxIndex != i) {
            std::swap(H[i], H[maxIndex]);
            siftDown(maxIndex);
        }
    }
    int getMax() {
        return H[0];
    }
    void insert(int p) {
        H.push_back(p);
        siftUp(H.size() - 1);
        ++size;
    }
    int extractMax() {
        int result = H[0];
        H[0] = H.back();
        H.pop_back();
        --size;
        siftDown(0);
        return result;
    }
    void remove(int i, std::vector<int> &H) {
        H[i] = INT_MAX;
        siftUp(i);
        extractMax();
    }
    void changePriority(int i, int p, std::vector<int> &H) {
        int old_p = H[i];
        H[i] = p;
        if (p > old_p)
            siftUp(i);
        else
            siftDown(i);
    }
    void buildHeap() {
        for (int i = size / 2; i >= 0; --i) {
            siftDown(i);
        }
    }
    void inplaceHeapSort() {
        buildHeap();
        while (--size) {
            std::swap(H[0], H[size]);
            siftDown(0);
        }
        size = H.size();
    }
};
