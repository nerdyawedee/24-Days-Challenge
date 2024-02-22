class Solution {
    void solve(vector<int>& nums,int i,vector<int> v,vector<vector<int>>&ans)
    {
        if(i == nums.size())
        {
            ans.push_back(v);
            return;
        }

        // Exclude
        solve(nums,i+1,v,ans);
        // Include
        v.push_back(nums[i]);
        solve(nums,i+1,v,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> v;
        solve(nums,0,v,ans);
        return ans;
    }
};
