class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        int n = searchWord.size();
        vector<vector<string>> res(n);
        for(int i = 0; i < n ; ++i){
            string s = searchWord.substr(0, i + 1);
            int times = 0; 
            for(auto &str : products){
                if(str.find(s) == 0){
                    times ++;
                    res[i].push_back(str);
                }
                if(times == 3)
                    break;
            }
        }
        return res;
    }
};