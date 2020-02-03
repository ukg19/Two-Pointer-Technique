/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false

Link : https://leetcode.com/problems/valid-parentheses/
*/

class Solution {
public:
    bool isValid(string s) {
        if(!s.size())
            return true;
        stack<char> st;
        map<char, char> my_map;
        my_map.insert(make_pair('(', ')'));
        my_map.insert(make_pair('{', '}'));
        my_map.insert(make_pair('[', ']'));
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '(' or s[i] == '{' or s[i]== '[')
                st.push(s[i]);
            else
            {
                if(st.size() > 0){
                auto c = st.top();
                if(my_map[c] != s[i])
                    return false;
                st.pop();
                }
                else
                    return false;
            }
        }
        return st.size() ? false : true; 
    }
};
