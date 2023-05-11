#include<windows.h>    //for windows device
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glOrtho(-10,+10,-10,+10,-10,+10);
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);//clear previous color if exists
    glBegin(GL_POLYGON);
    glColor3f(1,.5,0);
    glVertex2d(2,2);
     glVertex2d(3,3);
    glVertex2d(5,3);

    glVertex2d(6,2);

    glVertex2d(5,1);
    glVertex2d(3,1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(0,0);
     glVertex2d(0,2);
    glVertex2d(-3,2);

    glVertex2d(-3,0);
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
