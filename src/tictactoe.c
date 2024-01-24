#include <stdio.h>


struct XO{
    char value;
    int filled;
};

void setXOValue(struct XO *xo, char val){
    xo->value = val;
    xo->filled = 1;
}

//struct used for the state of the board.
struct Board{
    struct XO xo1;
    struct XO xo2;
    struct XO xo3;
    struct XO xo4;
    struct XO xo5;
    struct XO xo6;
    struct XO xo7;
    struct XO xo8;
    struct XO xo9;
    
};


struct Board makeBoard(){
    struct Board board = {{'1', 0} ,{'2', 0},{'3', 0},{'4', 0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0}};
    return board;
}

//used to set the value on the board by setting the embedded XO value to x or 0
void setBoardValue(struct Board *board, int spot, char val){
    switch(spot){
        case 1:
            if(board->xo1.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo1, val);
            }
            break;
        case 2:
            if(board->xo2.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo2, val);
            } break;
        case 3:
            if(board->xo3.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo3, val);
            }break;
        case 4:
            if(board->xo4.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo4, val);
            }break;
        case 5:
            if(board->xo5.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo5, val);
            } break;
        case 6:
            if(board->xo6.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo6, val);
            } break;       
        case 7:
            if(board->xo7.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo7, val);
            } break; 
        case 8:
            if(board->xo8.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo8, val);
            } break; 
        case 9:
            if(board->xo9.filled){
                printf("for trying to cheat you forfit your turn!\n");
            }else{
            setXOValue(&board->xo9, val);
            } break; 
    }
    
}


//method that checks if there is a winner, if it is x it returns 0, if o returns 1, if no-one returns 2
int checkWinner(struct Board *board){
    
    if ((board->xo1.value == board->xo2.value) && (board->xo2.value == board->xo3.value)&& (board->xo1.value == 'x')){
        
        return 0;
    }
    if ((board->xo1.value == board->xo4.value) && (board->xo4.value == board->xo7.value)&& (board->xo1.value == 'x')){
        return 0;
    }
    if ((board->xo1.value == board->xo5.value) && (board->xo5.value == board->xo9.value)&& (board->xo1.value == 'x')){

        return 0;
    }
    if ((board->xo2.value == board->xo5.value) && (board->xo5.value == board->xo8.value)&& (board->xo2.value == 'x')){
        return 0;
    }
    if ((board->xo3.value == board->xo6.value) && (board->xo6.value == board->xo9.value)&& (board->xo3.value == 'x')){
        return 0;
    }
    if ((board->xo3.value == board->xo5.value) && (board->xo5.value == board->xo7.value)&& (board->xo3.value == 'x')){
        return 0;
    }
    if ((board->xo4.value == board->xo5.value) && (board->xo5.value == board->xo6.value) && (board->xo4.value == 'x')){
        return 0;
    }
    if ((board->xo7.value == board->xo8.value) && (board->xo8.value == board->xo9.value) && (board->xo7.value == 'x')){
        return 0;
    }
    if ((board->xo1.value == board->xo2.value) && (board->xo2.value == board->xo3.value)&& (board->xo1.value == 'o')){
        
        return 1;
    }
    if ((board->xo1.value == board->xo4.value) && (board->xo4.value == board->xo7.value)&& (board->xo1.value == 'o')){
        return 1;
    }
    if ((board->xo1.value == board->xo5.value) && (board->xo5.value == board->xo9.value)&& (board->xo1.value == 'o')){

        return 1;
    }
    if ((board->xo2.value == board->xo5.value) && (board->xo5.value == board->xo8.value)&& (board->xo2.value == 'o')){
        return 1;
    }
    if ((board->xo3.value == board->xo6.value) && (board->xo6.value == board->xo9.value)&& (board->xo3.value == 'o')){
        return 1;
    }
    if ((board->xo3.value == board->xo5.value) && (board->xo5.value == board->xo7.value)&& (board->xo3.value == 'o')){
        return 1;
    }
    if ((board->xo4.value == board->xo5.value) && (board->xo5.value == board->xo6.value) && (board->xo4.value == 'o')){
        return 1;
    }
    if ((board->xo7.value == board->xo8.value) && (board->xo8.value == board->xo9.value) && (board->xo7.value == 'o')){
        return 1;
    }


    return 2;
}


//handles input
void handleInput(struct Board *board, int counter){
    char val;
    int spot;
    scanf("%d", &spot);

    //evalute whos turn it is
    if(counter ==0){
        val = 'x';
    }

    if((counter % 2) == 0){
        val = 'x';
    }
    
    else{
        val = 'o';
    }
    
    //checking if the value is correct
    if(spot > 9||spot <0){
        val = scanf("That number is too high or ");
    }else{
        setBoardValue(&*board, spot, val);
    }
    
}

//struct used to control the whole state of the board
struct Board board;

//counter for how many runs have played. used to determine whos turn it is. 
int counter = 0;

int main(){
    if (counter == 0){
        board = makeBoard();
        printf("X'S START O'S GO SECOND\n");
        printf("%c | %c | %c \n%c | %c | %c \n%c | %c | %c \n", board.xo1.value, board.xo2.value, board.xo3.value, board.xo4.value, board.xo5.value, board.xo6.value, board.xo7.value, board.xo8.value, board.xo9.value);

    }


    handleInput(&board, counter);
    
    printf("%c | %c | %c \n%c | %c | %c \n%c | %c | %c \n", board.xo1.value, board.xo2.value, board.xo3.value, board.xo4.value, board.xo5.value, board.xo6.value, board.xo7.value, board.xo8.value, board.xo9.value);

    if(checkWinner(&board) == 0){
        printf("X WINS!!!!!!!!!!!!!\n");
    }
    else if(checkWinner(&board) == 1){
        printf("O WINS!!!!!!!!!!!!!\n");
    }
    else if(checkWinner(&board) == 2){
        printf("no winner, text turn\n");
        counter++;
        main();
    }

    return 0;
}