    #include<windows.h>
    #ifdef _APPLE_
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <stdlib.h>
    #include<math.h>
    #define PI 3.1416
    float cx=0,cy=0, angleC=0;
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
          glColor3f(1,0,0);

          //glScaled(2,2,1);

            glTranslated(cx,cy,0);
             glRotated(angleC,0,0,-1);

           circle(1,1);
           glColor3f(0,1,0);
           glBegin(GL_LINES);
           glVertex2d(0,0);
           glVertex2d(0,-1);
           glEnd();

           glPopMatrix();




       glFlush();


    }
    void rotateCircle(){
    angleC=angleC+0.05;
    cx=cx+0.0001;
    glutPostRedisplay();
    }
    void rotateCircle1(){
    angleC=angleC-0.05;
    cx=cx-0.0001;
    glutPostRedisplay();
    }

    void normalKey(unsigned char key, int x, int y){

    switch(key){
    case 'a':
        glutIdleFunc(rotateCircle);

    break;

    case 'b':
        glutIdleFunc(NULL);
        glutPostRedisplay();

    break;

    case 'c':
        glutIdleFunc(rotateCircle1);
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

        glutCreateWindow("GLUT Circle");
        init();
        glutDisplayFunc(myDisplay);
        glutSpecialFunc(specialKey);
        glutKeyboardFunc(normalKey);
        glutMainLoop();


        return 0;
    }
