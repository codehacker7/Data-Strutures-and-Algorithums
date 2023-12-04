class data{
    public:
    int apos;
    int vpos;

    data(int v,int ap,int vp){
        val = v;
        apos = ap;
        vpos = vp;
    }
};

short mycomp{

    bool operator()(data &d1,data &d2){
        return d1.val > d2.val;
    }

};

int main(){

    int k;
    cin>>k;

    vector<vector<int> > array(k);

    priority_queue<data,vector<data>,mycomp> > pq;

    for(int i=0;i<k;i++) //k is number of array
{
    data d(arr[i][0],i,0);
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