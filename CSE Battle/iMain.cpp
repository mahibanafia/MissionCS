#include <iostream>
#include <stdlib.h>
using namespace std;
#include "iGraphics.h"

#define scrnWidth 1280
#define scrnHeight 680

int x = 0;
int y = 0;
int cld1PosX = 50;
int cld2PosX = 620;

int chIndex = 0;
int chIndex2 = 10;
int chPosX = 100;
int chPosY = 430;

bool chRight = true;
bool chLeft = true;
int chStand = 0;
int chStand2 = 0;

bool music = false;


int gameState = -1;
int gameState2 = -1;


struct buttonC{

	int x;
	int y;

}butco1[3], butco2[2], butco3;

char menu[200] = "bg\\menu.bmp";
char button[10][15] = { "button\\s.bmp", "button\\h.bmp", "button\\e.bmp" };
char button2[2][15] = { "button\\c.bmp", "button\\i.bmp" };
char back[20] = "button\\back.bmp";

char credit[15] = "bg\\cred.bmp";
char ins[15] = "bg\\ins.bmp";
char Hscore[15] = "bg\\Hscore.bmp";


char bg[15] = "bg\\1.bmp";
char cld[2][15] = { "bg\\cld1.bmp", "bg\\cld2.bmp" };
char ch[20][15] = { "ch\\1.bmp", "ch\\2.bmp", "ch\\3.bmp", "ch\\4.bmp", "ch\\5.bmp", "ch\\6.bmp", "ch\\7.bmp", "ch\\8.bmp", "ch\\9.bmp", "ch\\10.bmp", "ch\\11.bmp", "ch\\12.bmp", "ch\\13.bmp", "ch\\14.bmp", "ch\\15.bmp", "ch\\16.bmp", "ch\\17.bmp", "ch\\18.bmp", "ch\\19.bmp", "ch\\20.bmp" };


void iDraw()
{
	iClear();

	
	if (gameState == -1 && gameState2 == -1){

		iShowBMP(x, y, "bg\\menu.bmp");

		for (int i = 0; i < 3; i++){

			iShowBMP2(butco1[i].x, butco1[i].y, button[i], 0);
		}
		for (int j = 0; j < 2; j++){

			iShowBMP2(butco2[j].x, butco2[j].y, button2[j], 0);
		}

	}

	else if (gameState == 0){

		iShowBMP(x, y, bg);
		iShowBMP2(cld1PosX, 590, "bg\\cld1.bmp", 0);
		iShowBMP2(cld2PosX, 590, "bg\\cld2.bmp", 0);

		if (chRight){
			chLeft = false;
			iShowBMP2(chPosX, chPosY, ch[chIndex], 0);

			chStand++;
			if (chStand >= 20){
				chStand = 0;
				chIndex = 0;

			}
		}

		else if (chLeft){
			chRight = false;

			iShowBMP2(chPosX, chPosY, ch[chIndex2], 0);

			chStand2++;
			if (chStand2 >= 20){
				chStand2 = 0;
				chIndex2 = 10;

			}
		}

	}

	else if (gameState == 1){
		
		iShowBMP(0, 0, Hscore);
		iShowBMP2(10, 10, back, 0);
		
	}
	else if (gameState == 2){

		     exit(0);

	}
	 if (gameState2 == 0){

		iShowBMP(0, 0, credit);
		iShowBMP2(10, 10, back, 0);
	}
	else if (gameState2 == 1){

		iShowBMP(0, 0, ins);
		iShowBMP2(10, 10, back, 0);

	}

	
 
	
}// iDraw End


void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 3; i++){
			if (mx >= butco1[i].x && mx <= butco1[i].x + 178 && my >= butco1[i].y && my <= butco1[i].y + 70)
			{
				gameState = i;
			}
		}

		for (int j = 0; j < 2; j++){
			if (mx >= butco2[j].x && mx <= butco2[j].x + 178 && my >= butco2[j].y && my <= butco2[j].y + 70)
			{
				gameState2 = j;
			}
		}

		if (mx >= butco3.x && mx <= butco3.y + 83 && my >= butco3.y && my <= butco3.y + 83)
		{
			gameState = -1;
			gameState2 = -1;
		}
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
	
}



void iKeyboard(unsigned char key)
{
	if (key == 'w')
	{
		 
	}

	else if (key == 's')
	{
		
	}
	else if (key == 'a')
	{
		
	}
	else if (key == 'd')
	{
		
	}
	
	
}


void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		chLeft = false;
		chRight = true;

		chPosX += 10;


		if (chPosX > scrnWidth - 90){
			chPosX = scrnWidth - 90;

		}

	}


	if (key == GLUT_KEY_LEFT)
	{
		chRight = false;
		chLeft = true;
		chPosX -= 10;


		if (chPosX < 0){
			chPosX = 0;
		}

	}


	if (key == GLUT_KEY_UP)
	{
		if (chRight){
			chLeft = false;
			chPosY += 10;
			if (chPosY > scrnHeight - 94){
				chPosY = scrnHeight - 94;
			}
		}
			else if (!chRight){
				chLeft = true;
				chPosY += 10;
				if (chPosY > scrnHeight - 94){
					chPosY = scrnHeight - 94;
				}
			}


		}
	
	if (key == GLUT_KEY_DOWN)
	{
		if (chRight){
			chLeft = false;
			chPosY -= 10;
			if (chPosY < 150){
				chPosY = 150;
				
			}
		}
		else if (!chRight){
			chLeft = true;
			chPosY -= 10;
			if (chPosY < 150){
				chPosY = 150;
			}
		}
	}
	
}

void change(){


	if (chRight){


		chIndex++;

		if (chIndex > 9)
			chIndex = 0;
	}

	else if (chLeft)
	{
		chIndex2++;

		if (chIndex2 > 19)
		{
			chIndex2 = 10;
		}

	}

}
void change2(){

	cld1PosX++;
	cld2PosX++;
	if (cld1PosX >= 1280){
		cld1PosX = 0;
	}

	if (cld2PosX >= 1280){
		cld2PosX = 0;
	}
	
	
}



int main()
{
	iSetTimer(25, change);
	iSetTimer(50, change2);

	int sum = 165;
	for (int i = 2; i >= 0; i--){

		butco1[i].x = 270;
		butco1[i].y = sum;
		sum += 100;

	}
	int sum2 = 75;
	for (int j = 1; j >= 0; j--){
		
		butco2[j].x = sum2;
		butco2[j].y = 265;
		sum2 += 390;
	}
	butco3.x = 10;
	butco3.y = 10;
	
	if (!music)
	{
		PlaySound("music\\m.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	
	iInitialize(scrnWidth, scrnHeight, "Mission CS");
	iStart();
	
	
	return 0;
}