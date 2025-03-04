class Solution {
public:
    bool checkPowersOfThree(int n) {
        return check(0,n);
    }
    private:
      bool check(int power,int n){
        if(n==0)return 1;
        if(pow(3,power)>n)return 0;
        return check(power+1,n-pow(3,power)) || check(power+1,n);
      }
};