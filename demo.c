
/* 

   nocurses.h - nocurses library demo

   Compile and run with: $gcc -pthread -lm -o demo demo.c && ./demo

*/


#include <stdio.h>
#include "nocurses.h"

int i;

int waiting(){
  printf("\n\nHit ENTER to continue...");
  pause();
  clrscr();
  return 0;
}


int fancyline(void){
  int j;
  
  j = 0;
  for(i=0;i<51;i++){
    setfontcolor(j);
    j++;
    if (j == 8) j = 0;
    printf(".");
  }
  setfontcolor(BLACK);
  return 0;
}


int main(void) {

  clrscr();
  setfontbold(TRUE);

  fancyline();
  
  printf("\n\
                                             _\n\
 _ __   ___   ___ _   _ _ __ ___  ___  ___  | |__\n\
| '_ \\ / _ \\ / __| | | | '__/ __|/ _ \\/ __| | '_ \\\n\
| | | | (_) | (__| |_| | |  \\__ \\  __/\\__ \\_| | | |\n\
|_| |_|\\___/ \\___|\\__,_|_|  |___/\\___||___(_)_| |_|\n");

  fancyline();
  setfontbold(FALSE);

  setfontcolor(WHITE);
  
  printf("\n\n\nHello! Welcome to nocurses.h demo!\nLet me present you its features... \n");

  waiting();

  printf("The nocurses.h provides these set of functions:\n\n\
pause()\n\
clrscr()\n\
setfontcolor(COLOR_NAME)\n\
setbgrcolor(COLOR_NAME)\n\
gotoxy(XPOS,YPOS)\n\
setfontbold(STATE)\n\
setunderline(STATE)\n\
setblink(STATE)\n");
  waiting();

  printf("I am using the pause() function to wait for your\ncommand.");
  waiting();

  printf("See it? The screen was cleared with the clrscr() funciton.");
  waiting(); 

  gotoxy(5, 6);
  printf("Now I am here!");
  gotoxy(10, 8);
  printf("And now I am there!");

  printf("\n\nJust use gotoxy(position x, position y) to move around!");
  waiting(); 

  for(i=0;i<8;i++){
    setfontcolor(i);
    printf("I can change font colors!\n");
  }
  printf("\nUse setfontcolor(COLOR_NAME) function!");
  waiting();

  for(i=0;i<8;i++){
    setbgrcolor(i);
    printf("I can also change background colors!\n");
  }
  setbgrcolor(BLUE);
  setfontcolor(WHITE);
  printf("\nYou just have to use setbgrcolor(COLOR_NAME) function!");
  waiting();

  printf("See it!?\n\nThis is what happens if you clear\n a screen with your new colors!");
  waiting();

  resetcolors();
  clrscr();

  printf("Now I used resetcolors()");
  waiting();

  clrscr();
  printf("Now some fancy stuff. \n\nThis may or may not work in your terminal emulator,\n so I am going to TRY stuff, ok?\n\n");
  waiting();

  setfontcolor(WHITE);
  setbgrcolor(BLACK);

  setfontbold(TRUE);
  printf("BOLD is set to TRUE --> setfontbold(TRUE)\n\n");
  waiting();

  setfontbold(FALSE);
  printf("BOLD is set to FALSE --> setfontbold(FALSE)\n\n");
  waiting();

  setunderline(TRUE);
  printf("UNDERLINE is set to TRUE --> setunderline(TRUE)\n\n");
  waiting();

  setunderline(FALSE);
  printf("UNDERLINE is set to FALSE --> setunderline(FALSE)\n\n");
  waiting();

  setblink(TRUE);
  printf("Blinking cursor is set to TRUE --> setblink(TRUE)\n\n");
  waiting();

  setblink(FALSE);
  printf("Blinking cursor is set to FALSE --> setblink(FALSE)\n\n");
  waiting();

  printf("\n\nThat's all! Simple nocurses.h\n\nContribute with it on https://github.com/LionyxML/nocurses/\n\n");

  waiting();
  clrscr();
  
  
  return 0;
}


