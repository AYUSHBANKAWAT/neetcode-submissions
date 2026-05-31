class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> count;
        for (int n: nums) count[n]++;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto& [e, c]: count) {
            freq[c].push_back(e);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int e: freq[i]) {
                res.push_back(e);
                if (res.size() >= k) {
                    return res;
                }
            }
        } 
        return res;
    }
};
