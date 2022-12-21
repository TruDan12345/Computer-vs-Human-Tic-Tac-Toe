/*
  This is a game of tic-tac-toe that allows a person to play with a bot.
  The bot looks for good moves and applies them.

  Created by Daniel M Trushkov.
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

/**
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono;
    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + seconds(1));

    code snippet for system time delay
**/

int sd;
class main_board
{
public:
    bool won; // decides if the game ended
    // extra variables
    int plc, val[2], c = 1, m, rand_num;
    vector<int> x_nums; // applies all the coordinates "X" is taking
    vector<int> o_nums; // applies all the coordinates "O" is taking
    double val1;
    // This is used for adding "X" and "O" to the alternating numbers being alternated by "c"
    string txt;
    // player characters "x" and "o"
    string plr[2] = {"𝗫", "𝗢"};

    // small numbers used in empty spaces to give "hint" to players of its position
    string nums[3][3] = {
        {"₁", "₂", "₃"},
        {"₄", "₅", "₆"},
        {"₇", "₈", "₉"},
    };
    string board[3][3] =
        {
            {"1", "2", "3"},
            {"4", "5", "6"},
            {"7", "8", "9"}};

    // This is the interactive board
    void brd()
    {
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "===========" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "===========" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    }

    // This is the space between boards, usually should match the size of the terminal
    void space(int size = 9) // size 9 is default
    {
        for (int f = 0; f < size; f++)
        {
            cout << endl;
        }
    }
    void valPos()
    {
        val[0] = plc / 3, val[1] = (plc % 3) - 1, val1 = plc / 3.0;
        if (val[0] == val1)
        {
            val[0] -= 1;
        }
        if (val[1] == -1)
        {
            val[1] = 2;
        }
    }
    // program checks if someone won or its a tie
    void check_win()
    {
        if (((board[0][0] == "𝗫") && (board[0][1] == "𝗫") && (board[0][2] == "𝗫")) || ((board[1][0] == "𝗫") && (board[1][1] == "𝗫") && (board[1][2] == "𝗫")) || ((board[2][0] == "𝗫") && (board[2][1] == "𝗫") && (board[2][2] == "𝗫")))
        {
            brd();
            space();
            cout << "𝗫 Won!" << endl;
            won = 1;
        }
        else if (((board[0][0] == "𝗢") && (board[0][1] == "𝗢") && (board[0][2] == "𝗢")) || ((board[1][0] == "𝗢") && (board[1][1] == "𝗢") && (board[1][2] == "𝗢")) || ((board[2][0] == "𝗢") && (board[2][1] == "𝗢") && (board[2][2] == "𝗢")))
        {
            brd();
            space();
            cout << "O Won!" << endl;
            won = 1;
        }
        else if (((board[0][0] == "𝗫") && (board[1][1] == "𝗫") && (board[2][2] == "𝗫")) || ((board[0][2] == "𝗫") && (board[1][1] == "𝗫") && (board[2][0] == "𝗫")))
        {
            brd();
            space();
            cout << "𝗫 Won!" << endl;
            won = 1;
        }
        else if (((board[0][0] == "𝗢") && (board[1][1] == "𝗢") && (board[2][2] == "𝗢")) || ((board[0][2] == "𝗢") && (board[1][1] == "𝗢") && (board[2][0] == "𝗢")))
        {
            brd();
            space();
            cout << "O Won!" << endl;
            won = 1;
        }
        else if (((board[0][0] == "𝗫") && (board[1][0] == "𝗫") && (board[2][0] == "𝗫")) || ((board[0][1] == "𝗫") && (board[1][1] == "𝗫") && (board[2][1] == "𝗫")) || ((board[0][2] == "𝗫") && (board[1][2] == "𝗫") && (board[2][2] == "𝗫")))
        {
            brd();
            space();
            cout << "𝗫 Won!" << endl;
            won = 1;
        }
        else if (((board[0][0] == "𝗢") && (board[1][0] == "𝗢") && (board[2][0] == "𝗢")) || ((board[0][1] == "𝗢") && (board[1][1] == "𝗢") && (board[2][1] == "𝗢")) || ((board[0][2] == "𝗢") && (board[1][2] == "𝗢") && (board[2][2] == "𝗢")))
        {
            brd();
            space();
            cout << "𝗢 Won!" << endl;
            won = 1;
        }
        else if (m == 10)
        {
            brd();
            space();
            cout << "tie" << endl;
            won = 1;
        }
    }
    void o_move(int& sd) // computer decision part of the game
    {
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono;
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));

        for (int i = 0; i < sd; i++)
        {
            do
            {
                rand_num = rand() % 9 + 1;
                plc = rand_num;
                valPos();
            } while ((board[val[0]][val[1]] == "𝗫") || (board[val[0]][val[1]] == "𝗢"));
        }
    }
};
int main()
{
    main_board myboard; // object declaration  Here an object "myboard" was initialized

    // setting up first board, this is a preview board
    myboard.brd();
    cout << endl;
    cout << "--------------" << endl;
    cout << endl;
    cout << "Seed: ";
    cin >> sd;

    // first interactive board array being activated
    // this gives each space a "small number" unicode  This will later in the game be replaced
    for (int a = 0; a < 3; a++) // nested array to reach all positons of the "board" array
    {
        for (int b = 0; b < 3; b++)
        {
            myboard.board[a][b] = myboard.nums[a][b]; // every array position is assigned a unicode character
        }
    }

    do // the game starts here, this do-while loop will not stop until game ends
    {
        // Puts new board and space at the beginning of the loop
        myboard.brd();
        myboard.space();

        // alternates the player
        myboard.c = 1 - myboard.c;

        // assigns characters to their chosen numbers that is being alternated by "c"
        if (myboard.c == 0)
        {
            myboard.txt = "X";
        }
        else
        {
            myboard.txt = "O";
        }

        cout << myboard.txt << " turn" << endl;
        if (myboard.txt == "X") // person will make this move
        {

            cout << "Position: ";
            cin >> myboard.plc; // lets user type in interface
        }
        else // computer can only make this move
        {
            myboard.o_move(sd);
        }
        myboard.m++;

        // if the number chosen is not a number in between 1 and 9, it will not count that move
        while (!cin || ((myboard.plc > 9) || (myboard.plc < 1)))
        {
            myboard.space();
            myboard.brd();
            myboard.space();
            cout << myboard.txt << " turn" << endl;
            cout << "Enter a number between 1 and 9" << endl;
            cout << "Position: ";
            cin >> myboard.plc;
        }
        myboard.valPos();

        // if same space was chosen, it will not count that move
        while ((myboard.board[myboard.val[0]][myboard.val[1]] == "𝗫") || (myboard.board[myboard.val[0]][myboard.val[1]] == "𝗢"))
        {
            myboard.space();
            myboard.brd();
            myboard.space();
            cout << myboard.txt << " turn" << endl;
            cout << "Square is already used, please put in a different position!" << endl;
            cout << "Position: ";
            cin >> myboard.plc;
            myboard.valPos();
        }

        // after program check if the move is valid, it will assign the player to the chosen space
        myboard.board[myboard.val[0]][myboard.val[1]] = myboard.plr[myboard.c];
        myboard.space();

        // checks who wins or if it's a tie
        myboard.check_win();
    } while (myboard.won != 1);

    return 0;
}