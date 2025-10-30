class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
