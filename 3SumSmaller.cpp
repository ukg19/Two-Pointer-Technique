/*
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k 
with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Follow up: Could you solve it in O(n2) runtime?

 

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0
 

Constraints:

n == nums.length
0 <= n <= 300
-100 <= nums[i] <= 100
-100 <= target <= 100

Link : https://leetcode.com/problems/3sum-smaller/
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        int c = 0;
        for(int i = 0; i<sz-1; i++){
            int l = i+1;
            int r = sz-1;
            while(l < r){
                sum = nums[l]+nums[r]+nums[i];
                if(sum < target){
                    c += (r - l);
                    l++;
                }
                else
                    r--;
                
            }
        }
        return c;
    }
};
