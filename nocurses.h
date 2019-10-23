/*
  nocurses.h - Provides a basic 'VT100 ESC sequences' printing without
               the need to use ncurses. 
               This is inspired by Borland conio.h

  Author     - Rahul M. Juliato
  Original   - 25 jun 2005
  Revision   -    oct 2019
*/

#include <stdio.h>
// for getting term size
#ifdef _WIN32
# include <windows.h>
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__) || defined(__linux__)
# ifndef __unix__
#  define __unix__
# endif
# include <sys/ioctl.h>
# include <unistd.h>
#endif

#define ESC    "\x1b"

#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

#define BLOCK_BLINK     1
#define BLOCK           2
#define UNDERLINE_BLINK 3
#define UNDERLINE       4
#define BAR_BLINK       5
#define BAR             6

#define TRUE    1
#define FALSE   0

struct termsize {
    int cols;
    int rows;
};


static int bg_color = BLACK,
         font_color = WHITE,
         font_bold  = FALSE;


static void wait(){
    fgetc(stdin);
}


static void clrscr(){
    printf(ESC"[2J"ESC"[?6h");
}


static void gotoxy(int x, int y){
    printf(ESC"[%d;%dH", y, x);
}


static void setfontcolor(int color){
    printf(ESC"[3%dm", color);
    font_color = color;
}

static void setbgrcolor(int color){
    printf(ESC"[4%dm", color);
    bg_color = color;
}


static void setfontbold(int status){
    printf(ESC"[%dm", status);
    font_bold = status;
    setfontcolor(font_color);
    setbgrcolor(bg_color);
}

static void setunderline(int status){
    if (status) status = 4;
    printf(ESC"[%dm", status);
    setfontcolor(font_color);
    setbgrcolor(bg_color);
    setfontbold(font_bold);
}

static void setblink(int status){
    if (status) status = 5;
    printf(ESC"[%dm", status);
    setfontcolor(font_color);
    setbgrcolor(bg_color);
    setfontbold(font_bold);
}

static void settitle(char const* title) {
    printf(ESC"]0;%s\x7", title);
}

static void setcurshape(int shape){
    // vt520/xterm-style; linux terminal uses ESC[?1;2;3c, not implemented
    printf(ESC"[%d q", shape);
}

static struct termsize gettermsize(){
    struct termsize size;
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    size.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#elif defined(__unix__)
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    size.cols = win.ws_col;
    size.rows = win.ws_row;
#else
    size.cols = 0;
    size.rows = 0;
#endif
    return size;
}

static void clrline(){
    printf(ESC"[2K"ESC"E");
}

static void resetcolors(){
    printf(ESC"001b"ESC"[0m");
}

