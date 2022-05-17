class Solution {
public:
    
    int mySqrt(int x) {
        long long temp=x;
            while(temp*temp>x){temp=(temp+x/temp)/2;}
            return temp;
    }
};
