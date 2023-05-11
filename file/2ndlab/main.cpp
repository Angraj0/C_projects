#include<windows.h>
    #ifdef _APPLE_
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <stdlib.h>
    #include<math.h>
    #define PI 3.1416

void init(){
    glClearColor(0.033f,0.71f,0.3f,0.1f);
    glOrtho(-20,+20,-20,+20,-20,+20);
}
void circle(float radiusX,float radiusY){
    int i=0;
    float angle= 0.0;
    glBegin(GL_POLYGON);
    for (i=0;i<200 ;i++){

        angle= 2*PI*i/200;
        glVertex2d(radiusX*cos(angle),radiusY*sin(angle));
    }
        glEnd();
        }
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);//clear previous color if exists
    glBegin(GL_LINE_LOOP);

    glVertex2d(-13,8);
     glVertex2d(13,8);
    glVertex2d(13,-8);

    glVertex2d(-13,-8);



    glEnd();
    glBegin(GL_LINE_LOOP);

    glVertex2d(13,-2);
     glVertex2d(14,-2);
    glVertex2d(14,2);

    glVertex2d(13,2);



    glEnd();
glBegin(GL_LINE_LOOP);

    glVertex2d(13,-3);
     glVertex2d(11,-3);
    glVertex2d(11,3);

    glVertex2d(13,3);



    glEnd();
    glBegin(GL_LINE_LOOP);

    glVertex2d(13,-4);
     glVertex2d(10,-4);
    glVertex2d(10,4);

    glVertex2d(13,4);



    glEnd();




    glBegin(GL_LINE_LOOP);

    glVertex2d(-13,-2);
     glVertex2d(-14,-2);
    glVertex2d(-14,2);

    glVertex2d(-13,2);



    glEnd();
glBegin(GL_LINE_LOOP);

    glVertex2d(-13,-3);
     glVertex2d(-11,-3);
    glVertex2d(-11,3);

    glVertex2d(-13,3);



    glEnd();
    glBegin(GL_LINE_LOOP);

    glVertex2d(-13,-4);
     glVertex2d(-10,-4);
    glVertex2d(-10,4);

    glVertex2d(-13,4);
glEnd();

    glBegin(GL_LINES);
    glVertex2d(0,8);
    glVertex2d(0,-8);
    glEnd();

      glBegin(GL_LINE_LOOP);
      circle(2.0,2.5);
glEnd();
circle(.2,.3);


      glPushMatrix();

      glTranslated(-10.4,0,0);

      circle(.2,.35);
      glPopMatrix();
      glPushMatrix();

      glTranslated(10.4,0,0);

      circle(.2,.35);
      glPopMatrix();
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
