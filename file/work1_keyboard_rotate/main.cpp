    #include<windows.h>
    #ifdef _APPLE_
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <stdlib.h>
    #include<math.h>
    #define PI 3.1416
    float cx=0,cy=0, angleC=0.0;
    void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,+10,-10,+10,-10,+10);

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
          glClear(GL_COLOR_BUFFER_BIT);



           glPushMatrix();


            glRotated(angleC,0,0,-1);
            glPushMatrix();
            glColor3f(1,0,0);
            glTranslated(3,2,0);
            circle(1,1);
            glPopMatrix();
             glPushMatrix();
            glColor3f(1,0,0);

            glTranslated(-3,-2,0);
            circle(1,1);
            glPopMatrix();
            glPushMatrix();

            glColor3f(1,1,1);

            glBegin(GL_LINE_LOOP);
            glVertex2d(-2.5,-1.5);
            glVertex2d(2.5,1.5);

            glEnd();
            glPopMatrix();


            glPopMatrix();






       glFlush();


    }
    void rotateCircle(){
    angleC=angleC+0.01;
    glutPostRedisplay();
    }


    void normalKey(unsigned char key, int x, int y){

    switch(key){
    case 'a':
        glutIdleFunc(rotateCircle);
        glutPostRedisplay();

    break;

    case 'b':
        glutIdleFunc(NULL);
        glutPostRedisplay();

    break;


    default:
    break;
    }
    }



    int main(){

        glutInitWindowSize(800,800);
        glutInitWindowPosition(10,10);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

        glutCreateWindow("GLUT LAb task");
        init();
        glutDisplayFunc(myDisplay);
        glutKeyboardFunc(normalKey);
        sndPlaySound("1.mp3",SND_ASYNC);
        glutMainLoop();


        return 0;
    }
