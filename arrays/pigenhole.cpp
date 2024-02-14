// Pigeonhole
#include <iostream>
using namespace std;

int main() {

	int a[] = {1, 0, 4, 2, 3};
	int n = sizeof(a) / sizeof(int);

	int prefixSum[100];

	prefixSum[0] = a[0]; //sum till first element of the array is obsivouly first element itself


    for(int i=1;i<n;i++){
        prefixSum[i] = prefixSum[i-1] + a[i]; // this loop is calculating prefix sum
    }

    for(int i=0;i<n;i++){
        prefixSum[i] = prefixSum[i] %n; // this is calculatiing the remainders and if we get same remainders that means sum is same in that part
    }

    int cnt[10000];
    cnt[0] = 1; // this 1 is used for empty subarray

    for(int i=0;i<n;i++){
        cnt[prefixSum[i]]++; // this is counting how much time remainder (perfixsum %N) is occuring
    }
    
    /*

    elements :      1    0      4       2      3

    prefixsum%N:  0  1   1      0        2      0
    
    subarray is always between {l+1,r}

    now in every 2 0s there is 1 subarray so in 3 0s there is 3C2 subarrays
    
    
    */
    int ans =0;
    for (int i = 0; i < n; ++i)
	{
		ans += (cnt[i] * (cnt[i] - 1)) / 2;
	}

    return ans;

}