class Solution {
  public:
    
    void allSubsequences(string s,int index,vector<string> &subseq,string output,int length){
        if(index == length){
            subseq.push_back(output);
            return;
        }
        allSubsequences(s,index+1,subseq,output,length);
        output+= s[index];
        allSubsequences(s,index+1,subseq,output,length);

    }
  
    string findLongestWord(string S, vector<string> d) {
        // code here
        
        vector<string> subseq;
        int length = S.length();
        
        allSubsequences(S,0,subseq,"",length);
        
        int maxLen = INT_MIN;
        string ans = "";
        for(int i=0;i<d.size();i++){
            
            if(find(subseq.begin(), subseq.end(),d[i]) != subseq.end()){
                if(d[i].length() > maxLen){
                     maxLen = max(maxLen,d[i].length());
                     ans = d[i];
                }
                
               
            }
        }
        
        return ans;
    }
}