#include <windows.h>
#include <stdio.h>
#include <unistd.h>


int main( void )
{

    HWND hwnd = FindWindowA(NULL, "World of Warcraft");

    // random number between 1-12
    int randomNumber = rand() % 12 + 1;

    // while the game process is running
    while (hwnd != NULL) {
        printf("%d", randomNumber);

        // reset the random number to a different random number
        randomNumber = rand() % 12 + 1;

        sleep(randomNumber);
    }
    return 0;
}
