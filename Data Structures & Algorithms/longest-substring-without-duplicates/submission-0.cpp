#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Cleaner way to create a 256-size array initialized to -1
        std::vector<int> hash(256, -1); 
        
        int l = 0;
        int ans = 0;
        int n = s.size();
        
        // Let's use 'r' (right) instead of 'i' to make the sliding window clear
        for (int r = 0; r < n; r++) {
            // If we have seen this character before...
            if (hash[s[r]] != -1) {
                // AND if its previous index is inside our current window...
                if (hash[s[r]] >= l) {
                    // Jump the left pointer PAST the previous duplicate
                    l = hash[s[r]] + 1;
                }
            }
            
            // ALWAYS update the most recent index of the current character
            hash[s[r]] = r;
            
            // Calculate the current window size and update max
            int current_length = r - l + 1;
            ans = std::max(ans, current_length);
        }
        
        return ans;
    }
};