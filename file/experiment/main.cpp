    #include<windows.h>
    #ifdef _APPLE_
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <stdlib.h>
    #include<math.h>
    #define PI 3.1416
    float cx=0,cy=0, angleC=0.0, angleC1=0;
    void init(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-5,+5,-5,+5,-5,+5);

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

            glColor3f(0.1,0.9,0.1);
            glRotated(angleC,0,0,-1);

            glBegin(GL_LINE_LOOP);
            circle(1,2);
            glEnd();

            glColor3f(0.2,0.1,0.7);
            glTranslated(0.85,1,0);
            circle(0.2,0.2);
            glColor3f(0.7,0.2,0.5);
            glRotated(angleC1,0,0,1);

           glBegin(GL_LINES);
           glVertex2d(0,0);
           glVertex2d(0,0.2);
           glEnd();

           glPopMatrix();


           //2

            glPushMatrix();

             glColor3f(0.6,0.2,0.1);
             glRotated(angleC,0,0,-1);

            glBegin(GL_LINE_LOOP);
            circle(2,3);
            glEnd();

            glColor3f(0.3,0,0.1);
            glTranslated(0,2.95,0);
            circle(0.2,0.2);
            glColor3f(0.3,0.9,0.1);
            glRotated(angleC1,0,0,1);
            glBegin(GL_LINES);
            glVertex2d(0,0);
            glVertex2d(0,0.2);
            glEnd();

           glPopMatrix();

           //3

           glPushMatrix();


             glRotated(angleC,0,0,-1);
             glColor3f(0.6,0.2,0.5);
             glBegin(GL_LINE_LOOP);
             circle(3,4);
             glEnd();

             glColor3f(0.1,0.5,0.3);
             glTranslated(2.95,0,0);

              circle(0.2,0.2);
              glColor3f(0.1,0.2,0.5);
              glRotated(angleC1,0,0,1);

             glBegin(GL_LINES);
             glVertex2d(0,0);
             glVertex2d(0,0.2);

           glEnd();

           glPopMatrix();





       glFlush();


    }
    void rotateCircle(){
    angleC=angleC+0.05;
    glutPostRedisplay();
    }
    void rotateCircle1(){
    angleC1=angleC1+0.2;

    glutPostRedisplay();
    }

    void normalKey(unsigned char key, int x, int y){

    switch(key){
    case 'a':
        glutIdleFunc(rotateCircle1);

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

    void specialKey(int key, int x, int y){
      switch(key){
  case GLUT_KEY_UP:
    if(cy<4)
      cy++;
      glutPostRedisplay();
      break;

      case GLUT_KEY_DOWN:
          if(cy>-4)
      cy--;
      glutPostRedisplay();
      break;

      case GLUT_KEY_LEFT:
          if(cx>-4)
      cx--;
      glutPostRedisplay();
      break;

      case GLUT_KEY_RIGHT:
          if(cx<4)
      cx++;
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
        glutSpecialFunc(specialKey);
        glutKeyboardFunc(normalKey);
        glutMainLoop();


        return 0;
    }
