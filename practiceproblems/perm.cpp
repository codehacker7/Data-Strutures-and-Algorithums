#include<iostream>
#include<vector>
using namespace std;

void calculatePermuations(string str,int index,int n,vector<string> &permutations){
		if(index == n){
			permutations.push_back(str);
			return;
		}

      	for(int i=index;i<n;i++){
			swap(str[index],str[i]);
			calculatePermuations(str,index+1,n,permutations);
			swap(str[index],str[i]);
		}
}


int main() {


	string str;
	cin>>str;

	int n = str.length();

    // string intial = str;


	vector<string> permutations;


	calculatePermuations(str,0,n,permutations);




    	vector<string> answer;



	for(int i=0;i< permutations.size() ;i++){
		
		if(permutations[i] > str){
			answer.push_back(permutations[i]);
		}
	}
    for(int i=1;i<answer.size();i++){
		int j = i-1;
		string temp = answer[i];
		for(;j>=0;j--){
			if(answer[j]>temp){
				answer[j+1] = answer[j];
			}else{
				break;
			}
		}
		answer[j+1] = temp;
	}


    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }




	return 0;
}