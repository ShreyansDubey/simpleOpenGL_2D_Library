#include<GL/gl.h>
#include<stdio.h>
#include<math.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>

#define sign(x) ((x>0)?1:((x<0)?-1:0))


void setPixel(GLint x, GLint y)                     //To draw pixel (x,y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

/************************************/
/* BRESENHAM LINE DRAWING ALGORITHM */
void bres_general(int x1, int y1, int x2, int y2)   //To draw line joining (x1,y1) and (x2,y2)
{
  int dx, dy, x, y, d, s1, s2, swap=0, temp;
  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);
  if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}
  d = 2 * dy - dx;
  x = x1;
  y = y1;
  int i;
  for(i = 1; i <= dx; i++)
  {
    setPixel(x,y);

    while(d >= 0)
    {
      if(swap) x = x + s1;
      else
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
  }
  glFlush();
}
/* END BRESENHAM */
/*****************/

/****************************************/
/* ELLIPSE AND CIRCLE DRAWING ALGORITHM */
void ellip_circle(int xs1, int ys1, int rx, int ry)         //To draw ellipse with center (xs1, ys1) and radii (xr1, yr1)
{
    int x,y;
    float d1,d2,dx,dy;
    x = 0;
    y = ry;
    d1 = pow(ry,2) - (pow(rx,2) * ry) + (0.25 * pow(rx,2));
    dx = 2 * pow(ry,2) * x;
    dy = 2 * pow(rx,2) * y;
    do                         // region one
    {
        setPixel(x + xs1, y + ys1);
		setPixel(-x + xs1, -y + ys1);
		setPixel(x + xs1, -y + ys1);
		setPixel(-x + xs1, +y + ys1);
        if(d1<0)
        {
            x++;
            dx = dx + (2 * (pow(ry,2)));
            d1 = d1 + dx +(pow(ry,2));
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * (pow(ry,2)));
            dy = dy - (2 * (pow(rx,2)));
            d1 = d1 + dx - dy + (pow(ry,2));
        }
    }while(dx<dy);      // change over condition for region-2
    do                       // region two
    {
        setPixel(x + xs1, y + ys1);
		setPixel(-x + xs1, -y + ys1);
		setPixel(x + xs1, -y + ys1);
		setPixel(-x + xs1, +y + ys1);
        if(d2>0)
        {
            x = x;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            d2 = d2 - dy + pow(rx,2);
        }
        else
        {
            x++;
            y--;
            dy = dy - (2 * (pow(rx,2)));
            dx = dx + (2 * (pow(ry,2)));
            d2 = d2 +dx - dy + pow(rx,2);

        }
    }while(y>0);

    glFlush();
}
/* END ELLIPSE AND CIRCLE */
/**************************/

/***************************/
/* POLYGON USING BRESENHAM */
void polygon(int points_xy[], int num)              //array of the form {x, y, x ,y, ...} and number of points
{
    int i = 0;
    for(i = 0; i < 2 * num; i += 2){
        if(i + 2 == num * 2){
            printf("In");
            bres_general(points_xy[0], points_xy[1], points_xy[i], points_xy[i+1]);
            return;
        }
        bres_general(points_xy[i], points_xy[i+1], points_xy[i+2], points_xy[i+3]);
    }
}
/* END POLYGON */
/***************/

/**********************************/
/* COHEN SUTHERLAND LINE CLIPPING */



/* END LINE CLIPPING */
/*********************/



