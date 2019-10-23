/*
  nocurses.h - Provides a basic 'VT100 ESC sequences' printing without
               the need to use ncurses. 
               This is inspired by Borland conio.h

  Author     - Rahul M. Juliato
  Original   - 25 jun 2005
  Revision   -    oct 2019
*/

#include <stdio.h>

#define ESC    "\x1b"
#define BLACK   0
#define RED     1
#define GREEN   2
#define YELLOW  3
#define BLUE    4
#define MAGENTA 5
#define CYAN    6
#define WHITE   7

#define TRUE    1
#define FALSE   0


static int bg_color = BLACK,
         font_color = WHITE,
         font_bold  = FALSE;


static void pause(){
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

static void clrline(){
    printf(ESC"[2K"ESC"E");
}

static void resetcolors(){
    printf(ESC"001b"ESC"[0m");
}

