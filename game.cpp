#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include<string>
#include<cmath> 
using namespace std;
//variable declartion
float x = 496;
float y = 32; 
float x3 = 280;
float y3 = 32;
float x4 = 600;
float y4 = 32; 
int randomposition;
int points=328;
string Points;
int h=0;
int lifes=3;
string Life;
int level;
string Level;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
// display front menu
void menudisplay()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 400, 450, "PRESS 1-Start", colors[MISTY_ROSE]);
	DrawString( 400, 400, "PRESS 2-High Scores", colors[MISTY_ROSE]);
	DrawString( 400, 350, "PRESS 3-Help", colors[MISTY_ROSE]);
	DrawString( 400, 300, "PRESS 4-Exit", colors[MISTY_ROSE]);
	glutSwapBuffers();
	glutPostRedisplay();
}
// display game over at the end of game
void gameover(){
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

DrawString( 400, 450, "GAME OVER", colors[MISTY_ROSE]);
}
// display in order to print help menu
void help(){
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 100, 500, "Set of instructions", colors[RED]);
	DrawString( 100, 400, "1- Press arrow keys to control the car", colors[WHITE]);
	DrawString( 100, 360, "2- Press down key for downward movement.", colors[WHITE]);
	DrawString( 100, 320, "3- Press left key for leftward movement.", colors[WHITE]);
	DrawString( 100, 280, "4- Press left key for leftward movement.", colors[WHITE]);
	DrawString( 100, 240, "5- Press Space key to boost up the speed of your car", colors[WHITE]);
	DrawString( 100, 200, "6- Bonus of 100 after evry successive level.", colors[WHITE]);

	glutSwapBuffers();
	glutPostRedisplay();
}
// display reprint menu as the game is resumed
void reprintmenu()
{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 400, 450, "PRESS 1-Resume", colors[MISTY_ROSE]);
	DrawString( 400, 400, "PRESS 2-High Scores", colors[MISTY_ROSE]);
	DrawString( 400, 350, "PRESS 3-Help", colors[MISTY_ROSE]);
	DrawString( 400, 300, "PRESS 4-Exit", colors[MISTY_ROSE]);
	glutSwapBuffers();
	glutPostRedisplay();
}




float *colorfood[64];
int arpfoodx[64]={55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780,55,130,215,295,510,620,700,780};
int argfoody[64]={45,45,45,45,45,45,45,45,130,130,130,130,130,130,130,130,215,215,215,215,215,215,215,215,300,300,300,300,300,300,300,300,520,520,520,520,520,520,520,520,605,605,605,605,605,605,605,605,690,690,690,690,690,690,690,690,775,775,775,775,775,775,775,775};

// display of cars, arena
void GameDisplay()/**/{
if(h==1)
{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	Points=to_string(points);
	DrawString( 510, 850, "Score = "+Points, colors[RED]);
	Life=to_string(lifes);
	DrawString( 200, 850, "Lives = "+Life, colors[RED]);
	Level=to_string(level);
	DrawString( 350, 890, "Level = "+Level, colors[RED]);

	if ((x<=x3+10) && (y<=y3+10) && (x>=x3-10) && (y>=y3-10))
	{
	x = 496;
	y = 32; 
	x3 = 280;
	y3 = 32;
	srand(time(0));
	randomposition=rand()%3+1;
		if(randomposition==1)
		{x=496;
		y=760;}
		/*else if(randomposition==2)
		{x=24;
		y=472;}*/
		else if(randomposition==3)
		{x=760;
		y=472;}
	lifes--;
		for(int i=0;i<=63;i++)
		{
		colorfood[i]=colors[MISTY_ROSE];
		}
	if (level==1){points=0;}
	if (level==2){points=164;}
	if (level==3){points=328;}
	if (level==4){points=492;}
	}
	if(level==4)
	{
	if (((x4<=x3+10) && (y4<=y3+10) && (x4>=x3-10) && (y4>=y3-10)))
	{x = 496;
	y = 32;
	x4 = 600;
	y4 = 32;
		for(int i=0;i<=63;i++)
		{
		colorfood[i]=colors[MISTY_ROSE];
		}
	if (level==4){points=492;}	}
	}
	//Drawing Food
	
	// First row
	DrawLine(45,  45,  65, 45 , 10 , colorfood[0]);
	DrawLine(120, 45, 140, 45 , 10 , colorfood[1]);
	DrawLine(205, 45, 225, 45 , 10 , colorfood[2]);
	DrawLine(285, 45, 305, 45 , 10 , colorfood[3]);
	DrawLine(520, 45, 540, 45 , 10 , colorfood[4]);
	DrawLine(610, 45, 630, 45 , 10 , colorfood[5]);
	DrawLine(690, 45, 710, 45 , 10 , colorfood[6]);
	DrawLine(770, 45, 790, 45 , 10 , colorfood[7]);
	// Second row
	DrawLine(45,  130,  65, 130 , 10 , colorfood[8]);
	DrawLine(120, 130, 140, 130 , 10 , colorfood[9]);
	DrawLine(205, 130, 225, 130 , 10 , colorfood[10]);
	DrawLine(285, 130, 305, 130 , 10 , colorfood[11]);
	DrawLine(520, 130, 540, 130 , 10 , colorfood[12]);
	DrawLine(610, 130, 630, 130 , 10 , colorfood[13]);
	DrawLine(690, 130, 710, 130 , 10 , colorfood[14]);
	DrawLine(770, 130, 790, 130 , 10 , colorfood[15]);
	// Third row
	DrawLine(45,  215,  65, 215 , 10 , colorfood[16]);
	DrawLine(120, 215, 140, 215 , 10 , colorfood[17]);
	DrawLine(205, 215, 225, 215 , 10 , colorfood[18]);
	DrawLine(285, 215, 305, 215 , 10 , colorfood[19]);
	DrawLine(520, 215, 540, 215 , 10 , colorfood[20]);
	DrawLine(610, 215, 630, 215 , 10 , colorfood[21]);
	DrawLine(690, 215, 710, 215 , 10 , colorfood[22]);
	DrawLine(770, 215, 790, 215 , 10 , colorfood[23]);
	// Fourth row
	DrawLine(45,  300,  65, 300 , 10 , colorfood[24]);
	DrawLine(120, 300, 140, 300 , 10 , colorfood[25]);
	DrawLine(205, 300, 225, 300 , 10 , colorfood[26]);
	DrawLine(285, 300, 305, 300 , 10 , colorfood[27]);
	DrawLine(520, 300, 540, 300 , 10 , colorfood[28]);
	DrawLine(610, 300, 630, 300 , 10 , colorfood[29]);
	DrawLine(690, 300, 710, 300 , 10 , colorfood[30]);
	DrawLine(770, 300, 790, 300 , 10 , colorfood[31]);
	// Fifth row
	DrawLine(45,  520,  65, 520 , 10 , colorfood[32]);
	DrawLine(120, 520, 140, 520 , 10 , colorfood[33]);
	DrawLine(205, 520, 225, 520 , 10 , colorfood[34]);
	DrawLine(285, 520, 305, 520 , 10 , colorfood[35]);
	DrawLine(520, 520, 540, 520 , 10 , colorfood[36]);
	DrawLine(610, 520, 630, 520 , 10 , colorfood[37]);
	DrawLine(690, 520, 710, 520 , 10 , colorfood[38]);
	DrawLine(770, 520, 790, 520 , 10 , colorfood[39]);
	// Sixth row
	DrawLine(45,  605,  65, 605 , 10 , colorfood[40]);
	DrawLine(120, 605, 140, 605 , 10 , colorfood[41]);
	DrawLine(205, 605, 225, 605 , 10 , colorfood[42]);
	DrawLine(285, 605, 305, 605 , 10 , colorfood[43]);
	DrawLine(520, 605, 540, 605 , 10 , colorfood[44]);
	DrawLine(610, 605, 630, 605 , 10 , colorfood[45]);
	DrawLine(690, 605, 710, 605 , 10 , colorfood[46]);
	DrawLine(770, 605, 790, 605 , 10 , colorfood[47]);
	// Seventh row
	DrawLine(45,  690,  65, 690 , 10 , colorfood[48]);
	DrawLine(120, 690, 140, 690 , 10 , colorfood[49]);
	DrawLine(205, 690, 225, 690 , 10 , colorfood[50]);
	DrawLine(285, 690, 305, 690 , 10 , colorfood[51]);
	DrawLine(520, 690, 540, 690 , 10 , colorfood[52]);
	DrawLine(610, 690, 630, 690 , 10 , colorfood[53]);
	DrawLine(690, 690, 710, 690 , 10 , colorfood[54]);
	DrawLine(770, 690, 790, 690 , 10 , colorfood[55]);
	// Eighth row
	DrawLine(45,  775,  65, 775 , 10 , colorfood[56]);
	DrawLine(120, 775, 140, 775 , 10 , colorfood[57]);
	DrawLine(205, 775, 225, 775 , 10 , colorfood[58]);
	DrawLine(285, 775, 305, 775 , 10 , colorfood[59]);
	DrawLine(520, 775, 540, 775 , 10 , colorfood[60]);
	DrawLine(610, 775, 630, 775 , 10 , colorfood[61]);
	DrawLine(690, 775, 710, 775 , 10 , colorfood[62]);
	DrawLine(770, 775, 790, 775 , 10 , colorfood[63]);
	
	// Drawing opponent car
	float width = 13.9; 
	float height = 8.9;
	float* color = colors[BLUE_VIOLET]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color-475,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color-475,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color-475,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color-475,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color-475, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color-475, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color-475, radius/2); // body right rect

	// Drawing players car
	DrawRoundRect(x3,y3,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x3+width*3,y3,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x3+width*3,y3+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x3,y3+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x3, y3+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x3+width, y3+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x3+width*3, y3+height*2, width, height, color, radius/2); // body right rect

	//second opponent car for level four
	if (level==4){
	DrawRoundRect(x4,y4,width,height,color-475,radius); // bottom left tyre
	DrawRoundRect(x4+width*3,y4,width,height,color-475,radius); // bottom right tyre
	DrawRoundRect(x4+width*3,y4+height*4,width,height,color-475,radius); // top right tyre
	DrawRoundRect(x4,y4+height*4,width,height,color-475,radius); // top left tyre
	DrawRoundRect(x4, y4+height*2, width, height, color-475, radius/2); // body left rect
	DrawRoundRect(x4+width, y4+height, width*2, height*3, color-475, radius/2); // body center rect
	DrawRoundRect(x4+width*3, y4+height*2, width, height, color-475, radius/2); // body right rect
	}
	// Drawing Arena
	int gap_turn = 130;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];

	//Outer Arena
	DrawRectangle(sx-20, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx+20 + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx+20 + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx-20, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

	//First inner Arena
	DrawRectangle(sx+60, sy+80, swidth-80, sheight, scolor); // bottom left
	DrawRectangle(sx+100 + swidth - 80 + gap_turn, sy+80, swidth-80, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-80, sy+sheight+80, sheight*2, swidth-80, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-80, sy+sheight+swidth+gap_turn, sheight*2, swidth-80, scolor); // right up
	DrawRectangle(sx-80 + swidth+100 + gap_turn, sy+810-80, swidth-80, sheight, scolor); // top left
	DrawRectangle(sx+60, sy+810-80, swidth-80, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+80, sy+sheight+swidth+gap_turn, sheight*2, swidth-80, scolor); // left up
	DrawRectangle(sx-sheight*2+80, sy+sheight+80, sheight*2, swidth-80, scolor); // left down

	//Second inner Arena
	DrawRectangle(sx+140, sy+160, swidth-160, sheight, scolor); // bottom left
	DrawRectangle(sx+180 + swidth - 160 + gap_turn, sy+160, swidth-160, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-160, sy+sheight+160, sheight*2, swidth-160, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-160, sy+sheight+swidth+gap_turn, sheight*2, swidth-160, scolor); // right up
	DrawRectangle(sx-140 + swidth+160 + gap_turn, sy+810-160, swidth-160, sheight, scolor); // top left
	DrawRectangle(sx+140, sy+810-160, swidth-160, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+160, sy+sheight+swidth+gap_turn, sheight*2, swidth-160, scolor); // left up
	DrawRectangle(sx-sheight*2+160, sy+sheight+160, sheight*2, swidth-160, scolor); // left down

	//Third inner Arena
	DrawRectangle(sx+220, sy+240, swidth-240, sheight, scolor); // bottom left
	DrawRectangle(sx+260 + swidth - 240 + gap_turn, sy+240, swidth-240, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn-240, sy+sheight+240, sheight*2, swidth-240, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn-240, sy+sheight+swidth+gap_turn, sheight*2, swidth-240, scolor); // right up
	DrawRectangle(sx-220 + swidth+240 + gap_turn, sy+810-240, swidth-240, sheight, scolor); // top left
	DrawRectangle(sx+220, sy+810-240, swidth-240, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2+240, sy+sheight+swidth+gap_turn, sheight*2, swidth-240, scolor); // left up
	DrawRectangle(sx-sheight*2+240, sy+sheight+240, sheight*2, swidth-240, scolor); // left down

	//Last internal Square
	DrawRectangle(sx+300, sy+320, swidth-135, sheight, scolor); // bottom down
	DrawRectangle(sx+swidth*2+gap_turn-320, sy+sheight+320, sheight*2, swidth-255, scolor); // right down
        DrawRectangle(sx+swidth*2+gap_turn-320, sy+sheight+swidth+gap_turn-65, sheight*2, swidth-255, scolor); // topupright
	DrawRectangle(sx+300, sy+sheight+320, sheight*2, swidth-255, scolor); // right down
        DrawRectangle(sx+300, sy+sheight+swidth+gap_turn-65, sheight*2, swidth-255, scolor);
        DrawRectangle(sx+300, sy+810-320, swidth-135, sheight, scolor); // top right
	if (lifes<=0){gameover();}
	glutSwapBuffers(); 
}
}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		// what to do when left key is pressed...
		if((x3>=40)&&(y3>=330)&&(x3<=780)&&(y3<=450)&& x3!=520&& x3>24)
		{x3-=80;}

	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		// what to do when right key is pressed...
		if((x3>=20)&&(y3>=330)&&(x3<=760)&&(y3<=450)&& x3!=264 && x3 < 760)
		{x3+=80;}
	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) 
	{
		// what to do when upward key is pressed...
		if((x3>=330)&&(y3>=30)&&(x3<=450)&&(y3<=760)&&y3!=272 && y3<760)	
		{y3+=80;}
	}
	
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		// what to do when downward key is pressed...
		if((x3>=330)&&(y3>=40)&&(x3<=450)&&(y3<=780)&&y3!=520&& y3>32)	
		{y3-=80;}
	}
	//}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}
void PrintableKeys(unsigned char key, int w, int q) {
// exit the program when 4 key is pressed.	
	if (key == '4') 
	{exit(1);}

	if (key == ' ')
			{
//doubles the speed when space is pressed
		
	//same condition that moves the players car the speed of car
	if((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32))
	{x3-=4;}
	else if((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))
	{y3+=4;}
	else if((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760))
	{x3+=4;}
	else if((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32))
	{y3-=4;}

	if((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112))
	{x3-=4;}
	else if((x3==104)&&(y3>=112)&&(x3==104)&&(y3<680))
	{y3+=4;}
	else if((x3<680)&&(y3==680)&&(x3>=104)&&(y3==680))
	{x3+=4;}
	else if((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))
	{y3-=4;}

	if((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192))
	{x3-=4;}
	else if((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600))
	{y3+=4;}
	else if((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600))
	{x3+=4;}
	else if((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))
	{y3-=4;}
	
	if((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272))
	{x3-=4;}
	else if((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520))
	{y3+=4;}
	else if((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520))
	{x3+=4;}
	else if((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))
	{y3-=4;}
	}

	if (key == '1')
	{h=1;
 	glutDisplayFunc(GameDisplay);}
	
	if (key == '3')
	{h=0;
	glutDisplayFunc(help);}
	
	if (key == 'p' || key=='P')
	{
	h=0;
	glutDisplayFunc(reprintmenu);

	}
	

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * speed of different moving objects by varying the constant FPS.
 * */
void Timer(int m) {
if(h==1){
//A.I


if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x==392 && (y==760) )))
{y-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==392 && y==680 ) ))
{y-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && y==600 ) ))
{y-=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x==392 && y==600) ))
{y+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==392 && y==520 ) ))
{y+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==680 ) ))
{y+=80;}


//2nd round
if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x==392 && y==32) ))
{y+=80;}

else if((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==392 && y==112 ) ))
{y+=80;}

else if((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && (y<=192) && (y>=152) ) ))
{y+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x==392 && (y<=192) && (y>=152)) ))
{y-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==112 ) ))
{y-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==392 && y==32 ) ))
{y+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==392 && y==760 ) ))
{y-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && y==32 ) ))
{y+=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && y==760 ) ))
{y-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && y==112 ) ))
{y+=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x==392 && y==680 ) ))
{y-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==520 ) ))
{y+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==600 ) ))
{y+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==192 ) ))
{y-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==392 && y==272 ) ))
{y-=80;}


//3rd round(Right And left doors)
if( level==2 || level==3 || level==4 )
{
if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==104 && (y==400) )) )
{x-=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&&(((x==184 && (y==400) ))))
{x-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==264 && (y==400) ))) 
{x-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x==680 && (y==400) )) )
{x+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&&(((x==600 && (y==400) ))))
{x+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==520 && (y==400) ))) 
{x+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&& ((x==760 && (y==400) )) )
{x-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==680 && (y==400) )))
{x-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272)))&&((x==600 && (y==400) )))
{x-=80;}

else if((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&& ((x==24 && (y==400) )) )
{x+=80;}

else if((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x==104 && (y==400) )))
{x+=80;}

else if((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272)))&&((x==184 && (y==400) )))
{x+=80;}
}


if (level==4){
//1st round
if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x4==392 && (y4==760) )))
{y4-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==392 && y4==680 ) ))
{y4-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && y4==600 ) ))
{y4-=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x4==392 && y4==600) ))
{y4+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==392 && y4==520 ) ))
{y4+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==680 ) ))
{y4+=80;}
//2nd round
else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x4==392 && y4==32) ))
{y4+=80;}

else if((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==392 && y4==112 ) ))
{y4+=80;}

else if((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && (y4<=190) && (y4>=150) ) ))
{y4+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))) && ((x4==392 && (y4<=190) && (y4>=150)) ))
{y4-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==112 ) ))
{y4-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==392 && y4==32 ) ))
{y4+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==392 && y4==760 ) ))
{y4-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && y4==32 ) ))
{y4+=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && y4==760 ) ))
{y4-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && y4==112 ) ))
{y4+=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))) && ((x4==392 && y4==680 ) ))
{y4-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==520 ) ))
{y4+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==600 ) ))
{y4+=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==192 ) ))
{y4-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==392 && y4==272 ) ))
{y4-=80;}

//3rd round(Right And left doors)
else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==104 && (y4==400) )) )
{x4-=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&&(((x4==184 && (y4==400) ))))
{x4-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==264 && (y4==400) ))) 
{x4-=80;}

else if ((((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32)) || ((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760)) || ((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32)) || ((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))) && ((x4==680 && (y4==400) )) )
{x4+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&&(((x4==600 && (y4==400) ))))
{x4+=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==520 && (y4==400) ))) 
{x4+=80;}

else if ((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&& ((x4==760 && (y4==400) )) )
{x4-=80;}

else if ((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==680 && (y4==400) )))
{x4-=80;}

else if ((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272)))&&((x4==600 && (y4==400) )))
{x4-=80;}

else if((((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112) )||( (x3==104)&&(y3>=112)&&(x3==104)&&(y3<680) )||( (x3<680)&&(y3==680)&&(x3>=104)&&(y3==680) )||((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112)))&& ((x4==24 && (y4==400) )) )
{x4+=80;}

else if((((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192)) || ((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600)) || ((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600)) || ((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))) && ((x4==104 && (y4==400) )))
{x4+=80;}

else if((((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272)) || ((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520)) || ((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520)) || ((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272)))&&((x4==184 && (y4==400) )))
{x4+=80;}
}


// conditions to move opponents car in different arenas

	// function to move opponents car in outer arena
	if((x>=24)&&(y==32)&&(x<760)&&(y==32))
	{x+=4;}
	else if((x==760)&&(y>=32)&&(x==760)&&(y<760))
	{y+=4;}
	else if((x<=760)&&(y==760)&&(x>24)&&(y==760))
	{x-=4;}
	else if((x==24)&&(y<=760)&&(x==24)&&(y>32))
	{y-=4;}

	// function to move opponents car in first inner arena
	if((x>=104)&&(y==112)&&(x<680)&&(y==112))
	{x+=4;}
	else if((x==680)&&(y>=112)&&(x==680)&&(y<680))
	{y+=4;}
	else if((x<=680)&&(y==680)&&(x>104)&&(y==680))
	{x-=4;}
	else if((x==104)&&(y<=680)&&(x==104)&&(y>112))
	{y-=4;}

	// function to move opponents car in second inner arena
	if((x>=184)&&(y==192)&&(x<600)&&(y==192))
	{x+=4;}
	else if((x==600)&&(y>=192)&&(x==600)&&(y<600))
	{y+=4;}
	else if((x<=600)&&(y==600)&&(x>184)&&(y==600))
	{x-=4;}
	else if((x==184)&&(y<=600)&&(x==184)&&(y>192))
	{y-=4;}

	// function to move opponents car in last inner arena
	if((x>=264)&&(y==272)&&(x<520)&&(y==272))
	{x+=4;}
	else if((x==520)&&(y>=272)&&(x==520)&&(y<520))
	{y+=4;}
	else if((x<=520)&&(y==520)&&(x>264)&&(y==520))
	{x-=4;}
	else if((x==264)&&(y<=520)&&(x==264)&&(y>272))
	{y-=4;}
if (level==4)
{
// conditions to move opponents car in different arenas

	// function to move opponents car in outer arena
	if((x4>=24)&&(y4==32)&&(x4<760)&&(y4==32))
	{x4+=4;}
	else if((x4==760)&&(y4>=32)&&(x4==760)&&(y4<760))
	{y4+=4;}
	else if((x4<=760)&&(y4==760)&&(x4>24)&&(y4==760))
	{x4-=4;}
	else if((x4==24)&&(y4<=760)&&(x4==24)&&(y4>32))
	{y4-=4;}

	// function to move opponents car in first inner arena
	if((x4>=104)&&(y4==112)&&(x4<680)&&(y4==112))
	{x4+=4;}
	else if((x4==680)&&(y4>=112)&&(x4==680)&&(y4<680))
	{y4+=4;}
	else if((x4<=680)&&(y4==680)&&(x4>104)&&(y4==680))
	{x4-=4;}
	else if((x4==104)&&(y4<=680)&&(x4==104)&&(y4>112))
	{y4-=4;}

	// function to move opponents car in second inner arena
	if((x4>=184)&&(y4==192)&&(x4<600)&&(y4==192))
	{x4+=4;}
	else if((x4==600)&&(y>=192)&&(x==600)&&(y<600))
	{y4+=4;}
	else if((x4<=600)&&(y4==600)&&(x4>184)&&(y4==600))
	{x4-=4;}
	else if((x4==184)&&(y4<=600)&&(x4==184)&&(y4>192))
	{y4-=4;}

	// function to move opponents car in last inner arena
	if((x4>=264)&&(y4==272)&&(x4<520)&&(y4==272))
	{x4+=4;}
	else if((x4==520)&&(y4>=272)&&(x4==520)&&(y4<520))
	{y4+=4;}
	else if((x4<=520)&&(y4==520)&&(x4>264)&&(y4==520))
	{x4-=4;}
	else if((x4==264)&&(y4<=520)&&(x4==264)&&(y4>272))
	{y4-=4;}
}


// conditions to move players car in different arenas

	// function to move players car in outer arena
	if((x3>24)&&(y3==32)&&(x3<=760)&&(y3==32))
	{x3-=4;}
	else if((x3==24)&&(y3>=32)&&(x3==24)&&(y3<760))
	{y3+=4;}
	else if((x3<760)&&(y3==760)&&(x3>=24)&&(y3==760))
	{x3+=4;}
	else if((x3==760)&&(y3<=760)&&(x3==760)&&(y3>32))
	{y3-=4;}

	// function to move players car in first inner arena
	if((x3>104)&&(y3==112)&&(x3<=680)&&(y3==112))
	{x3-=4;}
	else if((x3==104)&&(y3>=112)&&(x3==104)&&(y3<680))
	{y3+=4;}
	else if((x3<680)&&(y3==680)&&(x3>=104)&&(y3==680))
	{x3+=4;}
	else if((x3==680)&&(y3<=680)&&(x3==680)&&(y3>112))
	{y3-=4;}

	// function to move players car in second inner arena
	if((x3>184)&&(y3==192)&&(x3<=600)&&(y3==192))
	{x3-=4;}
	else if((x3==184)&&(y3>=192)&&(x3==184)&&(y3<600))
	{y3+=4;}
	else if((x3<600)&&(y3==600)&&(x3>=184)&&(y3==600))
	{x3+=4;}
	else if((x3==600)&&(y3<=600)&&(x3==600)&&(y3>192))
	{y3-=4;}

	// function to move players car in last inner arena
	if((x3>264)&&(y3==272)&&(x3<=520)&&(y3==272))
	{x3-=4;}
	else if((x3==264)&&(y3>=272)&&(x3==264)&&(y3<520))
	{y3+=4;}
	else if((x3<520)&&(y3==520)&&(x3>=264)&&(y3==520))
	{x3+=4;}
	else if((x3==520)&&(y3<=520)&&(x3==520)&&(y3>272))
	{y3-=4;}

//loop that adds score and changes food from misty_rose to black
for(int i=0;i<64;i++)
{
	if ((x3<=arpfoodx[i]+40)&&(x3>=arpfoodx[i]-40)&&(y3<=argfoody[i]+40)&&(y3>=argfoody[i]-40))
	{
		if (colorfood[i]==colors[MISTY_ROSE]){points+=1;}
	colorfood[i]=colors[BLACK];
	}
}
if(points>0 && points<64){level=1;}
if(points>=64 && points<228){level=2;}
if(points>=228 && points<392){level=3;}
if(points>=392 && points<=556){level=4;}


if (points==64)
{
points = points + 100;
x = 496;
y = 32; 
x3 = 280;
y3 = 32;
	srand(time(0));
	randomposition=rand()%3+1;
	if(randomposition==1)
	{x=496;
	y=760;}
	/*else if(randomposition==2)
	{x=24;
	y=472;}*/
	else if(randomposition==3)
	{x=760;
	y=472;}
		for(int i=0;i<=63;i++)
		{colorfood[i]=colors[MISTY_ROSE];}
}

if (points==228)
{
points = points + 100;
x = 496;
y = 32; 
x3 = 280;
y3 = 32;
	srand(time(0));
	randomposition=rand()%3+1;
	if(randomposition==1)
	{x=496;
	y=760;}
	/*else if(randomposition==2)
	{x=24;
	y=472;}*/
	else if(randomposition==3)
	{x=760;
	y=472;}
		for(int i=0;i<=63;i++)
		{colorfood[i]=colors[MISTY_ROSE];}
	}
// conditions to move opponents car in different arenas
	if(level==3){
	// function to move opponents car in outer arena
	if((x>=24)&&(y==32)&&(x<760)&&(y==32))
	{x+=4;}
	else if((x==760)&&(y>=32)&&(x==760)&&(y<760))
	{y+=4;}
	else if((x<=760)&&(y==760)&&(x>24)&&(y==760))
	{x-=4;}
	else if((x==24)&&(y<=760)&&(x==24)&&(y>32))
	{y-=4;}

	// function to move opponents car in first inner arena
	if((x>=104)&&(y==112)&&(x<680)&&(y==112))
	{x+=4;}
	else if((x==680)&&(y>=112)&&(x==680)&&(y<680))
	{y+=4;}
	else if((x<=680)&&(y==680)&&(x>104)&&(y==680))
	{x-=4;}
	else if((x==104)&&(y<=680)&&(x==104)&&(y>112))
	{y-=4;}

	// function to move opponents car in second inner arena
	if((x>=184)&&(y==192)&&(x<600)&&(y==192))
	{x+=4;}
	else if((x==600)&&(y>=192)&&(x==600)&&(y<600))
	{y+=4;}
	else if((x<=600)&&(y==600)&&(x>184)&&(y==600))
	{x-=4;}
	else if((x==184)&&(y<=600)&&(x==184)&&(y>192))
	{y-=4;}

	// function to move opponents car in last inner arena
	if((x>=264)&&(y==272)&&(x<520)&&(y==272))
	{x+=4;}
	else if((x==520)&&(y>=272)&&(x==520)&&(y<520))
	{y+=4;}
	else if((x<=520)&&(y==520)&&(x>264)&&(y==520))
	{x-=4;}
	else if((x==264)&&(y<=520)&&(x==264)&&(y>272))
	{y-=4;}

}

if (points==392)
{
points = points + 100;
x = 496;
y = 32; 
x3 = 280;
y3 = 32;
	srand(time(0));
	randomposition=rand()%3+1;
	if(randomposition==1)
	{x=496;
	y=760;}
	/*else if(randomposition==2)
	{x=24;
	y=472;}*/
	else if(randomposition==3)
	{x=760;
	y=472;}
		for(int i=0;i<=63;i++)
		{colorfood[i]=colors[MISTY_ROSE];}
}


}
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/60 FPS
	//concept of double buffer
	glutTimerFunc(1000.0/60, Timer, 0);
}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	srand(time(0));
	randomposition=rand()%3+1;
	if(randomposition==1)
	{x=496;
	y=760;}
	/*else if(randomposition==2)
	{x=24;
	y=472;}*/
	else if(randomposition==3)
	{x=760;
	y=472;}
		
	for(int i=0;i<=63;i++)
	{colorfood[i]=colors[MISTY_ROSE];}
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 920; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	menudisplay();
	

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
