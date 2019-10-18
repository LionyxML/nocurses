/*
  nocurses.h - Provides a basic 'VT100 ESC sequences' printing without
               the need to use ncurses. 
               This is inspired by Borland conio.h

  Author     - Rahul M. Juliato
  Original   - 25 jun 2005
  Revision   - 17 oct 2019
*/

#include <stdio.h>

#define ESC    27
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


int GdBgColor   = 47,
    GdFontColor = 30,
    GdFontBold  = 0 ;


void pause(){
    fgetc(stdin);
}


void clrscr(){
    printf("%c[2J%c[?6h", ESC, ESC);
}


void gotoxy(int x, int y){
    printf("%c[%d;%dH", ESC, y, x);
}


void setfontcolor(int color){
    printf("%c[3%dm", ESC, color);
    GdFontColor = color;
}

void setbgrcolor(int color){
    printf("%c[4%dm", ESC, color);
    GdBgColor = color;
}


void setfontbold(int status){
    printf("%c[%dm", ESC, status);
    GdFontBold = status;
    setfontcolor(GdFontColor);
    setbgrcolor(GdBgColor);
}

void setunderline(int status){
    if (status) status = 4;
    printf("%c[%dm", ESC, status);
    setfontcolor(GdFontColor);
    setbgrcolor(GdBgColor);
    setfontbold(GdFontBold);
}

void setblink(int status){
    if (status) status = 5;
    printf("%c[%dm", ESC, status);
    setfontcolor(GdFontColor);
    setbgrcolor(GdBgColor);
    setfontbold(GdFontBold);
}

void clrline(){
    printf("%c[2K%cE", ESC, ESC);
}

