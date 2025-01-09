class Node
{
public:
    Node*children[26];
    int count;
    Node()
    {
        for(int i=0;i<26;++i)
        {
            children[i]=NULL;
        }
        count=0;
    }
};
class PrefixTree
{
private:
    Node*root;
public:
    PrefixTree()
    {
        root=new Node();
    }
    void Add(string& word)
    {
        Node*current=root;
        for(auto& c:word)
        {
            int idx=c-'a';
            if(current->children[idx]==NULL)
            {
                current->children[idx]=new Node();
            }
            current=current->children[idx];
            current->count++;
        }
    }

    int getPrefixCount(string& prefix)
    {
        Node*current=root;
        for(auto& c:prefix)
        {
            int idx=c-'a';
            if(current->children[idx]==nullptr)
            {
                return 0;
            }
            current=current->children[idx];
        }
        return current->count;
    }
};
class Solution{
public:
    int prefixCount(vector<string>&words,string prefix){
        PrefixTree tree;
        for(auto& it:words)
        {
            tree.Add(it);
        }
        return tree.getPrefixCount(prefix);
    }
};