class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size()-1;
        int ans = 0;
        int l =0;
        int r=n;
        int l_max=0;
        int r_max=0;
        while(l<r){
            l_max = max(l_max,h[l]);
            r_max = max(r_max,h[r]);
            if(l_max<r_max){
                ans += l_max-h[l];
                l++;
            }else{
                ans += r_max-h[r];
                r--;
            }
        }
        return ans;
    }
};
