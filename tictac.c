#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

void printBoard(int board[]);
char getWinner(int board[]);
int isOver(int board[]);
int getMove(int board[]);
int minimax(int board[],int depth,int isMax);

int comobo[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},
    {0,3,6},{1,4,7},{2,5,8},
    {0,4,8},{2,4,6}
};

int human = 0;
int ai = 0;
int tie = 0;
int exitcode = 0;
int moves = 0 ;

int main(void){
    
    
	// Initialize an empty board 
	int board[SIZE] = {0},move;
	// As long as the game is not over:
    //printBoard(board);
	while (! isOver(board)){
		//First the computer plays
		move = getMove(board);
		board[move] = 1;
        moves++;
		//Check if the game is over
		if (isOver(board))break;
		printBoard(board);
		move = -1;
		//Ask the user for his move 
        
		while ( move < 0 || move >= SIZE ){
			printf("1 player, your move is:");
			scanf("%d", &move);
            fflush(stdin);
            if (board[move] != 0 ){
                printf("illegal move\n");
                move = -1 ; 
            }
		}
		board[move] = -1;
        moves++;
        //printBoard(board);  //enable for two players

	}
	printf("And the winner is: %c \n",getWinner(board));


		printBoard(board);
        printf("enter the number 1 to exit .. : ");
        scanf("%d",&exitcode);
        if(exitcode){
            return 0;
        }
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

int isOver(int board[]){ // check if the game is over by checking if someone won or the bored is full
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

int getMove(int board[]){ //that is minimax algoriams
    /* 
    int bestMove = -1;
    while ( bestMove < 0 || bestMove >= SIZE ){
			printf("0 player, your move is:");
			scanf("%d", &bestMove);
            if (board[bestMove] != 0 ){
                printf("illegal move\n");
                bestMove = -1 ; 
            }
		}
    */
    int bestMove = -1,score = -1,bestScore = -100;
    for(int i = 0 ; i<SIZE;i++){
        if(board[i] == 0){
            board[i] = 1;
            score = minimax(board,0,0);
            board[i] = 0;
            if(score>bestScore){
                bestScore = score;
                bestMove =  i;
            }
        }
    }
    printf("CPU :there is %d possibilities\nhuman win : %d\nCPU win : %d\ntie : %d \n\n",(ai+human+tie),human,ai,tie);
    ai = 0;
    human = 0;
    tie = 0 ;
    printf("CPU :score this move is %d \n",bestScore);
    return bestMove;
}

int minimax(int board[],int depth,int isMax){ //
    char winner = getWinner(board);
    int bestScore;
    if(winner == 'X'){
        ai+=1;
        return (15 - depth);
    }
    if(winner == 'O'){
        human+=1;
        return (-15 + depth);
    }
    if(winner == '=' && isOver(board)){
        tie+=1;
        if (moves > 2) return 0;
        return -100 ;
    }

    if (isMax){
        int score = -100;
        bestScore = -100;
        for(int i = 0 ; i<SIZE;i++){
            if(board[i] == 0){
                board[i] = 1;
                //printBoard(board);
                score = minimax(board,depth +1,!isMax);
                board[i] = 0;
                if(score > bestScore){
                    bestScore = score;
                }
            }
        }


    }else{
        int score = 100;
        bestScore = 100;
        for(int i = 0 ; i<SIZE;i++){
            if(board[i] == 0){
                board[i] = -1;
                //printBoard(board);
                score = minimax(board,depth+1,!isMax);
                board[i] = 0;
                if(score < bestScore){
                    bestScore = score;
                }
            }
        }
    }
    return bestScore;
    
    
}
