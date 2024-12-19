class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxArr(n), minArr(n);
        maxArr[0] = arr[0];
        minArr[n - 1] = arr[n - 1];
        // To make sure that a left group's max is less than next group's min,
        //   we first find out each left group's max
        for (int i = 1; i < n; i++) {
            maxArr[i] = max(maxArr[i - 1], arr[i]);
        }
        //   and each right group's min
        for (int i = n - 2; i >= 0; i--) {
            minArr[i] = min(minArr[i + 1], arr[i]);
        }

        int groups = 1;
        // Whenever left group's max is less than right group's min,
        //   a split mark can be placed to create more groups
        for (int i = 0; i < n - 1; i++) {
            if (maxArr[i] < minArr[i + 1]) groups++;
        }
        return groups;
    }
    

};