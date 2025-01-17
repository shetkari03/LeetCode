class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool x = 0;
        for(auto i:derived) x ^= i;
        return !x;
    }
};