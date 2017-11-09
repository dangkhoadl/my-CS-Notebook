

int randInt(int a, int b) {
    // Seed with a real random value, if available
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(a, b-1);
    return uniform_dist(e1);
}


void stressTest(int nl_, int nh_, long long el_, long long eh_) {
    while (true) {

        // allocate
        N = randInt(nl_,nh_);                     // N
        

        // Create array
        for (int i = 1; i <= N; ++i) {            // N
            a[i] = randInt(el_,eh_);              // a
        }
        

        // test
        long long res1 = brute();               // brute()
        long long res2 = sol();         		// sol()
        if (res1 != res2) {

            cerr << N << "\n";                        // N
            for (int i = 1; i <= N; ++i) {            // N
                cerr << a[i] << ' ';                  // a
            }

            cerr << "\n";
            cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
    }
}
