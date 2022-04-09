class Solution {
    
    struct node
    {
        int Number,Frequency;
        node(int a,int b)
        {
            Number = a;
            Frequency = b;
        }
    };
    
    struct Compare
    {
        bool operator()(node const & a , node const & b)
        {
            return a.Frequency < b.Frequency;
        }
    
};
    
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        
    unordered_map<int,int>mp;
        
        //Step::1
        
        for(int Element : nums)
            mp[Element] += 1;
        
        //Step::2
        
        priority_queue<node,vector<node>,Compare>heap;
        
        for(auto it : mp)
        
        heap.push(node(it.first,it.second));
        vector<int>ans;
        
        //Step:3
        
        while(k--)
        {
            node temp = heap.top();
            heap.pop();
            
            ans.push_back(temp.Number);
        }
        return ans;
    }
};