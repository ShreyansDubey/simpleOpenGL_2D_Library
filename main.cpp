#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<windows.h>
#include<GL/glut.h>
#include"SARSGL.h"               //Bresenham Line Drawing


void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* Draw rectangle */
    bres_general(20,40,620,40);
    bres_general(620,40,620,440);
    bres_general(620,440,20,440);
    bres_general(20,440,20,40);

    /* Draw rhombus */
    bres_general(320,440,20,240);
    bres_general(20,240,320,40);
    bres_general(320,40,620,240);
    bres_general(620,240,320,440);

    /* 1 */
    bres_general(250,150,250,250);
    /* 0 */
    int points[] = {300,150,300,250,400,250,400,150};
    polygon(points, 4);
    //bres_general(300,150,300,250);
    //bres_general(300,250,400,250);
    //bres_general(400,250,400,150);
    //bres_general(400,150,300,150);
    /* Ellipse */
    ellip_circle(400,400,200,250);
    /* Circle */
    ellip_circle(250,250,250,250);
    glFlush();
}

void init() {
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Room");
    glClearColor(0.0,0.0,0.0,0);
    glColor3f(1.0,1.0,1.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
