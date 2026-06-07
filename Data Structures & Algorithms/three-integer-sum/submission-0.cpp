class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // Step 1: Sort the array
        sort(nums.begin(), nums.end()); 
        
        // Step 2: Lock in 'z' (which is nums[i])
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate 'z's to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Step 3: Use your Two-Pointer logic for 'x' and 'y'
            int l = i + 1;
            int r = nums.size() - 1;
            int target = -nums[i]; // x + y = -z
            
            while (l < r) {
                int sum = nums[l] + nums[r];
                
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    // Match found! Record the triplet
                    result.push_back({nums[i], nums[l], nums[r]});
                    
                    // Skip duplicate 'x's to avoid duplicate triplets
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return result;
    }
};