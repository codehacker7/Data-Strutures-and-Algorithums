#include <iostream>
#include <set>
using namespace std;

int main(){

    //pair ke first argument me sort
    set<pair<int,char> > s;

    s.insert({3,'C'});
    s.insert({2,'A'});
    s.insert({1,'D'});
    s.insert({4,'B'});

    //{3'C' ko dhoodo}

    auto x = s.find({3,'C'});

    if(x != s.end()){
        //
        s.erase(x);
    }

    s.insert({4,'C'});

    auto f = s.begin();

    while(!s.empty()){

        cout<<(*f).first<<", "<<(*f).second << endl;
        s.erase(f);
        f = s.begin();

     }



}