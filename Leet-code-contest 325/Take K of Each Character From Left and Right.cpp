class Solution {
public:
    bool solve(int mid, string &s, int k)
    {
        int f[3] = {};
        if(s.length() < k)
            return false;
        for(int i=0; i<mid; i++)
            f[s[i]-'a']++;
        if(f[0] >= k && f[1] >= k && f[2] >= k)
            return true;
        for(int j=1; j<=mid; j++)
        {
            f[s[mid-j]-'a']--;
            f[s[s.length()-j]-'a']++;
            if(f[0] >= k && f[1] >= k && f[2] >= k)
            return true;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        int ans = -1, n = s.length();
        int hi = n, lo = 3;
        if(k == 0)
            return 0;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(solve(mid, s, k))
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }
};
