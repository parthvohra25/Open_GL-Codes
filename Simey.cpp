#include <GL/glut.h>

void drawCircle(int centerX, int centerY, int radius) {
    int x = 0;
    int y = radius;
    int decisionParam = 5 - 4 * radius;

    glBegin(GL_POINTS);

    while (x <= y) {
        glVertex2i(centerX + x, centerY + y);
        glVertex2i(centerX - x, centerY + y);
        glVertex2i(centerX + x, centerY - y);
        glVertex2i(centerX - x, centerY - y);
        glVertex2i(centerX + y, centerY + x);
        glVertex2i(centerX - y, centerY + x);
        glVertex2i(centerX + y, centerY - x);
        glVertex2i(centerX - y, centerY - x);

        if (decisionParam < 0) {
            decisionParam += 8 * x + 12;
        } else {
            decisionParam += 8 * (x - y) + 20;
            y--;
        }
        x++;
    }

    glEnd();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 0.0, 0.0);

    glColor3f(1.0, 1.0, 0.0);
    drawCircle(250, 250, 200);

    glColor3f(1.0, 1.0, 0.0);
    drawCircle(150, 300, 40);
    drawCircle(350, 300, 40);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(250, 250);
    glVertex2i(300, 200);
    glVertex2i(200, 200);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(200, 100);
    glVertex2i(300, 100);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Question 1");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
