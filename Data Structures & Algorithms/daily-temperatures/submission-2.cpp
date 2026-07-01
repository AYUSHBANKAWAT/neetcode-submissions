class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        vector<int>ans(t.size(),0);
        int n = t.size();
        s.push(n-1);
        for ( int i = n-2;i>=0;i-- ){
            while( s.size() && t[s.top()]<=t[i] )s.pop();

            if( s.size() )ans[i]=s.top()-i;
            else ans[i] = 0;
            s.push(i);
        }
        return ans;
    }
};
