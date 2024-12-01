class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<double,int>mp;
        for(int i=0;i<arr.size();++i)
        {
           if(mp.count(arr[i]*2) || mp.count((double)arr[i]/2))return true;
           mp[arr[i]]++;
        }
        return false;
    }
};