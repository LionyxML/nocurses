/*
  nocurses.h - Provides a basic 'VT100 ESC sequences' printing without
               the need to use ncurses. 
               This is inspired by Borland conio.h

  Author     - Rahul M. Juliato
  Original   - 25 jun 2005
  Revision   -    oct 2019
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


int bg_color   = BLACK,
    font_color = WHITE,
    font_bold  = FALSE;


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
    font_color = color;
}

void setbgrcolor(int color){
    printf("%c[4%dm", ESC, color);
    bg_color = color;
}


void setfontbold(int status){
    printf("%c[%dm", ESC, status);
    font_bold = status;
    setfontcolor(font_color);
    setbgrcolor(bg_color);
}

void setunderline(int status){
    if (status) status = 4;
    printf("%c[%dm", ESC, status);
    setfontcolor(font_color);
    setbgrcolor(bg_color);
    setfontbold(font_bold);
}

void setblink(int status){
    if (status) status = 5;
    printf("%c[%dm", ESC, status);
    setfontcolor(font_color);
    setbgrcolor(bg_color);
    setfontbold(font_bold);
}

void clrline(){
    printf("%c[2K%cE", ESC, ESC);
}

void resetcolors(){
    printf("%c001b%c[0m", ESC, ESC);
}

