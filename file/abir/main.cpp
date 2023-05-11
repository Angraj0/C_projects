#include<windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#define PI 3.1416


void init(){
    glClearColor(0.19f,0.80f,0.19f,0.0);
    glOrtho(-30,+30,-30,+30,-5,+5);
}

void circle(float radiusX, float radiusY){
    int i=0;
    float angle=0.0;
    glBegin(GL_POLYGON);
    for (i=0;i<100;i++){
        angle = 2*PI*i/100;
        glVertex2d(radiusX*cos(angle), radiusY*sin(angle));
    }
    glEnd();

}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINE_LOOP);
        glVertex2d(20,10);
        glVertex2d(20,-10);
        glVertex2d(-20,-10);
        glVertex2d(-20,10 );
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(-20,5);
        glVertex2d(-13,5);
        glVertex2d(-13,-5);
        glVertex2d(-20,-5);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(-20,3);
        glVertex2d(-15,3);
        glVertex2d(-15,-3);
        glVertex2d(-20,-3);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(-20,2);
        glVertex2d(-20,-2);
        glVertex2d(-22,-2);
        glVertex2d(-22,2);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(20,5);
        glVertex2d(13,5);
        glVertex2d(13,-5);
        glVertex2d(20,-5);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(20,3);
        glVertex2d(15,3);
        glVertex2d(15,-3);
        glVertex2d(20,-3);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex2d(20,2);
        glVertex2d(22,2);
        glVertex2d(22,-2);
        glVertex2d(20,-2);
        glEnd();

        glBegin(GL_LINES);
        glVertex2d(0,10);
        glVertex2d(0,-10);
        glEnd();


glBegin(GL_LINE_LOOP);
circle(2,2);
glEnd();

    glFlush();

}

int main()
{
    //glutInit(&argc, argv);
    glutInitWindowSize(1100,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("GLUT Shapes");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;


}
