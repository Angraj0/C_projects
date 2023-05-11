
#include<windows.h>    //for windows device
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<math.h>
#define PI 3.1416

void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-5,+5,-10,+10,-5,+5);

}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);//clear previous color if exists
glBegin(GL_LINES);
   glColor3f(0.96,0.96,0.96) ;
    glVertex2d(-10,-10);
    glVertex2d(-10,-20);
    glVertex2d(-10,-20);
    glVertex2d(7,-20);
    glVertex2d(7,-20);
    glVertex2d(7,-10);
    glVertex2d(7,-10);
    glVertex2d(5,-10);
    glVertex2d(5,-10);
    glVertex2d(3,-8);
    glVertex2d(3,-8);
    glVertex2d(2,-10);
     glVertex2d(2,-10);
     glVertex2d(-10,-10);




  glEnd();


    glFlush();


}

int main(){
    //glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();


    return 0;
}
