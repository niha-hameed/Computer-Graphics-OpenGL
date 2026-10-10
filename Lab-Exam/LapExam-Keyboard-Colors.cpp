#include <GL/glut.h>

float q = 1.0f, w = 1.0f, e = 1.0f;
float r = 1.0f, t = 1.0f, y = 1.0f;
float j = 1.0f, k = 1.0f, i = 1.0f;
float z = 1.0f, x = 1.0f, c = 1.0f;


void display() {

    glClearColor(0.3, 0.3, 0.3, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);

    glBegin(GL_TRIANGLES);
    glColor3f(q, w, e);
    glVertex2f(300, 250);
    glVertex2f(175, 360);
    glVertex2f(300, 450);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(300, 250);
    glVertex2f(300, 400);
    glVertex2f(450, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(r, t, y);
    glVertex2f(300, 250);
    glVertex2f(400, 350);
    glVertex2f(500, 250);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(300, 250);
    glVertex2f(450, 250);
    glVertex2f(450, 150);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(j, k, i);
    glVertex2f(300, 250);
    glVertex2f(420, 170);
    glVertex2f(300, 50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f(300, 250);
    glVertex2f(300, 100);
    glVertex2f(150, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(z, x, c);
    glVertex2f(300, 250);
    glVertex2f(100, 250);
    glVertex2f(200, 150);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(300, 250);
    glVertex2f(150, 250);
    glVertex2f(150, 400);
    glEnd();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {

    switch (key)
    {

        // Key 1 = Red
    case '1':
        q = 1.0f; w = 0.0f; e = 0.0f;
        break;

        // Key 2 = Green
    case '2':
        z = 0.0f; x = 1.0f; c = 0.0f;
        break;

        // Key 3 = Blue
    case '3':
        j = 0.0f; k = 0.0f; i = 1.0f;
        break;

        // Key 4 = Magenta
    case '4':
        r = 1.0f; t = 0.0f; y = 1.0f;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutInitWindowPosition(50, 50);

    glutCreateWindow("Triangle Fan");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}