class MovieRentingSystem {
public:
    //1. movie->price->shop | 2.movie-.shop-.price
    unordered_map<int,map<int,set<int>>>rem;
    unordered_map<int,unordered_map<int,int>>prices;
    map<int,set<vector<int>>>ms;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& it:entries)
        {
            rem[it[1]][it[2]].insert(it[0]);
            prices[it[1]][it[0]]=it[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
        for(auto& it:rem[movie])
        {
            if(ans.size()==5)break;
            for(auto& it1:it.second)
            {
                ans.push_back(it1);
                if(ans.size()==5)break;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        if(prices[movie].find(shop)!=prices[movie].end())
        {
            int tmp=prices[movie][shop];//cost
            if(rem[movie].find(tmp)!=rem[movie].end() && rem[movie][tmp].find(shop)!=rem[movie][tmp].end())
            {
                ms[tmp].insert({shop,movie});
                rem[movie][tmp].erase(shop);
            }
        }
    }
    
    void drop(int shop, int movie) {
        vector<int>tmp={shop,movie};
        int chk=prices[movie][shop];
        ms[chk].erase(tmp);
        rem[movie][chk].insert(shop);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        for(auto& it:ms)
        {
            if(ans.size()==5)break;
            for(auto& it1:it.second)
            {
                ans.push_back(it1);
                if(ans.size()==5)break;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */