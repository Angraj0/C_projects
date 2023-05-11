#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,+10,-10,+10,-10,+10);
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
glColor3f(0.607,0.647,0.043) ;
    glVertex2d(-5.2,.2);
    glVertex2d(-7,1);
    glVertex2d(-7,2);
    glVertex2d(-5.2,1.2);


  glEnd();
   glBegin(GL_QUADS);
   glBegin(GL_LINES);
   glColor3f(0.568,0.109,0.384) ;
   glVertex2d(-7,2);
    glVertex2d(-5.2,1.2);

    glVertex2d(-7,2);
    glVertex2d(-4,6);
    glVertex2d(-4,6);
    glVertex2d(-2.3,5.1);
    glVertex2d(-2.3,5.1);
    glVertex2d(-5.2,1.2);
    glVertex2d(-5.2,1.2);
    glVertex2d(-7,2);



  glEnd();
  glBegin(GL_QUADS);
   glBegin(GL_LINES);
   glColor3f(0.047,0.541,0.717) ;
   glVertex2d(-5.2,.2);
    glVertex2d(-5.2,1.2);
    glVertex2d(-5.2,1.2);
glVertex2d(-2.3,5.1);
glVertex2d(-2.3,5.1);
glVertex2d(-2.3,4.1);
glVertex2d(-2.3,4.1);
glVertex2d(-5.2,.2);



glEnd();



    glBegin(GL_TRIANGLES);

            glColor3f(0,1,0) ;
        glVertex2d(3,5);
        glVertex2d(1,2);
        glVertex2d(4,1.3);
        glColor3f(0.662,0.490,0.290) ;
        glVertex2d(3,5);
        glVertex2d(4,1.3);
        glVertex2d(5,3);


    glEnd();




    glFlush();

}

int main(){
    //glutInit(&argc, argv);
    glutInitWindowSize(1000,750);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("GLUT Shapes");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();


    return 0;
}
