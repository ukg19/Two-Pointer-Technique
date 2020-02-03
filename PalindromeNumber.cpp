/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Link : https://leetcode.com/problems/palindrome-number/
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x % 10 == 0 and x != 0)
            return false;
        if(x < 10)
            return true;
        int revert = 0;
        while(x > revert){
            int dig = x % 10;
            revert = (revert*10) + (dig);
            x /= 10;
        }
        return (x == revert or x == revert/10);
            //return true;
        
    }
};
