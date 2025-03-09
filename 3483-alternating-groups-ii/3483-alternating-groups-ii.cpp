class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + (k-1));    //vector.insert(index(where to insert), from where , how much(length) ) //
        int count = 0;
        int left = 0;
        
        for (int right=0; right<colors.size(); right++) {
            if (right > 0 && colors[right] == colors[right-1]) {
                left = right;   //violates alternating group rule
            }
            
            if (right - left + 1 >= k) {    //valid group
                count++;  
            }
        }
        
        return count;
    }
};