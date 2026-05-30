class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // if( nums.size()<=1 )return false;
        // sort(nums.begin(),nums.end());
        // for( int i=0;i<nums.size()-1;i++){
        //     if( nums[i] == nums[i+1] )return true;
        // }
        // return false;
        unordered_map<int,int>mp;
        for( int i=0;i<nums.size();i++ ){
            mp[nums[i]]++;
            if(mp[nums[i]]>1)return true;
        }
        return false;

    }
};