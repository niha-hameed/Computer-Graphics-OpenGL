#include<GL\glut.h>

float q = 1.0f, w = 1.0f, e = 1.0f;
float r = 1.0f, t = 1.0f, y = 1.0f;
float u = 1.0f, i = 1.0f, o = 1.0f;
float a = 1.0f, s = 1.0f, d = 1.0f;


void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 550);

	glBegin(GL_TRIANGLES);
	glColor3f(q, w, e);
	glVertex2f(350, 300);
	glVertex2f(575, 300);
	glVertex2f(575, 525);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(r, t, y);
	glVertex2f(350, 300);
	glVertex2f(350, 525);
	glVertex2f(125, 525);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(u, i, o);
	glVertex2f(350, 300);
	glVertex2f(125, 300);
	glVertex2f(125, 75);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(a, s, d);
	glVertex2f(350, 300);
	glVertex2f(350, 75);
	glVertex2f(575, 75);
	glEnd();

	

	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y){
	
	switch (key)
	{
	case '1':
		q = 1.0f;
		w = 0.0f;
		e = 0.0f;
		break;

	case '2':
		r = 0.0f;
		t = 1.0f;
		y = 0.0f;
		break;

	case '3':
		u = 0.0f;
		i = 0.0f;
		o = 1.0f;
		break;

	case '4':
		a = 1.0f;
		s = 1.0f;
		d = 0.0f;
		break;
	}


}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Star Shape Triangles");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

