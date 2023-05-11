#include <windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void rshapeFunc(int width, int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)width/(double)height,1.00,100.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        glColor3f(1,0,0); //front
        glBegin(GL_QUADS);
            glVertex3d(+3,+3,+3);
            glVertex3d(+3,-3,+3);
            glVertex3d(-3,-3,+3);
            glVertex3d(-3,+3,+3);
        glEnd();
    glPopMatrix();

       glPushMatrix();
        glColor3f(0,1,0); //back
        glBegin(GL_QUADS);
            glVertex3d(+3,+3,-3);
            glVertex3d(+3,-3,-3);
            glVertex3d(-3,-3,-3);
            glVertex3d(-3,+3,-3);
        glEnd();
    glPopMatrix();

       glPushMatrix();
        glColor3f(0,0,1); //top
        glBegin(GL_QUADS);
            glVertex3d(-3,+3,+3);
            glVertex3d(+3,+3,+3);
            glVertex3d(+3,+3,-3);
            glVertex3d(-3,+3,-3);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,1); //bottom
        glBegin(GL_QUADS);
            glVertex3d(-3,-3,+3);
            glVertex3d(+3,-3,+3);
            glVertex3d(+3,-3,-3);
            glVertex3d(-3,-3,-3);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,1); //right
        glBegin(GL_QUADS);
            glVertex3d(+3,+3,+3);
            glVertex3d(+3,-3,+3);
            glVertex3d(+3,-3,-3);
            glVertex3d(+3,+3,-3);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0,0,1); //left
        glBegin(GL_QUADS);
            glVertex3d(-3,+3,+3);
            glVertex3d(-3,-3,+3);
            glVertex3d(-3,-3,-3);
            glVertex3d(-3,+3,-3);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();

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


    glutMainLoop();

    return 0;
}
