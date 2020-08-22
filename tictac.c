#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

void printBoard(int board[]);
char getWinner(int board[]);
int isOver(int board[]);
int getMove(int board[]);

int comobo[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},
    {0,3,6},{1,4,7},{2,5,8},
    {0,4,8},{2,4,6}
};
int main(void){
    
    
	// Initialize an empty board 
	int board[SIZE] = {0},move;
	// As long as the game is not over:
    printBoard(board);
	while (! isOver(board)){
		//First the computer plays
		move = getMove(board);
		board[move] = 1;
		//Check if the game is over
		if (isOver(board))break;
		printBoard(board);
		move = -1;
		//Ask the user for his move 
        
		while ( move < 0 || move >= SIZE ){
			printf("1 player, your move is:");
			scanf("%d", &move);
            if (board[move] != 0 ){
                printf("illegal move\n");
                move = -1 ; 
            }
		}
		board[move] = -1;
        printBoard(board);
	}
	printf("And the winner is: %c \n",getWinner(board));


		printBoard(board);
        //system("puase");
        return 0 ;
}

void printBoard(int board[]){

    for (int i = 0; i < 9; i++)
    {
        if(! (i%3) && !(i == 0) ){
            printf("\n**************\n");
        }
        if(board[i]==1){
           printf( "x"); 
        }else if(board[i]==-1){
            printf( "o");
        }
        else{
            printf(" ");
        }
        //printf( "%d", board[i] );
        if(!( i == 5 || i == 2 || i == 8 )){
            printf( "  *  ");
        }
        
        
    }
    printf("\n");
}

char getWinner(int board[]){
    for (int i = 0; i < 8; i++)
    {
        if( board[comobo[i][0]]==board[comobo[i][1]] && board[comobo[i][1]]==board[comobo[i][2]] && board[comobo[i][0]] != 0 ){ 
        if( board[comobo[i][0]] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
    }    
    }
    return ('=');
    
    
    

    
}

int isOver(int board[]){
    char outp = getWinner(board);
    if( outp == 'X' || outp == 'O'){
        return 1 ;
    }
    else
    {
        int blank = 0 ;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 0 ){
                blank++;
                break;
            }
        }
        return !blank ;
        
    }
    
}

int getMove(int board[]){
    int move = -1;
    while ( move < 0 || move >= SIZE ){
			printf("0 player, your move is:");
			scanf("%d", &move);
            if (board[move] != 0 ){
                printf("illegal move\n");
                move = -1 ; 
            }
		}

    return move ;
}
