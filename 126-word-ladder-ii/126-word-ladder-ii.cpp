class Solution {
private:
    string target;
    
public:
    void dfs(string current, int l, unordered_map<string,vector<string>> &g, vector<string> &run, vector<vector<string>> &output){
        if (l == 0){
            if (current == target)
                output.push_back(run);
            return;
        }
        for (auto i: g[current]){
            run.push_back(i);
            dfs(i,l-1,g,run,output);
            run.pop_back();
        }
        return;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for (auto i: wordList){
            dict.insert(i);
        }
        dict.insert(beginWord); target = beginWord;
        if (dict.find(endWord) == dict.end()){
            return {};
        }
        //directed adjancency list of words
        unordered_map<string,vector<string>>paths;
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        bool broke = false;
        while(!q.empty()){
            ++level;
            int S = q.size();
            for (int k = 0; k < S; ++k){
                string s = q.front();
                q.pop();
                if (dict.find(s) == dict.end()){
                    continue;
                }
                dict.erase(s);
                string t = s;
                for (int i = 0; i < s.size(); ++i){
                    char c = s[i];
                    for (int j = 0; j < 26; ++j){
                        s[i] = 'a' + j;
                        if (dict.find(s) != dict.end()){
                            q.push(s);
                            paths[s].push_back(t);
                            if (s == endWord){
                                broke = true;
                                //horrible goto statement, useful for exiting nested loops though
                                goto breakpoint;
                            }
                        }
                    }
                    s[i] = c;
                }
                breakpoint:;
            }
            if (broke) {
                break;
            }
        }
        //check to see whether any path was found using bfs
        if (!broke){
            return {};
        }
        vector<string> run = {endWord};
        vector<vector<string>> output;
        //perform dfs from the end word back to the start word using paths found from bfs
        dfs(endWord,level,paths,run,output);
        
        for (auto &i:output) reverse(i.begin(),i.end());
        
        return output;
    }
};