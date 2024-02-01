class data{
    public:
    int val;
    int apos;
    int vpos;

    data(int v,int ap,int vp){
        val = v;
        apos = ap;
        vpos = vp;
    }
};

class mycomp{
    public:
    bool operator()(data &d1,data &d2){
        return d1.val > d2.val;
        //return d1[vpos][apos] > d2[vpos][apos];
    }

};

int main(){

    int k;
    cin>>k;

    vector<vector<int> > array(k);

    priority_queue<data,vector<data>,mycomp> > pq;

    for(int i=0;i<k;i++) //k is number of array
{
    data d(arr[i][0],i,0); // this is representing the {value,arrayPosition,Position of element in the array}
    pq.push(d);
}
vector<int> ans;

while(!pq.empty()){
    data curr = pq.top();
    pq.pop();
    ans.push_back(curr.val);
    int arrayPosition = curr.apos;
    int vectorPosition = curr.vpos;

    if(vectorPosition + 1 < arr[arrayPosition].size()){
        data d(arr[arrayPosition][vectorPosition+1],ap,vp+1);
        pq.push(d);
    }
}
return ans;

}