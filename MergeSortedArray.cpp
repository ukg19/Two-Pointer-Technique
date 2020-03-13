/*
Link : https://leetcode.com/problems/merge-sorted-array/
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return;
        int i = m-1, j = n-1;
        
        while(j >= 0 and i >= 0){
            //cout << " i = " << i << " j = " << j <<endl;
            if(nums2[j] >= nums1[i]){
                nums1[i+j+1] = nums2[j];
                j--;
            }
            else{
                nums1[i+j+1] = nums1[i];
                i--;
            }
        }
        while(j >= 0){
            //cout << " i = " << i << " j = " << j <<endl;
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
};
