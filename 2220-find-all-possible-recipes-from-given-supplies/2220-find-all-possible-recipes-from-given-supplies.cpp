class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<string>ans;
        int tp=1;
        while(tp)
        {
            tp=0;
            for(int i=0;i<recipes.size();++i)
            {
                if(st.count(recipes[i]))continue;
                int ok=1;
                for(auto& it:ingredients[i])
                {
                    if(!st.count(it))
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    st.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    tp=1;
                }
            }
        }
        return ans;
    }
};