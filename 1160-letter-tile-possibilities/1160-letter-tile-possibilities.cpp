class Solution {
public:
void recur(vector<int>& arr,int& cnt)
{
    if(any_of(arr.begin(),arr.end(),[](int x)
    {
        return x>0;
    }))
    for_each(arr.begin(),arr.end(),[&](int& x)
    {
        if(x>=1){x--;cnt++;recur(arr,cnt);x++;}
    });
}
int numTilePossibilities(string tiles){
        vector<int>arr(26,0);
        int ans=0;
        for(auto& it:tiles)arr[it-'A']++;
        recur(arr,ans);
        return ans;
    }
};