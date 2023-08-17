 #include<iostream>
 #include<vector>
 using namespace std;
 
 bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      vector<int> emptyPlaces;

       int NumberOfFlowers = 0;

    // [1,0,0,0,0,0,1]

        for(int i=0;i<flowerbed.size();i++){


         if(flowerbed[i] == 0 ){

             if(emptyPlaces.size() > 0){

                 int lastPlace = emptyPlaces.back();
         
                  if(i - lastPlace > 1){
                      NumberOfFlowers++;
                      emptyPlaces.push_back(i);
                 }


             }

             else{
                 emptyPlaces.push_back(i);
                  NumberOfFlowers++;
             }
         
          }  

        }

  


        return NumberOfFlowers >=n;

        
        
    }


    int main(){


    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
   cout<<canPlaceFlowers(arr,2)<<endl;
  
    }