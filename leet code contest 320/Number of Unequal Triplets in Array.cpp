class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
           int count=0;
        for(int p=0;p<nums.size();p++)
            for(int j=p+1;j<nums.size();j++)
                for(int k=j+1;k<nums.size();k++)
                    if(nums[p]!=nums[j] && nums[p]!=nums[k] && nums[k]!=nums[j])
                        count++;
        return count;
            
    }
};
