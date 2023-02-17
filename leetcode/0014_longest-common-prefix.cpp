/*
14. Longest Common Prefix
Easy
12.6K
3.7K
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        // Sort the given array
        int n = strs.size();
        sort(strs.begin(), strs.end());

        // Find the minimum length from
        // first and last string
        int en = min(strs[0].size(), strs[n - 1].size());

        // Now the common prefix in first and
        // last string is the longest common prefix
        string first = strs[0], last = strs[n - 1];
        int i = 0;
        while (i < en && first[i] == last[i])
            i++;

        string pre = first.substr(0, i);
        return pre;
    }
};

// modified solution

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int en = min((strs.begin())->size(), (strs.begin() + n - 1)->size());
        string first = strs[0], last = strs[n - 1];
        int i = 0;
        while (i < en && first[i] == last[i]) {
            i++;
        }

        string pre = first.substr(0, i);
        return pre;
    }
};