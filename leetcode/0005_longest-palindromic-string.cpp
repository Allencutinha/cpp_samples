/*
Given a string s, return the longest
palindromic

substring
 in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
class Solution {
public:
    int mx = INT_MIN;
    string ans = "";
    int isPalindrome(string& s, int i, int j)
    {
        while (i < j) {
            if (s[i] != s[j]) {
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    void solve(int n, string& s)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    if (j - i + 1 > mx) {
                        ans = s.substr(i, j - i + 1);
                        mx = j - i + 1;
                    }
                }
            }
        }
    }
    string longestPalindrome(string s)
    {
        int n = s.size();
        solve(n, s);
        return ans;
    }
};