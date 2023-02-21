#include <GL/glut.h>
#include<iostream>
using namespace std;
int rx = 100, ry = 70;
int xCenter = 200, yCenter = 200;
void myinit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void ellipseMidPoint()
{

    float x = 0;
    float y = ry;
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    while (dx < dy)
    {

        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);


    while (y > 0)
    {

        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;

            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx - dy + (rx * rx);
        }
    }

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(2.0);
    ellipseMidPoint();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(100, 200);
    glVertex2i(300, 200);
    glVertex2i(200, 270);
    glVertex2i(200, 130);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(210, 210);
    glVertex2i(230, 210);
    glVertex2i(230, 230);
    glVertex2i(210, 230);

    glVertex2i(190, 190);
    glVertex2i(170, 190);
    glVertex2i(170, 170);
    glVertex2i(190, 170);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(190, 210);
    glVertex2i(170, 210);
    glVertex2i(180, 220);

    glVertex2i(230, 180);
    glVertex2i(220, 170);
    glVertex2i(240, 170);

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();

}
