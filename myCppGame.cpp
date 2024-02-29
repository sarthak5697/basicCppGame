#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <limits>  // Add t

using namespace std;

int i;

void clrscr() {
    system("cls");
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void star() {
    //cout << "working";
    gotoxy(1, 5);
    for (i = 1; i < 81; i++)
        cout << "*";
    gotoxy(1, 21);
    for (i = 1; i < 81; i++)
        cout << "*";
    for (i = 6; i < 21; i++) {
        gotoxy(1, i);
        cout << "!";
        gotoxy(80, i);
        cout << "!";
    }
}

int main() {
    char p[10] = { '\1','\1','\1','\1',' ',' ','\2','\2','\2','\2' };
    int q;
    int n;

    while (1) {
        q = 27;
        clrscr();
        star();
        gotoxy(36, 7);
        cout << "END TO END";
        for (i = 0; i < 10; i++) {
            gotoxy(q, 10);
            cout << p[i];
            q += 3;
        }
        gotoxy(27, 11);
        cout << "\6--\6--\6--\6--\6--\6--\6--\6--\6--\6" << endl;
        gotoxy(27, 13);
        cout << "0  1  2  3  4  5  6  7  8  9";
        gotoxy(5, 19);
        cout << "A) Enter 100 for Help ";
        gotoxy(29, 19);
        cout << "B) Enter 101 for Restart ";
        gotoxy(56, 19);
        cout << "C) Enter 102 for Exit ";

        if (p[0] == '\2' && p[1] == '\2' && p[2] == '\2' && p[3] == '\2' && p[6] == '\1' && p[7] == '\1' && p[8] == '\1' && p[9] == '\1') {
            gotoxy(26, 14);
            cout << "___";
            gotoxy(19, 15);
            cout << "\\   / |   | |   |     \\    /\\    / | |\\    |";
            gotoxy(20, 16);
            cout << "\\ /  |   | |   |      \\  /  \\  /  | |  \\  |";
            gotoxy(21, 17);
            cout << "|   |___| |___|       \\/    \\/   | |    \\|";
            std::cin.get();
            break;
        }

        gotoxy(3, 16);
        cout << "Which Smile you want to move Forward : ";
        cin >> n;
        cin.ignore();

        // Consume the newline character from the input buffer
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (n == 100) {
            cout << "n is now 100";
            clrscr();
            star();
            gotoxy(37, 9);
            cout << "\3 HELP \3";
            gotoxy(10, 12);
            cout << "The Object of the Game is to get the Black Smiles to the Right";
            gotoxy(23, 14);
            cout << "and get the White Smiles on the Left";
            gotoxy(10, 16);
            cout << "You can only move Smiles by jumping another Smiles or moving one";
            gotoxy(30, 18);
            cout << "step to an empty space";
            std::cin.get();
        }
        else if (n == 101) {
            p[0] = '\1'; p[1] = '\1'; p[2] = '\1'; p[3] = '\1';
            p[4] = ' '; p[5] = ' ';
            p[6] = '\2'; p[7] = '\2'; p[8] = '\2'; p[9] = '\2';
        }
        else if (n == 102) {
            break;
        }
        else if (p[n] == '\1') {
            if (p[n + 1] == ' ') {
                p[n] = ' ';
                p[n + 1] = '\1';
            }
            else if (p[n + 2] == ' ') {
                p[n] = ' ';
                p[n + 2] = '\1';
            }
            else {
                gotoxy(61, 16);
                cout << "Not Possible";
                std::cin.get();
            }
        }
        else if (p[n] == '\2') {
            if (p[n - 1] == ' ') {
                p[n] = ' ';
                p[n - 1] = '\2';
            }
            else if (p[n - 2] == ' ') {
                p[n] = ' ';
                p[n - 2] = '\2';
            }
            else {
                gotoxy(61, 16);
                cout << "Not Possible";
                std::cin.get();
            }
        }
        else {
            gotoxy(56, 16);
            cout << "Select the Smile";
            std::cin.get();
        }
    }

    return 0;
}
