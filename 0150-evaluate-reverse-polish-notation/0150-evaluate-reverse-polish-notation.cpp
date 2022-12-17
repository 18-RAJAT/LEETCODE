#define ll long long int

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
       
       for(auto &i:tokens)
       {
           if(i!="+"&&i!="-"&&i!="*"&&i!="/")
           {
              
               st.push(stoi(i));
           }
           else
           {
               int num1=st.top();
               st.pop();
               
               int num2=st.top();
               st.pop();
               
               if(i=="+") st.push(num2+num1);
               if(i=="-") st.push(num2-num1);
               if(i=="*") st.push((ll)num2*num1);
               if(i=="/") st.push(num2/num1);

           }
       } 
       int ans=st.top();
       return ans;
    }
};