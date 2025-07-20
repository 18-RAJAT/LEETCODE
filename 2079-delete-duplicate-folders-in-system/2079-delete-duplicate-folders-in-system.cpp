class Solution {
private:
    struct TrieNode
    {
        unordered_map<string,TrieNode*>children;
        string s;
        bool ok=false;
        TrieNode(string n=""):s(n){}
    };
    TrieNode* root=new TrieNode();
    unordered_map<string,vector<TrieNode*>>mp;

    void check(vector<string>& path)
    {
        TrieNode* curr=root;
        for(auto& it:path)
        {
            if(!curr->children.count(it))
            {
                curr->children[it]=new TrieNode(it);
            }
            curr=curr->children[it];
        }
    }
    string recur(TrieNode* node)
    {
        if(node->children.empty())
        {
            return "";
        }
        vector<pair<string,string>>vp;
        for(auto& [F,S]:node->children)
        {
            vp.push_back({F,recur(S)});
        }
        sort(vp.begin(),vp.end());
        string key;
        for(auto& [it,s]:vp)
        {
            key+="("+it+s+")";
        }
        mp[key].push_back(node);
        return key;
    }
    void sol(TrieNode* node,vector<string>& curr,vector<vector<string>>& res)
    {
        for(auto& [F,S]:node->children)
        {
            if(S->ok)
            {
                continue;
            }
            curr.push_back(F);
            res.push_back(curr);
            sol(S,curr,res);
            curr.pop_back();
        }
    }
    void duplicate()
    {
        for(auto& [F,S]:mp)
        {
            if(S.size()>=2)
            {
                for(TrieNode* node:S)
                {
                    node->ok=true;
                }
            }
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for(auto& it:paths)check(it);
        recur(root);
        duplicate();
        vector<vector<string>>res;
        vector<string>curr;
        sol(root,curr,res);
        return res;
    }
};