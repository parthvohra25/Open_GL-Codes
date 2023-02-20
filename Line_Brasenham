#include <gl/glut.h>
#include <Windows.h>
#include <iostream>
using namespace std;
int x1, y11, x2, y2;
void line(int x1, int y11, int x2, int y2) {
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);

	int dx = x2 - x1;
	int dy = y2 - y11;
	float m = float(dy) / float(dx);
	int po = 2 * dy - dx;

	glBegin(GL_POINTS);
	int x = x1, y = y11;
	while (x < x2 && y < y2)
	{
		glVertex2i(x, y);

		if (m < 1)
		{
			if (po < 0)
			{
				x = x + 1;

				po = po + 2 * dy;
			}
			else
			{
				x = x + 1;
				y = y + 1;
				po = po + 2 * dy - 2 * dx;
			}
		}

		else
		{
			if (po < 0)
			{
				x = x1;
				y = y + 1;
				po = po + 2 * dy;
			}
			else
			{
				x = x + 1;
				y = y + 1;
				po = po + 2 * dx - 2 * dy;
			}
		}
	}

	glEnd();
	glFlush();
}
void myDisplay()
{
	line(x1, y11, x2, y2);
	glFlush();
}
int main(int argc, char** argv) {
	cout << "enter x1" << endl;
	cin >> x1;
	cout << "enter x2" << endl;
	cin >> x2;
	cout << "enter y1" << endl;
	cin >> y11;
	cout << "enter y2" << endl;
	cin >> y2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Line Draw OpenGL");
	glClearColor(0.6, 0.23, 0.35, 0.56);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 500, 500);

	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
