class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<ll,int> freqMap;
        
        for(auto el : nums){
            freqMap[el]++;
        }
        
        int ans = 1;
        
        for(auto p : freqMap){
            long long element = p.first;
            int freq = p.second;
            
            int count = 0;
            
            
            while(freqMap.find(element) != freqMap.end() && freqMap[element]){
                if(element == 1) count += freqMap[1];
                
                else if(freqMap[element] >= 2) count +=2;
                
                else if(freqMap[element] == 1) {count +=1; break;}
                
                freqMap[element] = 0;
                if(element > 1e6) break;
                
                element = element * element;
            }
            
            ans = max(ans,count - (count %2 == 0));
            
        }
        
        return ans;
        
        
    }
};