class Solution {
public:
 void In(TreeNode* root, vector<int>& nums) {
        if(root) {
            In(root->left,nums);
            nums.push_back(root->val);
            In(root->right,nums);
        }
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        In(root,nums);
        vector<vector<int>> ans;
        int n = queries.size();
        
        for(int p=0; p<n; p++){
            int mini = -1, maxi = -1;
            int ind = lower_bound(nums.begin(),nums.end(), queries[p]) - nums.begin();
            if(ind != nums.size())
            {
                maxi = nums[ind];
                if(maxi == queries[p]) {
                    mini = maxi;
                } else {
                    if(ind==0){
                        mini = -1;
                    } else {
                        mini = nums[ind-1];
                    }
                }
            }
            else {
                mini = nums.back();
            }
            ans.push_back({mini, maxi});
        }
        
        return ans;
    }
};
