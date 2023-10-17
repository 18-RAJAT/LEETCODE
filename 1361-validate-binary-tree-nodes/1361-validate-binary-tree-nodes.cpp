class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>parent(n,-1);
        // iota(parent.begin(),parent.end(),0);
        
        function<int(vector<int>&,int)>find=[&](vector<int>&parent,int node)->int
        {
            if(parent[node]==-1)
            {
                return node;
            }
            return parent[node]=find(parent,parent[node]);
        };
        for(int i=0;i<n;++i)
        {
            if(~leftChild[i])
            {
                if(find(parent,i)==find(parent,leftChild[i]))
                {
                    return false;
                }
                parent[leftChild[i]]=i;
            }
            if(~rightChild[i])
            {
                if(find(parent,i)==find(parent,rightChild[i]))
                {
                    return false;
                }
                parent[rightChild[i]]=i;
            }
        }
        int count_root=0;
        for(int i=0;i<n;++i)
        {
            if(parent[i]==-1)
            {
                count_root++;
                if(count_root>1)
                {
                    return false;//more than one root node
                }
            }
        }
        return count_root==1?true:false;
    }
};