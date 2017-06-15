

/*----------------------------------- MAX HEAP -----------------------------------------------------------------*/
struct MaxHeap {
public:
	std::vector<int> H;
	int size;
public:
	MaxHeap() : H(), size(0) {}
	MaxHeap(std::vector<int> A) : H(A), size(A.size()) {}
	int parent(int i) {
		return (i + 1) / 2 - 1;
	}
	int leftChild(int i) {
		return (2 * (i + 1) - 1);
	}
	int rightChild(int i) {
		return (2 * (i + 1));
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

/*----------------------------------- MIN HEAP -----------------------------------------------------------------*/
struct MinHeap {
public:
	std::vector<std::pair<int, int>> H;
	int size;
public:
	MinHeap() : H(), size(0) {}
	int parent(int i) {
		return (i + 1) / 2 - 1;
	}
	int leftChild(int i) {
		return (2 * (i + 1) - 1);
	}
	int rightChild(int i) {
		return (2 * (i + 1));
	}
	void siftUp(int i) {
		while (i > 0 && H[parent(i)] > H[i]) {
			std::swap(H[parent(i)], H[i]);
			i = parent(i);
		}
	}
	void siftDown(int i) {
		int minIndex = i;

		int l = leftChild(i);
		if (l < size && H[l] < H[minIndex])
			minIndex = l;

		int r = rightChild(i);
		if (r < size && H[r] < H[minIndex])
			minIndex = r;

		if (minIndex != i) {
			std::swap(H[i], H[minIndex]);
			siftDown(minIndex);
		}
	}
	int getMin() {
		return H[0].second;
	}
	void insert(std::pair<int, int> p) {
		H.push_back(p);
		siftUp(H.size() - 1);
		++size;
	}
	int extractMin() {
		int result = H[0].second;
		H[0] = H.back();
		H.pop_back();
		--size;

		siftDown(0);
		return result;
	}
	void remove(int i) {
		H[i].first = INT_MIN;
		siftUp(i);
		extractMin();
	}
	bool empty() {
		if (size == 0)
			return true;
		return false;
	}
	struct CompareSecond {
		CompareSecond(int val) : val_(val) {}
		bool operator()(const std::pair<int, int>& e) const {
			return val_ == e.second;
		}
	private:
		int val_;
	};
	void changePriority(std::pair<int, int> p) {
		auto it = std::find_if(H.begin(), H.end(), CompareSecond(p.second));

		if (it != H.end()) {
			int i = it - H.begin();
			int old_p = H[i].first;
			H[i].first = p.first;
			if (p.first < old_p)
				siftUp(i);
			else
				siftDown(i);
		}
	}
};

/*----------------------------------- MIN HEAP STL-----------------------------------------------------------------*/
struct MinHeap {
public:
	std::vector<std::pair<int, int>> H_;
public:
	void makeHeap() {
		std::make_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
	}
	void insert(std::pair<int, int>  p) {
		H_.push_back(p);
		std::push_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
	}
	bool empty() {
		if (H_.size() == 0)
			return true;
		return false;
	}
	int getMin() {
		return H_.front().second;
	}
	int extractMin() {
		int min = H_.front().second;
		std::pop_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
		H_.pop_back();
		return min;
	}
	struct CompareSecond {
		CompareSecond(int val) : val_(val) {}
		bool operator()(const std::pair<int, int>& element) const {
			return val_ == element.second;
		}
	private:
		int val_;
	};
	bool exist(int z) {
		auto it = std::find_if(H_.begin(), H_.end(), CompareSecond(z));
		if (it != H_.end())
			return true;
		return false;
	}
	void changePriority(std::pair<int, int> p) {
		auto it = std::find_if(H_.begin(), H_.end(), CompareSecond(p.second));
		if (it != H_.end()) {
			it->first = p.first;
			std::make_heap(H_.begin(), H_.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {return a.first > b.first; });
		}
	}
};
