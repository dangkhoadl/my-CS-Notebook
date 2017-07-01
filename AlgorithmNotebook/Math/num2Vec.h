
// convert n --> vector<int>

vector<int> numV;
void num2Vec(int num) {
	numV.clear();
	int a = 0;
	while(num) {
		a = num % 10;
		num /= 10;
		numV.pb(a);
	}
	reverse(all(numV));
}
