/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* func(vector<vector<int>>&grid,int i,int j,int n){
        
        int one=0,zero=0;
        for(int k=i;k<i+n;k++)
        {
            for(int m=j;m<j+n;m++)
            {
                if(grid[k][m]==0)
                {
                    zero=1;
                }
                else
                {
                    one=1;
                }
                
                if(zero and one)
                {          
                    auto root=new Node(0,false);
                    
                    root->topLeft=func(grid,i,j,n/2);
                    root->topRight=func(grid,i,j+n/2,n/2);
                    root->bottomLeft=func(grid,i+n/2,j,n/2);
                    root->bottomRight=func(grid,i+n/2,j+n/2,n/2);
                    return root;
                }
            }
        }
        return new Node(grid[i][j],true);
    }
    
    Node* construct(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        return func(grid,0,0,n);
    }
};