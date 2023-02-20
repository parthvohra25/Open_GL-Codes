#include <gl/glut.h>  
#include <iostream>
using namespace std;
int rx, ry;
int xi, yi;

void ellipseMidPoint() {
	int x = 0, y = ry;
	int p1 = (ry * ry) + (rx * rx * 0.25) - (ry * rx * rx);
	int dx = 2 * x * (ry * ry);
	int dy = 2 * y * (rx * rx);
	while (dy > dx) {
		glVertex2i(x + xi, y + yi);
		glVertex2i(x + xi, -y + yi);
		glVertex2i(-x + xi, -y + yi);
		glVertex2i(-x + xi, y + yi);
		if (p1 < 0) {
			x++;
			dx = 2 * x * (ry * ry);
			p1 += dx + (ry * ry);
		}
		else {
			x++;
			y--;
			dx = 2 * x * (ry * ry);
			dy = 2 * y * (rx * rx);
			p1 += dx + (ry * ry) - dy;
		}
	}
	int p2 = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
	while (y > 0) {
		glVertex2i(x + xi, y + yi);
		glVertex2i(x + xi, -y + yi);
		glVertex2i(-x + xi, -y + yi);
		glVertex2i(-x + xi, y + yi);
		if (p2 > 0) {
			y--;
			dy = 2 * y * (rx * rx);
			p2 += (rx * rx) - dy;
		}
		else {
			y--;
			x++;
			dy -= 2 * (rx * rx);
			dx += 2 * (ry * ry);
			p2 += dx + (rx * rx) - dy;
		}
	}
}

void display() {
	//glClear(GL_COLOR_BUFFER_BIT); already mentioned in main program
	glColor3f(0.0, 1.0, 1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	//int rx = 40, ry = 50, xi = 200, yi = 250;
	ellipseMidPoint();
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	cout << "\n\nEnter Center Of Ellipse  \n\n";
	cout << "\n x = ";
	cin >> xi;
	
	cout << "\n y = ";
	cin >> yi;
	
	cout << " Enter a Semi Major Axix : ";
	cin >> rx;
	cout << " \nEnter a Semi Minor Axis: ";
	cin >> ry;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Drawing Algorithm");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 500, 500);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
