class Solution {
public:
    struct Node
    {
        int index,depth;
        int nxt[26];
        Node()
        {
            index=-1,depth=1e9;
            for(int i=0;i<26;++i)
            {
                nxt[i]=-1;
            }
        }
    };

    vector<Node>trie;

    void insert(string ert,int index,int pos)
    {
        int node=0;

        for(int i=0;i<ert.size();++i)
        {
            int index_vals=ert[i]-'a';

            if(trie[node].nxt[index_vals]==-1)
            {
                trie[node].nxt[index_vals]=trie.size();
                trie.push_back(Node());
            }

            node=trie[node].nxt[index_vals];

            if(trie[node].depth>ert.size())
            {
                trie[node].depth=ert.size();
                trie[node].index=pos;
            }
        }
    }

    int countPrefix(string ert)
    {
        int node=0;

        for(int i=0;i<ert.size();++i)
        {
            int index_vals=ert[i]-'a';

            if(trie[node].nxt[index_vals]==-1)
            {
                if(i==0)
                {
                    return -1;
                }

                break;
            }

            node=trie[node].nxt[index_vals];
        }

        return trie[node].index;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        trie.push_back(Node());

        int m=wordsContainer.size();

        for(int i=0;i<m;++i)
        {
            reverse(wordsContainer[i].begin(),wordsContainer[i].end());
            insert(wordsContainer[i],i,i);
        }

        vector<int> ans;

        int res=-1;
        int ert=1e9;

        for(int i=0;i<m;++i)
        {
            int sza=wordsContainer[i].size();

            if(sza<ert)
            {
                res=i;
                ert=sza;
            }
        }

        int n=wordsQuery.size();

        for(int i=0;i<n;++i)
        {
            reverse(wordsQuery[i].begin(),wordsQuery[i].end());

            ans.push_back(countPrefix(wordsQuery[i]));

            if(ans.back()==-1)
            {
                ans[i]=res;
            }
        }

        return ans;
    }
};