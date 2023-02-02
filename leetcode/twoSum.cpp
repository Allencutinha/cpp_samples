class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;

        int N = nums.size();

        for (int i = 0; i < N; i++) {
            if (map.count(target - nums[i])) {
                return vector{i, map[target - nums[i]]};
            }

            map[nums[i]] = i;
        }

        return vector<int>{};
    }
};