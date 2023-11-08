class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0];//largest - smallest
        
        int largest = arr[n-1] - k;
        int smallest = arr[0] + k;
        
        int mi,ma;
        
        for(int i=0;i<n-1;i++){
            ma = max(largest,arr[i]+k); //inc the height of chota tower
            mi = min(smallest,arr[i+1]-k);
            if(mi < 0) continue;
            ans = min(ans,ma-mi);
            
        }
        return ans;
        
    }
};