class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for ( auto i : nums){
            numSet.insert(i);
        }
        int longest = 0;
        for( auto it : nums ){
            if( numSet.find(it-1) ==numSet.end() ){
            int x = it;
            int cnt = 1;
            while( numSet.find(x+1)!=numSet.end() ){
                x=x+1;
                cnt=cnt+1;
            }
            longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
