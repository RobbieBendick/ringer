#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  HWND hwnd = FindWindowA(NULL, "World of Warcraft");

  // random number between 1-12
  int randomNumber = rand() % 12 + 1;

  while (hwnd != NULL) {
    // change the random number to a different random nubmer
    randomNumber = rand() % 12 + 1;

    // wait
    sleep(randomNumber);
    
    // press the F key
    // @params (virtualKeyCode, 0, KeyboardAction, 0)
                       // keydown
    keybd_event(0x46, 0, 0x0001, 0);
                       // keyup
    keybd_event(0x46, 0, 0x0002, 0);
  }
  return 0;
}