// class Solution {
//     vector<bool>flag;
// public:
//     // vector<int>v1;
    
//     bool makesquare(vector<int>& nums) {
//         int ac=accumulate(begin(nums),end(nums),0);
//         if(nums.size()<=3 or ac%4!=0) return false;
//         int tar=ac/4;
//         sort(nums.begin(),nums.end(),greater<int>());
//         if(nums[0]>tar) return false;
//         flag.resize(nums.size(),false);
//         for(int i=0; i<3; ++i) 
//         {
//             if (false==dfs(nums,0,tar)) 
//             {
//                 return false;
//                 // cout<<"Ptr";
//             }
//         }
//         return true;
//     }
    
//     bool dfs(vector<int> &nums,int in,int tar) {
//         int res=false;
        
//         for(int i=in;i<nums.size();++i) 
//         {
//             if(flag[i]==true)continue;
//             // cout<<"F"
            
//             if(nums[i]==tar) 
//             {
//                 flag[i]=true;
//                 res=true;break;
//                 // cout<<"Ptrst";
//             }
//             if(nums[i]<tar) {
//                 if(dfs(nums,i+1,tar-nums[i])) 
//                 {
//                     flag[i] = true;
//                     res=true;
//                     break;
//                     // cout<<"1";
//                 }
//             }
//         }
        
//         return res;
//     }
// };


//*************************************************************************

//NP Solution -> O(4^n)



// class Solution {
//     bool dfs(vector<int>&sl,const vector<int> &m, int idx) {
//         if(idx==m.size()){return sl[0]==sl[1] and sl[1]==sl[2] and sl[2]==sl[3];}
//         for(int i=0;i<4;++i) 
//         {
//             sl[i]+=m[idx];
//             if(dfs(sl,m,idx+1))
//                 return true;
//             sl[i]-=m[idx];
//         }
//         return false;
//     }
// public:
//     bool makesquare(vector<int>& nums)
//     {
//         if(nums.empty()){return false;}
//         vector<int>sl(4,0);
//         return dfs(sl,nums,0);
//     }
// };

//*************************************************************************



// class Solution{
//     public:
//     int n;
//     vector<int>ms;
//     int t=0;
//     bool helper(int i,int a,int b,int c,int d)
//     {
//         if(i==n)
//         {return a==t and b==t and c==t and d==t;}
//         if(a+ms[i]<=t){if(helper(i+1,a+ms[i],b,c,d))return true;}
//         if(a+ms[i]<=t){if(helper(i+1,a,b+ms[i],c,d))return true;}
//         if(a+ms[i]<=t){if(helper(i+1,a,b,c+ms[i],d))return true;}
//         if(a+ms[i]<=t){if(helper(i+1,a,b,c,d+ms[i]))return true;}
        
//         return false;
//     }
    
//     bool makesquare(vector<int>& matchsticks){
//         ms=matchsticks;
//         n=matchsticks.size();
//         int sum=0;
//         for(int i=0;i<n;++i)sum=sum+matchsticks[i];
//         if(sum%4!=0){return false;}
//         t=sum/4;
//         sort(ms.begin(),ms.end());
//         return helper(0,0,0,0,0);
//     }
// };




class Solution {
public:
    bool sol(vector<int> &m,vector<bool> &vis,int tar,int s,int ind,int k){
        if(k==4)return true;
        if(s==tar)return sol(m,vis,tar,0,0,k+1);
        for(int i=ind;i<m.size();i++){
            if(vis[i] or s+m[i]>tar)continue;
            vis[i]=true;
            if(sol(m,vis,tar,s+m[i],i+1,k))return true;
            vis[i]=false;
        }
        return false;
    }
    bool makesquare(vector<int>& m) {
        int sum=0;
        for(int &i:m)sum+=i;
        if(m.size()<4 or sum%4>0)return false;
        vector<bool> vis(m.size(),false);
        return sol(m,vis,sum/4,0,0,1);
    }
};