#include<stdio.h>
    #include <conio.h>
    
    int square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    //char square[3][3];
    
    int win();
    void board();
    
    int main()
    {
        int player = 1, i, choice;
    
        char score;
        do
        {
            board();
            player = (player % 2) ? 1 : 2;
    
            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);
    
            score = (player == 1) ? 'X' : 'O';
    
            if (choice == 1 && square[1] == '1')
                square[1] = score;
    
            else if (choice == 2 && square[2] == '2')
                square[2] = score;
    
            else if (choice == 3 && square[3] == '3')
                square[3] = score;
    
            else if (choice == 4 && square[4] == '4')
                square[4] = score;
    
            else if (choice == 5 && square[5] == '5')
                square[5] = score;
    
            else if (choice == 6 && square[6] == '6')
                square[6] = score;
    
            else if (choice == 7 && square[7] == '7')
                square[7] = score;
    
            else if (choice == 8 && square[8] == '8')
                square[8] = score;
    
            else if (choice == 9 && square[9] == '9')
                square[9] = score;
    
            else
            {
                printf("Invalid move ");
    
                player--;
                getch();
            }
            i = win();
    
            player++;
        }while (i ==  - 1);
    
        //board();
    
        if (i == 1)
        {
            board();
            printf("==>\aPlayer %d win ", --player);
        }
        else
            printf("==>\aGame draw");
    
        getch();
    
     return 0;
    }
    int win()
    {
        if (square[1] == square[2] && square[2] == square[3])
            return 1;
    
        else if (square[4] == square[5] && square[5] == square[6])
            return 1;
    
        else if (square[7] == square[8] && square[8] == square[9])
            return 1;
    
        else if (square[1] == square[4] && square[4] == square[7])
            return 1;
    
        else if (square[2] == square[5] && square[5] == square[8])
            return 1;
    
        else if (square[3] == square[6] && square[6] == square[9])
            return 1;
    
        else if (square[1] == square[5] && square[5] == square[9])
            return 1;
    
        else if (square[3] == square[5] && square[5] == square[7])
            return 1;
    
        else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
            square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
            != '7' && square[8] != '8' && square[9] != '9')
    
            return 0;
        else
          return-1;
    }
    void board()
    {
        system("clr");
        printf("\n\n\tTic Tac Toe\n\n");
    
        printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    
        printf(" _________________\n");
        printf("|     |     |     |\n");
        printf("|  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);
    
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
    
        printf("|  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);
    
        printf("|_____|_____|_____|\n");
        printf("|     |     |     |\n");
    
        printf("|  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
    
        printf("|_____|_____|_____|\n\n");
        
    }