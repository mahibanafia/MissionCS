#include "iGraphics.h"
#include <iostream>
using namespace std;


#define scrnWidth 1200
#define scrnHeight 600

int x = 0;
int y = 0;
int chIndex = 0;
int chIndex2 = 10;
int chPosX = 100;
int chPosY = 430;
bool chRight = true;
bool chLeft = true;
int chStand = 0;
int chStand2 = 0;

void bgImg(){
	int bg[4] = { iLoadImage("bg\\1.png") };
	iShowImage(x, y, scrnWidth, scrnHeight, bg[0]);
}

void ch(){

	int ch[20] = { iLoadImage("ch\\1.png"), iLoadImage("ch\\2.png"), iLoadImage("ch\\3.png"), iLoadImage("ch\\4.png"), iLoadImage("ch\\5.png"), iLoadImage("ch\\6.png"), iLoadImage("ch\\7.png"), iLoadImage("ch\\8.png"), iLoadImage("ch\\9.png") };
	iShowImage(chPosX, chPosY, 94, 94, ch[chIndex]);

}
void ch2(){
	int ch[20] = { iLoadImage("ch\\10.png"), iLoadImage("ch\\11.png"), iLoadImage("ch\\12.png"), iLoadImage("ch\\13.png"), iLoadImage("ch\\14.png"), iLoadImage("ch\\15.png"), iLoadImage("ch\\16.png"), iLoadImage("ch\\17.png"), iLoadImage("ch\\18.png"), iLoadImage("ch\\19.png"), iLoadImage("ch\\20.png") };
	iShowImage(chPosX, chPosY, 94, 94, ch[chIndex2]);
}
 

















