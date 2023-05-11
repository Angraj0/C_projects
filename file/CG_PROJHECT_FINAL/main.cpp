#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define PI 3.1416

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();


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
	glClearColor(0.247,0.576,0.039,0.2);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-150.0,1200,0.0,800,50.0,0);
	glutPostRedisplay();
}




void bus() {
	glPushMatrix();
     glTranslated(-600,-100,0.0);
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
	glTranslated(700,300,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.5,1.4);
	glPopMatrix();

	glPushMatrix();//back tyre
	glTranslated(920,300,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.5,1.4);
	glPopMatrix();
}

void car() {
	glPushMatrix(); //making color for outer line
    glTranslated(-150,400,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.811,0.784,0.011);
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
	glTranslated(-50,450,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.3,1.2);
	glPopMatrix();

	glPushMatrix();//front tyre
	glTranslated(200,450,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);

	circle(1.3,1.2);
	glPopMatrix();
}


void traffic_light() {
	//traffic signal controller
	glPushMatrix();
	glTranslatef(-190,20,0);
	glColor3f(0.0,0.0,0.0);

	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,350);
		glVertex2d(650,350);
		glVertex2d(650,370);     //floor
		glVertex2d(600,370);  //12
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.6,0.2,0.0);
		glVertex2d(630,370);
		glVertex2d(630,520);
		glVertex2d(620,520);
		glVertex2d(620,370);
	glEnd();
	glPopMatrix();

	// Left Red Light
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(600,450);
		glVertex2d(600,600);
		glVertex2d(550,600);
		glVertex2d(550,450);
	glEnd();
	glPopMatrix();

	//Right Red Light
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(700,450);
		glVertex2d(700,600);
		glVertex2d(650,600);
		glVertex2d(650,450);
	glEnd();
	glPopMatrix();

	//Connecting Rod
	glPushMatrix();
	glTranslatef(-190,20,0);
	glBegin(GL_POLYGON);
	// glColor3f(0.7,0.3,0.0);
		glVertex2d(650,520);
		glVertex2d(650,540);
		glVertex2d(600,540);
		glVertex2d(600,520);
	glEnd();
	glPopMatrix();

	//Left Lights
	//Red 1
	glPushMatrix();
	glTranslatef(385, 580, 0);

		glColor3f(1.0, 0.0, 0.0);
		circle(12.5,12.4);


	glPopMatrix();

	//Yellow 1
	glPushMatrix();
	glTranslatef(385, 540, 0);

		glColor3f(1.0, 1.0, 0.0);
         circle(12.5,12.4);

	glPopMatrix();

	//Green 1
	glPushMatrix();
	glTranslatef(385, 500, 0);

		glColor3f(0.0, 1.0, 0.0);

       circle(12.5,12.4);

	glPopMatrix();

	//Right Lights
	//Red 2
	glPushMatrix();
	glTranslatef(485, 580, 0);

		glColor3f(1.0, 0.0, 0.0);
	circle(12.5,12.4);
	glPopMatrix();

	//Yellow 2
	glPushMatrix();
	glTranslatef(485, 540, 0);

		glColor3f(1.0, 1.0, 0.0);

	circle(12.5,12.4);
	glPopMatrix();

	//Green 2
	glPushMatrix();
	glTranslatef(485, 500, 0);

		glColor3f(0.0, 1.0, 0.0);

	circle(12.5,12.4);
	glPopMatrix();
}



void white_strips() {
	//Left
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(12.0);
	glLineStipple (4, 255);
    drawOneLine (-150, 365.0, 250.0, 365.0);
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
		glVertex2d(-150,200);
		glVertex2d(-150,250);
		glVertex2d(1200,250);
		glVertex2d(1200,200);
	glEnd();
	glPopMatrix();

	//second  upper yellow strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.85,0.64,0.12);
		glVertex2d(-150,500);
		glVertex2d(-150,550);
		glVertex2d(1200,550);
		glVertex2d(1200,500);
	glEnd();
	glPopMatrix();

	//second grey strip
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);
		glVertex2d(-150,250);
		glVertex2d(-150,500);
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
		glVertex2d(2.0,8.0);
		glVertex2d(3.5,8.0);
		glVertex2d(5.0,5.0);
	glEnd();
	glPopMatrix();

	zebra();
	//Grass


	//Dotted strips
	white_strips();
	car();
	traffic_light();
	bus();
}

void main_display() {
	glClear(GL_COLOR_BUFFER_BIT);

		init();

		road_strips();

	glutSwapBuffers();


}

int main() {

	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1200,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic Light ");
	glutDisplayFunc(main_display);
	glutIdleFunc(main_display);

	glutMainLoop();
	return 0;
}
