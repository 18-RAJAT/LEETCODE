class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        map<string,int>mp;
        int index=0;
        for(int i=0;i<n;++i)mp[arr[i]]++;
        for(int i=0;i<n;++i)
        {
            if(mp[arr[i]]==1)index++;
            if(index==k)return arr[i];
        }
        return "";
    }
};