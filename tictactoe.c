/*

PLAYER 1 ~ X ~ 1
PLAYER 2 ~ O ~ 2

1 2 3 
4 5 6
7 8 9 

    --- EXAMPLE ---

1  0  2            X - O
0  1  0     =      - X -
2  0  1            O - X

(take input)
p1 1st chance ->  X at 1
p2 1st chance ->  O at 3
p1 2nd chance ->  X at 9 
p2 2nd chance ->  O at 7 
p1 3rd chance ->  X at 5


p1 wins the game!
(after every chance, use checkWinner() function)

******

for row 0 -> ind = r+c+1
so, col = ind - row - "1", ref = 1

for row 1 -> ind = r+c+2
so, col = ind - row - "2", ref = 2

*/

#include <stdio.h>
#include <stdlib.h>

// initializing the TIC-TAC-TOE table 
int mat[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
};

void getInput(int pNum);
void checkWinner();
void printTable();
int checkTie();

int main(){
    
    printf("\nTIC-TAC-TOE !!\n")
    printf("1 2 3 \n");
    printf("4 5 6 \n");
    printf("7 8 9 \n");

    // game loop 
    do{
        // for player 1
        getInput(1);
        // for player 2
        getInput(2);      
        // showing resulting TTT table after 1 round
        printTable();  
        checkWinner();

        int sts = checkTie();
        if (sts != 0) {
            printf("Game Tied !");
            break;
        }     
    }while(1>0);
}

void getInput(int pNum){

    int ind,col,row,ref;
    printf("\nPlayer %d: Enter index no.-> ", pNum);
    scanf("%d",&ind);

    if(ind>=1 && ind<=9){

        // finding row number
        if(ind>=1 && ind<=3){
            row = 0;
        } else if (ind>=4 && ind<=6){
            row = 1;
        } else if (ind>=7 && ind<=9){
            row = 2;
        }

        // finding ref number
        switch(row){
            case 0: ref = 1;
            break;
            case 1: ref = 3;
            break;
            case 2: ref = 5;
            break;
        }

        // finding col num & inputting to matrix
        col = ind - row - ref;

        if(mat[row][col] == 0){
            mat[row][col] = pNum;
        }else{
            printf("Choose an empty space !\n");
            getInput(pNum);
        }

        // confirmation to the user
        if(pNum == 1){
            printf("Player %d: X at %d\n \n",pNum,ind);
        } else if(pNum == 2){
            printf("Player %d: O at %d\n \n",pNum,ind);
        }
    } else if(ind = -1){
        exit(0);
    } else {
        printf("Wrong input, please try again\n");
        getInput(pNum);
    }   
}

void checkWinner(){ 

    for(int i=0; i<3; i++){

        //  checking rows 
        if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != 0){
            printf("Player %d Wins !!\n",mat[i][0]);
            exit(0);
            
        //  checking cols
        }else if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i] && mat[0][i] != 0){
            printf("Player %d Wins !!\n",mat[0][i]);
            exit(0);

        // checking right diagonal 
        }else if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != 0){
            printf("Player %d Wins !!\n",mat[0][0]);
            exit(0);

        // checking left diagonal   
        }else if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != 0){
            printf("Player %d Wins !!\n",mat[0][2]);
            exit(0);
        }
    } 
    // tie-game check
//     for(int i=0; i<3; i++){
//         for(int j=0; i<3; j++){
//             if(mat[i][j] == 1 || mat[i][j] == 2){
//                 printf("Game Tied !\n");
//                 exit(0);
//             }
//         }
//     }       
}

int checkTie()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (mat[i][j] == 0) {
                return 0;
            }
        }
    }
    return 2;
}

void printTable(){
    // "X" instead of 1, "O" instead of 2
    // "_" in place of default value 0
    
    for (int i = 0; i < 3; i++) {
        int cnt = 0;

        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == 1) {
                printf("X ");
            } else if (mat[i][j] == 2) {
                printf("O ");
            } else if (mat[i][j] == 0) {
                printf("_ ");
            }           
        } 
        printf("\n");      
    }
}