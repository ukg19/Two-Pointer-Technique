/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
Link : https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> l_out;
        int i = 0,j = 1, k = nums.size()-1;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if(sz < 3)
            return l_out;
        for(int i = 0; i<sz-1; i++){
            
            int l = i+1;
            int r = sz-1;
        
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0){
                //cout << " i= " << i << " l = " << l << " r = " << r <<endl;
                vector<int> v;
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
            else if(sum < 0){
                //i++;
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
};
