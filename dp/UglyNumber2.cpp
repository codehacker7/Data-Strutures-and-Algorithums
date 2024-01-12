class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> arr(n+1);

        int i2;
        int i3;
        int i5;

        //pointing to 1st ugly number
        i2 = i3 = i5 = 1;

        //first ugly number is 1
        arr[1] = 1;

        for(int i=2;i<=n;i++){

            int i2uglynumber = arr[i2] *2;
            int i3uglynumber = arr[i3] * 3;
             int i5uglynumber = arr[i5] * 5;

             int minUgly = min(i2uglynumber,min(i3uglynumber,i5uglynumber));
             arr[i] = minUgly;

             //jiska minimum hua uska pointer bada do

             if(minUgly == i2uglynumber){
                 i2++;
             }  if(minUgly == i3uglynumber){
                 i3++;
             }
             if(minUgly == i5uglynumber){
                 i5++;
             }

        }

        return arr[n];
    }
};