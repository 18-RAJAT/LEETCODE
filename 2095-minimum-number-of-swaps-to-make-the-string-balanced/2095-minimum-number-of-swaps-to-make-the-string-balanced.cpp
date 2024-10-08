class Solution{
public:
    int minSwaps(string s){
        int balance=0,maxUnbalanced=0;
        for(char c:s)
        {
            if(c=='[')balance++;
            else balance--;
            if(balance<0)maxUnbalanced=max(maxUnbalanced,-balance);
        }
        return (maxUnbalanced+1)/2;
    }
};