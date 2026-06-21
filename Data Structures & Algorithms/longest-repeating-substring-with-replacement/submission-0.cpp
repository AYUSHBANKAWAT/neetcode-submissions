class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> hash(26, 0); 
        int l = 0;
        int maxFreq = 0; 
        int ans = 0;
        
        // Let's use 'r' for the right pointer of our window
        for (int r = 0; r < s.size(); r++) {
            // 1. Add the new character to our window's hash map
            hash[s[r] - 'A']++;
            
            // 2. Update the highest frequency of a single character seen so far
            maxFreq = std::max(maxFreq, hash[s[r] - 'A']);
            
            // 3. Check if the window is invalid
            // Window Size - Max Frequency = Characters that need replacing
            while ((r - l + 1) - maxFreq > k) {
                // If invalid, shrink the window from the left
                hash[s[l] - 'A']--;
                l++;
            }
            
            // 4. Update our max answer (the window is guaranteed to be valid here)
            ans = std::max(ans, r - l + 1);
        }
        
        return ans;
    }
};