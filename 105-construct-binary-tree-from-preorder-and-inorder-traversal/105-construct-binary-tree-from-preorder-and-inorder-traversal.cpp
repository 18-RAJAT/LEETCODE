class Solution {
public:
    int idx=0;
    int find(vector<int>& inorder,int val,int str,int end){
        
        for(int i=str;i<=end;i++){
            if(inorder[i]== val){
                return i;
            }
        }
        
        return -1;
    }
    
    TreeNode* built(vector<int>& preorder,vector<int>& inorder,int str,int end){
       if(str>end){
           return NULL;
       }
        TreeNode* root= new TreeNode(preorder[idx]);
        idx++;
        if(str==end){
            return root;
        }
        
        
        int pos= find(inorder,root->val,str,end);
        
        root->left = built(preorder,inorder,str,pos-1);
        root->right= built(preorder,inorder,pos+1,end);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return built(preorder,inorder,0,inorder.size()-1);
    }
};