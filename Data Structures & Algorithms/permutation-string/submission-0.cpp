class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        // Populate frequency map for s1 and the FIRST window of s2
        for (auto k : s1) a[k - 'a']++;
        for (int i = 0; i < n1; i++) {
            b[s2[i] - 'a']++;
        }

        // Check if the very first window happens to be a match
        if (a == b) return true;

        int l = 0;
        int r = n1; // r should point to the FIRST character OUTSIDE the initial window

        while (r < n2) {
            // 1. Remove the old character on the left
            b[s2[l] - 'a']--;
            
            // 2. Add the new character on the right
            b[s2[r] - 'a']++;
            
            // 3. Slide BOTH pointers forward
            l++;
            r++;

            // 4. Check if the newly shifted window is a match
            if (a == b) return true;
        }

        return false;
    }
};