class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int i=0;i<asteroids.size();i++){

            if(asteroids[i] >= 0){
                st.push(asteroids[i]);
            }else{
                // make sure to check if st.top()>0 because i forgot that
                while(!st.empty() && st.top() > 0 &&  st.top() < abs(asteroids[i]) ){ 
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();                
                } 
                // the below condition is wrong
                // else if(!st.empty() && st.top() > abs(asteroids[i])){
                //     continue;
                 
                 else if(st.empty() || st.top() < 0){ // be careful with st.top()<0 condition
                    st.push(asteroids[i]);
                } 

                }

                

            }


           

            vector<int> answer(st.size());
            for(int i=st.size()-1;i>=0;i--){
                answer[i] = st.top();
                st.pop();
            }


            return answer;
    
    
    
    
    
        }
        
    
};