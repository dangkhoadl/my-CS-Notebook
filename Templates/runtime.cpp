

void solve(unsigned long long t) {
    time_t startt = clock();
    printf("Case #%llu: %lld\n", t, sol());
    cerr << "Case #" << t << ": " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
}

