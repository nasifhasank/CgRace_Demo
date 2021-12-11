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

int start=0;
//main_car_move
int maincar_pos_x = 0;
int maincar_pos_y = 0;

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

//obstacle
float tree1=4;
float tree2=0;
float tree3=0;
float tree4=4;
float tree5=17;
float tree6=21;
float tree7=4;
float tree8=0;
float tree9=0;
float tree10=4;
float tree11=22;
float tree12=10;

float box1=0;
float box2=0;
float box3=0;

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
    glVertex2f(+1,car1 +14);
    glVertex2f(+1,car1 +11);
    glVertex2f(+2.5,car1 +11);
    glVertex2f(+2.5, car1 +14);

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

     ///tree-1

      glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree1+0 );
    glVertex2f(-8.5, tree1-1 );
    glVertex2f(-7.5, tree1-1);


    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree1+0.15 );
    glVertex2f(-8.5, tree1-0.65 );
    glVertex2f(-7.5, tree1-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree1-0.5 );
    glVertex2f(-8, tree1-1.8 );
    glEnd();


     tree1 = tree1 - 0.18;
           if (tree1 < -30)
        {
        tree1 = 9;

       }
    glLoadIdentity();

    ///tree-2
    glTranslatef(-1.2,0,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree2+0 );
    glVertex2f(-8.5, tree2-1 );
    glVertex2f(-7.5, tree2-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree2+0.15 );
    glVertex2f(-8.5, tree2-0.65 );
    glVertex2f(-7.5, tree2-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree2-0.5 );
    glVertex2f(-8, tree2-1.8 );
    glEnd();


     tree2 = tree2 - 0.18;
           if (tree2 < -30)
        {
        tree2 = 9;

       }
    glLoadIdentity();

    ///tree-3
    glTranslatef(-1,10,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree3+0 );
    glVertex2f(-8.5, tree3-1 );
    glVertex2f(-7.5, tree3-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree3+0.15 );
    glVertex2f(-8.5, tree3-0.65 );
    glVertex2f(-7.5, tree3-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree3-0.5 );
    glVertex2f(-8, tree3-1.8 );
    glEnd();


     tree3 = tree3 - 0.18;
           if (tree3 < -30)
        {
        tree3 = 9;

       }
    glLoadIdentity();

    ///tree-4
    glTranslatef(-0.5,20,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree4+0 );
    glVertex2f(-8.5, tree4-1 );
    glVertex2f(-7.5, tree4-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree4+0.15 );
    glVertex2f(-8.5, tree4-0.65 );
    glVertex2f(-7.5, tree4-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree4-0.5 );
    glVertex2f(-8, tree4-1.8 );
    glEnd();


     tree4 = tree4 - 0.18;
           if (tree4 < -30)
        {
        tree4 = 9;

       }
    glLoadIdentity();

    ///tree-5
    glTranslatef(-0.5,2,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree5+0 );
    glVertex2f(-8.5, tree5-1 );
    glVertex2f(-7.5, tree5-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree5+0.15 );
    glVertex2f(-8.5, tree5-0.65 );
    glVertex2f(-7.5, tree5-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree5-0.5 );
    glVertex2f(-8, tree5-1.8 );
    glEnd();


     tree5 = tree5 - 0.18;
           if (tree5 < -30)
        {
        tree5 = 9;

       }
    glLoadIdentity();

    ///tree-6
    glTranslatef(-1,10,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree6+0 );
    glVertex2f(-8.5, tree6-1 );
    glVertex2f(-7.5, tree6-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree6+0.15 );
    glVertex2f(-8.5, tree6-0.65 );
    glVertex2f(-7.5, tree6-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree6-0.5 );
    glVertex2f(-8, tree6-1.8 );
    glEnd();


     tree6 = tree6 - 0.18;
           if (tree6 < -30)
        {
        tree6 = 9;

       }
    glLoadIdentity();

    ///tree-7
    glTranslatef(-1,10,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree7+0 );
    glVertex2f(-8.5, tree7-1 );
    glVertex2f(-7.5, tree7-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree7+0.15 );
    glVertex2f(-8.5, tree7-0.65 );
    glVertex2f(-7.5, tree7-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree7-0.5 );
    glVertex2f(-8, tree7-1.8 );
    glEnd();


     tree7 = tree7 - 0.18;
           if (tree7 < -30)
        {
        tree7 = 9;

       }
    glLoadIdentity();

    ///tree-8
    glTranslatef(+16,10,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree8+0 );
    glVertex2f(-8.5, tree8-1 );
    glVertex2f(-7.5, tree8-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree8+0.15 );
    glVertex2f(-8.5, tree8-0.65 );
    glVertex2f(-7.5, tree8-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree8-0.5 );
    glVertex2f(-8, tree8-1.8 );
    glEnd();


     tree8 = tree8 - 0.18;
           if (tree8 < -30)
        {
        tree8 = 9;

       }
    glLoadIdentity();

    ///tree-9
    glTranslatef(+16,15,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree9+0 );
    glVertex2f(-8.5, tree9-1 );
    glVertex2f(-7.5, tree9-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree9+0.15 );
    glVertex2f(-8.5, tree9-0.65 );
    glVertex2f(-7.5, tree9-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree9-0.5 );
    glVertex2f(-8, tree9-1.8 );
    glEnd();


     tree9 = tree9 - 0.18;
           if (tree9 < -30)
        {
        tree9 = 9;

       }
    glLoadIdentity();

    ///tree-10
    glTranslatef(+16.5,0,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree10+0 );
    glVertex2f(-8.5, tree10-1 );
    glVertex2f(-7.5, tree10-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree10+0.15 );
    glVertex2f(-8.5, tree10-0.65 );
    glVertex2f(-7.5, tree10-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree10-0.5 );
    glVertex2f(-8, tree10-1.8 );
    glEnd();


     tree10 = tree10 - 0.18;
           if (tree10 < -30)
        {
        tree10 = 9;

       }
    glLoadIdentity();

    ///tree-11
    glTranslatef(+16.5,0,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree11+0 );
    glVertex2f(-8.5, tree11-1 );
    glVertex2f(-7.5, tree11-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree11+0.15 );
    glVertex2f(-8.5, tree11-0.65 );
    glVertex2f(-7.5, tree11-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree11-0.5 );
    glVertex2f(-8, tree11-1.8 );
    glEnd();


     tree11 = tree11 - 0.18;
           if (tree11 < -30)
        {
        tree11 = 9;

       }
    glLoadIdentity();

    ///tree-12
    glTranslatef(+16.5,20,0);

    glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree12+0 );
    glVertex2f(-8.5, tree12-1 );
    glVertex2f(-7.5, tree12-1);


    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree12+0.15 );
    glVertex2f(-8.5, tree12-0.65 );
    glVertex2f(-7.5, tree12-0.65);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3f(0.5,1.0,0.0);
    glVertex2f(-8, tree12-0.5 );
    glVertex2f(-8, tree12-1.8 );
    glEnd();


     tree12 = tree12 - 0.18;
           if (tree12 < -30)
        {
        tree12 = 9;

       }
    glLoadIdentity();

    ///box-1
    glTranslatef(-8,0,0);
        glPointSize(30);
        glBegin(GL_POINTS);
            glColor3f(0.470, 0.305, 0.231);
            glVertex2f(0,box1+0);
        glEnd();


    box1 = box1 - 0.18;
           if (box1 < -30)
        {
        box1 = 9;

       }
     glLoadIdentity();

     ///box-2
    glTranslatef(-9,15,0);
        glPointSize(30);
        glBegin(GL_POINTS);
            glColor3f(0.470, 0.305, 0.231);
            glVertex2f(0,box2+0);
        glEnd();


    box2 = box2 - 0.18;
           if (box2 < -30)
        {
        box2 = 9;

       }
     glLoadIdentity();

     ///box-3
    glTranslatef(+8,25,0);
        glPointSize(30);
        glBegin(GL_POINTS);
            glColor3f(0.470, 0.305, 0.231);
            glVertex2f(0,box3+0);
        glEnd();


    box3 = box3 - 0.18;
           if (box3 < -40)
        {
        box3 = 9;

       }
     glLoadIdentity();

    ///Score Board
    glBegin(GL_POLYGON);
     glColor3f(0.0, 0.3, 0.1);

    glVertex2f(7, 8.6);
    glVertex2f(7, 5.6);
    glVertex2f(9.8, 5.6 );

    glVertex2f(9.8, 8.6);

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


