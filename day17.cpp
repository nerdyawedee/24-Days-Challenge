class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i  = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] <= nums.size())// number should be in the range, otherwise we cannnot fix its place
            {
                if(nums[i] != i+1) // if Number is not at its correct place  [1,2,3,4]
                {
                    if(nums[nums[i]-1] != nums[i]) // if nums[i] - 1 index already holds nums[i] [Duplicate]
                    {
                        swap(nums[i], nums[nums[i] - 1]); // place nums[i] at correct place
                        i--; // now recheck ith index
                    }
                }
            }
        }

        for(int i = 0 ;i < nums.size(); i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }

        return nums.size() + 1;
    }
};
