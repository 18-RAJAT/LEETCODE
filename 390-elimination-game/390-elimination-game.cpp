class Solution {
public:
    int lastRemaining(int n) {
        
        bool left=true;
        int initial =1,move=1,rem=n;
        while(rem>1) 
        {
            if(left or rem%2==1) {initial=initial+move;}   
            rem=rem/2;move=move*2;left=!left;
        }
        return initial;
    }
};