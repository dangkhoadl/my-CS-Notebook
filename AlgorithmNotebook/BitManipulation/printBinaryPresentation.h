
void printBin(int x, int display) {
	for (int i = display-1; i >= 0; --i) {
		if (x&(1 << i))
			cout << '1';
		else
			cout << '0';
	}
	cout << endl;
}

void printBin(int x) {
	cout << bitset<32>(x).to_string() << endl;
}
