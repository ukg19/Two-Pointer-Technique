/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Link : https://leetcode.com/problems/two-sum/
*/
int binarySearch(vector<int> &nums, int &val, int l, int r)
{
    if(l > r)
        return -1;
    int x = l + (r/2);
    if(nums[x] == val)
        return x;
    if(val < nums[x])
        return binarySearch(nums, val, l, x-1);
    else
        return binarySearch(nums, val, x+1, r);
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> l_out;
        unordered_map<int,int> my_map;
        for(int i = 0; i<nums.size(); i++){
            my_map.insert(make_pair(nums[i], i));
        }
        for(int i = 0; i<nums.size(); i++){
            auto it = my_map.find(target-nums[i]);
            if(it != my_map.end() and it->second != i){
                l_out.push_back(i);
                l_out.push_back(it->second);
                return l_out;
            }
        }
        return l_out;
    }
};
