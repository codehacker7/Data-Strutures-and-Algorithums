class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> wordSize;
        
        for(string w : words){
            wordSize.push_back(w.length());
        }
        sort(wordSize.begin(),wordSize.end());
       
        
        map<char,int> freq;
        for(auto w : words){
            for(char ch : w){
                freq[ch]++;
            }
        }
        
        int even = 0, odd = 0, n = words.size();
        
        for(auto p : freq){
            even = even + p.second/2;
            odd = odd + p.second%2;
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(wordSize[i] %2 == 1){
                if(odd){
                    odd--;
                }else{
                    even--;
                    odd = odd + 2;
                    odd--;
                }
            }
            
            
            if(even < wordSize[i]/2 )break;
            even -= wordSize[i]/2;
            ans++;
        }
        
        return ans;
        
    }
};