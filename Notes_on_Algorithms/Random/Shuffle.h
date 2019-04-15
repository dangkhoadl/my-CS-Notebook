
vector<int> nums;

// method 1
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
shuffle(nums.begin(), nums.end(), default_random_engine(seed));

// method 2
mt19937 rng(5);
shuffle(all(orders), rng);
