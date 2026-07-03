class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for( int i = 0;i< position.size();i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        vector<double> stk;
        for(auto& p: cars)
        {
            double time = ((double)(target-p.first)/p.second);
            stk.push_back(time);
            if(stk.size()>= 2 && stk.back()<= stk[stk.size()-2])
            {
                stk.pop_back();
            }
        }
        return stk.size();
        
    }
};
