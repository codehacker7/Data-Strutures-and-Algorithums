class Solution {
public:
    
    bool isPrefixSuffix(string original,string toBeChecked){
        
        //first we need to check prefix
        int i = 0;
        int j = original.length();
        string prefixFormed = toBeChecked.substr(i,j);
        
        if(prefixFormed != original){
            return false;
        }
        
        i = toBeChecked.size() - original.length();
        j = toBeChecked.size();
        
        string suffixFormed = toBeChecked.substr(i,j);
        
        if(prefixFormed != suffixFormed){
            return false;
        }
        return true;
        
    } 
    
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int count = 0;
        for(int i = 0; i < words.size();i++){
            for(int j = i + 1 ; j < words.size();j++){
                string original = words[i];
                string toBeChecked = words[j];
                
                if(isPrefixSuffix(original,toBeChecked)){
                    count++;
                }
            }
        }
        return count;
        
    }
};