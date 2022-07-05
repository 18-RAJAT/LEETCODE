class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){return 0;}if(n==1){return 1;}
        
        if(n%2==0){return isUgly(n/2);}
        if(n%3==0){return isUgly(n/3);}
        if(n%5==0){return isUgly(n/5);}
        return 0;
    }
};
