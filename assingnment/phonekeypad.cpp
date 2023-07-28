#include<iostream>
using namespace std;


void getAllCombinations(string nums[], int index,string number,string answer){


    if(index == number.length()){
        cout<<answer<<endl;
        return;
    }




    int length = nums[ number[index] - '0'- 1].length();
    
    for(int i=0;i<length;i++){
        
        answer +=  nums[number[index] - '0' - 1][i];
        getAllCombinations(nums,index+1,number,answer);
        answer = answer.substr(0,answer.length()-1);

    }






}

int main(){

    string nums[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    
    getAllCombinations(nums,0,"23","");




    return 0;
}