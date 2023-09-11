class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {

        if(s1.empty() && s2.empty()){
            s1.push(x);
        }else if(s1.empty() && !s2.empty()){
            s2.push(x);
        }else{
            s1.push(x);
        }
        
    }
    void insertAtBottom(stack<int> &s,int t){
    if(s.empty()){
        s.push(t);
        return;
    }
    int t2 = s.top();
    s.pop();
    insertAtBottom(s,t);
    s.push(t2);
}   


void reverseStack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int t = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,t);

}
    
    int pop() {

        if(s1.empty() && s2.empty()){
            return -1;

        } else if(s1.empty() && !s2.empty()){
            while(s2.size() > 1){
                s1.push(s2.top());
                s2.pop();
            }
            int ans = s2.top();
            s2.pop();
            reverseStack(s1);
            return ans;

        } else{
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
            int ans = s1.top();
            s1.pop();
            reverseStack(s2);
            return ans;

        }
        
    }

    int peek() {

        if(s1.empty() && s2.empty()){
            return -1;

        } else if(s1.empty() && !s2.empty()){
            while(s2.size() > 1){
                s1.push(s2.top());
                s2.pop();
            }
            int ans = s2.top();
            s2.pop();
            // s1.push(ans);
            reverseStack(s1);
            insertAtBottom(s1,ans);
            return ans;

        } else{
            while(s1.size() > 1){
                s2.push(s1.top());
                s1.pop();
            }
            int ans = s1.top();
            s1.pop();
             reverseStack(s2);
            insertAtBottom(s2,ans);
            return ans;

        }
        
    }
    
    bool empty() {

        return s1.empty() && s2.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */