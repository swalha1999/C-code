#include <stdio.h>
#define SIZE 9

void printBoard(int board[]);
char getWinner(int board[]);
int isOver(int board[]);
int getMove(int board[]);


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
    if( board[0]==board[1] && board[1]==board[2] && board[0] != 0 ){ // case 1 top row
        if( board[0] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[3]==board[4] && board[4]==board[5] && board[3] != 0 ){ // case 2 middle row
        if( board[3] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[6]==board[7] && board[7]==board[8] && board[8] != 0 ){ // case 3 last row
        if( board[8] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[0]==board[3] && board[3]==board[6] && board[6] != 0 ){ // case 4 first coloum
        if( board[6] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[1]==board[4] && board[4]==board[7] && board[7] != 0 ){ // case 5 middle coloum
        if( board[7] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[2]==board[5] && board[5]==board[8] && board[8] != 0 ){ // case 6 last coloum
        if( board[8] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else  if( board[0]==board[4] && board[4]==board[8] && board[8] != 0 ){ // case 7 dignal 
        if( board[0] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else if( board[2]==board[4] && board[4]==board[6] && board[6] != 0 ){ //case 8 dignal 
        if( board[6] == 1 ){
            return ('X');
        }
        else
        {
            return('O');
        }
        
    }else {
        return ('=');
    }
    
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