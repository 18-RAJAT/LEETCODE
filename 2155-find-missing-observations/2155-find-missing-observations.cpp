class Solution{
public:
    vector<int> missingRolls(vector<int>&rolls,int mean,int n){
        int m=rolls.size();
        int total=mean*(n+m);
        int sum=accumulate(rolls.begin(),rolls.end(),0LL);
        int target=total-sum;
        if(target<n||target>6*n)return{};
        vector<int>result(n,target/n);
        int remainder=target%n;
        for(int i=0;i<remainder;++i)
        {
            result[i]++;
        }
        return result;
    }
};