/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length() - 1;
        int peak = find_peak(mountainArr, n);

        int ans = search(mountainArr, 0, peak, target);
        if (ans != -1) return ans;
        ans = search2(mountainArr, peak, n, target);
        if (ans != -1) return ans;

        return -1;

    }

    int find_peak(MountainArray &mountainArr, int r) {
        int l = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (mountainArr.get(m) > mountainArr.get(m + 1)) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }

    int search(MountainArray &mountainArr, int l, int r, int target) {
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            int x = mountainArr.get(m);
            if (x >= target) {
                if (x == target) ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }

    int search2(MountainArray &mountainArr, int l, int r, int target) {
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            int x = mountainArr.get(m);
            if (x <= target) {
                if (x == target) ans = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-in-mountain-array/description/
