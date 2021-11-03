//OpenGL-sunrise and sunset code

#include <GL\glut.h>
#include <math.h>

void display();
void reshape(int, int);
void timer(int);

float x_position = -10.0;
float x_position1 = 10;
float pos_x = -12;
float pos_y = -12;
float pos_x1 = 12;
float pos_y1 = 12;

void init()
{
	if (pos_x<10)
	{
		glClearColor(1.0, 1.0, 1.0, 0.5);
	}
	else
	{
		glClearColor(0.0, 0.0, 0.0, 0.5);
	}

}
	



void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if ((x_position+10)<20)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.647059, 0.164706, 0.164706);
		glVertex2f(x_position, 1.0);
		glVertex2f(x_position+1, -1.0);
		glVertex2f(x_position + 4, -1.0);
		glVertex2f(x_position + 5, 1.0);
		glEnd();
	}
	else
	{
		glBegin(GL_POLYGON);
		glColor3f(0.647059, 0.164706, 0.164706);
		glVertex2f(x_position1, 1.0);
		glVertex2f(x_position1 + 1, -1.0);
		glVertex2f(x_position1+ 4, -1.0);
		glVertex2f(x_position1+ 5, 1.0);
		glEnd();

	}
	float x_0, y_0,x1_0,y1_0;
	if (pos_x < 10)
	{
		for (double j = 0; j <= 360;)
		{
			glBegin(GL_TRIANGLES);
			x_0 = 3 * cos(j);
			y_0 = 3 * sin(j);
			glColor3f(1, 0.5, 0);
			glVertex2d(x_0 + pos_x, y_0 + pos_y);
			j = j + .5;
			x_0 = 3 * cos(j);
			y_0 = 3 * sin(j);
			glVertex2d(x_0 + pos_x, y_0 + pos_y);
			glColor3f(1, 1, 0);
			glVertex2d(pos_x, pos_y);
			glEnd();
			j = j + .5;
		}

	}
	else
	{
		for (double k = 0; k <= 360;)
		{
			glBegin(GL_TRIANGLES);
			x1_0 = 3 * cos(k);
			y1_0 = 3 * sin(k);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2d(x1_0 + pos_x1, y1_0 + pos_y1);
			k= k + .5;
			x1_0 = 3 * cos(k);
			y1_0 = 3 * sin(k);
			glVertex2d(x1_0 + pos_x1, y1_0 + pos_y1);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2d(pos_x1, pos_y1);
			glEnd();
			k= k + .5;
		}
	}
	
	glBegin(GL_POLYGON);
	glColor3f(0,1.0,1.0);
	glVertex2f(-10, 0);
	glVertex2f(-10,-10);
	glVertex2f(10,-10);
	glVertex2f(10,0);
	glEnd();
	glutSwapBuffers();
	
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Animations");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer,0);
	init();
	glutMainLoop();
}
void timer(int)
{
	init();
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	if (x_position<20)
		x_position += 0.02;
	else
	{
		if (x_position > x_position1)
		{
			x_position1 -= 0.02;
		}
	}
	if (pos_x < 12)
	{
		pos_x += 0.02;
		pos_y = sqrt(90 - (pos_x * pos_x));
	}
	else
	{
		if (pos_x1 > 0)
		{
			pos_x1 -= 0.02;
			pos_y1 = sqrt(90 - (pos_x1 * pos_x1));
		}
	}
			
}


