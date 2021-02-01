#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <GL/glut.h> 
#include <math.h> 
//----------------------------------------------------------
int matrix[16][16] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1 },
	{ 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0,0, 1 },
	{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1,1 },
	{ 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0,0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,0, 1 },
	{ 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0,0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0,0, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0,0, 1 },
	{ 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0,1, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0,0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0,1 },
	{ 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0,1 },
	{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0,1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1 }};


float lx = 0.0f, lz = -1.0f;
float x = 0.0f, z = 5.0f;
float theta = 0.0f;
float fraction = 0.1f;


int matrixi = 12;
int matrixj = 4;
float xr = -3, yr = -5;

//----------------------------------------------------------
void processSpecialKeys(int, int, int);
void init();
void reshape(int, int);
void display();
void Maze();
void CalculatWinning();
//----------------------------------------------------------
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Maze");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutSpecialFunc(processSpecialKeys);
	init();
	//glutFullScreen();
	glutMainLoop();
	return 0;
}
//----------------------------------------------------------

void reshape(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	gluPerspective(80, 1.0, 5.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
//----------------------------------------------------------

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	//Camera
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		1.0f, 0.0f, 1.0f);

	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	Maze();
	glPopMatrix();
	glutSwapBuffers();
	CalculatWinning();
}
//----------------------------------------------------------

void init()
{
	glClearColor(0.6, 0.8, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	//light
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0 };
	GLfloat light_diffuse[] = { 0.8, 0.6, 0.6 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	
}
//----------------------------------------------------------

void Maze() {
	//Build Maze
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			glPushMatrix();
			int x = matrix[i][j];
			if (x != 0) {
				glTranslatef(-7.0 + j, 7 - i, -10.0);
				glScalef(0.5, 0.5, .2);
				glColor3f(0.8, 0.4, 0.8);
				glutSolidCube(2);
				glColor3f(0.8, 0.4, 0.8);
			}
			else {
				x++;
			}glPopMatrix();
		}
	}

	// Moving Sphere
	glPushMatrix();
	glTranslatef(xr, yr, -10.0);
	glColor3d(1, 0, 0.5);
	glutSolidSphere(0.4, 50, 50);
	glColor3d(1, 1, 1);
	glPopMatrix();


	// Goal
	glPushMatrix();
	glTranslatef(7, 6, -10.0);
	glColor3d(1, 0.5, 0);
	glutSolidSphere(0.5, 50, 50);
	glColor3d(1, 1, 1);
	glPopMatrix();
}

//----------------------------------------------------------
void CalculatWinning()
{
	if ((yr ==6) && (xr==7))
	{

		MessageBox(NULL, "", "Good Job YOU Made it  ", 0);
		exit(EXIT_SUCCESS);

	}
}

//----------------------------------------------------------
void processSpecialKeys(int key, int xx, int yy)
{

	/*std::cout << matrixi;
	std::cout << "  ";
	std::cout << matrixj;
	std::cout << "  ";
	std::cout << matrix[matrixi][matrixj];
	std::cout << "  ";*/

	switch (key) {

	case GLUT_KEY_LEFT:
		if (xr<8 && xr>-8) {
			if (matrix[matrixi][matrixj - 1] == 0)
			{
				if (matrixj > 0)
				{
					matrixj--;
					xr = xr - 1;
				}
				glutPostRedisplay();
			}break;
		}break;
	case GLUT_KEY_RIGHT:
		if (xr<8 && xr>-8) {
			if (matrix[matrixi][matrixj + 1] == 0)
			{
				glutPostRedisplay();
				if (matrixj < 16)
				{
					matrixj++;
					xr = xr + 1;
				}
			}
			break;
		}break;
	case GLUT_KEY_UP:
		if (yr<8 && yr>-8) {

			if (matrix[matrixi - 1][matrixj] == 0)
			{
				glutPostRedisplay();
				if (matrixi >0)
				{
					matrixi--;
					yr = yr + 1;
				}
			}break;
		}break;
	case GLUT_KEY_DOWN:
		if (yr<8 && yr>-8) {
			if (matrix[matrixi + 1][matrixj] == 0)
			{
				if (matrixi < 16)
				{
					matrixi++;
					yr = yr - 1;
				}
				glutPostRedisplay();
			}break;
		}break;


	case GLUT_KEY_F1:
		theta -= 0.01f;
		lx = sin(theta);
		lz = -cos(theta);
		break;

	case GLUT_KEY_F2:
		theta += 0.01f;
		lx = sin(theta);
		lz = -cos(theta);
		break;

	case GLUT_KEY_F3:
		x += lx * fraction;
		z += lz * fraction;
		break;

	case GLUT_KEY_F4:
		x -= lx * fraction;
		z -= lz * fraction;
		break;

	}
}
//----------------------------------------------------------
