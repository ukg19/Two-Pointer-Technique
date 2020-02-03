/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2. 
Link :  https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& h) {
        int sz = h.size();
        if(sz == 1)
            return 0;
        int i = 0;
        int j = sz -1;
        int max = 0;
        while(i< j){
            int m = min(h[i], h[j]);
            int area  = m * (j-i);
            if(area > max)
                max = area;
            if(h[i] < h[j])
                i++;
            else
                j--;
        }
        return max;
    }
};
