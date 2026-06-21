class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int n = s.size();
        int m = t.size();
        
        // Populate the "shopping list" with what we need
        for (auto k : t) {
            hash[k]++;
        }
        
        int r = 0;
        int l = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIndex = -1;
        
        while (r < n) {
            // If the character at 'r' is on our shopping list, increment our valid count
            if (hash[s[r]] > 0) {
                cnt++;
            }
            // Cross the character off our list (even if it goes negative / becomes surplus)
            hash[s[r]]--;
            
            // When we have all required characters, try to shrink the window
            while (cnt == m) {
                // 1. Record the current window if it's the smallest we've seen
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                
                // 2. We are about to remove s[l] from our window, so put it back on the list
                hash[s[l]]++;
                
                // 3. If putting it back makes the requirement > 0, we just lost a needed character
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                
                // 4. Actually move the left pointer!
                l++;
            }
            
            // Expand the window
            r++;
        }
        
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};