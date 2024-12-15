#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

void drawCloud(int x, int y) {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    circle(x, y, 20);
    circle(x + 30, y, 30);
    circle(x + 70, y, 20);
    floodfill(x + 1, y, WHITE);
    floodfill(x + 31, y, WHITE);
    floodfill(x + 71, y, WHITE);
}

void drawRaindrop(int x, int y) {
    setcolor(BLUE);
    line(x, y, x - 5, y + 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");

    int maxX = getmaxx();
    int maxY = getmaxy();


    setcolor(LIGHTBLUE);
    rectangle(0, 0, maxX, maxY);
    floodfill(1, 1, LIGHTBLUE);


    setcolor(GREEN);
    rectangle(0, maxY - 100, maxX, maxY);
    floodfill(1, maxY - 99, GREEN);


    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(100, 100, 50);
    floodfill(100, 100, YELLOW);


    drawCloud(200, 50);
    drawCloud(400, 80);


    for (int i = 0; i < 1000; i++) {
        int x = rand() % maxX;
        int y = rand() % maxY;
        drawRaindrop(x, y);
    }

    getch();
    closegraph();
    return 0;
}
