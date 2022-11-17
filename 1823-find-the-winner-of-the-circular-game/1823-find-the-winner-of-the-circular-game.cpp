class Solution {
public:
    int findTheWinner(int n, int k) {
        int startingPos=0;
        for(int i=1;i<=n;++i)
        {
            int temp=(startingPos+k-1);
            startingPos=temp%i;
            
            startingPos++;
        }
        return startingPos;
    }
};