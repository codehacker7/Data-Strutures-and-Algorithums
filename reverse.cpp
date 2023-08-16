#include<iostream>
#include<vector>
using namespace std;


string reversewords(string s){

    vector<string> ans;

    string temp = "";
    string finalans = "";
    bool check = false;
    //   hello world
    for(int i=0;i<s.length();i++){

        
        // cout<<s[i]<<endl;
        if(s[i] == ' ' && check == false && temp != ""){
            cout<<"pushing "<<temp<<endl;
            ans.push_back(temp);
            temp = "";
            check = true;
            continue;
        }

        if(s[i] != ' '){
            temp += s[i];
            cout<<"Temp is "<<temp<<endl;
            check = false;
        }

 }
    
    if(temp != ""){
        cout<<"out temp is ";
    ans.push_back(temp);
    }

   

    for(int i=ans.size()-1;i>=0;i--){
        
       finalans += ans[i];
       if(i != 0){
       finalans += " ";
       }
    }

    return finalans;


    
}

int main(){



reversewords("  hello world  ");


    return 0;

}