#include<iostream>
using namespace std;

bool isSafeToPlace(int board[100][100],int n,int row,int column){

    //first we need to check the columns

        for(int i=0;i < n;i++){

            if(board[i][column] == 1){
                return false;
            }
        }



        // now our task is to check right diagonal 

        int rdr = row-1;
        int rdc = column+1; 

        while( rdr >=0 && rdc <n){

                if(board[rdr][rdc] == 1){
                    return false;
                }
                rdr--;
                rdc++;
        }


        // now our task is to check left diagonal

        int ldr = rows - 1;
        int ldc = column - 1;

        while(ldr >=0  && ldc >= 0){

                    if(board[ldr][ldc] == 1){
                    return false;
                }
                ldr--;
                ldc--;

        }




        return true;
}




bool nqueens(int board[100][100],int n,int rows){


    if( row == n){          //remember why row ==n and why not row-1 ==n

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }



        return true;
        // return false; this is for case where you need to print all the paths

    }

    


    for(int j=0;j<n;j++){


        // before placing a queen on the current column we need to check if we can place queen on that cell
            bool canPlace = false;

            canPlace = isSafeToPlace(board,n,rows,j);

            if(canPlace){
            board[row][j] = 1; // queen has been placed right here

            bool canPlaceAllQueens = nqueens(board,n,row+1); // now we check can we place at next cell

            if(canPlaceAllQueens){
                return true;        // if yes then its pretty good
            }
        }


            board[row][j] = 0;  // if no then it is an issue so I would recommend you to remove queen backtracking
    
    }

                    return false;




}


int main(){

    int board[100][100] = {};
    //queen is represented by 1 --> queen , 0 --> empty cell 

    int n = 4;


    nqueens(board,n,0);





    return 0;
}