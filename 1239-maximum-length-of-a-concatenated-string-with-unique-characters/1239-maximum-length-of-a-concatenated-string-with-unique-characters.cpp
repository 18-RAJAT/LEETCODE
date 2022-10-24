// class Solution {
// public:
    
//     bool checkUnique(string s)
//     {
//         int count[26];
//         memset(count,0,sizeof(count));
//         for(int i=0;i<s.size();i++)
//         {
//             if(count[s[i]-'a']==1)
//             {
//                 return false;
//             }
//             else
//             {
//                 count[s[i]-'a']++;
//             }
//         }
//         return true;
//     }
    
//     void backTracking(vector<string>& arr,string s,int index,int &count)
//     {
//         int x=s.size();
//         if(checkUnique(s))
//             count=(s.size()>count)?x:count;
        
//         for(int i=index;i<arr.size();i++)
//             backTracking(arr,s+arr[i],i+1,count);
//     }
    
//     int maxLength(vector<string>& arr) 
//     {
//         int val=arr[0].size();
//         int count=0;
//         if(val<0)
//         {
//             return 0;
//         }
//         if(val==1)
//         {
//             return val;
//         }
//         backTracking(arr,"",0,count);
//         return count;
//     }
// };



class Solution {
public:
    map<string,int>dp;
    bool possible(string s)
    {
        sort(s.begin(),s.end());
        int n=s.size();
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==s[i+1])
            {
                return false;
            }
        }
        return true;
    }
    
    int helper(vector<string>&arr,int idx,string s)
    {
        if(idx<0)
        {
            return 0;
        }
        string key=s+" "+to_string(idx);
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        string tp=s+arr[idx];
        if(possible(tp))
        {
            int sz=arr[idx].size();
            int res=max(sz+helper(arr,idx-1,tp),helper(arr,idx-1,s));
            
            dp.insert(make_pair(key,res));
            return res;
        }
        int r=helper(arr,idx-1,s);
        dp.insert(make_pair(key,r));
        return r;
    }
    int maxLength(vector<string>& arr) {
        string s="";
        return helper(arr,arr.size()-1,s);
    }
};