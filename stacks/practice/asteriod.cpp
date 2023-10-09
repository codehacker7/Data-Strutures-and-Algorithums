class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            
            if(asteroids[i] >=0 ){ // that means collision cannot happen 
               st.push(i);
            }
            else{

            while(!st.empty() && asteroids[st.top()] >= 0 &&                    abs(asteroids[st.top()]) < abs(asteroids[i]))         
     {
                st.pop(); // destory the asteriod
      }
    if(!st.empty() && asteroids[st.top()]>=0 && abs(asteroids[st.top()]) <= abs(asteroids[i])){
            st.pop();
        }
      else if(!st.empty() && asteroids[st.top()] < 0){
          st.push(i);
      } else if(st.empty()){ // this means stack is empty if we reached in here
            st.push(i);
      }
    
        //now i think about a case where [-2,-4,-6] everything is negative
                   
        }
        }
    

    vector<int> answer(st.size());

    for(int i=st.size()-1;i>=0;i--){
        answer[i] = asteroids[st.top()];
        st.pop();
    }

    return answer;



    }
};