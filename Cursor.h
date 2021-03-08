#ifndef CURSOR_H
#define CURSOR_H

    #if _WIN64 || _WIN32    //define los macros de CLEAR y SLEEP para Windows
        #include <Windows.h>
        #include <conio.h>
        #define CLEAR system("cls")
        #define SLEEP(x) Sleep(x)
        #define GETCH() getch()
        #define KBHIT() kbhit()
    #else                   //define los macros de CLEAR y SLEEP para Linux
        #include <sys/ioctl.h>
        #include <termios.h>
        #include <chrono>
        #include <thread>
        #define CLEAR system("clear");
        #define SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
        #define KBHIT() { \
            termios term; \
            tcgetattr(0, &term); \
            termios term2 = term; \
            term2.c_lflag &= ~ICANON; \
            tcsetattr(0, TCSANOW, &term2); \
            int byteswaiting; \
            ioctl(0, FIONREAD, &byteswaiting); \
            tcsetattr(0, TCSANOW, &term); \
            return byteswaiting > 0; \
        }
    #endif

    //incluye las bibliotecas necesarias para manipular el cursor y el tiempo
    #include <stdio.h>

    #define GOTO_XY(x, y) printf("%c[%d;%df",0x1B,y,x);  //macro para definir las coordenadas donde imprimir
    #define HIDE_CURSOR printf("\e[?25l");   //macro para esconder el cursor
    #define SHOW_CURSOR printf("\e[?25h");   //macro para mostrar el cursor

#endif
