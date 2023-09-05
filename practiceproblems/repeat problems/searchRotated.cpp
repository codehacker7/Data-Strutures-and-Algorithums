class Solution {
public:
    int search(vector<int>& arr, int target) {
      
      int lo = 0;
      int hi = arr.size() -1;

      while(lo <=hi){
          //our job is to indentify the sorted half now
          int mid = (lo + hi)/2;

          if(arr[mid] == target){
              return mid;
          }

          if(arr[lo] <= arr[mid]){
              if(arr[lo] <= target && target <= arr[mid]){
                  hi = mid -1;
              }
              else{
                  lo = mid + 1;
              }
          } else {
              //the other part is sorted 
              if(arr[mid] <= target && target <= arr[hi]){
                  lo = mid + 1;
              }else{
                  hi = mid - 1;
              }
          }
      }
    
        return -1;

    }
};