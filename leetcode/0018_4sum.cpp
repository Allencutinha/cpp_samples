/*
18. 4Sum
Medium
8.7K
1K
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c],
nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
Accepted
708.1K
Submissions
2M
Acceptance Rate
36.0%
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j + 1, high = n - 1;
                while (low < high) {
                    if (nums[low] + nums[high] < newTarget) {
                        low++;
                    } else if (nums[low] + nums[high] > newTarget) {
                        high--;
                    } else {
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while (low < high && nums[low] == nums[tempIndex1])
                            low++;
                        while (low < high && nums[high] == nums[tempIndex2])
                            high--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1])
                    j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return output;
    }
};
