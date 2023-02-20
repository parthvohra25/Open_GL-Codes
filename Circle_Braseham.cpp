#include <gl/glut.h>
#include <Windows.h>
#include <iostream>

using namespace std;
int xc, yc, r;
void putpixel(int x, int y)
{
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glVertex2i(x, y);

}
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y);
    putpixel(xc - x, yc + y);
    putpixel(xc + x, yc - y);
    putpixel(xc - x, yc - y);
    putpixel(xc + y, yc + x);
    putpixel(xc - y, yc + x);
    putpixel(xc + y, yc - x);
    putpixel(xc - y, yc - x);
}

void bres_circle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    glBegin(GL_POINTS);
    while (y >= x)
    {
        drawCircle(xc, yc, x, y);

        if (d >= 0)
        {
            x = x + 1;
            y = y - 1;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            x = x + 1;
            y = y;
            d = d + 4 * x + 6;
        }
    }
    glEnd();
    glFlush();
}

void myDisplay()
{
    bres_circle(xc, yc, r);
    glFlush();
}
int main(int argc, char** argv) {
    cout << "enter xc" << endl;
    cin >> xc;
    cout << "enter yc" << endl;
    cin >> yc;
    cout << "enter r" << endl;
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Draw OpenGL");
    glClearColor(1.0, 1.0, 1.0, 0.56);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, 500, 500);

    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
