class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ar(10,0),ans;
        for(auto& it:digits)ar[it]++;
        for(int i=1;i<=9;++i)
        {
            if(ar[i]==0)continue;
            ar[i]--;
            for(int j=0;j<=9;++j)
            {
                if(ar[j]==0)continue;
                ar[j]--;
                for(int k=0;k<=8;k+=2)
                {
                    if(ar[k]==0)continue;
                    ar[k]--;
                    int tmp=i*100+j*10+k;
                    ans.push_back(tmp);
                    ar[k]++;
                }
                ar[j]++;
            }
            ar[i]++;
        }
        return ans;
    }
};