class Solution {
public:
    int M= pow(10,9)+7;
    
    int ncr(int n,int k){
        
 
        int C[n + 1][k + 1];
        int i, j;

        for (i = 0; i <= n; i++) {
            for (j = 0; j <= min(i, k); j++) {
                
                if (j == 0 || j == i)
                    C[i][j] = 1;

                else
                    C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%M;
            }
        }

        return C[n][k];
        
    }
    int ways(vector<int>&nums){
        
        int n= nums.size();
        if(n<=2){
            return 1;
        }
        int root= nums[0];
        
        vector<int>left,right;
        for(int i=1; i<n; i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        long lcount= ways(left);
        long rcount= ways(right);
        
        long t1= (ncr(n-1,left.size())*lcount)%M;
        long t2= (t1*rcount)%M;
        
        return t2;
    }
    int numOfWays(vector<int>& nums) {
        
        int ans= ways(nums);
        return ans-1;
        
    }
};