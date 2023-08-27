#include<iostream>
using namespace std;

int ct =0;

bool isSafeToPlace(int row,int grid[100][100],int column,int n){

    // in here we are checking the column if there is a queen or not 
    
    for(int i=0;i<n;i++){
        if(grid[i][column] == 1){
            return false;
        }
    }

    // left diagonal
    
    //now our task is to check the very left diagonal


    int ldr = row-1;
    int ldc = column+1;

    while(ldr >= 0 && ldc <n){


        if(grid[ldr][ldc] == 1){
            return false;
        }

        ldr--;
        ldc++;

    }

    //now our last task is to check the right diagonal

    int rdr = row-1;
    int rdc = column-1;

    while(rdr >= 0 && rdc >= 0){
        if(grid[rdr][rdc] == 1){
            return false;

        }
        rdr--;
        rdc--;
    }

    return true;


}

bool nqueens(int row,int grid[100][100],int n){


    if(row == n){
        ct++;
        return  false;
    }




   for(int j=0;j<n;j++){

        bool canPlace = isSafeToPlace(row,grid,j,n);

        if(canPlace){
                //place queen here if it is safe to place
               grid[row][j] = 1;

               //now check next row

              bool canPlaceAllQueens =  nqueens(row+1,grid,n);

              if(canPlaceAllQueens){
                 
                 return  true;
              }


        }

        grid[row][j] = 0;

   }
 



    return false;

}



int main(){


    int n;
    cin>>n;

    int grid[100][100] = {};

    
    nqueens(0,grid,n);

    cout<<ct<<endl;



    return 0;

}