#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#define PI 3.1416
float cx=0, cy=0;

void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,+10,-10,+10,-10,+10);
}

void animate(){
    if(cx<11){
        cx=cx+0.001;
        cy=cy+0.001;
    }else if(cx>11){
        cx=-11;
        cy=-11;
    }
    glutPostRedisplay();

}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    animate();
    glPushMatrix();
        glTranslated(cx,cy,1);
        glColor3f(1,0.3,0.4);
       glBegin(GL_POLYGON);
          glVertex2d(1,1);
          glVertex2d(4,2);
          glVertex2d(5,3);
          glVertex2d(6,4);
          glEnd();

    glPopMatrix();

    glFlush();

}

int main(){
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Animate");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();


    return 0;
}
