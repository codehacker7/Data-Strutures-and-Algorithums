#include<iostream>
#include<vector>
#include<stack>
using namespace std;
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] >= 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                } else if (st.top() == abs(asteroids[i])) {
                    st.pop(); // Both asteroids explode
                }
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }

//more intutuive version

    class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int i = 0; i < asteroids.size();i++){
            if(asteroids[i] >= 0){
                st.push(asteroids[i]);
            }else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    //if the asteriod coming is greater than our asteriods in the stack then obviously destroy them
                    st.pop();        
                }
                if(st.empty()){
                   st.push(asteroids[i]);
                }else if(st.top() > 0 && st.top() == abs(asteroids[i])){
                    st.pop();
                }else if(st.top() > 0 && st.top() < abs(asteroids[i])){
                    continue;
                }else if(st.top() > 0 && st.top() > abs(asteroids[i])){
                    continue;
                }else{
                     st.push(asteroids[i]);
                }
            }
        }

        if(st.size() == 0){
            return {};
        }

        vector<int> ans(st.size());
        int n = st.size() - 1;

        while(!st.empty()){
            ans[n] = st.top();
            st.pop();
            n--;
        }

        return ans;




        
    }
};
