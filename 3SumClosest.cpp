/*
Given an array nums of n integers and an integer target, find three integers in nums 
such that the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

Link : https://leetcode.com/problems/3sum-closest/
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int cls = INT_MAX,diff=INT_MAX;
        int sum = 0;
        for(int i = 0; i<sz-1; i++){
            int l = i+1;
            int r = sz-1;
            while(l < r){
                sum = nums[l]+nums[r]+nums[i];
                if(sum == target)
                    return sum;
                else if(sum < target){
                    l++;
                }
                else
                    r--;
                if(abs(target-sum) < diff){
                    cls = sum;
                    diff = abs(target-sum);
                }
            }
        }
        return cls;
    }
};

