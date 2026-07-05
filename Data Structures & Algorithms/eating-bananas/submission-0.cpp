
class Solution {
public:
    // 1. Pass vector by reference to avoid copying it every time
    // 2. Return 'long long' to prevent integer overflow
    long long tHrs(const vector<int>& p, int t) {
        long long total = 0;
        for (int a : p) {
            // The C++ integer ceiling math trick
            total += (a + t - 1) / t;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        
        int l = 1; 
        int r = maxi;
        int ans = maxi; // Default answer to the maximum possible speed
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long t = tHrs(piles, mid);
            
            // If Koko finishes in time (or faster), this is a valid speed.
            // But we want the MINIMUM speed, so let's try to go slower.
            if (t <= h) {
                ans = mid;     // Record this valid speed
                r = mid - 1;   // Try a slower speed (left half)
            } 
            // If Koko takes too long, she MUST eat faster.
            else {
                l = mid + 1;   // Try a faster speed (right half)
            }
        }
        return ans;
    }
};