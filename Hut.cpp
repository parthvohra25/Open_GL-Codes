//Black Window
#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void triangle()
{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.5, 0.6, 0.5);
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, -0.4);
		glVertex2f(-0.7, -0.4);
		glVertex2f(-0.4, 0.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, -0.4);
		glVertex2f(0.3, -0.4);
		glVertex2f(0.2, 0.0);
		glVertex2f(-0.4, 0.0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.7, -0.4);
		glVertex2f(-0.7, -0.8);
		glVertex2f(-0.1, -0.8);
		glVertex2f(-0.1, -0.4);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.1, -0.4);
		glVertex2f(0.3, -0.4);
		glVertex2f(0.3, -0.8);
		glVertex2f(-0.1, -0.8);
		glEnd();
		glFlush();
}
//Program to create an empty Widnow
void init()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("empty window");
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutDisplayFunc(triangle);
	glutMainLoop();
	return 0;
}
