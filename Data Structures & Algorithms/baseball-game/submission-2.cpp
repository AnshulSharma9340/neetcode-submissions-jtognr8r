class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(string op: operations){
            if(op == "C"){
                sum -= st.top();
                st.pop();
            }
            else if(op == "D"){
                int x = st.top() * 2;
                st.push(x);    
                sum += x;
            }
             else if(op == "+"){
               int a = st.top();   
                st.pop();
                int b = st.top();   
                st.push(a);        
                int x = a + b;      
                st.push(x);        
                sum += x;           
            }
            else{
                int x = stoi(op);   
                st.push(x);        
                sum += x;           
            }
        } 
        return sum;       
    }
};