class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>pairs;
        vector<vector<int>>point=points;
        for(auto& it:point)
        {
            pairs.emplace_back(it[0],it[1]);
        }
        function<bool(pair<int,int>&,pair<int,int>&)>cmp=[&](pair<int,int>&a,pair<int,int>&b)->bool
        {
            if(a.first==b.first)
            {
                return a.second<b.second;
            }
            return a.first<b.first;
        };
        function<bool(pair<int,int>&,pair<int,int>&)>recur=[&](pair<int,int>&a,pair<int,int>&b)->bool
        {
            return a.first<=b.first  && a.second>=b.second;
        };
        function<bool(pair<int,int>&,pair<int,int>&,pair<int,int>&)>check=[&](pair<int,int>&point,pair<int,int>&top_left,pair<int,int>&bottom_right)->bool
        {
            int x=point.first;
            int y=point.second;
            int reactangle1=top_left.first;
            int reactangle2=top_left.second;
            int reactangle3=bottom_right.first;
            int reactangle4=bottom_right.second;
            if(!recur(top_left,bottom_right))
            {
                return false;
            }
            if(reactangle1<=x && x<=reactangle3 && reactangle2>=y && y>=reactangle4)
            {
                return true;
            }
            return false;
        };
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(recur(pairs[i],pairs[j]))
                {
                    int flag=1;
                    for(int k=0;k<n;k++)
                    {
                        if(k==i || k==j)
                        {
                            continue;
                        }
                        if(check(pairs[k],pairs[i],pairs[j]))
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};