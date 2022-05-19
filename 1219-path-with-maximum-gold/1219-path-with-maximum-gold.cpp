#define ll long long
#define f(a,b) for(int i=a;i<b;i++)
#define f2(x,a,b) for(int x=a;x<b;x++)
#define fr(b,a) for(int i=b;i>=a;i--)
#define fit(nums) for(auto &it:nums)
#define v vector
#define p priority_queue
#define um unordered_map
#define us unordered_set
#define pb push_back
#define ppb pop_back
#define TN TreeNode
#define LN ListNode

class Solution {
public:
        int mG=0,ans=0;
        void gold(int i,int j,v<v<int>> &grid){
                ans=max(mG,ans);
                if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return;
                int curr=grid[i][j];
                mG+=grid[i][j];
                grid[i][j]=0;
                gold(i-1,j,grid);
                gold(i+1,j,grid);
                gold(i,j-1,grid);
                gold(i,j+1,grid);
                grid[i][j]=curr;
                mG-=curr;
        }
        
        int getMaximumGold(vector<vector<int>>& grid) {
                f(0,grid.size()){
                        mG=0;
                        f2(j,0,grid[0].size()){
                                if(grid[i][j]!=0)gold(i,j,grid);
                        }
                }
                return ans;
    }
        
};