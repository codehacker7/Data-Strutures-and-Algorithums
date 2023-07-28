#include<iostream>
using namespace std;

    string nums[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void getAllCombinations(string digits,string answer,int index,int length){

        if(index == length){
            cout<<answer<<endl;
            return;
        }

        char ch = digits[index];
        int ch1 = ch - '0';

        int number1 = nums[ch1];
        int number = number1 - 1;
        string value = nums[number];
       
        for(int i=0; i < value.length(); i++){
        
        answer += nums[(digits[index] - '0')-1][i];

        getAllCombinations(digits,answer,index+1,length);

        answer = answer.substr(0,answer.length()-1);

        }

    }


int  main(){


   string digits = "abc";

    getAllCombinations(digits,"",0,digits.length());

    return 0;
}