class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        // Pass 1: Compute prefixes directly into the ans array
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = left_product;
            left_product *= nums[i];
        }
        
        // Pass 2: Compute postfixes on the fly and multiply them into ans
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }
        
        return ans;
    }
};