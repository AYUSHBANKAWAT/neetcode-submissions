class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size()-1;
        vector<int>ans(2,0);
        for(int i=0;i<=n;i++ ){
            int t = target - nums[i];
            if( mp.count(t) ){
                return {mp[t], i};
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
