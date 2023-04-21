class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
            //TLE
//         function<int(int,int,int,vector<int>&,vector<int>&)>scheme=[&](int n,int i,int minimumProfit,vector<int>&group,vector<int>&profit)->int
//         {
//             if(n<0)
//             {
//                 return 0;
//             }
//             if(i==group.size())
//             {
//                 return (minimumProfit<=0)?1:0;
//             }
//             int includeScheme=scheme(n-group[i],i+1,minimumProfit-profit[i],group,profit);
//             int excludeScheme=scheme(n,i+1,minimumProfit,group,profit);
            
//             int totalScheme=includeScheme+excludeScheme;
//             return totalScheme%=1000000007;
//         };
//         int crimeGenerates=0;
//         return scheme(n,crimeGenerates,minProfit,group,profit);
        
        
        
        vector<vector<int>>scheme(minProfit+1,vector<int>(n+1));
        scheme[0][0]=1;
        for(int k=0;k<group.size();++k)
        {
            int include=group[k];
            int exclude=0;
            
            if(profit[k]>0)
            {
                exclude=profit[k];
            }
            for(int i=minProfit;i>=0;--i)
            {
                for(int j=n;j>=include;--j)
                {
                    scheme[min(i+exclude,minProfit)][j]+=scheme[i][j-include];
                    scheme[min(i+exclude,minProfit)][j]%=1000000007;
                }
            }
        }
        int numberOfSchemes=0;
        for(int i=0;i<=n;++i)
        {
            numberOfSchemes=(numberOfSchemes+scheme[minProfit][i])%1000000007;
        }
        return numberOfSchemes;
    }
};