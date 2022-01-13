#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;


vector<string> split(const string &str, char delim) {
    vector<string> vec_str;
    stringstream ss(str);
    string part;
    while (getline(ss, part, (delim))) {
        vec_str.emplace_back(part);
    }
    return move(vec_str);
}

vector<vector<string>> ops;
void readInput() {
    ifstream input_file("input.in");

    // Read content by lines
    vector<string> lines;
    for (string line(""); getline(input_file, line);) {
        if(line != "") lines.push_back(line);
    }
    input_file.close();

    // Parse ops
    for(string &line:lines) {
        ops.push_back( split(line, ' ') );
    }
}

int get_second(const string &var, unordered_map<string, int> &values) {
    if(var == "w" || var == "x" || var == "y" || var == "z") {
        return values[var];
    }
    return stoi(var);
}

unsigned long long q_pow(unsigned long long x, unsigned long long n) {
    // Base cases
    if(n == 0 || n == 1) return 1;

    // Divide and Conquer
    unsigned long long half = q_pow(x, n/2);
    if(n%2 == 0) return half*half;
    return x*half*half;
}
struct hash_vector {
    template <class T>
    unsigned long long operator()(const vector<T>& vec) const {
        unsigned long long p = 999999999989;
        unsigned long long x = 999836351609;

        unsigned long long hash_val = 0;
        for(int i=0; i<vec.size(); ++i) {
            hash_val += (vec[i] * q_pow(x, i) % p);
        }

        return hash_val;
    }
};

unsigned long long cache_hits = 0;
unsigned long long cache_misses = 0;
unordered_map<vector<int>, pair<bool, string>, hash_vector> dp_cache;
pair<bool, string> guess(int idx, int w_val, int x_val, int y_val, int z_val) {
    if(dp_cache.find(vector<int>({idx,w_val,x_val,y_val,z_val})) != dp_cache.end()) {
        cache_hits += 1;
        return dp_cache[vector<int>({idx,w_val,x_val,y_val,z_val})];
    }

    unordered_map<string, int> values =  {
        {"w", w_val},
        {"x", x_val},
        {"y", y_val},
        {"z", z_val}
    };

    // Prune
    if (values["z"] > static_cast<int>(1e6)) return {false, ""};

    // Debug
    cache_misses += 1;
    cout << "[Cache info: hits=" << cache_hits << " misses=" << cache_misses << " curr_size=" << dp_cache.size() << "]" << \
        "[" << idx << "/" << ops.size() << "]: " << \
        w_val << " " <<  x_val << " " <<  y_val << " " <<  z_val << endl;

    // End
    if (idx == ops.size()) return { values["z"] == 0, "" };

    // ALU
    vector<string> op = ops[idx];

    if(op[0] == "inp") {
        for(int &digit: vector<int>({1,2,3,4,5,6,7,8,9})) {
            values[op[1]] = digit;

            // Cache
            pair<bool, string> res = guess(idx + 1, values["w"], values["x"], values["y"], values["z"]);
            dp_cache[vector<int>({idx + 1, values["w"], values["x"], values["y"], values["z"]})] = res;

            if(res.first == true) return {true, to_string(digit) + res.second};
        }

        // Cache
        dp_cache[vector<int>({idx, values["w"], values["x"], values["y"], values["z"]})] = {false, ""};
        return {false, ""};
    }

    int second_op = get_second(op[2], values);
    if(op[0] == "add") values[op[1]] += second_op;
    else if (op[0] == "mul") values[op[1]] *= second_op;
    else if (op[0] == "div") {
        if(second_op == 0) {
            // Cache
            dp_cache[vector<int>({idx, values["w"], values["x"], values["y"], values["z"]})] = {false, ""};
            return {false, ""};
        }
        values[op[1]] /= second_op;
    }
    else if (op[0] == "mod") {
        if (values[op[1]] < 0 || second_op <= 0) {
            // Cache
            dp_cache[vector<int>({idx, values["w"], values["x"], values["y"], values["z"]})] = {false, ""};
            return {false, ""};
        }
        values[op[1]] %= second_op;
    }
    else if (op[0] == "eql") {
        if (values[op[1]] == second_op) values[op[1]] = 1;
        else values[op[1]] = 0;
    }
    else {
        // Cache
        dp_cache[vector<int>({idx, values["w"], values["x"], values["y"], values["z"]})] = {false, ""};
        return {false, ""};
    }

    // Cache
    pair<bool, string> res = guess(idx + 1, values["w"], values["x"], values["y"], values["z"]);
    dp_cache[vector<int>({idx+1, values["w"], values["x"], values["y"], values["z"]})] = res;
    return res;
}


void solve() {
    pair<bool, string> ans = guess(0, 0,0,0,0);
    cout << "Correct: " << ans.second << endl;
}

/*------------------------------------- MAIN ---------------------------------------------------------------*/
int main(int agrc, char *argv[]) {
    ios::sync_with_stdio(false);
    // cin.tie(false);
    cout << fixed << setprecision(11);

    // This code is here to increase the stack size to avoid stack overflow
    // in depth-first search.
    const rlim_t kStackSize = 64L * 1024L * 1024L;  // min stack size = 64 Mb
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
/*----------------------------------------------------------------------------------------------------*/
    //InOut
    readInput();

    //solve
    solve();

    return 0;
}
