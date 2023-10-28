class Solution
{
   public:
    string ReFormatString(string s, int k){
        int count =0;   
        string ans ="";
        for(int i=s.length()-1;i>=0;i--){

            char ch = s[i];

            if(ch == '-'){
                continue;
            }else{
                if(count < k){
                    char ch1 = toupper(ch);
                    ans = ch1 + ans;
                    count++;
                }
                if(count ==k ){
                    ans = "-" + ans;
                    count =0;
                }

            }

        }
       if (!ans.empty() && ans[0] == '-') {
            ans = ans.substr(1);
        }

        return ans;
    	
    	
    }
};