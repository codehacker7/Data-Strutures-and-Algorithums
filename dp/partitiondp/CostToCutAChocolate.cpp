#include <bits/stdc++.h> 

int f(int i,int j,vector<int> &cuts){

    if(i > j) return 0;

    int mini = INT_MAX;
    for(int ind = i; ind <=j; ind++){
        int cost = cuts[j+1] - cuts[i-1] + f(i,ind-1,cuts) + f(ind+1,j,cuts);
        mini = min(mini,cost);
    }
    return mini;

}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.

    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    return f(1,c,cuts);
}