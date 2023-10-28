 string encryptString(string s) {
        // code here
        
        if(s.length() == 0){
            return "";
        }
        char ch = s[0];
        int count = 1;
        string ans = "";
       for(int i=1;i<s.length();i++){
           if(s[i] == s[i-1]){
               count++;
           } else{
                 ans = ans + ch;
                 string hex = "";
                 
                 while(count !=0){
                     int rem = count%10;
                     if(rem < 10){
                         hex += ('0'+rem);
                     }else{
                          hex += ('a' + (rem-10)); 
                     }
                     count = count/16;
                 }
                 
                 ans = ans+hex;
                 ch=s[i];
                 count = 1;
           }
       }

    return ans;
    }