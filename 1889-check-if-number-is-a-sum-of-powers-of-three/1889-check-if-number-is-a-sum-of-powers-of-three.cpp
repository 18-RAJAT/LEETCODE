class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==1)return 1;
        return n?n%3!=2 && checkPowersOfThree(n/3):true;
    }
};