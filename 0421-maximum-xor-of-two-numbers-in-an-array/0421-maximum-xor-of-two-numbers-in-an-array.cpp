struct TrieNode
{
    TrieNode* child[2];
    bool hasChild(int bit)
    {
        return child[bit]!=nullptr;
    }
    TrieNode* getChild(int bit)
    {
        return child[bit];
    }
    void setChild(int bit,TrieNode* node)
    {
        child[bit]=node;
    }
};
class Trie
{
    TrieNode* root;
    public:
    Trie()
    {
        root=new TrieNode();
    }
    void insert(int num)
    {
        TrieNode* cur=root;
        for(int bit=31;~bit;--bit)
        {
            int b=(num>>bit)&1;
            if(!cur->hasChild(b))
            {
                cur->setChild(b,new TrieNode());
            }
            cur=cur->getChild(b);
        }
    }
    int getMaxXor(int num)
    {
        TrieNode* cur=root;
        int mxXor=0;
        for(int bit=31;~bit;--bit)
        {
            int b=(num>>bit)&1;
            /*
                (1-b)->trying to maximize the XOR at each bit position
                0 → we want to go to 1 (because 0 ^ 1 = 1)
                1 → we want to go to 0 (because 1 ^ 0 = 1)
                1 - b->>[If b == 0 -> 1 - 0 = 1 ||| If b == 1 -> 1 - 1 = 0]
            */
            if(cur->hasChild(1-b))
            {
                mxXor|=(1<<bit);
                cur=cur->getChild(1-b);
            }
            else
            {
                cur=cur->getChild(b);
            }
        }
        return mxXor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto& it:nums)trie.insert(it);
        int ans=0;
        for(auto& it:nums)
        {
            ans=max(ans,trie.getMaxXor(it));
        }
        return ans;
    }
};