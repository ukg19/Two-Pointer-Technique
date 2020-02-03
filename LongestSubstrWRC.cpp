/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
 
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto len = s.size();
        int c = 0;
        int max = 0;
        int i = 0, j = 0;
        set<char> my_set;
        while(i < len and j < len){
            auto it = my_set.find(s[j]);
            //cout << "j = " << j << " i = " << i << endl;
            if(it == my_set.end()){
                my_set.insert(s[j]);
                max = std::max(j-i+1,max);
                j++;
            }
            else{
                my_set.erase(s[i]);
                i++;
            }
        }
        return max;
    }
};
