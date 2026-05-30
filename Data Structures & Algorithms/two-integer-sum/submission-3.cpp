class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int>mp;
        // int n = nums.size()-1;
        // vector<int>ans(2,0);
        // for(int i=0;i<=n;i++ ){
        //     int t = target - nums[i];
        //     if( mp.count(t) ){
        //         return {mp[t], i};
        //     }
        //     mp[nums[i]] = i;
        // }
        // return ans;

        unordered_map<int, int> mp;
        
        // Optimize Memory: Pre-allocate space to prevent expensive rehashing
        mp.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            
            // Optimize Time: Search the map exactly once
            auto it = mp.find(t);
            
            // Check if the iterator reached the end (meaning not found)
            if (it != mp.end()) {
                // it->second is the index stored in the map
                return {it->second, i}; 
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
