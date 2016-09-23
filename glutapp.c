/*
** OpenGL Demo: GLUT Skeleton Code
** Author: Michael Papasimeon (mikepsn) 
** Date: February 2001
*/

#include <stdlib.h> 

#ifdef __APPLE__ 
#include <OpenGL/gl.h> 
#include <OpenGL/glu.h> 
#include <GLUT/glut.h> 
#else 
#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#endif

#ifdef WIN32
#endif

#ifdef __linux__
#endif


// FUNCTION PROTOTYPES
static void display(void);
static void idle(void);
static void reshape(int width, int height);
static void key(unsigned char key, int x, int y);
//static void special_key(int key, int x, int y);
static void init(int argc, char** argv);

int main(int argc, char** argv)
{ 
    glutInit(&argc, argv); 
    glutInitWindowSize(640, 480); 
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
    glutCreateWindow("Skeleton GLUT Application - mikepsn");

    init(argc, argv); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(key); 
    glutIdleFunc(idle); 

    glutMainLoop(); 
	
    return 0;
}


static void init(int argc, char** argv)
{
	glClearDepth(1.0);
	glClearColor(0.5, 0.5, 0.5, 0.5);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(-70.0, 1.0, 0.0, 0.0);
	glRotatef(-30.0, 0.0, 0.0, 1.0);

		// DRAW SCENE HERE
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3i(0, 0, 0);
	glVertex3i(1, 0, 0);
	glVertex3i(1, 1, 0);
	glVertex3i(0, 1, 0);
	glVertex3i(0, 0, 0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glRectf(0.01, 0.01, 0.99, 0.99);

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(0.35, 0.35, 0.35);
	
	glBegin(GL_LINES);
	for (int x = -10; x <= 10; x++)
	{
		glVertex3f((float)x, -10.0, 0.0);
		glVertex3f((float)x, 10.0, 0.0);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int y = -10; y <= 10; y++)
	{
		glVertex3f(-10.0, (float)y, 0.0);
		glVertex3f( 10.0, (float)y, 0.0);
	}
	glEnd();

	glPopMatrix();

		// draw axes
	glPushMatrix();
	glLineWidth(2.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3i(-10, 0, 0);
	glVertex3i( 10, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(0, -10, 0);
	glVertex3i(0,  10, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(0, 0, -10);
	glVertex3i(0, 0,  10);
	glEnd();

	glLineWidth(1.0);
	glPopMatrix();

	glutSwapBuffers();
} 

static void reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, 4.0/3.0, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, -10.0f, 
			  0.0f, 0.0f, 0.0f,
			  0.0f, 0.0f, 1.0f);
	glViewport(0, 0, (GLint) width, (GLint) height);
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: // Escape key
        exit (0);
        break;
    }
    glutPostRedisplay();
} 

static void idle(void)
{
    glutPostRedisplay(); 
}
