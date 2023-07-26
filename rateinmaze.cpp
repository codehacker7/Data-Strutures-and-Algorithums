#include<iostream>
using namespace std;

bool rateinMaze(int grid[4][5],int path[4][5],int rows,int columns,int currRow,int currCol){


    if(currRow == rows-1 && currCol == columns-1){

        path[currRow][currCol] = 1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cout<<path[i][j];
            }
            cout<<endl;
        }



        return true;



    }



    path[currRow][currCol] = 1;

    if(currCol+1 < columns && grid[currRow][currCol+1] == 0){
    bool canreach = rateinMaze(grid,path,rows,columns,currRow,currCol+1);
    if(canreach){
        return true;
    }


    }

    if(currRow+1 < rows && grid[currRow+1][currCol] ==0 ){
        bool canreach = rateinMaze(grid,path,rows,columns,currRow+1,currCol);
    if(canreach){
        return true;
    }
    }


    path[currRow][currCol] = 0;
    return false;





}


int main(){

    int n =4;
    int m =5;

    int grid[4][5] = {

        {0,0,0,0,1},
        {0,1,1,0,0},
        {0,0,1,1,1},
        {0,0,0,0,0}
    };

    int path[4][5] = {0};


    return 0;
}