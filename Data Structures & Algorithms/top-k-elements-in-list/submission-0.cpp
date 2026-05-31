class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>freq(mp.begin(),mp.end());
        sort(freq.begin(), freq.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second > b.second;
         });

    vector<int> ans;

    for (int i = 0; i < k; i++) {
        ans.push_back(freq[i].first);
    }
    return ans;
        
    }
};
