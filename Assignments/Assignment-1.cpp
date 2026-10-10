#include <GL/glut.h>
#include <math.h>

void display();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Nile & Pyramids");
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 500, 0, 400);

    // ===== Nile =====
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.85f, 1.0f);
    glVertex2f(0, 0);
    glVertex2f(500, 0);
    glVertex2f(500, 200);
    glVertex2f(0, 150);
    glEnd();

    // ===== Desert =====
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.9f, 0.6f);
    glVertex2f(0, 150);
    glVertex2f(500, 200);
    glVertex2f(500, 250);
    glVertex2f(0, 250);
    glEnd();

    // ===== Boat Body (Dark Brown) =====
    glBegin(GL_POLYGON);
    glColor3f(0.35f, 0.2f, 0.1f);

    glVertex2f(80, 110);
    glVertex2f(420, 110);
    glVertex2f(360, 40);
    glVertex2f(140, 40);

    glEnd();

    // ===== Mast =====
    glBegin(GL_POLYGON);
    glColor3f(0.82f, 0.71f, 0.55f);

    glVertex2f(260, 110);
    glVertex2f(270, 110);
    glVertex2f(270, 270);
    glVertex2f(260, 270);

    glEnd();

    // ===== Smaller Sail =====
    glBegin(GL_TRIANGLES);
    glColor3f(0.35f, 0.35f, 0.35f);

    glVertex2f(260, 110);
    glVertex2f(260, 240);
    glVertex2f(180, 110);

    glEnd();

    // ===== Sun (Top Right Corner) =====
    glColor3f(1.0f, 0.8f, 0.0f);

    float cx = 450;   // مركز الشمس
    float cy = 350;
    float r = 30;

    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        float angle = 2 * 3.1416f * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);

        glVertex2f(cx + x, cy + y);
    }
    glEnd();

    // ===== Small Tree =====

    // Trunk
    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.27f, 0.07f);

    glVertex2f(60, 250);
    glVertex2f(70, 250);
    glVertex2f(70, 280);
    glVertex2f(60, 280);

    glEnd();

    // Leaves
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.6f, 0.0f);

    glVertex2f(50, 280);
    glVertex2f(80, 280);
    glVertex2f(65, 310);

    glEnd();

    glFlush();
}
