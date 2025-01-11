#include <iostream>

using namespace std;

// Global Variables

char board[3][3] ;
char winner = ' ';
char player_1 = 'X';
char player_2 = 'O';
int free_Spaces = 9;
int spaces;
bool game_Done = false;


// Function Prototypes

void reset_Board();
void print_Board();
void player_1_Move();
void player_2_Move();
int check_Free_Spaces();
char check_Winner();
void print_Winner(char winner);


// Main Function

int main()
{
    reset_Board();
    print_Board();
    do{
        player_1_Move();
        if(game_Done)
            break;

        player_2_Move();
        if(game_Done)
            break;


    }while(spaces != 0 && winner == ' ');

    return 0;
}

// Fuction Definition

void reset_Board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void print_Board(){
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
void player_1_Move(){
    int x;
    int y;
    cout << "Player 1's turn : \n";
    do{
        do{
            cout << "\n Choose row (1->3) : ";
            cin >> x;
            if(x > 3 || x < 1){
                cout << "Invalid Number !";
            }
        }while(x > 3 || x < 1);
        x--;
        do{
            cout << "\n Choose column (1->3) : ";
            cin >> y;
            if(y > 3 || y < 1){
                cout << "Invalid Number !";
            }
        }while(y > 3 || y < 1);
        y--;
        if(board[x][y] != ' '){
            cout << "\nInvalid cell !";
        }else{
            board[x][y] = player_1;
            break;
        }
    }while(board[x][y] != ' ');
    print_Board();
    winner = check_Winner();
    spaces = check_Free_Spaces();
    if(winner != ' '){
        print_Winner(winner);
        game_Done = true;
    }else if(spaces == 0){
        cout << "Tie !";
        game_Done = true;
    }
}
void player_2_Move(){
    int x;
    int y;
    cout << "Player 2's turn : \n";
    do{
        do{
            cout << "\n Choose row (1->3) : ";
            cin >> x;
            if(x > 3 || x < 1){
                cout << "Invalid Number !";
            }
        }while(x > 3 || x < 1);
        x--;
        do{
            cout << "\n Choose column (1->3) : ";
            cin >> y;
            if(y > 3 || y < 1){
                cout << "Invalid Number !";
            }
        }while(y > 3 || y < 1);
        y--;
        if(board[x][y] != ' '){
            cout << "\nInvalid cell !";
        }else{
            board[x][y] = player_2;
            break;
        }
    }while(board[x][y] != ' ');
    print_Board();
    winner = check_Winner();
    spaces = check_Free_Spaces();
    if(winner != ' '){
        print_Winner(winner);
        game_Done = true;
    }else if(spaces == 0){
        cout << "Tie !";
        game_Done = true;
    }
}
int check_Free_Spaces(){
    int spaces = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' ')
                spaces--;
        }
    }
    return spaces;
}
char check_Winner(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];
    return ' ';
}
void print_Winner(char winner){
    if(winner == 'X'){
        cout << "Player1 win !";
    }else if(winner == 'O'){
        cout << "Player2 win!";
    }
}
