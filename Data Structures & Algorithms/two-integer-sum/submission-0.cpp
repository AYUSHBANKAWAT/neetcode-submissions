class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size()-1;
        vector<int>ans(2,0);
        for(int i=0;i<=n;i++ ){
            int t = target - nums[i];
            if( mp[t] ){
                ans[1]=i;
                ans[0]=mp[t]-1;
                return ans;
            }
            mp[nums[i]] = i+1;
        }
        return ans;
    }
};
