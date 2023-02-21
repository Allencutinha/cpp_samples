/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
class Solution {
public:
    vector<string> ans;
    map<int, string> mp;
    void backtrack(string& dig, int start, string& temp)
    {

        if (start == dig.size())
            ans.push_back(temp);

        for (auto x: mp[dig[start] - '0']) {
            temp.push_back(x);
            backtrack(dig, start + 1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string dig)
    {
        if (dig == "")
            return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp;
        backtrack(dig, 0, temp);
        return ans;
    }
};