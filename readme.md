nocurses.h
----------

This library provides terminal manipulation capability by the use of VT100 ESC sequences. 

It is aimed to simple applications where ncurses is simple "too much".

Inspired on the old Borland conio.h for DOS.


Functions Provided
------------------
| Function                 |                                       Description                                      |        Example       |
|--------------------------|:--------------------------------------------------------------------------------------:|:--------------------:|
| pause()                  |                           Waits for the user to hit [ENTER].                           |       pause();       |
| clrscr()                 |                                   Clears the screen.                                   |       clrscr();      |
| gotoxy(x, y)             | Sets the cursor do the position x, y. Where x is the row number and y the line number. |    gotoxy(10,25);    |
| setfontcolor(color_name) | Sets the text color to one of the colors described on the color table below.           | setfontcolor(RED);   |
| setbgrcolor(color_name)  | Sets the background color to one of the colors described on the color table below.     | setbgrcolor(BLUE);   |
| setfontbold(status)      | Sets the bold atribute on or off. status can be TRUE or FALSE.                         | setfontbold(TRUE);   |
| setunderline(status)     | Sets the underline atribute on or off. status can be TRUE or FALSE.                    | setunderline(FALSE); |
| setblink(status)         | Sets the blink atribute on or off. status can be TRUE or FALSE.                        | setblink(TRUE);      |
| clrline()                | Clears the row contents.                                                               | clrline();           |



color_name
----------

Valid color names are:

| color_name |
|:----------:|
| BLACK      |
| RED        |
| GREEN      |
| YELLOW     |
| BLUE       |
| MAGENTA    |
| CYAN       |
| WHITE      |

