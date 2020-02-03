/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

https://leetcode.com/problems/next-permutation/
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int index = -1, index2 = -1;
        int sz = nums.size();
        if(sz == 1)
            return;
        int num = nums[sz-1];
        bool found = false;
        for(int i = sz-1; i>=1; i--){
         if(nums[i-1] < nums[i])
         {
             index = i-1;
             int ind = i;
             for(int j = i + 1; j<sz; j++){
                 if(nums[index] < nums[j] and nums[j] < nums[ind])
                     ind = j;
             }
             int temp = nums[ind];
             nums[ind] = nums[index];
             nums[index] = temp;
             break;
         }
            
        }
        
        sort(nums.begin()+index+1, nums.end());
    }
};
