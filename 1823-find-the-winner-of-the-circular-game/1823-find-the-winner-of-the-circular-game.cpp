class Solution {
public:
    int findTheWinner(int n, int k) {
        
        //using math's
        
        int startingPos=0;
        for(int i=1;i<=n;++i)
        {
            int temp=(startingPos+k-1);
            startingPos=temp%i;
            
            startingPos++;
        }
        return startingPos;
        
        //using vector
        
        // vector<int>ans;
        // int m=ans.size();
        // for(int i=1;i<=n;++i)
        // {
        //     ans.push_back(i);
        // }
        // int startingPos=0;
        // // while(m<=1)
        // while(m!=1)
        // {
        //     startingPos=(startingPos+k-1)%m;
        //     ans.erase(ans.begin()+startingPos);
        // }
        // return ans[0];
        
        
        //queue solution
        
    }
};