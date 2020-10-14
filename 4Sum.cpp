/*
Link : https://leetcode.com/problems/4sum/
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums 
such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []
 

Constraints:

0 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
class Solution {
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start,int n) {
        vector<vector<int>> l_out;
        int i = start,j = start+1, k = nums.size()-1;
        int sz = nums.size();
        if(sz-start < 3)
            return l_out;
        //cout << " lokking for. "<< target <<endl;
        for(int i = start; i<sz-1; i++){   
            int l = i+1;
            int r = sz-1;
            //cout << " l = " << l << " r = "<< r <<endl;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                //cout << " sum = " << sum <<endl;
                if(sum == target){
                    vector<int> v;
                    v.push_back(n);
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    l_out.push_back(v);
                    l++; r--;
                    while(l < r){
                        if(nums[l] == nums[l-1])
                            l++;
                        else
                            break;
                    }
                    while(r > l){
                        if(nums[r] == nums[r+1])
                        r--;
                    else
                        break;
                }
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
            while(i<sz-1){
                if(nums[i+1] == nums[i] )
                    i++;
                else
                    break;
            }
        }
        return l_out;
    }
public:
    // -2 -1 0 0 1 2
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> l_out;
          if(nums.size() < 4)
            return l_out;
         sort(nums.begin(), nums.end());
         for(int i = 0; i<nums.size()-1;){
             auto x = threeSum(nums, target-nums[i], i+1,nums[i]);
             //cout << x.size() <<endl;
             if(x.size())
             l_out.insert(l_out.end(), x.begin(), x.end());
             //i++;
             while(i+1 < nums.size() and nums[i] == nums[++i]);
         }
        return l_out;
    }
};
