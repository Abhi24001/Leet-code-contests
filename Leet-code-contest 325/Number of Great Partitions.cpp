class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        int n = nums.size();
        if (n == 1 || sum / 2 < k) {
            return 0;
        }
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long all_ways = 1;
        for (int i = 0; i < n; i++) {
            all_ways = (all_ways * 2) % mod;
        }
        vector<long long> ways_sum_to_n(k);
        ways_sum_to_n[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = k - nums[i] - 1; j >= 0; j--) {
                int t = nums[i] + j;
                ways_sum_to_n[t] = (ways_sum_to_n[t] + ways_sum_to_n[j]) % mod;
            }
        }
        long long undesired_ways = accumulate(ways_sum_to_n.begin(), ways_sum_to_n.end(), 0LL);
        undesired_ways = (undesired_ways * 2) % mod;
        return (all_ways - undesired_ways + mod) % mod;
    }
};
