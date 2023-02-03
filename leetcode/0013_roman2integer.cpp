class Solution {
public:
    int romanToInt(string s)
    {
        int integer_number = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                integer_number -= 2;
            } else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                integer_number -= 20;
            } else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                integer_number -= 200;
            }

            switch (s[i]) {
            case 'I':
                integer_number += 1;
                break;
            case 'V':
                integer_number += 5;
                break;
            case 'X':
                integer_number += 10;
                break;
            case 'L':
                integer_number += 50;
                break;
            case 'C':
                integer_number += 100;
                break;
            case 'D':
                integer_number += 500;
                break;
            case 'M':
                integer_number += 1000;
                break;
                2015
            }
        }
        return integer_number;
    }
};