#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utility.h"



void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    //cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

void textAttr(char Attr) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Attr);
}

void textBackground(char Color) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&Info);
    textAttr((Color << 4)+(Info.wAttributes & 0x0F));
}

void textForeground(char Color) {
    CONSOLE_SCREEN_BUFFER_INFO Info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&Info);
    textAttr((Info.wAttributes << 4)+(Color & 0x0F));
}

void curseur()
{
    POINT pt;
    BOOL bContinue = TRUE;
    const SHORT Mask = 32768;
    while (bContinue)
    {
        if (GetKeyState(VK_ESCAPE) & Mask)
           bContinue = FALSE;
        GetCursorPos(&pt);
        if (GetKeyState(VK_UP) & Mask)
           pt.y -= 5;
        if (GetKeyState(VK_DOWN) & Mask)
           pt.y += 5;
        if (GetKeyState(VK_LEFT) & Mask)
           pt.x -= 5;
        if (GetKeyState(VK_RIGHT) & Mask)
           pt.x += 5;
        SetCursorPos(pt.x,pt.y);
        printf("%d - %d", (int)pt.x,(int)pt.y);
        //Sleep(50);
        system("cls");
    }
}

void welcomemsg()
{
    int c;
    char *ch = "WELCOME TO NAGATO WORLD";
    char *ca = "WARNING \n";
    char *ce = "IF YOU CHOOSE A NUMBER BIGGER THAN 12; YOU GONNA BE TELEPORTED TO HELL";
    char *cc = "\t\t\t\t\t\t";
    char *t = ca;
    color(9,0);
    gotoxy(25,15);
    while(*t != '\0')
    {
        printf("%c",*t);
        t++;
        Sleep(60);
    }
    t = ce;
    gotoxy(30,18);
    while(*t != '\0')
    {
        printf("%c",*t);
        t++;
        Sleep(50);
    }

    do
    {
        c = getch();
        //printf(" c = %d", c);
    }while(c != 13);

    system("cls");
    t = cc;
    gotoxy(25,18);
    color(9,0);
    printf("CHARGEMENT :");
    gotoxy(40,18);
    color(0,7);
    while(*t != '\0')
    {
        printf("%c",*t);
        t++;
        Sleep(500);
    }
    color(9,0);
    t = ch;
    gotoxy(53,20);
    while(*t != '\0')
    {
        printf("%c",*t);
        t++;
        Sleep(100);
    }
    do
    {
        c = getch();
    }while(c != 13);
    system("cls"); // clear screen
}

void drawframe()
{
    int i=0;
    gotoxy(144,2);
    color(0,15);
    printf(" M E N U");
    color(10,0);
    gotoxy(140,3);
    printf("__________________");

    gotoxy(144,5);
    printf("Couleurs");
    gotoxy(144,6);
    printf("________");

    gotoxy(144,8);
    color(0,8);
    printf("   ");
    color(10,0);

    gotoxy(144,10);
    color(0,9);
    printf("   ");
    color(10,0);

    gotoxy(144,12);
    color(0,10);
    printf("   ");
    color(10,0);

    gotoxy(144,14);
    color(0,11);
    printf("   ");
    color(10,0);

    gotoxy(149,8);
    color(0,12);
    printf("   ");
    color(10,0);

    gotoxy(149,10);
    color(0,13);
    printf("   ");
    color(10,0);

    gotoxy(149,12);
    color(0,14);
    printf("   ");
    color(10,0);

    gotoxy(149,14);
    color(0,15);
    printf("   ");
    color(10,0);


    gotoxy(144,17);
    printf("Pinceaux");
    gotoxy(144,18);
    printf("________");

    gotoxy(144,20);
    //color(0,10);
    printf("*");
    color(10,0);

    gotoxy(149,20);
    color(0,10);
    printf("  ");
    color(10,0);

    gotoxy(144,25);
    printf("________");
    gotoxy(144,26);
    printf("\\ Gomme \\");
    gotoxy(145,27);
    printf("________");



    while(i<50)
    {
        gotoxy(140,i);
        printf("%c", 219);
        i++;
    }
}


