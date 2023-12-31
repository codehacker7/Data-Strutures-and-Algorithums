#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int> s;
    //Insertation : 0{LOGN}
    //DELETEION : 0(LOGN)
    //AUTOMATICALLY SORTS THE VALUES
    //will not accept the duplicate values
    
    s.insert(3);
    s.insert(2);
    s.insert(1); 
    s.insert(4);

    /*
    PRINTS 1,2,3,4
    */

    auto f = s.begin();

    while(!s.empty()){

    cout<<*f<<endl;
    s.erase(f);
     f = s.begin();

    }

    for(auto e:s){
        cout<<e<<endl;
    }
    

}