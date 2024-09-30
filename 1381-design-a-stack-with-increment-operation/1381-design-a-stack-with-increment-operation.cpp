class CustomStack {
    int*stack;
    int size,top;
public:
    CustomStack(int maxSize) {
        size=maxSize;
        stack=new int[size];
        top=-1;
    }
    
    void push(int x)
    {
        if(top<size-1)stack[++top]=x;
    }
    
    int pop()
    {
        return top==-1?-1:stack[top--];
    }
    
    void increment(int k,int val)
    {
        for(int i=0;i<min(k,top+1);++i)stack[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */