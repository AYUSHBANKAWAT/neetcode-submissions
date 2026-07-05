class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        // Stack stores pairs of {start_index, height}
        stack<pair<int, int>> st; 
        
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            
            // While the stack is not empty and the current height is SHORTER 
            // than the height at the top of the stack...
            while (!st.empty() && heights[i] < st.top().second) {
                // 1. Pop the taller bar
                int index = st.top().first;
                int height = st.top().second;
                st.pop();
                
                // 2. Calculate the area (height * width)
                // The width is the current index 'i' minus where this height started
                maxArea = max(maxArea, height * (i - index));
                
                // 3. The current shorter bar can be extended backwards to 'index'
                start = index; 
            }
            
            // Push the current bar with its new calculated starting index
            st.push({start, heights[i]});
        }
        
        // Cleanup: Process any bars that made it all the way to the end of the array
        int n = heights.size();
        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            
            // Width is the full length of the array 'n' minus the starting index
            maxArea = max(maxArea, height * (n - index));
        }
        
        return maxArea;
    }
};