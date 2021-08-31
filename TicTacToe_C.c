#include <stdio.h>

void showGame();
void guide();
void gameLogic(int givenInput, int player);
int validation(int input);
int winningLogic();
void reset();
void showResult();

char arr[3][3];
int indexArr[9][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
int playerOneWin = 0;
int playerTwoWin = 0;
int draws = 0;
char player1[20], player2[20];

int main()
{
    int givenInput;
    int player = 1;
    int result;
    int count = 0;
    int play = 1;
    int playTime = 0;

    printf("Enter player 1 name: ");
    scanf("%s", &player1);
    printf("Enter player 2 name: ");
    scanf("%s", &player2);
    while (1)
    {

        if (playTime > 0)
        {
            showResult();
            printf("\nPress 1 to Play again and Any number to quit_ ");
            reset();
            scanf("%d", &play);
            player = 1;
            count = 0;
        }

        if (play != 1)
            break;

        while (play == 1)
        {
            system("cls");
            printf("\n\n");
            showGame();
            player = !player; // if value is 1 then it becomes 0 and if value is 0 it will be 1.

            player ? printf("\n(O) %s turn...\n", player2) : printf("\n (X) %s turn...\n", player1);
            guide();

            scanf("%d", &givenInput);

            int value = validation(givenInput);
            if (value == 1)
            {
                player = !player;
                printf("\nValue already exists!\n");
                continue;
            }

            if (givenInput >= 1 && givenInput <= 9)
            {
                gameLogic(givenInput, player);
                count++;

                result = winningLogic();
                if (result == 1)
                {
                    system("cls");
                    printf("\n\n");
                    showGame();
                    printf("\n\\\\\\\\\\\\ %s Won The Game !! \\\\\\\\\\\\\n", player1);
                    playerOneWin++;
                    break;
                }
                else if (result == 2)
                {
                    system("cls");
                    printf("\n\n");
                    showGame();
                    printf("\n\\\\\\\\\\\\ %s Won The Game !! \\\\\\\\\\\\\n", player2);
                    playerTwoWin++;
                    break;
                }

                if (count == 9)
                {
                    system("cls");
                    printf("\n\n");
                    showGame();
                    printf("\n\\\\\\\\\\\\ Match draw !! \\\\\\\\\\\\\n");
                    draws++;
                    break;
                }
            }
            else
            {
                system("cls");
                printf("\n\n");
                showGame();
                player = !player;
                printf("#### Wrong Input! ####\n");
                guide();
                continue;
            }
        }
        playTime++;
    }

    return 0;
}

void showGame()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == '\0')
            {
                printf("[   ] ");
            }
            else
            {
                printf("[ %c ] ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void guide()
{
    printf("Enter number between 1 to 9_ ");
}

void gameLogic(int givenInput, int player)
{
    givenInput = givenInput - 1;
    int row = indexArr[givenInput][0];
    int column = indexArr[givenInput][1];

    // if (player)
    // {
    //     arr[row][column] = 'O';
    // }
    // else
    // {
    //     arr[row][column] = 'X';
    // }

    arr[row][column] = player ? 'O' : 'X';
}

int validation(int input)
{
    input = input - 1;
    int row = indexArr[input][0];
    int column = indexArr[input][1];

    if (arr[row][column] == 'X' || arr[row][column] == 'O')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int winningLogic()
{
    if ((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X') ||
        (arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X') ||
        (arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X') ||
        (arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X') ||
        (arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X') ||
        (arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X') ||
        (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') ||
        (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X'))
    {
        return 1;
    }
    else if ((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O') ||
             (arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O') ||
             (arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O') ||
             (arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O') ||
             (arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O') ||
             (arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O') ||
             (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') ||
             (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O'))
    {
        return 2;
    }
}

void reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = '\0';
        }
    }
}

void showResult()
{
    printf("\n\nScores_\n");
    printf("%s Won: %d Times\n", player1, playerOneWin);
    printf("%s Won: %d Times\n", player2, playerTwoWin);
    printf("Draws: %d\n", draws);
}