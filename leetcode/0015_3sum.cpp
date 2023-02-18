/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and
j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num)
    {
        vector<vector<int>> result;
        if (num.size() == 0 || num.size() == 1 || num.size() == 2)
            return result;

        // sort the array, this is the key
        sort(num.begin(), num.end());

        int n = num.size();

        for (int i = 0; i < n - 2; i++) {
            // skip the duplication
            if (i > 0 && num[i - 1] == num[i])
                continue;
            int a = num[i];
            int low = i + 1;
            int high = n - 1;
            while (low < high) {
                int b = num[low];
                int c = num[high];
                if (a + b + c == 0) {
                    result.push_back({a, b, c});
                    // Continue search for all triplet combinations summing to zero.
                    // skip the duplication
                    while (low < n - 1 && num[low] == num[low + 1])
                        low++;
                    while (high > 0 && num[high] == num[high - 1])
                        high--;
                    low++;
                    high--;
                } else if (a + b + c > 0) {
                    // skip the duplication
                    while (high > 0 && num[high] == num[high - 1])
                        high--;
                    high--;
                } else {
                    // skip the duplication
                    while (low < n - 1 && num[low] == num[low + 1])
                        low++;
                    low++;
                }
            }
        }
        return result;
    }
};