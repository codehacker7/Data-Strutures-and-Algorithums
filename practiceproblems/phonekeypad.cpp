#include<iostream>
using namespace std;
    string nums[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void getAllCombinations(string s,int index,int length,string output){

        if(index == length){
            cout<<output<<endl;
            return;
        }

        int length1 = nums[s[index]-'0'].length();
        for(int i=0; i<length1 ;i++){
        output = output +  nums[s[index] - '0'][i];
        getAllCombinations(s,index+1,length,output);
        output = output.substr(0,output.length()-1);
        }
    }


int main(){

    string s = "23";
    int n = s.length();
    getAllCombinations(s,0,n,"");
}