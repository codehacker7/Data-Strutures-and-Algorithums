 bool isIsomorphic(string s, string t) { 

        if(s.length() != t.length()){
            return false;
        }

        for(int i=0;i<s.length();i++){
            char ch = s[i];// e
            char ch1 = t[i]; //a

            for(int j = 0;j<s.length();j++){
                if(i != j && s[j] == ch && t[j] != ch1){
                    return false;
                }
            }
            

        }

         for(int i=0;i<t.length();i++){
            char ch = t[i];// e
            char ch1 = s[i]; //a

            for(int j = 0;j<s.length();j++){
                if(i != j && t[j] == ch && s[j] != ch1){
                    return false;
                }
            }
            

        }


        return true;
        
    }