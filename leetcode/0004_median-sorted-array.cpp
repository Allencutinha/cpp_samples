class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);
        int n = n1 + n2;
        int cut1, cut2;
        int l1, l2, r1, r2;
        int low = 0, high = n1;
        while (low <= high) {
            cut1 = (low + high) >> 1;
            cut2 = (n + 1) / 2 - cut1;
            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1)
                if (n % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};