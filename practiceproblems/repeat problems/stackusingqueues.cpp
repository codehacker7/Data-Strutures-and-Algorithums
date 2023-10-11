#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
  queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
        
        if(q1.empty() && q2.empty()){
            q1.push(x);
        }else if(!q1.empty() && q2.empty()){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }
    
    int pop() {
        if(q1.empty() && q2.empty()){
            return -1;

        }else if(!q1.empty() && q2.empty()){
           while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
           }
           int elem = q1.front();
           q1.pop();
           return elem;
        }else{
            while(q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
           }
           int elem = q2.front();
           q2.pop();
           return elem;
        }
        
    }
    
    int top() {
         if(q1.empty() && q2.empty()){
             return -1;
        }else if(!q1.empty() && q2.empty()){
           while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
           }
           int elem = q1.front();
           q1.pop();
           q2.push(elem);
           return elem;
        }else{
            while(q2.size() > 1){
            q1.push(q2.front());
            q2.pop();
           }
           int elem = q2.front();
           q2.pop();
           q1.push(elem);
           return elem;
        }
        
    }
    
    bool empty() {

        return q1.empty() && q2.empty();
        
    }
};
