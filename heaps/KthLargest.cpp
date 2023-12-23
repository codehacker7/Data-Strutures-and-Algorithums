#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	// k=n-k;//make k=n-k
	k = k % n;

	priority_queue<int> pq;

	for(int i=0;i<n;i++){
		pq.push(a[i]);
	}

	int count = 1;

	while(count < k){
		pq.pop();
		count++;
	}
	cout<<pq.top()<<endl;



	// sort(a,a+n);//sort array
	// for(int i=0;i<n;i++)
	// {
	// 	if(i==k)
	// 	{
	// 		cout<<a[i];
	// 		break;
	// 	}
	// }
        return 0;

}