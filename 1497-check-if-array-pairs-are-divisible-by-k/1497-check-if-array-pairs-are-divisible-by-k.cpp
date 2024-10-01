class Solution{
public:
    bool canArrange(vector<int>& arr,int k){
        unordered_map<int,int>remainderCount;
        for(auto& it:arr)
        {
            int remainder=(it%k+k)%k;
            remainderCount[remainder]++;
        }
        for(int i=1;i<k;++i)
        {
            if(remainderCount[i]!=remainderCount[k-i])
            {
                return false;
            }
        }
        if(remainderCount[0]%2!=0)
        {
            return false;
        }
        return true;
    }
};