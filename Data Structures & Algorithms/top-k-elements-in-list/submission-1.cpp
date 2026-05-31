class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // Create buckets where the index is the frequency.
        // Size is nums.size() + 1 because frequency can be up to nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // it->first is the number, it->second is the frequency
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> ans;
        
        // Read the buckets backwards (highest frequency first)
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};