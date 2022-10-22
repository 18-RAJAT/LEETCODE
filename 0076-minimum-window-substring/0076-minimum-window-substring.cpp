class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> mp;
        int n = s.size();
        for(char i : t) mp[i]++;    // mantain count of each char of t
        int i = 0, j = 0, mn = INT_MAX;
        
        int count = mp.size();
        string ans = "";
        
        while(j < n){
            if(mp.find(s[j]) != mp.end()) {     // if that char is found reduce it's count
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;     //if that char's count got to 0 then we've completely found one char so reduce var count
            }
            
            while(count == 0){
                if(mn > j-i+1){
                    mn = min(mn, j-i+1);     // change min as found a valid canditate for ans
                    ans = s.substr(i,j-i+1);
                }
                if(mp.find(s[i]) != mp.end()){    //optimize further and slide the window
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};