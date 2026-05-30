class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size())return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)return true;
        // return false;
        // based on feedback of redundantloop
        // if(s.size()!=t.size())return false;
        // unordered_map<char,int>mp;
        // for( int i = 0;i<s.size();i++ ){
        //     mp[s[i]]++;
        //     mp[t[i]]--;
        // }
        // // for( int i = 0;i<t.size();i++ ){
        // //     if(mp[t[i]])mp[t[i]]--;
        // //     else return false;
        // // }
        // for( int i = 0;i<s.size();i++ ){
        //     if(mp[s[i]]>0 || mp[t[i]]>0 )return false;
        // }
        // return true;
        if(s.size()!=t.size())return false;
        int a[26] ={0};
        for( int i = 0;i<s.size();i++ ){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        // for( int i = 0;i<t.size();i++ ){
        //     if(mp[t[i]])mp[t[i]]--;
        //     else return false;
        // }
        for( int i = 0;i<s.size();i++ ){
            if(a[s[i]-'a']>0 || a[t[i]-'a']>0 )return false;
        }
        return true;
    }
};
