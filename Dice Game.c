#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to add clock to enable delay of terminal outputs
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);               
}

// Struct to hold player's name data
struct Player{
    char name[20];
};

// Function prototypes
void displayDice(int);
int compareScore(int score[]);
void game(struct Player* , int);
int setDice();
void setPlayer(struct Player*);
void rules();
void header();

// Main Function
int main() {
    char c;
    struct Player ply[2];                               // Declare struct

    header();                                           // Print header
    rules();                                            // Print rules
    setPlayer(ply);                                     // Run function to set player name
    int dice = setDice();                               // Set number of dice roles
    game(ply , dice);                                   // Pass number of dice to Game Function >w<

    printf("Enter Y to continue the game, others will end the game \n");
    scanf( " %c" , &c);
        while(c == 'Y'){                                //  (B. Repetition : While Loop)
            main();
        };

    return 0;
}

// Function to display dice faces for the game ( C. Function That Recieves Parameters)
void displayDice(int x){
    // ( B. Selection : Switch Case Statements)
    switch (x)
    {
        case 1:
            printf("---------\n");
            printf("|       |\n");
            printf("|   o   |\n");
            printf("|       |\n");
            printf("---------\n");
        break;
        case 2:
            printf("---------\n");
            printf("|       |\n");
            printf("| o   o |\n");
            printf("|       |\n");
            printf("---------\n");
        break;
        case 3:       
            printf("---------\n");
            printf("| o     |\n");
            printf("|   o   |\n");
            printf("|     o |\n");
            printf("---------\n");
        break;
        case 4:
            printf("---------\n");
            printf("| o   o |\n");
            printf("|       |\n");
            printf("| o   o |\n");
            printf("---------\n");
        break;
        case 5:
            printf("---------\n");
            printf("| o   o |\n");
            printf("|   o   |\n");
            printf("| o   o |\n");
            printf("---------\n");
        break;
        case 6:
            printf("---------\n");
            printf("| o   o |\n");
            printf("| o   o |\n");
            printf("| o   o |\n");
            printf("---------\n");
        }
}


// Function to compare score ( C. Function That Receives An Array )
int compareScore(int score[]){
    int s1 = score[0], s2 = score[1];

    if (s1 > s2)
        {
            return 1;
        }
    else if (s1 < s2)
        {
            return 2;
        }
    else if (s1 == s2)
        {
            return 3;
        }
}

// Function for the game section of this program
void game(struct Player *ptr , int x){

    int score[2];                                       // (D. Array)

    for (int i = 0; i < 2; i++)                         // (B. Repetition : For Loop)
    {
        int total = 0;

        printf("\n%s's turn to role ( Press Enter )\n" , ptr->name );       // (E. Pointers)
        getch();
        printf("Rolling.."); delay(1); printf(".."); delay(1); printf(".."); delay(1); printf("\n\n");
        
        for (int j = 0; j < x ; j++)
            {
                srand(time(NULL));
                int r = 1 + rand() % (6 + 1 - 1);       // (A. Arithmetic Expression)
                displayDice(r);
                delay(1);

                total = total + r;
            }
        printf ( "%s's score is %d \n" , ptr->name , total);
        delay(1);
        score[i] = total ;
        ptr++;
    }
  
    ptr--; ptr--;
    int f = compareScore(score);

    if (f == 1)                                            // (B. Selection : If Else Statement)
        {
            printf("---------------------------\n");
            printf("(ノಠ益ಠ)ノ彡 %s Wins \n" , ptr->name);
            printf("---------------------------\n");
        }
    else if (f == 2)
        {
            ptr++;
            printf("---------------------------\n");
            printf("(つ◉益◉)つ %s Wins \n" , ptr->name);
            printf("---------------------------\n");
        }
    else if (f == 3)
        {
            printf( "Draw :(");
        }
}

// Function to set the number of dice to roll ( C. Function That Has Return Values)
int setDice(){
    int x;

    printf("\nEnter how many dice to be rolled ( 1 - 3 ): ");
    scanf("%d", &x);

    if (x >= 1 && x <=3){
        return x;
    }
    else{
        printf("Invalid Input Try Again\n");
        setDice();
    }

}

// Function to pass player name to struct
void setPlayer(struct Player *ptr){

    for (int i = 1; i < 3; i++){
        printf("Enter name of player %d: " , i);
        gets(ptr->name);  

        ptr++;
    }
}

// Function that print rules of the game ( C. Function That Not Recieves Parameters)
void rules(){
    int x;

    printf ("The Rules\n");
    printf("---------------------------------\n");
    printf("2 Players Play Against Each Other\n");
    printf("Each Player Roles A Set Amount Of Dice\n");
    printf("Higher Score At The End Wins\n");
    printf("---------------------------------\n");
    printf("Press Enter To Continue\n");
    getch();
    printf("\n\n");

}

// Function that prints header for the program ( C. Function That Has No Return Value)
void header(){
    printf("---------------------------------\n");
    printf("|   Welcome to the Dice Game    |\n");
    printf("---------------------------------\n");
    printf("|       | o     | o   o | o   o |\n");
    printf("| o   o |   o   |   o   | o   o |\n");
    printf("|       |     o | o   o | o   o |\n");
    printf("---------------------------------\n");
}








