#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h> 
#include <GL/glut.h>
#include <Windows.h>

double rod = 0;

void CircleCoordinat(double r, int vertex) {
	double ngon = (double)vertex;
	glColor3ub(255, 215, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex; i++) {
		double x = cos(2 * M_PI * i / ngon) * r + 50;
		double y = sin(2 * M_PI * i / ngon) * r + 50;
		glVertex2d(x, y);
	}
	glEnd();
}

void CircleLines(double r, int vertex) {
	double ngon = (double)vertex;
	glColor3ub(255, 255, 255);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < vertex; i++) {
		double x = cos(2 * M_PI * i / ngon) * r + 50;
		double y = sin(2 * M_PI * i / ngon) * r + 50;
		glVertex2d(x, y);
	}
	glEnd();
}

void Display() {

	//Planet Merkurius
	glPointSize(9.5);
	glBegin(GL_POINTS);
	{
		glColor3ub(255, 140, 0);
		glVertex2f(sin(rod / 1.2) * 10 + 50, cos(rod / 1.2) * 10 + 50);
	}glEnd();

	//Planet Venus
	glPointSize(13.5);
	glBegin(GL_POINTS);
	{
		glColor3ub(222, 184, 135);
		glVertex2f(sin(rod / 1.3) * 20 + 50, cos(rod / 1.3) * 20 + 50);
	}glEnd();

	//Planet Bumi
	glPointSize(14);
	glBegin(GL_POINTS);
	{
		glColor3ub(0, 191, 255);
		//glVertex2f(70, 70); 
		glVertex2f(sin(rod / 1.4) * 30 + 50, cos(rod / 1.4) * 30 + 50);
	}glEnd();

	//Satelit Bumi (Bulan)    
	glPointSize(6.5);
	glBegin(GL_POINTS);
	{
		glColor3ub(220, 220, 220);
		glVertex2f(sin(rod * 5) * 3 + (sin(rod / 1.4) * 30 + 50), cos(rod * 5) * 3 + (cos(rod / 1.4) * 30 + 50));

	}glEnd();

	//Planet Mars
	glPointSize(13.8);
	glBegin(GL_POINTS);
	{
		glColor3ub(250, 128, 114);
		//glVertex2f(80, 80);
		glVertex2f(sin(rod / 1.5) * 40 + 50, cos(rod / 1.5) * 40 + 50);
	}glEnd();

	//Satelit Mars (Phobos)
	glPointSize(6.5);
	glBegin(GL_POINTS);
	{
		glColor3ub(105, 105, 105);
		glVertex2f(sin(rod * 4) * 2 + (sin(rod / 1.5) * 40 + 50), cos(rod * 4) * 2 + (cos(rod / 1.5) * 40 + 50));
	}glEnd();

	//Satelit Mars (Deimos)
	glPointSize(4);
	glBegin(GL_POINTS);
	{
		glColor3ub(250, 235, 215);
		glVertex2f(sin(rod * 3) * 1.5 + (sin(rod / 1.5) * 36 + 50), cos(rod * 3) * 1.5 + (cos(rod / 1.5) * 36 + 50));
	}glEnd();

	glFlush();
}

void UpdateDisplay(int) {

	rod += 0.02f;

	std::cout << sin(rod) + 50 << std::endl;

	glutPostRedisplay();
	glutTimerFunc(17, UpdateDisplay, 1);
}

void RenderProcess() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	CircleCoordinat(5.5, 50);
	CircleLines(10, 80);
	CircleLines(20, 80);
	CircleLines(30, 80);
	CircleLines(40, 80);
	Display();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Milleano Jody Alfredo Walimema 672018141");

	glutDisplayFunc(RenderProcess);

	gluOrtho2D(0, 100, 100, 0);
	glEnable(GL_POINT_SMOOTH);
	glutTimerFunc(17, UpdateDisplay, 1);

	glutMainLoop();

	return(0);
}

