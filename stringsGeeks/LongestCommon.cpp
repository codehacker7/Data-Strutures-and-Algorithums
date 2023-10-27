class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
      
        string finalans = "";
        for(int i=0; i < arr.size();i++){
            char ch = arr[0][i];
            bool match = true;
            for(int j=1;j<arr.size();j++){

                if(i > arr[j].size() || ch != arr[j][i]){
                    match = false;
                    break;
                }
            }

            if(match == true){
                finalans = finalans + ch;
            }
        }
        return finalans;
        
    }
};