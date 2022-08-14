#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int, int> PII;
typedef vector<ll> VI;
typedef vector<vector<ll>> VII;
typedef vector<vector<string>> VIS;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<ll,ll> MPII;
typedef map<string,ll> MPSI;
typedef priority_queue<pair<ll,pair<ll,ll>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef unordered_map<string, unordered_set<string>> UMPSS;
typedef unordered_set<string> SETI;
typedef queue<string> QS;
typedef multiset<ll> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define CHAR(ch) for(char x = 'a'; x <= 'z'; ++x)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


// class Solution {
// public:
//     VVS result;//store all the possible paths
//     void dfs(string& bw,string& ew,UMPSS& adj,VS& path)
//     {
//         path.PB(bw);//push current word
//         if(bw==ew){result.PB(path);path.pop_back();return;}
        
//         for(auto it:adj[bw]) dfs(it,ew,adj,path);
//         path.pop_back(); //pop current word to backtrack
//     }
    
//     vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
//         //Adjacency list
//         UMPSS adj;
//         //Insert word inside the set
//         SETI dict(wl.begin(),wl.end());
        
//         //Step-1
//         //Queue string for bfs traversal
//         QS que;
//         //push start node bw
//         que.push(bw);
//         //traversal like key-string,node and value-level(dfs)
//         MPSI visited;
//         //start node will always be at level 0
//         visited[bw]=0 ;
        
//         while(!que.empty())
//         {
//             string current=que.front();
//             que.pop();
//             string temp=current;
//             //for all the characters
//             f1(i,0,current.size())
//             {
//                 //try all the 26 possible chracters contains
//                 CHAR(ch)
//                 {
//                     if(temp[i]!=x) //skip if letter is same as in original word
//                     continue;// break;
                    
//                     temp[i]=x;
//                     //find the new word present or not in wordlist
//                     if(dict.count(temp)>0)
//                     {
//                         //check if the new word is already visited
//                         if(visited.count(temp)==0)
//                         {
//                             visited[temp]=visited[current]+1;
//                             que.push(temp);
//                             adj[current].insert(temp);
//                         }
//                         //if already visited and the new word is the child then (we should always move down)
//                         else if(visited[temp]==visited[current]+1)
//                             adj[current].insert(temp);
//                     }
//                 }
//                 //temp to current remove back
//                 temp[i]=current[i];
//             }
//         }
        
//         //Step-2
//         VS path;
//         //finding all the minimum paths with minimum depth
//         dfs(bw,ew,adj,path);
//         return result;
//     }
// };



class Solution {
public:
    
    void genPaths(const string &word, const string& beginWord, const unordered_map<string, unordered_set<string>> &parents, vector<string> &acc, vector<vector<string>> &sln) {
        if (word == beginWord) {
            auto path = acc;
            path.push_back(beginWord);
            reverse(path.begin(), path.end());
            sln.push_back(path);
        } else {
            acc.push_back(word);
            for (auto &w : parents.at(word)) {
                genPaths(w, beginWord, parents, acc, sln);
            }
            acc.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // convert for O(1) word presence lookup.
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // the standard BFS bookkeeping. we treat each word as a graph node.
        queue<string> q;
        unordered_set<string> visited;
        
        // initialize BFS
        q.push(beginWord);
        visited.insert(beginWord);
        
        // during BFS, this map records the parent word nodes for each word W,
        // those parents are the words that can transform to word W.
        unordered_map<string, unordered_set<string>> parents;

        while (!q.empty()) {
            // each iteration of the while loop proccess a complete BFS level.
            // save the current level node count because we will push new
            // nodes after visiting the current level nodes.
            auto lvl_count = q.size();
            
            // if we discover endWord, then we discovered the shortest path.
            // break from the loop after visiting all nodes in the current level.
            // going levels deeper in BFS has no value.
            bool finished = false;
            unordered_set<string> lvl_visited;
            
            // the next lvl_count nodes in the queue are exactly the nodes in the
            // current level.
            for (int i = 0; i < lvl_count; ++i) {
                auto curr = q.front();
                q.pop();
                
                // generate all possible transformations for W.
                string w = curr;
                for (int j = 0; j < w.size(); ++j) {
                    char cw = w[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        w[j] = c;
                        // skip invalid transformations.
                        if (dict.count(w) == 0) continue;
                        // this level has the answer.
                        else if (w == endWord) finished = true;
                        else if (visited.count(w) != 0) continue;
                        else if (lvl_visited.count(w) == 0) {
                            q.push(w);
                            lvl_visited.insert(w);
                        }
                        // record how we reached this node to help us
                        // building the shortest path later.
                        parents[w].insert(curr);
                    }
                    // revert the word modification.
                    w[j] = cw;
                }
            }
            if (finished) break;
            visited.insert(lvl_visited.begin(), lvl_visited.end());
        }
        
        vector<vector<string>> sln;
        // if the endWord has no parent, then it is unreachable and there is no
        // path discovered from beginWord to endWord.
        if (!parents[endWord].empty()) {
            vector<string> acc;
            genPaths(endWord, beginWord, parents, acc, sln);    
        }
        
        return sln;
    }
};