//
//#include <iostream>
//#include <GL/glut.h> 
//#include <math.h>   
//#include<Windows.h>
//using namespace std;
//
//
//float lx = 0.0f, lz = -1.0f;
//float x = 0.0f, z = 5.0f;
//float angle = 0.0f;
//float xr = 0, yr = 0;
//bool gameOver = false;
//int score = 10;
//
////----------------------------------------------------------
//void processNormalKeys(unsigned char, int, int);
//void processSpecialKeys(int, int, int);
//void init();
//void reshape(int, int);
//void drawBorders();
//void display();
//void Maze();
//void Cube();
//void end_Cube();
////----------------------------------------------------------
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowPosition(200, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Maze");
//	// register callbacks
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutIdleFunc(display);
//	glutKeyboardFunc(processNormalKeys);
//	glutSpecialFunc(processSpecialKeys);
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//void reshape(int w, int h)
//{
//	if (h == 0)
//		h = 1;
//	float ratio = w * 1.0 / h;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	gluPerspective(70, 1.0, 5.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//	// Set the camera
//	gluLookAt(x, 1.0f, z, x + lx, 1.0f, z + lz, 1.0f, 0.0f, 1.0f);
//	//glRotatef(90, 0, 1, 0);
//	Maze();
//	glutSwapBuffers();
//
//	if ((yr >= -30 && yr<-25) && (xr <= 50 && xr >= 45))
//	{
//		char Score[10];
//
//		_itoa_s(score, Score, size_t(10), 10);
//		char text[50] = "Well done ";
//		strcat_s(text, rsize_t(50), Score);
//		MessageBox(NULL, text, "GAME OVER", 0);
//		exit(EXIT_SUCCESS);
//
//	}
//
//}
//
//void init()
//{
//
//	glClearColor(0.8, 0.8, 1, 0.0);
//	glEnable(GL_DEPTH_TEST);
//
//}
//
//void drawBorders() {
//	glBegin(GL_QUADS);
//
//	// front
//	glColor3f(1, 1, 1);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	//back
//	glColor3f(0.9, 0.9, 0.9);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	//right
//	glColor3f(0.8, 0.8, 0.8);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	//left
//	glColor3f(0.7, 0.7, 0.7);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	//top
//	glColor3f(0.6, 0.6, 0.6);
//
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	//bottom
//	glColor3f(0.5, 0.5, 0.5);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glEnd();
//	//glutSwapBuffers();
//
//}
//
//void Maze() {
//
//
//	//glLoadIdentity();
//
//	//floor
//	glBegin(GL_QUADS);
//	glColor3f(0.8, 0.6, 1.0);
//	glVertex3f(-4.0, 4.0, -10);
//	glColor3f(0.6, 0.4, 0.8);
//	glVertex3f(4.0, 4.0, -10);
//	glColor3f(0.4, 0.2, 0.6);
//	glVertex3f(4.0, -4.0, -10);
//	glColor3f(0.2, 0.0, 0.4);
//	glVertex3f(-4.0, -4.0, -10);
//	glEnd();
//	//glutSwapBuffers();
//
//
//
//
//	// border_1
//	glPushMatrix();
//	glTranslatef(0.0, 4.0, -10.0);
//	glScalef(4, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//
//	// border_2
//	glPushMatrix();
//	glTranslatef(0.0, -4.0, -10.0);
//	glScalef(4, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// border_3
//	glPushMatrix();
//	glTranslatef(-3.9, 0.0, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(4, 0.15, .2);
//
//	drawBorders();
//	glPopMatrix();
//
//	// border_4
//	glPushMatrix();
//	glTranslatef(3.9, 0.0, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(4, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//
//	// obestecl_1
//	glPushMatrix();
//	glTranslatef(-3.0, -1.5, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(2.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_2
//	glPushMatrix();
//	glTranslatef(0.0, 2.5, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(1.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_3
//	glPushMatrix();
//	glTranslatef(-1.5, -1.0, -10.0);
//	glScalef(1.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_4
//	glPushMatrix();
//	glTranslatef(-1.5, 2.5, -10.0);
//	glScalef(1.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_5
//	glPushMatrix();
//	glTranslatef(2.0, -3.5, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(0.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_6
//	glPushMatrix();
//	glTranslatef(3.0, 0.0, -10.0);
//
//	glScalef(1.0, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_7
//	glPushMatrix();
//	glTranslatef(2.0, 2.5, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(1.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	// obestecl_8
//	glPushMatrix();
//	glTranslatef(0.2, -3.0, -10.0);
//	glScalef(2.0, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	/*glPushMatrix();
//	glTranslatef(0.-4, 3.0, -10.0);
//	glScalef(3.0, 0.15, .2);
//	drawBorders();
//	glPopMatrix();*/
//	// obestecl_9
//	glPushMatrix();
//	glTranslatef(1.0, -0.5, -10.0);
//	glRotatef(90, 0, 0, 1);
//	glScalef(2.5, 0.15, .2);
//	drawBorders();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-1.5, 0.0, -9.0);
//	glScalef(.1, 0.1, .1);
//	Cube();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(3, -3, -9.0);
//	glScalef(.5, 0.3, .1);
//	end_Cube();
//	glPopMatrix();
//
//
//
//}
//
//void Cube()
//{
//	glBegin(GL_QUADS);
//	// front
//	glColor3f(0.6, 0, 0);
//
//	glVertex3f(-1.0 + xr, 1.0 + yr, 1.0);
//	glVertex3f(-1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, 1.0 + yr, 1.0);
//	//back
//	glColor3f(1, 0.4, 0.4);
//	glVertex3f(1.0 + xr, 1.0 + yr, -1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, -1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, 1.0 + yr, -1.0);
//	//right
//	glColor3f(1, 0.2, 0.2);
//	glVertex3f(1.0 + xr, 1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, -1.0);
//	glVertex3f(1.0 + xr, 1.0 + yr, -1.0);
//	//left
//	glColor3f(1, 0, 0);
//	glVertex3f(-1.0 + xr, 1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, -1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(-1.0 + xr, 1.0 + yr, 1.0);
//	//top
//	glColor3f(0.8, 0, 0);
//
//	glVertex3f(-1.0 + xr, 1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, 1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, 1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, 1.0 + yr, -1.0);
//	//bottom
//	glColor3f(1, 0.6, 0.6);
//	glVertex3f(-1.0 + xr, -1.0 + yr, -1.0);
//	glVertex3f(-1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, 1.0);
//	glVertex3f(1.0 + xr, -1.0 + yr, -1.0);
//	glEnd();
//
//	//glutSwapBuffers();
//
//}
//void end_Cube()
//{
//	glBegin(GL_QUADS);
//	// front
//	glColor3f(0.6, 0, 0);
//
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	//back
//	glColor3f(1, 0.4, 0.4);
//	glVertex3f(1.0, 1.0, -1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	//right
//	glColor3f(1, 0.2, 0.2);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	//left
//	glColor3f(1, 0, 0);
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	//top
//	glColor3f(0.8, 0, 0);
//
//	glVertex3f(-1.0, 1.0, -1.0);
//	glVertex3f(-1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, 1.0);
//	glVertex3f(1.0, 1.0, -1.0);
//	//bottom
//	glColor3f(1, 0.6, 0.6);
//	glVertex3f(-1.0, -1.0, -1.0);
//	glVertex3f(-1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, 1.0);
//	glVertex3f(1.0, -1.0, -1.0);
//	glEnd();
//
//	//glutSwapBuffers();
//
//}
//
//void processNormalKeys(unsigned char key, int x, int y)
//{
//
//	if (key == 27)
//		exit(0);
//}
//
//void processSpecialKeys(int key, int xx, int yy)
//{
//
//	float fraction = 0.1f;
//
//	switch (key) {
//	case GLUT_KEY_UP:
//		
//		xr++;
//		glutPostRedisplay();
//		break;
//	case GLUT_KEY_DOWN:
//		xr--;
//		glutPostRedisplay();
//		break;
//
//		
//	case GLUT_KEY_RIGHT:
//		yr--;
//		glutPostRedisplay();
//		break;
//
//	case GLUT_KEY_LEFT:
//		yr = yr + 1;
//		glutPostRedisplay();
//		break;
//
//	case GLUT_KEY_F1:
//		x -= lx * fraction;
//		z -= lz * fraction;
//		break;
//		
//	case GLUT_KEY_F2:
//		x += lx * fraction;
//		z += lz * fraction;
//		break;
//		
//	case GLUT_KEY_F3:
//
//		angle += 0.01f;
//		lx = sin(angle);
//		lz = -cos(angle);
//		break;
//	case GLUT_KEY_F4:
//		angle -= 0.01f;
//		lx = sin(angle);
//		lz = -cos(angle);
//		break;
//	}
//}
//
////----------------------------------------------------------