class Solution {
public:
    bool compare(const vector<int>&a,const vector<int>&b)
    {
        return a[0]<b[0];
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<vector<int>>v(n,vector<int>(4,0));
        for(int i=0;i<n;++i)
        {
            v[i][0]=positions[i];
            v[i][1]=healths[i];
            v[i][2]=(directions[i]=='L'?true:false);
            v[i][3]=i;
        }
        sort(v.begin(),v.end());
        //[idvals,health]
        vector<pair<int,int>>ans;
        int i=0;
        stack<pair<int,int>>s;
        while(i<n)
        {
            int vals=v[i][1],index=v[i][3];
            if(v[i][2])
            {
                while(vals && !s.empty())
                {
                    auto tp=s.top();
                    int node=tp.second;
                    int f=tp.first;
                    s.pop();
                    if(vals<node)
                    {
                        vals=-1,node--;
                        if(node)
                        {
                            s.push({f,node});
                            break;
                        }
                    }
                    else if(node==vals)
                    {
                        vals=-1;
                        break;
                    }
                    else
                    {
                        vals-=1;
                    }
                }
                if(vals>0)
                {
                    ans.push_back({index,vals});
                }
            }
            else
            {
                s.push({index,vals});
            }
            i++;
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
             s.pop();
        }
        sort(ans.begin(),ans.end());
        vector<int>res;
        for(auto &it:ans)
        {
            res.push_back(it.second);
        }
        return res;
    }
};