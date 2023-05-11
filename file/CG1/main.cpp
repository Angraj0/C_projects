#include<windows.h>    //for windows device
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glOrtho(-20,+20,-20,+20,-20,+20);
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1,.5,0);
glVertex2d(0.1,4);
    glVertex2d(0.1,7);
    glVertex2d(3,7);
    glVertex2d(3,6);
     glVertex2d(4,6);
    glVertex2d(4,4);
    glVertex2d(1,7);
     glVertex2d(1,9);
     glVertex2d(2.2,9);
     glVertex2d(2.2,7);

      glVertex2d(-4,4);
     glVertex2d(5,4);
     glVertex2d(5,3);
     glVertex2d(4.2,2);
     glVertex2d(4,1.2);
     glVertex2d(3,1);
     glVertex2d(-2,1);
     glVertex2d(-3,1.2);
     glVertex2d(-3.2,2);
     glVertex2d(-4,3);
     glVertex2d(-4,4);
glEnd();
    glFlush();

}

int main(){
    //glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();


    return 0;
}
