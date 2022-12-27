class Solution
{
public:

    bool isValid(int minDiff, vector<int>& price, int k) {
        int n = price.size();
        int cnt = 1;

        int prev = price[0];

        for(int i = 1; i < n; i++) {
            if(price[i] - prev >= minDiff) {
                cnt++;
                prev = price[i];
            }
        }

        if(cnt >= k) return true;

        return false;

    }
    int maximumTastiness(vector<int> &price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();

        int st = 0;
        int en = price[n - 1] - price[0];

        int ans = -1;

        while(st <= en) {
            int mid = st + (en - st) / 2;

            if(isValid(mid, price, k)) ans = mid, st = mid + 1;
            else en = mid - 1; 
        }

        return ans;
    }
};
// upvote if you like the solution
