// Convert s from base b to Decimal (max 16, can be modified)
int toDecimal(const string &s, int b) {
	int multiplier = 1;
	int n = 0;

	for (int i = s.size() - 1; i >= 0; --i, multiplier *= b) {
		if (s[i] > '0' && s[i] < '9') 
			n += (s[i] - '0') * multiplier;
		else if (s[i] >= 'a' && s[i] <= 'f') 
			n += (s[i] - 'a' + 10) * multiplier;
		else if (s[i] >= 'A' && s[i] <= 'F')
			n += (s[i] - 'A' + 10) * multiplier;
	}
	return n;
}

/*------------------------------------------------------------------------------------------------------------*/

// Convert n from Decimal to base b (max 16, can be modified)
string fromDecimal2(int n, int b) {
	string chars = "0123456789ABCDEF";
	string result = "";

	while (n > 0) {
		result = chars[n % b] + result;
		n /= b;
	}

	return result;
}
