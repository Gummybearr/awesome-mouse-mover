#include <iostream>
#include <Windows.h>
#include <conio.h>

char WORKSPACE = 'f';

void showIntro() {
    //Tells users how to use the program and how they can set the program run in background or foreground.
    printf("\
    *********************************************************************** \n \
        This program moves your mouse to upper left corner every 5 minutes. \n \
        If you want to execute this program in foreground, press F key.     \n \
        Otherwise, this program will run in background in 5 seconds.       \n \
   ***********************************************************************  \n\n");
}

void getKeyboardInput() {
    //Stores keyboard inputs and saves to global variable WORKSPACE.
    int counter = 0;
    int nKey;
    while (counter <= 5) {
        if (_kbhit()) { nKey = _getch();    WORKSPACE = nKey; }
        ++counter;  Sleep(1000);
    }
}

void determineConsoleState() {
    //Determines process to be run in background or on foreground depending on user input.
    printf("Program rus ");
    if (WORKSPACE == 'f' || WORKSPACE == 'F') { 
        printf("on FOREGROUND\n"); 
    }
    else { 
        printf("in BACKGROUND\n");
        printf("To terminate the program, you would have to run process manager by pressint ALT + SHIFT + DEL\n");
        Sleep(2000);
    }
    if (!(WORKSPACE == 'f' || WORKSPACE == 'F')) FreeConsole();
}

void runMacro() {
    //Moves mouse to upper left corner and clicks every 5 minutes.
    int counter = 0;
    while (true) {
        if (counter >= 300) {
            printf("cursor moves to ( 0,  0 )\n");
            counter = 0;
            SetCursorPos(763, 1060);
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        ++counter;  Sleep(1000);
    }
}

int main(){
    showIntro();
    getKeyboardInput();
    determineConsoleState();
    runMacro();
    return 0;
}
