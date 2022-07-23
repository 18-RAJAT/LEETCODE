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


class NumberContainers {
public:
    MPII mp;
    NumberContainers() {
        mp.clear();
    }
    
    void change(int index, int number) {
        mp[index]=number;
    }
    
    int find(int number) {
        for(auto it:mp){if(it.second==number){return it.first;}}
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */