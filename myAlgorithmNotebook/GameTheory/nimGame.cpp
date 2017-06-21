
int randint(int a, int b) {
	return a + (1.0*(b - a)*rand()) / (1.0 + RAND_MAX);
}
int n, st;
bool flag; 
void nimGame() {
	cout << "Rules: A heap contain n amount of sticks, you can choose n\n";
	cout << "Each turn Player or machine can choose to remove 1 - 3 sticks\n";
	cout << "Who remove the last stick ===== WINNNER\n";
	cout << "Let's play - Enter number of sticks: ";
	do {
		cin >> n;
		if (n < 4)
			cout << "Enter a bigger n: ";
	} while(n < 4);

	while(true) {
		cout << "Sticks left: " << n << endl;
		cout << "Removes 1-3 sticks: ";
		do{
			cin >> st;
			if(st < 1 || st > 3)
				cout << "You can only remove 1-3 sticks: ";
		} while(st < 1 || st > 3);

		cout << "Player removes " << st << " sticks" << endl;
		n -= st;
		if(n == 0) {
			cout << "Player wins !!!!!!!" << endl;
			break;
		}

		//Machine strat
		flag = false;
		for (int i = 1; i <= 3; ++i) {
			if((n - i) % 4 == 0) {
				n -= i;
				cout << "Machine removes " << st << " sticks" << endl;
				flag = true;
				break;
			}
		}
		if(!flag) {
			int i = randint(1,4);
			n -= i;
			cout << "Machine removes " << i << " sticks" << endl;
		}

		if(n == 0) {
			cout << "Machine wins !!!!!!!" << endl;
			break;
		}
	} 
}
