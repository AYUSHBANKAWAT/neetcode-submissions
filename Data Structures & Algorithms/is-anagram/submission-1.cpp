class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size())return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)return true;
        // return false;
        if(s.size()!=t.size())return false;
        unordered_map<char,int>mp;
        for( int i = 0;i<s.size();i++ ){
            mp[s[i]]++;
        }
        for( int i = 0;i<t.size();i++ ){
            if(mp[t[i]])mp[t[i]]--;
            else return false;
        }
        for( int i = 0;i<s.size();i++ ){
            if(mp[s[i]]>0)return false;
        }
        return true;
    }
};
