#include <gl/glut.h>
#include <Windows.h>
#include <iostream>
using namespace std;
int x1, y1;
int x2, y2;

void line() {
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    //int x1 = 10, y1 = 9, x2 = 100, y2 = 150;
    int steps, dx = x2 - x1, dy = y2 - y1;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    }
    else {
        steps = abs(dy);
    }
    float xInc = (float)dx / (float)steps;
    float yInc = (float)dy / (float)steps;
    float x = x1, y = y1;
    glBegin(GL_POINTS);
    for (int i = 0; i < steps; i++) {
        glVertex2i(x, y);
        x += xInc;
        y += yInc;
    }
    glEnd();
    glFlush();
}

void display() {
    //glClear(GL_COLOR_BUFFER_BIT); already mentioned in main program
    glColor3f(0.0, 1.0, 1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    //int rx = 40, ry = 50, xi = 200, yi = 250;
    line();
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {

    cout << "\n\nEnter the Co-ordinates  \n\n";
    cout << "\n x1 = ";
    cin >> x1;

    cout << "\n y1 = ";
    cin >> y1;

    cout << "\n x2 = ";
    cin >> x2;

    cout << "\n y2 = ";
    cin >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Draw OpenGL");
    glClearColor(0.6, 0.23, 0.35, 0.56);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, 500, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
