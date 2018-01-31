#include <iostream>
using namespace std;
int n;
int x;
int board[100][100];
int count = 1;
class Queen {
	private:
		int row;
		int column;
		Queen *adjacent;
	public:     
		Queen(int col, Queen  *adj) { 
			column = col; 
			adjacent = adj;
			row = 1;
		}

		bool getsolution(){
			while (adjacent && adjacent->Attacking(row, column))
				if (! movetonext())
					return false;
				return true;
		}

		bool movetonext(){
			if (row < n) {
				row++;
				return getsolution();
			}
			if (adjacent && ! adjacent->movetonext())
				return false;
			row = 1;
			return getsolution();
		}

		bool Attacking(int i, int j){
			int diff=j-column;
			if((row == i)||(row+diff==i)||(row-diff==i))
				return true;
			if(adjacent!= NULL)
				return adjacent->Attacking(i,j);
			return false;
		}

		void print(int i){
			if(adjacent != NULL){
				adjacent->print(i);
				if(i==1){
					board[row-1][column-1]=1;
				}
			}
			else{ 
				if(i==1){
				board[row-1][column-1]=1;
				}
				x=row;
			}
		}
};

void makeboard(){
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					board[i][j]=0;
				}
		}
}

void printBoard(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
	cout<<endl;
	}
}

int main() 
{
	Queen  *lastQueen = 0;
	cout <<"Enter the value of n"<< endl;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		lastQueen = new Queen(i, lastQueen);
		if (! lastQueen->getsolution())
			cout << "no solution\n";
	}
	lastQueen->print(0);
	int q=x;
	int p=0;
	cout<<endl;
	while(lastQueen->movetonext()){
		if(x>q)
			p=1;
		if(x==q&&p==1)
			break;
		if(lastQueen->getsolution()){
			makeboard();
			lastQueen->print(1);
			printBoard(n);
			count++;
			cout<<endl;
		}      
	}
	cout<<count-1; 
}
