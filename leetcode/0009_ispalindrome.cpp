class Solution {
public:
    bool isPalindrome(int x)
    {
        unsigned int rev = 0;
        int ref = x;
        if (x < 0)
            return false;
        while (x) {
            rev = x % 10 + rev * 10;
            x = x / 10;
        }
        return (ref == rev) ? true : false;
    }
};