#include <iostream>
#include <Windows.h>
#include <conio.h>

void showIntro() {
    //Tells users how to use the program and how they can close the program
    MessageBox(0, 
        L"\
    ****************************************************************** \n \
                                                                       \n \
          This program will press shift key every 5 minutes.               \n \
          This program WILL run in BACKGROUND.                         \n \
          If you want to close the program,                            \n \
          press ALT + SHIFT + DEL to activate process manger.          \n \
                                                                       \n \
   ******************************************************************", 
        L"Awesome-mouse-mover Instruction", 
        MB_SETFOREGROUND);
}

void runMacro() {
    //Moves mouse to upper left corner and press shift every 5 minutes.
    int counter = 0;
    while (true) {
        if (counter >= 300) {
            counter = 0;
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
        ++counter;  Sleep(1000);
    }
}

int main(){
    showIntro();
    FreeConsole();
    runMacro();
    return 0;
}
