class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mt, int target) {
        int n = mt.size();
        int m = mt[0].size();
        int l = 0;
        int r = (n*m)-1;
        while( l<=r ){
            int mid = (l+r)/2;
            int row = mid/m;
            int col = mid%m;
            if( mt[row][col]>target ){
                r = mid-1;
            }
            else if ( mt[row][col]< target ){
                l = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
