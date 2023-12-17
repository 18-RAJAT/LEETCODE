class FoodRatings {
public:
    map<string,set<pair<int,string>>>mp;
    unordered_map<string,string>fc;
    unordered_map<string,int>fr;
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        mp.clear();
        fc.clear();
        fr.clear();
        for(int i=0;i<f.size();i++){
            mp[c[i]].insert({r[i],f[i]});
            fc[f[i]]=c[i];
            fr[f[i]]=r[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c=fc[food];
        int r=fr[food];
        mp[c].erase({r,food});
        mp[c].insert({newRating,food});
        fr[food]=newRating;
        
        
    }
    
    string highestRated(string cuisine) {
        int r=(mp[cuisine].rbegin())->first;
        string a="";
       for(auto it=mp[cuisine].rbegin();it!=mp[cuisine].rend();it++){
           if(it->first>r){
               r=it->first;
               a=it->second;
            }
           else if(it->first==r)
           {
               a=it->second;
           }
           else break;
       }
        return a;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */