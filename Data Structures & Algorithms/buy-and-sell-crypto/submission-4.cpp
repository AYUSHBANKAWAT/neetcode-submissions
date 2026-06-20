class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int rMax = p[n-1];
        int j = n-1;
        int profit =0;
        // if(n==1)return 0;

        while( j>=0 ){
            profit = max( profit,rMax-p[j] );
            rMax = max(rMax,p[j]);
            j--;
        }
        return profit;
    }
};
