#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<char,int> MPC;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define f for(int i=0;i<suits.size();++i)
#define ff for(int i=0;i<ranks.size();++i)

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        MPC s;MPC r;
//         string res="High Card";
//         for(auto it:ranks){r[it]++;}
//         for(auto it:suits){s[it]++;}
        
//         for(auto it:r){if(it.second==5){res="Flush";return res;}}
//         for(auto it:s){if(it.second>=3){res="Three of a Kind";}else if(it.second==2){res="Pair";}}
//         return res;
         f{s[suits[i]]++;r[ranks[i]]++;}
        string ans;
        if(s.size()==1)
        {
            for(auto it:s)
            {
                if(it.second==suits.size())
                {
                    ans="Flush";
                    return ans;
                }
            }
        }
        for(auto it:r)
        {
            if(it.second>=3)
            {
                ans="Three of a Kind";
                return ans;
            }
        }
        for(auto it:r)
        {
            if(it.second==2)
            {
                ans="Pair";
                return ans;
            }
        }
        ans="High Card";
        return ans;
    }
};