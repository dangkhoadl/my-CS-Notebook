
# Divide & Conquer template

```C++
class Solution {
    int __foo(int m, int l, int r) {
        // do main task on [l,r] with m identified
        return do_main_task;
    }

    int get(int l, int r) {
        if(l == r) return base_case;

        int m = l + (r-l)/2;

        int get_left_half = get(l,m);
        int get_right_half = get(m+1,r);
        int get_across_2_halves = __foo(m, l, r);

        return aggregate(get_left_half, get_right_half, get_across_2_halves);
    }
    int main(vector<int> &nums) {
        return get(0, nums.size());
    }
};
```
