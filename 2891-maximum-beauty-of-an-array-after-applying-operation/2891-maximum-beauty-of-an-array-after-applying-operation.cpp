#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int maxBeauty = 1; // Variable to track the maximum size of a valid subsequence

        // Step 2: Iterate through each element
        for (int i = 0; i < n; i++) {
            // Find the upper bound index where nums[j] <= nums[i] + 2 * k
            int ub = find(nums, nums[i] + 2 * k);
            // Update maxBeauty with the size of the current valid subsequence
            maxBeauty = max(maxBeauty, ub - i + 1);
        }
        return maxBeauty; // Return the maximum valid subsequence size
    }

private:
    // Helper function to find the upper bound index where nums[j] <= val
    int find(const vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        int res = -1; // Stores the index of the last element <= val

        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate mid-point
            if (nums[mid] <= val) {
                res = mid; // Update result and search in the right half
                l = mid + 1;
            } else {
                r = mid - 1; // Search in the left half
            }
        }
        return res; // Return the index of the last element <= val
    }
};