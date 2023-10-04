#include<iostream>
using namespace std;

void solve(string n,string ans,bool isFirst = true){

    if (ans.size() > n.size()) {
        return;
    }

      if (isFirst == false) {
        if (stoi(ans) <= stoi(n)) {
            cout << ans << " ";
        }
    }

    
    int start = isFirst ? 1 : 0;

     for (int i = start; i <= 9; i++) {
        char ch = i + '0';
        ans.push_back(ch);
        solve(n, ans, false);
        ans.pop_back();
    }

    
    
    }


int main(){
    string in, out = "";
    cin >> in;
    cout << '0' << " ";
    solve(in, out, true);
    cout << endl;

    return 0;
}