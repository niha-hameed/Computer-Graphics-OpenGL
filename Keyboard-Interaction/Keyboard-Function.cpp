#include<GL\glut.h>


void display();
void changeColor(int key, int x, int y);
void keyboard(unsigned char key, int x, int y);
float red = 1.0f, green = 1.0f, blue = 1.0f;
float tx = 0.0f, ty = 0.0f;
float scale = 1.0f;
float angle = 0.0f;
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Keyboard Function");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(changeColor);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 'w': ty += 0.7f; break;
	case 's': ty -= 0.7f; break;
	case 'd': tx += 0.7f; break;
	case 'a': tx -= 0.7f; break;

	case '+': scale += 0.1f; break;
	case '-': scale -= 0.1f; break;

	case 'r': angle -= 1.0f; break;
	case 't': angle += 1.0f; break;
	}
	glutPostRedisplay();
}



void changeColor(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		red = 1;
		green = 0;
		blue = 0;break;
	case GLUT_KEY_F2:
		red = 0;
		green = 1;
		blue = 0;break;
	case GLUT_KEY_F3:
		red = 0;
		green = 0;
		blue = 1;break;
	}

}

void display() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 400);
	glTranslatef(tx, ty, 0);
	glScalef(scale, scale, 0);
	glRotatef(angle, 0,0,1);

	glBegin(GL_QUADS);
	glColor3f(red, green, blue);
	glVertex2f(100, 100);
	glVertex2f(300, 100);
	glVertex2f(300, 300);
	glVertex2f(100, 300);
	glEnd();

	glutSwapBuffers();
}

