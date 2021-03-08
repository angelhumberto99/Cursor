#include <iostream>
#include "Cursor.h"

int main() { 
    while(true) {
        if (KBHIT()) {
            std::cout << (char)GETCH() << std::endl;
            break;
        }
        std::cout << "infinito" << std::endl;
        SLEEP(1000);
    }
}