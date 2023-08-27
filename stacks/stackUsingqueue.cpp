#include<iostream>
#include<queue>
using namespace std;

class stack{

    public:

    queue<int> q1;
    queue<int> q2;
    
    void push(int data){

        if(q1.empty() && q2.empty()){
            q1.push(data);
        }
        else if(q1.empty() && !q2.empty()){
            q2.push(data);
        }else{
            q1.push(data);
        }


    }

    void pop(){
         //stack is empty
         if(q1.empty() && q2.empty()){
         
         }else if(q1.empty() && !q2.empty()){
            //transfer n-1 elements to q1

            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();  
          }

          q2.pop();
         } else{
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();  
          }

          q1.pop();

         }


    }

    int top(){
//  if(q1.empty() && q2.empty()){
         
/*   */ if(q1.empty() && !q2.empty()){
            //transfer n-1 elements to q1

            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();  
          }
            int ans = q2.front();
            q1.push(ans);
            q2.pop();
            return ans;
         } else{
                while(q1.size() > 1){
                    q2.push(q1.front());
                    q1.pop();  
          }
          int ans = q1.front();
          q2.push(ans);
          q1.pop();
          return ans;

         }



    }


    int size(){


        return max(q1.size(),q2.size());
    }

    bool empty(){
        return q1.empty() && q2.empty();
    }




};
