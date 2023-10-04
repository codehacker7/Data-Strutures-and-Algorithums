#include<iostream>

using namespace std;

void allPerm(string s,int index,string copy,vector<string> &vec){

    if(index == s.length()){
        if(s >= copy){
            vec.push_back(s);
        return;
        }
    }

    for(int i=index;i<s.length();i++){
        swap(s[i],s[index]);
        allPerm(s,index+1,copy,vec);
        swap(s[i],s[index]);

    }

}

int main(){

    string s = "abc";
    vector<string> vec;
    string copy = s;
    allPerm(s,0,copy,vec);

    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }


    return 0;
}