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
//road_divider
float divider1=0;
float divider2=5;
float divider3=-5;
float divider4=-10;
float divider5=-15;

//opposite_car
float car1=-1;
float car2=20;
float car3=-8;
float car4=0;


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

        divider1 = divider1 - 0.4;
           if (divider1 < -4.5)
        {
        divider1 = 1;

        }
        divider2 = divider2 - 0.4;
           if (divider2 < +0.5)
        {
        divider2 = 6;

        }
        divider3 = divider3 - 0.4;
           if (divider3 < -9.5)
        {
        divider3 = -4;

        }
        divider4 = divider4 - 0.4;
           if (divider4 < -14.5)
        {
        divider4 = -9;
        }
         divider5 = divider5 - 0.4;
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

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,1.0);
    glVertex2f(maincar_pos_x-3,maincar_pos_y-9);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(maincar_pos_x-2.25,maincar_pos_y-9.5);
    glColor3f(0.0,0.22,0.5);
    glVertex2f(maincar_pos_x-1.5,maincar_pos_y-9);

    glEnd();


    glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);
    glVertex2f(maincar_pos_x-3.3,maincar_pos_y-6.5);
    glVertex2f(maincar_pos_x-3.3,maincar_pos_y-7);
    glVertex2f(maincar_pos_x-1.3,maincar_pos_y-7);
    glVertex2f(maincar_pos_x-1.3,maincar_pos_y-6.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(maincar_pos_x-3.3,maincar_pos_y-8.5);
    glVertex2f(maincar_pos_x-3.3,maincar_pos_y-8);
    glVertex2f(maincar_pos_x-1.3,maincar_pos_y-8);
    glVertex2f(maincar_pos_x-1.3,maincar_pos_y-8.5);
    glEnd();
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

     ///opposite_car_1 (red)

     //wheel();

        glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.7,car1+13.5);
    glVertex2f(0.7,car1+13);
    glVertex2f(2.7,car1+13);
    glVertex2f(2.7,car1+13.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(0.7,car1+12);
    glVertex2f(0.7,car1+11.5);
    glVertex2f(2.7,car1+11.5);
    glVertex2f(2.7,car1+12);
    glEnd();

     //car
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(1,car1 +14);
    glVertex2f(1,car1 +11);
    glVertex2f(2.5,car1 +11);
    glVertex2f(2.5, car1 +14);

    glEnd();
     glLoadIdentity();

      car1 = car1 - 0.12;
         if (car1 < -30)
       {
        car1 = 1;
          }

    ///opposite_car_2 ( yellow )

    //wheel();

     glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);

    glVertex2f(-2.8,car2+6.5);
    glVertex2f(-2.8,car2+6);
    glVertex2f(-0.8,car2+6);
    glVertex2f(-0.8,car2+6.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(-2.8,car2+5);
    glVertex2f(-2.8,car2+4.5);
    glVertex2f(-0.8,car2+4.5);
    glVertex2f(-0.8,car2+5);
    glEnd();


    //car
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-2.5,car2 +7);
    glVertex2f(-2.5, car2+4);
    glVertex2f(-1, car2+4);
    glVertex2f(-1, car2+7);

    glEnd();
     glLoadIdentity();

     car2 = car2 - 0.15;
           if (car2 < -30)
        {
        car2 = 7;

        }

     ///opposite_car_3  ( blue )

    //wheel();

    glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-5.8,car3+9.5);
    glVertex2f(-5.8,car3+9);
    glVertex2f(-3.8,car3+9);
    glVertex2f(-3.8,car3+9.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(-5.8,car3+8);
    glVertex2f(-5.8,car3+7.5);
    glVertex2f(-3.8,car3+7.5);
    glVertex2f(-3.8,car3+8);
    glEnd();

    //car
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,1.0);

    glVertex2f(-5.5, car3+10);
    glVertex2f(-5.5,car3 +7);
    glVertex2f(-4, car3 +7);
    glVertex2f(-4,car3 +10);

    glEnd();
     glLoadIdentity();

     car3 = car3 - 0.1;
        if (car3 < -30)
       {
        car3 = 3;

       }

    ///opposite_car_4 ( cyan )
    ///wheel();

      glBegin(GL_QUADS);
    // front
    glColor3f(0.0,0.0,0.0);
    glVertex2f(3.7,car4+4.5);
    glVertex2f(3.7,car4+4);
    glVertex2f(5.7,car4+4);
    glVertex2f(5.7,car4+4.5);
    //back
     glColor3f(0.0,0.0,0.0);
    glVertex2f(3.7,car4+3);
    glVertex2f(3.7,car4+2.5);
    glVertex2f(5.7,car4+2.5);
    glVertex2f(5.7,car4+3);
    glEnd();

    //car
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(4, car4 +5);
    glVertex2f(4, car4 +2);
    glVertex2f(5.5,car4 +2);
    glVertex2f(5.5,car4 +5);

     car4 = car4 - 0.18;
           if (car4 < -30)
        {
        car4 = 9;

       }

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

    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

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
    glLineWidth(50);
    glBegin(GL_QUADS);
        glColor3f(0,0,0);
        glVertex2f(-10,-15);
        glVertex2f(-10,10);
        glVertex2f(12,10);
        glVertex2f(12,-15);
    glEnd();

    glLineWidth(15);
    glBegin(GL_LINES);
        glColor3f(1,0,0);

        //c
        glVertex2f(-4,4);
        glVertex2f(-4,7);

        glVertex2f(-2.5,7);
        glVertex2f(-4,7);

        glVertex2f(-2.5,4);
        glVertex2f(-4,4);

        //G
        glVertex2f(-0.5,4);
        glVertex2f(-0.5,7);

        glVertex2f(1,7);
        glVertex2f(-0.5,7);

        glVertex2f(1,4);
        glVertex2f(-0.5,4);

        glVertex2f(1,4);
        glVertex2f(1,5);

        //R
        glVertex2f(-4,1);
        glVertex2f(-4,-2);

        glVertex2f(-2.5,1);
        glVertex2f(-4,1);

        glVertex2f(-2.5,1);
        glVertex2f(-2.5,-0.5);

        glVertex2f(-2.5,-0.5);
        glVertex2f(-4,-0.5);

        glVertex2f(-4,-0.5);
        glVertex2f(-2.5,-2);

        //A
        glVertex2f(-0.5,1);
        glVertex2f(-0.5,-2);

        glVertex2f(1,1);
        glVertex2f(-0.5,1);

        glVertex2f(1,1);
        glVertex2f(1,-2);

        glVertex2f(1,-0.5);
        glVertex2f(-0.5,-0.5);

        //c
        glVertex2f(2.5,1);
        glVertex2f(2.5,-2);

        glVertex2f(4,-2);
        glVertex2f(2.5,-2);

        glVertex2f(4,1);
        glVertex2f(2.5,1);

        //E

        glVertex2f(5.5,1);
        glVertex2f(5.5,-2);

        glVertex2f(7,-2);
        glVertex2f(5.5,-2);

        glVertex2f(7,1);
        glVertex2f(5.5,1);

        glVertex2f(6.5,-0.5);
        glVertex2f(5.5,-0.5);


    glEnd();

    glLoadIdentity();


    glFlush();
    glutSwapBuffers();
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
