
int randint(int a, int b) {
	return a + (1.0*(b - a)*rand()) / (1.0 + RAND_MAX);
}
int n, st;
bool flag;
vector<int> options;
void nimGame2() {
	cout << "Rules: A heap contain n amount of sticks, you can choose n\n";
	cout << "Each turn Player or machine can choose to remove x sticks (which x is smaller and k divisible)\n";
	cout << "Example: if there is 6 sticks left: You can choose to remove 1,2 or 3 sticks\n";
	cout << "Who remove the last stick ===== Loser\n";
	cout << "Let's play - Enter number of sticks: ";
	do {
		cin >> n;
		if (n < 4)
			cout << "Enter a bigger n: ";
	} while(n < 4);

	while(true) {
		cout << endl << "Sticks left: " << n << endl;
		
		cout << "You can remove: 1 ";
		for (int i = 2; i <= n / 2; ++i)
			if(n % i == 0)
				cout << i << ' ';
		cout << "sticks: ";
		do {
			cin >> st;
			if(n % st != 0) {
				cout << "You can only remove: 1 ";
				for (int i = 2; i <= n / 2; ++i)
					if(n % i == 0)
						cout << i << ' ';
				cout << "sticks: ";
			} 
		} while (n % st != 0);

		cout << "Player removes " << st << " sticks" << endl;
		n -= st;
		if(n == 0) {
			cout << "Machine wins !!!!!!!" << endl;
			break;
		}

		//Machine strat
		flag = false;
		options.resize(1,1);
		cout << endl << "Sticks left: " << n << endl;
		cout << "Machine can remove: 1 ";
		for (int i = 2; i <= n / 2; ++i)
			if(n % i == 0) {
				options.push_back(i);
				cout << i << ' ';
			}
		cout << "sticks" << endl;

		for (int i = options.size()-1; i >= 0; --i) {
			if((n-options[i]) % 2 != 0) {
				n -= options[i];
				flag = true;
				cout << "Machine removes " << options[i] << " sticks" << endl;
				break;
			}
		}
		if(!flag) {
			int i = randint(0,options.size());
			n -= options[i];
			cout << "Machine removes " << options[i] << " sticks" << endl;
		}
		
		if(n == 0) {
			cout << "Player wins !!!!!!!" << endl;
			break;
		}
	}
}
