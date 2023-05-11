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
    glRotated(angle,0.5,1,0);

    glPushMatrix();
        glColor3f(1,0.647,0); //front
        glBegin(GL_QUADS);
            glVertex3d(-3,-2,+3);
            glVertex3d(3,-2,+3);
            glVertex3d(6,1,+3);
            glVertex3d(-6,1,+3);

        glEnd();
    glPopMatrix();


glPushMatrix();
        glColor3f(1,0.647,0); //front
        glBegin(GL_QUADS);
            glVertex3d(-3,-2,-3);
            glVertex3d(3,-2,-3);
            glVertex3d(6,1,-3);
            glVertex3d(-6,1,-3);

        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3f(1,0,0); //front
        glBegin(GL_QUADS);
            glVertex3d(6,1,+3);
             glVertex3d(6,1,-3);
            glVertex3d(3,-2,-3);
            glVertex3d(3,-2,+3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //front
        glBegin(GL_QUADS);
            glVertex3d(-6,1,+3);
              glVertex3d(-6,1,-3);
           glVertex3d(-3,-2,-3);
             glVertex3d(-3,-2,+3);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1,0,0); //front
        glBegin(GL_QUADS);
            glVertex3d(-3,-2,+3);
            glVertex3d(-3,-2,-3);
            glVertex3d(3,-2,-3);
            glVertex3d(3,-2,+3);



        glEnd();
    glPopMatrix();

     glPushMatrix();
        glColor3f(1,.905,.729); //front
        glBegin(GL_QUADS);
            glVertex3d(6,1,+3);
             glVertex3d(6,1,-3);
            glVertex3d(-6,1,-3);
            glVertex3d(-6,1,+3);




        glEnd();
    glPopMatrix();












     glPushMatrix();
        glColor3f(0,1,0); //front
        glBegin(GL_QUADS);
            glVertex3d(-2,1,+3);
            glVertex3d(2,1,+3);
            glVertex3d(2,3,+3);
            glVertex3d(-2,3,+3);




        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,1,0);//front
        glBegin(GL_QUADS);
            glVertex3d(-2,1,-3);
            glVertex3d(2,1,-3);
            glVertex3d(2,3,-3);
            glVertex3d(-2,3,-3);




        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,1,0); //front
        glBegin(GL_QUADS);
             glVertex3d(-2,1,+3);
            glVertex3d(-2,1,-3);
            glVertex3d(-2,3,-3);
            glVertex3d(-2,3,+3);




        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,1,0); //front
        glBegin(GL_QUADS);
             glVertex3d(2,3,+3);
             glVertex3d(2,3,-3);
            glVertex3d(-2,3,-3);
            glVertex3d(-2,3,+3);





        glEnd();
    glPopMatrix();


    glPushMatrix();
        glColor3f(0,1,0); //front
        glBegin(GL_QUADS);
            glVertex3d(2,1,+3);
            glVertex3d(2,1,-3);
            glVertex3d(2,3,-3);

            glVertex3d(2,3,+3);





        glEnd();
    glPopMatrix();












    glutSwapBuffers();

}

void rotateobj(){
    angle=angle+0.02;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state==GLUT_DOWN){
                glutIdleFunc(rotateobj);
        }
        break;

    case GLUT_RIGHT_BUTTON:
        glutIdleFunc(NULL);

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
    glutCreateWindow("Online Lab");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(rshapeFunc);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);


    glutMainLoop();

    return 0;
}
