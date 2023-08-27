#include<iostream>
using namespace std;

string moveAllX(string str){

	//axbxc

	if(str.length()==0){
		return "";
	}

	char ch = str[0];

	string ans = moveAllX(str.substr(1));

	if(	ch == 'x'){
		return ans + ch;
	}

	return ch + ans;
	






}

int main() {

	string str;
	cin>>str;

	string s = moveAllX(str);
	cout<<s<<endl;



	return 0;
}