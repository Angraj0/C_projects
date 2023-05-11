#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

double angle;


void rshapeFunc(int width, int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(double)width/(double)height,1.0,100.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslated(0,0,-20);
    glRotated(angle,0.4,1,0);


    glPushMatrix();
        glColor3f(1,0,0); //left
        glBegin(GL_POLYGON);
            glVertex3f(-2,-1,+3);
            glVertex3f(-1.2,-1,+3);
            glVertex3f(-1.2,-4,+3);
            glVertex3f(-2,-4,+3);



        glEnd();
    glPopMatrix();

     glPushMatrix();           //left back
             glBegin(GL_POLYGON);
             glVertex3f(-2,-1,+2.4);
            glVertex3f(-1.2,-1,+2.4);
            glVertex3f(-1.2,-4,+2.4);
            glVertex3f(-2,-4,+2.4);

             glEnd();

             glPopMatrix();

             glPushMatrix();           //left left
             glBegin(GL_POLYGON);
             glVertex3f(-2,-1,+3);
            glVertex3f(-2,-1,+2.4);
            glVertex3f(-2,-4,+2.4);
             glVertex3f(-2,-4,+3);

             glEnd();

             glPopMatrix();

             glPopMatrix();

             glPushMatrix();           //left right
             glBegin(GL_POLYGON);
             glVertex3f(-1.2,-1,+3);
            glVertex3f(-1.2,-1,+2.4);
            glVertex3f(-1.2,-4,+2.4);
              glVertex3f(-1.2,-4,+3);

             glEnd();

             glPopMatrix();

             //right

     glPushMatrix();
        glColor3f(1,0,0); //right
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,+3);
            glVertex3f(1.2,-1,+3);
            glVertex3f(1.2,-4,+3);
            glVertex3f(2,-4,+3);

        glEnd();
    glPopMatrix();


     glPushMatrix();
        glColor3f(1,0,0); //right back
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,+2.4);
            glVertex3f(1.2,-1,+2.4);
            glVertex3f(1.2,-4,+2.4);
            glVertex3f(2,-4,+2.4);

        glEnd();
    glPopMatrix();

     glPushMatrix();
        glColor3f(1,0,0); //right right
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,+3);
            glVertex3f(2,-1,+2.4);
             glVertex3f(2,-4,+2.4);
            glVertex3f(2,-4,+3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //right left
        glBegin(GL_POLYGON);
            glVertex3f(1.2,-1,+3);
            glVertex3f(1.2,-1,+2.4);
             glVertex3f(1.2,-4,+2.4);
           glVertex3f(1.2,-4,+3);

        glEnd();
    glPopMatrix();

  //back left



     glPushMatrix();
        glColor3f(1,0,0); //back left
        glBegin(GL_POLYGON);
            glVertex3f(-2,-1,-3);
            glVertex3f(-1.2,-1,-3);
            glVertex3f(-1.2,-4,-3);
            glVertex3f(-2,-4,-3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //back left
        glBegin(GL_POLYGON);
            glVertex3f(-2,-1,-2.4);
            glVertex3f(-1.2,-1,-2.4);
            glVertex3f(-1.2,-4,-2.4);
            glVertex3f(-2,-4,-2.4);

        glEnd();
    glPopMatrix();

      glPushMatrix();
        glColor3f(1,0,0); //back left left
        glBegin(GL_POLYGON);
            glVertex3f(-2,-1,-2.4);
             glVertex3f(-2,-1,-3);
             glVertex3f(-2,-4,-3);
            glVertex3f(-2,-4,-2.4);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //back left right
        glBegin(GL_POLYGON);
             glVertex3f(-1.2,-1,-3);
            glVertex3f(-1.2,-1,-2.4);
            glVertex3f(-1.2,-4,-2.4);
           glVertex3f(-1.2,-4,-3);

        glEnd();
    glPopMatrix();







     glPushMatrix();
        glColor3f(1,0,0); //back right
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,-3);
            glVertex3f(1.2,-1,-3);
            glVertex3f(1.2,-4,-3);
            glVertex3f(2,-4,-3);

        glEnd();
    glPopMatrix();

     glPushMatrix();
        glColor3f(1,0,0); //back right back
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,-2.4);
            glVertex3f(1.2,-1,-2.4);
            glVertex3f(1.2,-4,-2.4);
            glVertex3f(2,-4,-2.4);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //back right left
        glBegin(GL_POLYGON);
            glVertex3f(2,-1,-3);
           glVertex3f(2,-1,-2.4);
            glVertex3f(2,-4,-2.4);
            glVertex3f(2,-4,-3);

        glEnd();
    glPopMatrix();

      glPushMatrix();
        glColor3f(1,0,0); //back right left
        glBegin(GL_POLYGON);
           glVertex3f(1.2,-1,-3);
           glVertex3f(1.2,-1,-2.4);
            glVertex3f(1.2,-4,-2.4);
            glVertex3f(1.2,-4,-3);

        glEnd();
    glPopMatrix();











    glPushMatrix();
        glColor3f(0.854,0.647,0.125);  //front sit
        glBegin(GL_POLYGON);
            glVertex3f(-2.2,-0.2,+3);
            glVertex3f(+2.2,-0.2,+3);
            glVertex3f(+2.2,-1,+3);
            glVertex3f(-2.2,-1,+3);

        glEnd();
    glPopMatrix();

     glPushMatrix();
        glColor3f(0.854,0.647,0.125);   //back sit
        glBegin(GL_POLYGON);
            glVertex3f(-2.2,-0.2,-3);
            glVertex3f(+2.2,-0.2,-3);
            glVertex3f(+2.2,-1,-3);
            glVertex3f(-2.2,-1,-3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
      glColor3f(0.854,0.647,0.125);   //side right
        glBegin(GL_POLYGON);
            glVertex3f(+2.2,-0.2,+3);
            glVertex3f(+2.2,-0.2,-3);
            glVertex3f(+2.2,-1,-3);
            glVertex3f(+2.2,-1,+3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.854,0.647,0.125);   //side right
        glBegin(GL_POLYGON);
             glVertex3f(-2.2,-0.2,+3);
             glVertex3f(-2.2,-0.2,-3);
             glVertex3f(-2.2,-1,-3);
            glVertex3f(-2.2,-1,+3);


        glEnd();
    glPopMatrix();

    glPushMatrix();
         glColor3f(0.854,0.647,0.125); //side right
        glBegin(GL_POLYGON);
             glVertex3f(-2.2,-0.2,+3);
             glVertex3f(-2.2,-0.2,-3);
             glVertex3f(+2.2,-0.2,-3);
           glVertex3f(+2.2,-0.2,+3);


        glEnd();
    glPopMatrix();

  glPushMatrix();
        glColor3f(0.933,0.250,0); //stand back
        glBegin(GL_POLYGON);
             glVertex3f(-2.2,-0.2,-3);
             glVertex3f(+2.2,-0.2,-3);
             glVertex3f(+2.2,5.2,-3);
           glVertex3f(-2.2,+5.2,-3);


        glEnd();
    glPopMatrix();

     glPushMatrix();
        glColor3f(0.933,0.250,0); //stand front
        glBegin(GL_POLYGON);
             glVertex3f(-2.2,-0.2,-2.7);
             glVertex3f(+2.2,-0.2,-2.7);
             glVertex3f(+2.2,5.2,-2.7);
           glVertex3f(-2.2,+5.2,-2.7);


        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.933,0.250,0); //stand left
        glBegin(GL_POLYGON);
             glVertex3f(-2.2,-0.2,-3);
             glVertex3f(-2.2,-0.2,-2.7);
             glVertex3f(-2.2,+5.2,-2.7);
            glVertex3f(-2.2,+5.2,-3);


        glEnd();
    glPopMatrix();

 glPushMatrix();
        glColor3f(0.933,0.250,0); //stand right
        glBegin(GL_POLYGON);
             glVertex3f(+2.2,-0.2,-2.7);
             glVertex3f(+2.2,-0.2,-3);
            glVertex3f(+2.2,5.2,-3);
            glVertex3f(+2.2,5.2,-2.7);


        glEnd();
    glPopMatrix();

glPushMatrix();
        glColor3f(0.933,0.250,0); //stand right
        glBegin(GL_POLYGON);
             glVertex3f(+2.2,5.2,-2.7);
             glVertex3f(+2.2,5.2,-3);
            glVertex3f(-2.2,+5.2,-3);
            glVertex3f(-2.2,+5.2,-2.7);


        glEnd();
    glPopMatrix();












    glutSwapBuffers();

}

void rotateobj(){
    angle=angle+0.02;
    glutPostRedisplay();
}

void normalKey(unsigned char key, int x, int y){

    switch(key){
    case 'r':
        glutIdleFunc(rotateobj);
        glutPostRedisplay();

    break;

    case 's':
        glutIdleFunc(NULL);
        glutPostRedisplay();

    break;


    default:
    break;
    }
    }

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D Shapes");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(rshapeFunc);
    glutDisplayFunc(display);
    glutKeyboardFunc(normalKey);


    glutMainLoop();

    return 0;
}
