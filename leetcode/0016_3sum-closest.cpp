class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 1e6;
        for (int i = 0; i < nums.size(); i++) {
            int tar = nums[i];
            int s = i + 1;
            int l = nums.size() - 1;
            while (s < l) {
                int t = tar + nums[s] + nums[l];
                if (t > target) {
                    --l;
                } else if (t < target) {
                    ++s;
                } else {
                    return (target);
                }
                if (abs(target - ans) > abs(target - t)) {
                    ans = t;
                }
            }
        }
        return (ans);
    }
};