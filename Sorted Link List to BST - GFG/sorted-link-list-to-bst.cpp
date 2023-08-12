//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    // TNode* ans=nullptr;
    
    TNode* sortedListToBST(LNode *head) {
        //code here
        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return new TNode(head->data);
        }
        LNode*slow=head,*fast=head->next;
        LNode*prev=nullptr;
        // while(fast && fast->next->next)
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            // prev=slow;
            slow=slow->next;
        }
        // LNode*root=new TNode(slow->next);
        LNode* root=slow->next; // Get the middle element node
        slow->next=nullptr;//initaly
        TNode* rootNode=new TNode(root->data); // Create a new TNode for the root

        rootNode->left=sortedListToBST(head);
        rootNode->right=sortedListToBST(root->next);
        
        return rootNode;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends