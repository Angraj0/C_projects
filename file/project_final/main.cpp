#include<windows.h>
#include<MMSystem.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define PI 3.1416
#define RED 0
#define YELLOW 1
#define GREEN 2

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();
   using namespace std;

   bool rl1[] = {false, false, true};
bool rl2[] = {false, false, true};
float crx = -200, blx = -300;
float sx=0,cx=900,py=0,px=0;

int view=0;

void text(int x, int y, string s, int font) {
	int i=0;
	glColor3f(0.0,0.0,0.8);
	glRasterPos2f(x,y);
	for(i=0;i<s.length();i++) {
		if(font==1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
		else if(font==2)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
		else if(font==3) {
			glColor3f(1.0,0.0,0.0);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
		}
	}
}


void circle(float radiusX, float radiusY){
    int i=0;
    float angle=0.0;
    glBegin(GL_POLYGON);
    for(i=0;i<200;i++){
        angle=2*PI*i/200;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
    }
    glEnd();

}


void init() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 0.964, 0.560, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0,1200,0.0,1200,50.0,0.0);
	glutPostRedisplay();
}


void First_win() {
	glClearColor(1.0,1.0,0.6,1.0);
	text(330,700,"TRAFFIC SIGNAL SYSTEM",1);
	text(390,660,"Using OpenGL",1);
	text(400,620,"Group member:",2);
	text(100,580,"SAJIB KOTAL &&  ANRAG MD. SARGIA SHOWRAV",1);
	text(350,540,"INSTRUCTIONS::",2);
	text(20,500,"For Left Traffic Light",2);
	text(20,460,"q -- Red Light",2);
	text(20,420,"w -- Yellow Light",2);
	text(20,380,"r -- Green Light",2);
	text(260,500,"For Right Traffic Light",2);
	text(300,460,"a -- Red Light",2);
	text(300,420,"s -- Yellow Light",2);
	text(300,380,"d -- Green Light",2);

	text(530,500,"For People crossing road",2);
	text(550,460,"click left button on the mouse ",2);
	text(550,400,"click right button to stop ",2);

	text(910,500,"For cloud and sun moving",2);
	text(900,460,"z -- press to move both",2);
	text(900,420,"x -- press to stop moving both",2);



	text(200,100,"***PRESS SPACEBAR TO ENTER INTO THE TRAFFIC SYSTEM***",3);
	glutPostRedisplay();

}


void bus() {
	glPushMatrix();
     glTranslated(blx,-100,0.0);
	glScaled(50.0,50.0,0.0);
	glColor3f(0.219,0.572,0.972);

	//bus out line
	glBegin(GL_POLYGON);
	glVertex2f(25,8);
	glVertex2f(25,9.5);
	glVertex2f(26,11);
	glVertex2f(32,11);
	glVertex2f(32,8);
	glEnd();

	//window frame
	glColor3f(0.039,0.054,0.050);
	glBegin(GL_POLYGON);
	glVertex2f(26.1,9.5);
	glVertex2f(26.1,10.5);
	glVertex2f(31.8,10.5);
	glVertex2f(31.8,9.5);
	glEnd();

	//Doors
	glColor3f(0.098,0.235,0.294);
	glBegin(GL_POLYGON);
	glVertex2f(26.2,9);
	glVertex2f(26.2,10.4);
	glVertex2f(27.7,10.4);
	glVertex2f(27.7,9);
	glEnd();


	glColor3f(0.039,0.545,0.627);
	glBegin(GL_POLYGON);
	glVertex2f(27,8.4);
	glVertex2f(27,10.4);
	glVertex2f(27.7,10.4);
	glVertex2f(27.7,8.4);
	glEnd();

	//small windows
	glColor3f(0.098,0.235,0.294);
	glBegin(GL_POLYGON);
	glVertex2f(27.8,9.6);
	glVertex2f(27.8,10.4);
	glVertex2f(29,10.4);
	glVertex2f(29,9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(29.1,9.6);
	glVertex2f(29.1,10.4);
	glVertex2f(30.2,10.4);
	glVertex2f(30.2,9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30.3,9.6);
	glVertex2f(30.3,10.4);
	glVertex2f(31.7,10.4);
	glVertex2f(31.7,9.6);
	glEnd();


	//driver window
	glColor3f(0.098,0.235,0.294);
	glBegin(GL_POLYGON);
	glVertex2f(25,9.5);
	glVertex2f(26,11);
	glVertex2f(26,9.5);
	glEnd();
	glPopMatrix();

	//tyre
	glPushMatrix();//front tyre
	glTranslated(blx+1320,300,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.5,1.4);
	glPopMatrix();

	glPushMatrix();//back tyre
	glTranslated(blx+1520,300,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.5,1.4);
	glPopMatrix();
}

void car() {
	glPushMatrix(); //making color for outer line
    glTranslated(crx,370,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.871,0.0,0.488);
	glBegin(GL_POLYGON);
	glVertex2f(2.5,2.5);
	glVertex2f(3.0,3.5);
	glVertex2f(3.5,3.75);
	glVertex2f(4.0,4.0);
	glVertex2f(4.5,4.0);
	glVertex2f(5.0,3.75);
	glVertex2f(5.5,3.5);
	glVertex2f(5.75,3.0);
	glVertex2f(6.0,2.5);
	glVertex2f(16.5,2.5);
	glVertex2f(16.75,3.0);
	glVertex2f(17.0,3.5);
	glVertex2f(17.5,3.75);
	glVertex2f(18.0,4.0);
	glVertex2f(18.5,4.0);
	glVertex2f(19.0,3.75);
	glVertex2f(19.5,3.5);
	glVertex2f(19.75,3.0);
	glVertex2f(20.0,2.5);
	glVertex2f(21.0,2.5);
	glVertex2f(21.0,4.0);
	glVertex2f(21.5,4.0);
	glVertex2f(21.0,4.5);
	glVertex2f(20.0,5.0);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.5);
	glVertex2f(13.0,6.0);
	glVertex2f(12.0,6.5);
	glVertex2f(11.0,7.0);
	glVertex2f(6.0,7.0);
	glVertex2f(5.0,6.5);
	glVertex2f(4.5,6.25);
	glVertex2f(4.25,6.0);
	glVertex2f(4.0,5.75);
	glVertex2f(3.5,5.5);
	glVertex2f(3.0,5.5);
	glVertex2f(1.9,5.45);
	glVertex2f(1.8,5.4);
	glVertex2f(1.7,5.35);
	glVertex2f(1.6,5.3);
	glVertex2f(1.5,5.25);
	glVertex2f(1.4,5.15);
	glVertex2f(1.3,5.0);
	glVertex2f(1.2,4.85);
	glVertex2f(1.1,4.7);
	glVertex2f(1.0,4.3);
	glVertex2f(1.0,3.2);
	glVertex2f(1.1,3.05);
	glVertex2f(1.2,2.9);
	glVertex2f(1.3,2.9);
	glVertex2f(1.4,2.75);
	glVertex2f(1.5,2.65);
	glVertex2f(1.6,2.6);
	glVertex2f(1.7,2.55);
	glVertex2f(1.8,2.5);
	glVertex2f(1.9,2.45);
	glVertex2f(2.0,2.5);
	glEnd();


	glColor3f(0.098,0.235,0.294); //color for outer window
	glBegin(GL_POLYGON);
	glVertex2f(5.0,5.0);
	glVertex2f(14.0,5.0);
	glVertex2f(11.5,6.5);
	glVertex2f(10.5,6.75);
	glVertex2f(7.0,6.75);
	glEnd();

    glPopMatrix();

	glPushMatrix();//back tyre
	glTranslated(crx+100,420,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.3,1.2);
	glPopMatrix();

	glPushMatrix();//front tyre
	glTranslated(crx+350,420,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.3,1.2);
	glPopMatrix();
}



void tree(){



glPushMatrix();
glTranslatef(950,50,0);
glBegin(GL_QUADS);
glColor3f(0.588,0.435,0.2);
glVertex2d(150,500);  //1
		glVertex2d(180,500);  //2
		glVertex2d(180,650);  //3
		glVertex2d(150,650);  //12
glEnd();




glPopMatrix();

glPushMatrix();
glTranslatef(1100,700,0);
glColor3f(0,803,0.4);
circle(50,50);
glPopMatrix();

glPushMatrix();
glTranslatef(1130,700,0);
glColor3f(0,803,0.4);
circle(50,50);
glPopMatrix();

glPushMatrix();
glTranslatef(1105,770,0);
glColor3f(0,803,0.4);
circle(50,50);
glPopMatrix();

glPushMatrix();
glTranslatef(1120,770,0);
glColor3f(0,803,0.4);
circle(50,50);
glPopMatrix();

glPushMatrix();
glTranslatef(1110,840,0);
glColor3f(0,803,0.4);
circle(40,40);
glPopMatrix();




glPushMatrix();
glTranslatef(850,50,0);
glBegin(GL_QUADS);
glColor3f(0.3,0.1,0.6);

glVertex2d(150,500);  //1
		glVertex2d(160,500);  //2
		glVertex2d(160,700);  //3
		glVertex2d(150,700);  //12
glEnd();
glPopMatrix();



glPushMatrix();
glTranslatef(830,10,0);
glBegin(GL_TRIANGLES);
glColor3f(0.0,0.199,0.0);

glVertex2d(140,690);  //1
		glVertex2d(245,740);  //2
		glVertex2d(140,800);  //3
		  //12
glEnd();

glPopMatrix();



}
void people(){


glPushMatrix();
glTranslated(px,py,0);
glTranslated(640,350,0);
glColor3f(0.898,0.760,0.596);
circle(20,30);

glColor3f(0,0,0);
glTranslated(0,30,0);

circle(20,5);

glColor3f(0.898,0.4,0.596);
glTranslated(-80,-230,0);
glScaled(20,25,1);
glBegin(GL_QUADS);
glVertex2d(3,7);
glVertex2d(5,7);
glVertex2d(5,4);
glVertex2d(3,4);


glEnd();
glPopMatrix();

//right leg
glPushMatrix();
glTranslated(px,py,0);
glTranslated(440,174,0);
glColor3f(0.2,0.4,0.8);
glScaled(60,20,1);
glBegin(GL_QUADS);

glVertex2f(3.1,4);
glVertex2f(3.3,4);
glVertex2f(3.3,1.2);
glVertex2f(3.1,1.2);
glEnd();
glPopMatrix();

//right leg
glPushMatrix();
glTranslated(px,py,0);
glTranslated(455,174,0);
glColor3f(0.2,0.4,0.8);
glScaled(60,20,1);
glBegin(GL_QUADS);

glVertex2f(3.1,4);
glVertex2f(3.3,4);
glVertex2f(3.3,1.2);
glVertex2f(3.1,1.2);
glEnd();
glPopMatrix();


//left hand
glPushMatrix();
glTranslated(px,py,0);
glTranslated(530,115,0);
glColor3f(0.898,0.760,0.596);
glScaled(30,30,1);
glBegin(GL_QUADS);

glVertex2f(3,7);
glVertex2f(2.5,5);
glVertex2f(2.7,5);
glVertex2f(3,6.2);
glEnd();
glPopMatrix();

 //left hand circle
glPushMatrix();
glTranslated(px,py,0);
glTranslated(610,265,0);
glColor3f(0.898,0.760,0.596);
circle(5,5);


glPopMatrix();
  //right hand
glPushMatrix();
glTranslated(px,py,0);
glTranslated(510,115,0);
glColor3f(0.898,0.760,0.596);
glScaled(30,30,1);
glBegin(GL_QUADS);

glVertex2f(5,7);
glVertex2f(5.3,5);
glVertex2f(5.1,5);
glVertex2f(5,6.2);
glEnd();
glPopMatrix();

 //right hand circle
glPushMatrix();
glTranslated(px,py,0);
glTranslated(665,265,0);
glColor3f(0.898,0.760,0.596);
circle(5,5);
glPopMatrix();








}

 void background(){

     glPushMatrix();

glBegin(GL_QUADS);
glColor3f(0.529,0.807,0.921);

glVertex2d(-200,900);  //1
		glVertex2f(-200,1200);  //2
		glVertex2f(1200,1200);  //3
		glVertex2f(1200,900);  //12
glEnd();

glPopMatrix();

   glPushMatrix();
glTranslated(sx,1100,0);

glColor3f(1,0.0,0);

circle(40,40);



glPopMatrix();

glPushMatrix();
glTranslated(cx,1100,0);

glColor3f(0.815,0.8,0.8);
circle(40,40);
glPopMatrix();

glPushMatrix();
glTranslated(cx+50,1120,0);
circle(40,40);



glPopMatrix();

glPushMatrix();
glTranslated(cx+50,1080,0);
circle(40,40);



glPopMatrix();

glPushMatrix();
glTranslated(cx+100,1100,0);
circle(40,40);



glPopMatrix();








 }
void hill(){



glPushMatrix();
glColor3f(0.803,0.407,0.223);
glBegin(GL_TRIANGLES);


glVertex2d(-200,900);  //2
		glVertex2d(100,1200);  //3
		glVertex2d(400,900);
		glEnd();

		glPopMatrix();

		glPushMatrix();
glColor3f(0.803,0.407,0.223);
glBegin(GL_TRIANGLES);


glVertex2d(300,900);  //2
		glVertex2d(600,1200);  //3
		glVertex2d(900,900);
		glEnd();

		glPopMatrix();

			glPushMatrix();
glColor3f(0.803,0.407,0.223);
glBegin(GL_TRIANGLES);


glVertex2d(800,900);  //2
		glVertex2d(1000,1000);  //3
		glVertex2d(1200,900);
		glEnd();

		glPopMatrix();





}
void lamppost(){

     glPushMatrix();
glTranslatef(100,70,0);
glBegin(GL_QUADS);
glColor3f(0.664,0.664,0.859);


glVertex2d(150,500);  //1
		glVertex2d(160,500);  //2
		glVertex2d(160,700);  //3
		glVertex2d(150,700);  //12
glEnd();

glPopMatrix();

 glPushMatrix();
glTranslatef(100,70,0);
glBegin(GL_QUADS);
glColor3f(0.664,0.664,0.859);

glVertex2d(160,690);  //1
		glVertex2d(190,690);  //2
		glVertex2d(190,680);  //3
		glVertex2d(160,680);  //12
glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(100,70,0);
glBegin(GL_TRIANGLES);
glColor3f(0.664,0.664,0.859);

glVertex2d(175,680);  //1
		glVertex2d(175,640);  //2
		glVertex2d(200,670);  //3
		  //12
glEnd();

glPushMatrix();
glTranslatef(185,660,0);

glColor3f(0.996,0.996,0.0);
glScaled(21.0,21.0,0.0);
circle(0.2,0.2),


glPopMatrix();

}

void house(){
glPushMatrix();

glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6); //1st house

glVertex2d(400,900);  //1
		glVertex2d(400,1000);  //2
		glVertex2d(500,1000);  //3
		glVertex2d(500,900);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6);

glVertex2d(510,900);  //2nd house
		glVertex2d(510,1000);  //2
		glVertex2d(610,1000);  //3
		glVertex2d(610,900);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6); //3rd house

glVertex2d(620,900);  //1
		glVertex2d(620,1050);  //2
		glVertex2d(690,1050);  //3
		glVertex2d(690,900);  //12
glEnd();

   //1st door

glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(440,900);  //1
		glVertex2d(440,930);  //2
		glVertex2d(460,930);  //3
		glVertex2d(460,900);  //12
glEnd();

 //2nd door

glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,900);  //1
		glVertex2d(550,930);  //2
		glVertex2d(570,930);  //3
		glVertex2d(570,900);  //12
glEnd();




glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd door

glVertex2d(650,900);  //1
		glVertex2d(650,930);  //2
		glVertex2d(660,930);  //3
		glVertex2d(660,900);  //12
glEnd();




//1st building



glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window1

glVertex2d(410,970);  //1
		glVertex2d(410,990);  //2
		glVertex2d(430,990);  //3
		glVertex2d(430,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window2

glVertex2d(440,970);  //1
		glVertex2d(440,990);  //2
		glVertex2d(460,990);  //3
		glVertex2d(460,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window3

glVertex2d(470,970);  //1
		glVertex2d(470,990);  //2
		glVertex2d(490,990);  //3
		glVertex2d(490,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window11

glVertex2d(410,940);  //1
		glVertex2d(410,960);  //2
		glVertex2d(430,960);  //3
		glVertex2d(430,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window22

glVertex2d(440,940);  //1
		glVertex2d(440,960);  //2
		glVertex2d(460,960);  //3
		glVertex2d(460,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window33

glVertex2d(470,940);  //1
		glVertex2d(470,960);  //2
		glVertex2d(490,960);  //3
		glVertex2d(490,940);  //12
glEnd();




//2nd building


glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(520,970);  //2nd house
		glVertex2d(520,990);  //2
		glVertex2d(540,990);  //3
		glVertex2d(540,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,970);  //2nd house
		glVertex2d(550,990);  //2
		glVertex2d(570,990);  //3
		glVertex2d(570,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(580,970);  //2nd house
		glVertex2d(580,990);  //2
		glVertex2d(600,990);  //3
		glVertex2d(600,970);  //12
glEnd();






glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(520,940);  //2nd house
		glVertex2d(520,960);  //2
		glVertex2d(540,960);  //3
		glVertex2d(540,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,940);  //2nd house
		glVertex2d(550,960);  //2
		glVertex2d(570,960);  //3
		glVertex2d(570,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(580,940);  //2nd house
		glVertex2d(580,960);  //2
		glVertex2d(600,960);  //3
		glVertex2d(600,940);  //12
glEnd();




glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(630,1010);  //1
		glVertex2d(630,1040);  //2
		glVertex2d(650,1040);  //3
		glVertex2d(650,1010);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(660,1010);  //1
		glVertex2d(660,1040);  //2
		glVertex2d(680,1040);  //3
		glVertex2d(680,1010);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(630,970);  //1
		glVertex2d(630,1000);  //2
		glVertex2d(650,1000);  //3
		glVertex2d(650,970);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(660,970);  //1
		glVertex2d(660,1000);  //2
		glVertex2d(680,1000);  //3
		glVertex2d(680,970);  //12
glEnd();


glPopMatrix();





glPushMatrix();

glTranslatef(-580,0,0);

glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6); //1st house

glVertex2d(400,900);  //1
		glVertex2d(400,1000);  //2
		glVertex2d(500,1000);  //3
		glVertex2d(500,900);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6);

glVertex2d(510,900);  //2nd house
		glVertex2d(510,1000);  //2
		glVertex2d(610,1000);  //3
		glVertex2d(610,900);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6); //3rd house

glVertex2d(620,900);  //1
		glVertex2d(620,1050);  //2
		glVertex2d(690,1050);  //3
		glVertex2d(690,900);  //12
glEnd();

   //1st door

glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(440,900);  //1
		glVertex2d(440,930);  //2
		glVertex2d(460,930);  //3
		glVertex2d(460,900);  //12
glEnd();

 //2nd door

glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,900);  //1
		glVertex2d(550,930);  //2
		glVertex2d(570,930);  //3
		glVertex2d(570,900);  //12
glEnd();




glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd door

glVertex2d(650,900);  //1
		glVertex2d(650,930);  //2
		glVertex2d(660,930);  //3
		glVertex2d(660,900);  //12
glEnd();




//1st building



glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window1

glVertex2d(410,970);  //1
		glVertex2d(410,990);  //2
		glVertex2d(430,990);  //3
		glVertex2d(430,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window2

glVertex2d(440,970);  //1
		glVertex2d(440,990);  //2
		glVertex2d(460,990);  //3
		glVertex2d(460,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window3

glVertex2d(470,970);  //1
		glVertex2d(470,990);  //2
		glVertex2d(490,990);  //3
		glVertex2d(490,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window11

glVertex2d(410,940);  //1
		glVertex2d(410,960);  //2
		glVertex2d(430,960);  //3
		glVertex2d(430,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window22

glVertex2d(440,940);  //1
		glVertex2d(440,960);  //2
		glVertex2d(460,960);  //3
		glVertex2d(460,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1); //1st window33

glVertex2d(470,940);  //1
		glVertex2d(470,960);  //2
		glVertex2d(490,960);  //3
		glVertex2d(490,940);  //12
glEnd();




//2nd building


glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(520,970);  //2nd house
		glVertex2d(520,990);  //2
		glVertex2d(540,990);  //3
		glVertex2d(540,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,970);  //2nd house
		glVertex2d(550,990);  //2
		glVertex2d(570,990);  //3
		glVertex2d(570,970);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(580,970);  //2nd house
		glVertex2d(580,990);  //2
		glVertex2d(600,990);  //3
		glVertex2d(600,970);  //12
glEnd();






glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(520,940);  //2nd house
		glVertex2d(520,960);  //2
		glVertex2d(540,960);  //3
		glVertex2d(540,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(550,940);  //2nd house
		glVertex2d(550,960);  //2
		glVertex2d(570,960);  //3
		glVertex2d(570,940);  //12
glEnd();





glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2d(580,940);  //2nd house
		glVertex2d(580,960);  //2
		glVertex2d(600,960);  //3
		glVertex2d(600,940);  //12
glEnd();




glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(630,1010);  //1
		glVertex2d(630,1040);  //2
		glVertex2d(650,1040);  //3
		glVertex2d(650,1010);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(660,1010);  //1
		glVertex2d(660,1040);  //2
		glVertex2d(680,1040);  //3
		glVertex2d(680,1010);  //12
glEnd();



glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(630,970);  //1
		glVertex2d(630,1000);  //2
		glVertex2d(650,1000);  //3
		glVertex2d(650,970);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);//3rd house

glVertex2d(660,970);  //1
		glVertex2d(660,1000);  //2
		glVertex2d(680,1000);  //3
		glVertex2d(680,970);  //12
glEnd();


glPopMatrix();


//house

glPushMatrix();
glTranslated(650,650,0);
glScaled(20,20,0);

glBegin(GL_POLYGON);
glColor3f(1,0,1);

glVertex2d(1,1);  //1
		glVertex2d(1,6);  //2
		glVertex2d(10,6);  //3
		glVertex2d(10,1);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.6,0.2,0);

glVertex2d(16,9);  //1
		glVertex2d(16,14);  //2
		glVertex2d(10,6);  //3
		glVertex2d(10,1);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(0,1,1);

glVertex2d(10,6);   //1
		glVertex2d(16,14);  //2
		glVertex2d(13,16);  //3
		glVertex2d(5,10);  //12
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.2,0.6,1);

glVertex2d(5,10);  //1
		glVertex2d(1,6);  //2
		glVertex2d(10,6);  //3
		 //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.5,0.1,0.3);

glVertex2d(4,1);   //1
		glVertex2d(6,1);  //2
		glVertex2d(6,4);  //3
		glVertex2d(4,4);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);

glVertex2f(12,4.2);   //1
		glVertex2f(12,8);  //2
		glVertex2f(13,9);  //3
		glVertex2f(13,5.3);  //12
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.3,0.5,1);

glVertex2f(4,7);   //1
		glVertex2f(4,8);  //2
		glVertex2f(6,8);  //3
		glVertex2f(6,7);  //12
glEnd();

glPopMatrix();


glPushMatrix();
glTranslated(500,800,0);
glColor3f(0,1,1);
circle(90,90);
glPopMatrix();
glPushMatrix();
glTranslated(550,700,0);
circle(90,90);
glPopMatrix();

glPushMatrix();
glTranslated(500,750,0);
circle(90,90);
glPopMatrix();
glPushMatrix();
glTranslated(550,750,0);
circle(90,90);
glPopMatrix();






}

void busstop(){

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6);

glVertex2d(570,460);  //1
		glVertex2d(800,460);  //2
		glVertex2d(830,520);  //3
		//glVertex2d(830,570);
		glVertex2d(620,520); //12
		//glVertex2d(570,460);
		glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6);
		glVertex2d(570,350);
		glVertex2d(570,460);
		glVertex2d(580,460);
		glVertex2d(580,350);

glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.3,0.2,0.6);
		glVertex2d(800,350);
		glVertex2d(800,520);
		glVertex2d(790,520);
		glVertex2d(790,350);

glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,100,0);
glBegin(GL_POLYGON);
glColor3f(0.664,0.664,0.859);
		glVertex2d(610,460);
		glVertex2d(810,460);
		glVertex2d(800,490);
		glVertex2d(620,490);

glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.039,0.195,0.312);
		glVertex2d(620,360);
		glVertex2d(630,360);
		glVertex2d(630,350);
		glVertex2d(620,350);

glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.039,0.195,0.312);
		glVertex2d(620,360);
		glVertex2d(630,360);
		glVertex2d(630,350);
		glVertex2d(620,350);

glEnd();

glPopMatrix();

glPushMatrix();
glTranslatef(-700,200,0);
glBegin(GL_POLYGON);
glColor3f(0.039,0.195,0.312);
		glVertex2d(620,360);
		glVertex2d(630,360);
		glVertex2d(630,350);
		glVertex2d(620,350);

glEnd();

glPopMatrix();





}

void car_chalao() {
	if(rl1[GREEN] || crx > 0)
		crx += 0.7;
	if(!rl1[GREEN] && (crx > -200 && crx < 0)) {
		crx -= 0.7;
	}
	if(rl1[RED] && crx < -200)
		crx += 0.7;
	if(rl1[YELLOW] && (crx > 0 || crx < -200))
		crx += 0.7;
	if(crx > 1500) {
		crx = -900;
	}
}

void bus_chalao() {
	// blx -= 2;
	if(rl2[GREEN] || blx > 700) {
		blx -=0.5;
	}
	if(!rl2[GREEN] && (blx < -550 && blx > -720)) {
		blx += 0.5;
	}
	if((rl2[RED] || rl2[YELLOW]) && (blx > -550 || blx < -720)) {
		blx -= 0.5;
	}
	if(blx < -1950) {
		blx = 100;
	}
}

void traffic_light() {
	//traffic signal controller
	glPushMatrix();
	glTranslatef(-190,20,0);
	glColor3f(0.0,0.0,0.0);

	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,350);  //1
		glVertex2d(650,350);  //2
		glVertex2d(650,370);  //3
		glVertex2d(600,370);  //12
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.6,0.2,0.0);
		glVertex2d(630,370);  //4
		glVertex2d(630,520);  //5
		glVertex2d(620,520);  //10
		glVertex2d(620,370);  //11
	glEnd();
	glPopMatrix();

	// Left Red Light
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,450);  //6
		glVertex2d(600,600);  //7
		glVertex2d(550,600);  //8
		glVertex2d(550,450);  //9
	glEnd();
	glPopMatrix();

	//Right Red Light
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(700,450);  //11
		glVertex2d(700,600);  //12
		glVertex2d(650,600);  //13
		glVertex2d(650,450);  //14
	glEnd();
	glPopMatrix();

	//Connecting Rod
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(650,520);  //15
		glVertex2d(650,540);  //16
		glVertex2d(600,540);  //17
		glVertex2d(600,520);  //18
	glEnd();
	glPopMatrix();

	//Left Lights
	//Red 1
	glPushMatrix();
	glTranslatef(385, 580, 0);
	if(rl1[RED])
		glColor3f(1.0, 0.0, 0.0);
	else
		glColor3f(0.2, 0.0, 0.0);
	circle(13,13);
	glPopMatrix();

	//Yellow 1
	glPushMatrix();
	glTranslatef(385, 540, 0);
	if(rl1[YELLOW])
		glColor3f(1.0, 1.0, 0.0);
	else
		glColor3f(0.2, 0.2, 0.0);
	glutSolidSphere(12, 80, 80);
	glPopMatrix();

	//Green 1
	glPushMatrix();
	glTranslatef(385, 500, 0);
	if(rl1[GREEN])
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(0.0, 0.2, 0.0);
	glutSolidSphere(12, 80, 80);
	glPopMatrix();

	//Right Lights
	//Red 2
	glPushMatrix();
	glTranslatef(485, 580, 0);
	if(rl2[RED])
		glColor3f(1.0, 0.0, 0.0);
	else
		glColor3f(0.2, 0.0, 0.0);
	glutSolidSphere(12, 80, 80);
	glPopMatrix();

	//Yellow 2
	glPushMatrix();
	glTranslatef(485, 540, 0);
	if(rl2[YELLOW])
		glColor3f(1.0, 1.0, 0.0);
	else
		glColor3f(0.2, 0.2, 0.0);
	glutSolidSphere(12, 80, 80);
	glPopMatrix();

	//Green 2
	glPushMatrix();
	glTranslatef(485, 500, 0);
	if(rl2[GREEN])
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(0.0, 0.2, 0.0);
	glutSolidSphere(12, 80, 80);
	glPopMatrix();
}



void white_strips() {
	//Left
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (4, 255);
    drawOneLine (-200, 365.0, 250.0, 365.0);
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();

	//Right
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (4, 255);
    drawOneLine (620.0, 365.0, 1500.0, 365.0);
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();
}

void zebra() {
	//Left
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (0, 255);
	for(float i=360.0, j=280.0, c=0; c<10; i-=5, j-=5, c++) {
		drawOneLine (i, 250.0, j, 500.0);
	}
	glDisable(GL_LINE_STIPPLE);
    glPopMatrix();

	//Right
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (1, 255);
	// drawOneLine (660, 250.0, 550, 500.0);
	for(float i=660.0, j=550.0, c=0; c<10; i-=5, j-=5, c++) {
		drawOneLine (i, 250.0, j, 500.0);
	}
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();

	//Top
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (1, 255);
	// drawOneLine (300, 505.0, 500, 505.0);
	for(float i=550.0, j=550.0, c=0; c<10; i-=5, j-=5, c++) {
		drawOneLine (300, i, 500, j);
	}
	glDisable(GL_LINE_STIPPLE);
	glPopMatrix();

}

void road_strips() {
	//first bottom yellow strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.85,0.64,0.12);
		glVertex2d(-200,200);
		glVertex2d(-200,250);
		glVertex2d(1200,250);
		glVertex2d(1200,200);
	glEnd();
	glPopMatrix();

	//second  upper yellow strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.85,0.64,0.12);
		glVertex2d(-200,500);
		glVertex2d(-200,550);
		glVertex2d(1200,550);
		glVertex2d(1200,500);
	glEnd();
	glPopMatrix();

	// grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(-200,250);
		glVertex2d(-200,500);
		glVertex2d(1200,500);
		glVertex2d(1200,250);
	glEnd();
	glPopMatrix();

	//uper grey strip
	glPushMatrix();
	glScaled(100.0,100.0,0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(3.0,5.0);
		glVertex2d(0.5,10.0);
		glVertex2d(1.0,10.0);
		glVertex2d(5.0,5.0);
	glEnd();
	glPopMatrix();

background();
hill();

house();

tree();
lamppost();
busstop();

	zebra();
	//Grass


	//Dotted strips
	white_strips();

	car();


	traffic_light();
	bus();
    people();

	car_chalao();
	bus_chalao();


}
void sun_func(){
sx=sx+0.1;
if(sx>1300){
    sx=-300;
}

cx=cx-0.1;
if(cx<-300){
    cx=1300;
}
glutPostRedisplay();


}

void peop(){
if(px>-95 && py<500){


px=px-0.06;
py=py+0.2;
}

glutPostRedisplay();


}

void traffic_start() {

}

void keyboard(unsigned char key, int x, int y) {

	switch(key) {


		case ' ':
			view=1;
			glClearColor(0.6, 0.8, 0.2, 0);
			//glColor3f(0.85,0.64,0.12);
			traffic_start();
			break;

		case 'q':
			cout<<"Red light 1 to RED"<<endl;
			rl1[RED] = true;
			rl1[YELLOW] = false;
			rl1[GREEN] = false;
			break;

		case 'w':
			cout<<"Red light 1 to YELLOW"<<endl;
			rl1[RED] = false;
			rl1[YELLOW] = true;
			rl1[GREEN] = false;
			break;

		case 'e':
			cout<<"Red light 1 to GREEN"<<endl;
			rl1[RED] = false;
			rl1[YELLOW] = false;
			rl1[GREEN] = true;
			break;

		case 'a':
			cout<<"Red light 2 to RED"<<endl;
			rl2[RED] = true;
			rl2[YELLOW] = false;
			rl2[GREEN] = false;
			break;

		case 's':
			cout<<"Red light 2 to YELLOW"<<endl;
			rl2[RED] = false;
			rl2[YELLOW] = true;
			rl2[GREEN] = false;
			break;

		case 'd':
			cout<<"Red light 2 to GREEN"<<endl;
			rl2[RED] = false;
			rl2[YELLOW] = false;
			rl2[GREEN] = true;
			break;

			case 'z':
			    glutIdleFunc(sun_func);
			    break;

			    case 'x':
			    glutIdleFunc(NULL);

			    break;








		default:
			cout<<key<<endl;
	}
}


void mouse(int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:

                glutIdleFunc(peop);

        break;

    case GLUT_RIGHT_BUTTON:
        glutIdleFunc(NULL);

        break;

    default:
        break;
    }
}

void main_display() {
glClear(GL_COLOR_BUFFER_BIT);
init();
if(view==0) {
		init();
		First_win();
	}
	else {

		road_strips();
lamppost();
busstop();
	}




glutSwapBuffers();
}






int main(int argc,char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1200,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic Signal ");
	glutDisplayFunc(main_display);
	glutKeyboardFunc(keyboard);
	 glutMouseFunc(mouse);
	glutIdleFunc(main_display);

	glutMainLoop();
	return 0;
}
