// reset time after each compile xD
srand(time(0) + randint(0, 100000000));

// Random in range [a, b)
int randint(int a, int b) {
    return a + (1.0*(b-a)*rand()) / (1.0+RAND_MAX);
}

// Random in range [a, b)
int randintNaive(int a, int b) {
    return a + rand() % (b-a);
}

/*_________________________________ True Random C++ ____________________________________ */
// Random in range [a, b)
int randInt(int a, int b) {
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}
