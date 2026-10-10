#include <GL/glut.h>
#include <math.h>

// متغيرات التحويل
float posX = 0.0, posY = 0.0;
float angle = 0.0;
float scale = 1.0;

// رسم دائرة
void drawCircle(float cx,float cy,float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float a = 2 * 3.14159 * i / 100;
        glVertex2f(cx + cos(a) * r, cy + sin(a) * r);
    }
    glEnd();
}

// رسم مستطيل
void rect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}

// رسم الروبوت
void drawRobot() {

    // الجسم
    glColor3f(0.3, 0.3, 0.35);
    rect(-0.4, -0.4, 0.4, 0.3);

    // لوحة
    glColor3f(0.1, 0.1, 0.1);
    rect(-0.3, -0.2, 0.3, 0.2);

    // الرأس
    glColor3f(0.5, 0.5, 0.55);
    rect(-0.25, 0.3, 0.25, 0.6);

    // العيون
    glColor3f(0.0, 1.0, 0.0);
    drawCircle(-0.1, 0.45, 0.05);
    drawCircle(0.1, 0.45, 0.05);

    // الفم
    rect(-0.1, 0.35, 0.1, 0.37);

    // الهوائي
    glColor3f(0.7, 0.0, 0.0);
    rect(-0.02, 0.6, 0.02, 0.75);
    drawCircle(0.0, 0.78, 0.03);
}

// العرض
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // تطبيق التحويلات
    glTranslatef(posX, posY, 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(scale, scale, 1);

    drawRobot();

    glutSwapBuffers();
}

// الكيبورد (حروف)
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': angle += 10; break;     // دوران
        case '+': scale += 0.1; break;    // تكبير
        case '-': scale -= 0.1; break;    // تصغير
        case 27: exit(0);                 // ESC خروج
    }
    glutPostRedisplay();
}

// الأسهم (تحريك)
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:  posX -= 0.1; break;
        case GLUT_KEY_RIGHT: posX += 0.1; break;
        case GLUT_KEY_UP:    posY += 0.1; break;
        case GLUT_KEY_DOWN:  posY -= 0.1; break;
    }
    glutPostRedisplay();
}

// تهيئة
void init() {
    glClearColor(0.0, 0.0, 0.1, 1.0);
}

// main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Robot Transformation");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}