class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
//         int n=prop.size();
//         sort(prop.begin(),prop.end());
//         int maximum1=0,maximum2=0;
//         int group=prop[n-1][0];
        
//         int result=0;
//         for(int i=n-1;i>=0;--i)
//         {
//             if(prop[i][0]!=group){group=prop[i][0];maximum1=maximum2;}
//             maximum2=max(maximum2,prop[i][1]);
            
//             if(prop[i][1]<maximum1)result++;
//         }return result;
        int n=prop.size();
        sort(prop.begin(),prop.end());
        int ans=0,a=prop[n-1][0],b=prop[n-1][1],maxi=prop[n-1][1];
        for(int i=n-2;i>=0;i--)
        {
            if(prop[i][0]<prop[i+1][0])
            {
                b=max(maxi,0);
                maxi=max(b,prop[i][1]);
            }
            if(prop[i][0]<a and prop[i][1]<b){ans++;}
        }return ans;
    }
};