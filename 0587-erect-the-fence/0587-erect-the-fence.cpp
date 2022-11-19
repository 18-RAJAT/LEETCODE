class Solution {
public:
    
    static bool cmp(vector<int>& a,vector<int>& b){return a[0]<b[0] or (a[0]==b[0] and a[1]<b[1]);}
    
    int navigation(vector<int>& a,vector<int>& b,vector<int>& c){return (b[0]-a[0])*(c[1]-b[1])-(b[1]-a[1])*(c[0]-b[0]);}
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // Andrew's monotone chain method
        int n = trees.size();
        vector<vector<int>> ans;
        sort(trees.begin(),trees.end(),cmp);
        
        // l to r
        for(int i=0;i<n;++i) 
        {
            while(ans.size()>1 and navigation(ans[ans.size()-2],ans.back(),trees[i])<0) 
                
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        
        //if all trees present in a line then n==ans.size();
        if(ans.size()==n)
        {
            // cout<<ans.size()<<"\n";
            return ans;
        }
        
        // r to l
        for(int i=n-2;i>=0;--i) 
        {
            while(ans.size()>1 and navigation(ans[ans.size()-2],ans.back(),trees[i])<0) 
                
                ans.pop_back();
            ans.push_back(trees[i]);
        }
        
        ans.pop_back();
        return ans;
    }
};