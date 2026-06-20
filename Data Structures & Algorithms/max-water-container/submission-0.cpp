class Solution {
public:
    int maxArea(vector<int>& h) {
        int i =0;
        int j = h.size()-1;
        int area = 0;
        while(i<j){
            int k = (j-i)*min(h[i],h[j]);
            area = max(k,area);
            h[i]<h[j]?i++:j--;
        }
        return area;
    }
};

