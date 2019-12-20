#include <iostream>

using namespace std;

bool isSafe(int board[][4],int row,int col,int n){

	for(int i=0;i<row;i++){
		if(board[i][col]){
			return false;
		}
	}

	int x = row;
	int y = col;

	while(x>=0 and y>=0){
		if(board[x][y]){
			return false;
		}
		x--;
		y--;
	}

	x = row;
	y = col;

	while(x>=0 and y<n){
		if(board[x][y]){
			return false;
		}
		x--;
		y++;
	}

	return true;
}

bool NQueens(int board[][4],int row,int n){
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

				if(board[i][j]){
					cout<<"Q ";
				}else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		cout<<"***************"<<endl;
		return true;
	}

	for(int col=0;col<n;col++){

		if(isSafe(board,row,col,n)){

			board[row][col] = 1;

			bool rest_of_the_queens = NQueens(board,row+1,n);
			if(rest_of_the_queens){
				return true;
			}

			board[row][col] = 0;
		}
	}

	return false;
}

void printNQueens(int board[][4],int row,int n){
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

				if(board[i][j]){
					cout<<"Q ";
				}else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		cout<<"***************"<<endl;
		return;
	}

	for(int col=0;col<n;col++){
		if(isSafe(board,row,col,n)){

			board[row][col]=1;

			printNQueens(board,row+1,n);

			board[row][col] = 0;
		}
	}

	return;
}

int countNQueens(int board[][4],int row,int n){
	if(row==n){
		return 1;
	}

	int count = 0;	

	for(int col=0;col<n;col++){
		if(isSafe(board,row,col,n)){

			board[row][col]=1;

			count+=countNQueens(board,row+1,n);

			board[row][col] = 0;
		}
	}

	return count;
}

bool ratInMaze(char maze[][4],int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return true;
	}

	if(sr>er or sc>ec){
		return false;
	}

	if(maze[sr][sc]=='X'){
		return false;
	}

	bool horizontal = ratInMaze(maze,sr,sc+1,er,ec);
	bool vertical = ratInMaze(maze,sr+1,sc,er,ec);

	return horizontal or vertical;
}

void printRatInAMaze(char maze[][4],int sol[][4],int sr,int sc,int er,int ec)

int main(){

	int board[4][4] = {0};
	int n = 4;

	// cout<<NQueens(board,0,n)<<endl;

	// printNQueens(board,0,n);

	// cout<<countNQueens(board,0,n)<<endl;

	char maze[][4] = {
     	{'0','0','0','0'},
     	{'0','0','0','0'},
     	{'0','0','X','0'},
     	{'0','X','0','0'},
     };

    // cout<<ratInMaze(maze,0,0,3,3)<<endl;

     int sol[4][4] = {0};

    cout<<printRatInAMaze(maze,sol,0,0,3,3)<<endl;

	return 0;
}