class Solution {
public:
    bool check(string a, int target) {
        int n = a.size();
        string x = "";
        for (int i = 0; i < n; i++) {//O(N^2)
            x += a[i];
            int sum = stoi(x);
            
           
            if (i == n - 1) {//Base case
                if (sum == target) return true;
            } else if (sum <= target) {//else check for the rest string 
                if (check(a.substr(i + 1), target - sum)) return true;
            }
        }
        return false;
    }

    int solve(int n) {
        long long ans = 0;//Initializing the ans 
        for (int i = 1; i <= n; i++) {//O(N)
            int squared = i * i;
            if (check(to_string(squared), i)) {//COnsition to check the punishment number
                ans += squared;//if true add to answer
            }
        }
        return ans;
    }
    int punishmentNumber(int n) {
        return solve(n);//To solve my problem and give me the solution 
        //Time Complexity:O(N^3) but since N's max value is 1000 it works 
        //Space Complexity:O(N) due to Recursion Call stack.
    }
};