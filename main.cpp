#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define SPACEBAR 32

void display();
void reshape(int,int);
void timer(int);
void car_key(int,int,int);
void game_key(unsigned char,int,int);

void init()
{
   glClearColor(0.2,0.8,0.2,1.0);
   // glClearColor(0.0,0.0,0.0,1.0);
}

//opposite_car_move
float y_positioncar1= 0.0;
float y_positioncar2= 0.0;
int state1=1;
int state2=2;
//main_car_move
int maincar_pos_x = 0;
int maincar_pos_y = 0;

void wheel()
{

       glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-3.3,-6.5);
    glVertex2f(-3.3,-7);
    glVertex2f(-1.2,-7);
    glVertex2f(-1.2,-6.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(-3.3,-8.5);
    glVertex2f(-3.3,-8);
    glVertex2f(-1.3,-8);
    glVertex2f(-1.3,-8.5);
    glEnd();


}
float divider1=0;
float divider2=5;
float divider3=-5;
float divider4=-10;
float divider5=-15;

void road_middle()
{

     glBegin(GL_QUADS);

    glColor3f(1.0,1.0,1.0);
    glVertex2f(0, divider1 + 9);
    glVertex2f(0, divider1 +5);
    glVertex2f(0.5, divider1 +5 );
    glVertex2f(0.5, divider1 +9);

     glVertex2f(0, divider2 + 9);
    glVertex2f(0, divider2 +5);
    glVertex2f(0.5, divider2 +5 );
    glVertex2f(0.5, divider2 +9);

      glVertex2f(0, divider3 + 9);
    glVertex2f(0, divider3 +5);
    glVertex2f(0.5, divider3 +5 );
    glVertex2f(0.5, divider3 +9);

    glVertex2f(0, divider4 + 9);
    glVertex2f(0, divider4 +5);
    glVertex2f(0.5, divider4 +5 );
    glVertex2f(0.5, divider4 +9);

     glVertex2f(0, divider5 + 9);
    glVertex2f(0, divider5 +5);
    glVertex2f(0.5, divider5 +5 );
    glVertex2f(0.5, divider5 +9);



        glEnd();

        glLoadIdentity();

        divider1 = divider1 - 0.05;
           if (divider1 < -4.5)
        {
        divider1 = 1;

        }
        divider2 = divider2 - 0.05;
           if (divider2 < +0.5)
        {
        divider2 = 6;

        }
        divider3 = divider3 - 0.05;
           if (divider3 < -9.5)
        {
        divider3 = -4;

        }
        divider4 = divider4 - 0.05;
           if (divider4 < -14.5)
        {
        divider4 = -9;
        }
         divider5 = divider5 - 0.05;
           if (divider5 < -19.5)
        {
        divider5 = -14;
        }


}

void road_property()
{
        ///road
    glPointSize(10.0);
    glBegin(GL_POLYGON);

    glColor3f(0.3,0.3,0.3);
    glVertex2f(-7,10);
    glVertex2f(-7,-10);
    glVertex2f(6.9,-10);
    glVertex2f(6.9,10);


    glEnd();

     glLoadIdentity();

     ///road-lane
     glLineWidth(15.0);
    glBegin(GL_LINES);

    glColor3f(1.0,1.0,0.0);

    //left
    glVertex2f(-6.6,10);
    glVertex2f(-6.6,-10);
    //right
    glVertex2f(6.5,-10);
    glVertex2f(6.5,10);

    glEnd();
    glLoadIdentity();



}


///Start_game_function
void start_game()
{
    glLoadIdentity();
     //Score Board
    glBegin(GL_POLYGON);
     glColor3f(0.0, 0.3, 0.1);

    glVertex2f(7, 8.6);
    glVertex2f(7, 5.6);
    glVertex2f(9.8, 5.6 );
    glVertex2f(9.8, 8.6);

    glEnd();
     glLoadIdentity();

    ///road
    road_property();

    road_middle();

    ///main_car
   //  glTranslatef(maincar_pos_x+0.0,maincar_pos_y+0.0,0.0);
    ///wheel();
    //car_body
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(maincar_pos_x-3,maincar_pos_y-6);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(maincar_pos_x-3,maincar_pos_y-9);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(maincar_pos_x-1.5,maincar_pos_y-9);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(maincar_pos_x-1.5,maincar_pos_y-6);

    glEnd();
     glLoadIdentity();

     ///opposite_car_1
    // glTranslatef(5.0,y_positioncar1+10.0,0.0);
     ///wheel();
     //car
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(2,y_positioncar1 +4);
    glVertex2f(2,y_positioncar1 +1);
    glVertex2f(3.5,y_positioncar1 +1);
    glVertex2f(3.5,y_positioncar1 +4);

    glEnd();
     glLoadIdentity();

    ///opposite_car_2
     glTranslatef(0.0,y_positioncar2+13.0,0.0);
    ///wheel();
    //car
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-3,y_positioncar2 +7);
    glVertex2f(-3,y_positioncar2 +4);
    glVertex2f(-1.5,y_positioncar2 +4);
    glVertex2f(-1.5,y_positioncar2 +7);

    glEnd();
     glLoadIdentity();

    glutSwapBuffers();
}
void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    //gluPerspective(60,1,2.0,50.0);

    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

    switch(state1)
    {

    case -1:
        if(y_positioncar1<10)
            y_positioncar1+=0.15;
        else
            state1=1;
        break;
    case 1:
        if(y_positioncar1>-13)
            y_positioncar1-=0.08;
        else
            state1=-1;
        break;
    }
    switch(state2)
    {

    case -2:
        if(y_positioncar2 < 8)
            y_positioncar2+=0.08;
        else
            state2=2;
        break;
    case 2:
        if(y_positioncar2>-15)
            y_positioncar2-=0.15;
        else
            state2=-2;
        break;
    }

}

void car_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        if (maincar_pos_y >= 1)
        {
            maincar_pos_y = maincar_pos_y - 2;

        }

        break;
    case GLUT_KEY_UP:

        if (maincar_pos_y <= 14)
        {
            maincar_pos_y = maincar_pos_y + 2;
        }
        break;

    case GLUT_KEY_LEFT:
        if (maincar_pos_x >= -2)
        {
            maincar_pos_x = maincar_pos_x - 1;

        }
        break;

    case GLUT_KEY_RIGHT:
        if (maincar_pos_x <= 6)
        {
            maincar_pos_x = maincar_pos_x + 1 ;
        }
        break;

    default:
        break;
    }
}

int start=0;

void introduction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(50);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex2f(0,0);
        glVertex2f(0,5);
    glEnd();
    glLoadIdentity();
    glFlush();
}

void game_key(unsigned char key, int x, int y)
{

    switch (key)
    {
    case SPACEBAR:
        if (start == 0)
        {
            start=1;
            break;
        }
        else{
            introduction();
        }
    }
}


void display()
{

    glClear(GL_COLOR_BUFFER_BIT);


        if (start == 1)
    {
        start_game();

    }

    else
    {
        introduction();
    }

}

int main (int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(200, 50);


    glutCreateWindow("CG-Race");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(game_key);
    glutSpecialFunc(car_key);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}
