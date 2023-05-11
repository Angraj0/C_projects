/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-5,+5,-5,+5,-5,+5);
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    //glutSwapBuffers()
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
     init();
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
