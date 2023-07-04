#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define NENDS 2				/* number of end "points" to draw */

GLdouble width, height;  		/* widndow width and height */
int wd;							/* GLUT window handle */
int ends[NENDS][2];				/* array of 2D points */


void init(void) {
	width = 1280.0;
	height = 800.0;
	ends[0][0] = (int)(0.25*width);
	ends[0][1] = (int)(0.75*height);
	ends[1][0] = (int)(0.75*width);
	ends[1][1] = (int)(0.25*height);
}

/* Draw the window */
void display(void) {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	for (i=0; i<NENDS; i++) {
		glVertex2iv((GLint *) ends[i]);
	}
	glEnd();
	glFlush();
}

void
reshape(int w, int h) {
	width = (GLdouble) w;
	height = (GLdouble) h;

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, -1.f, 1.f);
}

void
kbd(unsigned char key, int x, int y) {
	switch((char)key) {
		case 'q':
		case 2:
			glutDestroyWindow(wd);
			exit(0);
		default:
			break;
		}
}

int main(int argc, char* argv[]) {
	init();
	
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize((int) width, (int) height);

	wd = glutCreateWindow("Experiment with line drawing");

	glutReshapeFunc(reshape);

	glutKeyboardFunc(kbd);
	glutDisplayFunc(display);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);

	glutMainLoop();
	exit(0);

}