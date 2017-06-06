// Random in range [a, b)
int randint(int a, int b) {
	return a + (1.0*(b-a)*rand()) / (1.0+RAND_MAX);
}

// Random in range [a, b)
int randintNaive(int a, int b) {
	return a + rand() % (b-a);
}
