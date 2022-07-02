#ifndef MACRO_H
#define MACRO_H
#include <iostream>
#include <Windows.h>
#include <cstdint>
#include <vector>
#include <string>

class Macro {

    std::vector<CHAR> keys;
    std::vector<DWORD> pause;
    bool loop = false;
    UINT stopKey = VK_END;

    public:
        Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop = false, UINT stopKey = VK_END) {
            this->keys = keys;
            this->pause = pause;
            this->loop = loop;
            this->stopKey = stopKey;
        };
        static void pressKey(CHAR keyParam) {
            SHORT key;
            UINT mappedkey;

            INPUT input = { 0 };
            key = VkKeyScan(keyParam);
            mappedkey = MapVirtualKey(LOBYTE(key), 0);
            input.type = INPUT_KEYBOARD;
            input.ki.dwFlags = KEYEVENTF_SCANCODE;
            input.ki.wScan = mappedkey;
            SendInput(1, &input, sizeof(input));
            Sleep(10);
            input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(input));
        }
        void run() {
        if (keys.size() != pause.size()) {
            std::cout << "Amount of keys and breaks must be equal!" << std::endl;
            return;
        }
        do {
            for(int i = 0; i < keys.size(); i++){
                pressKey(keys.at(i));
                Sleep(pause.at(i)*700 + 50);
            }
            if (GetAsyncKeyState(stopKey)) return;
        } while(loop);
    }
};

#endif // MACRO_H
