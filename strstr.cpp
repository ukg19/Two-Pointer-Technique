/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Link  : https://leetcode.com/problems/implement-strstr/
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz = haystack.size();
        int sz1 = needle.size();
        if(sz1 == 0)
            return 0;
        if(sz1 > sz)
            return -1;
        int k = sz - sz1;
        int i = 0, j;
        bool found = true;
        while(i <= k)
        {
            int matches = 0;
            //cout << "here\n";
            for(int l = i; l<i+sz1; l++)
            {
                //cout <<" l = " << l << " i = " << i <<endl;
                if(needle[l-i] == haystack[l])
                {
                    matches++;
                }
                else
                    break;
            }
            if(matches == sz1)
                return i;
            i++;
        }
        return -1;
    }
};
