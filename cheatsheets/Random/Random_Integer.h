// reset time after each compile xD
srand(time(0) + rand_int(0, 100000000));

/*_________________________________ Quick Random C++ ____________________________________ */
// Random in range [a, b)
int rand_int(int a, int b) {
    return a + (1.0*(b-a)*rand()) / (1.0+RAND_MAX);
}

// Random in range [a, b)
int rand_int_naive(int a, int b) {
    return a + rand() % (b-a);
}

/*_________________________________ True Random C++ ____________________________________ */
// Random in range [a, b)
int rand_int(int a, int b) {
    // Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}
