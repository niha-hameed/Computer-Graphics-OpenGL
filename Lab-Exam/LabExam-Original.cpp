#include <GL/glut.h>
#include <math.h>

// Current color state (Key4 behavior: cycles through colors)
int colorMode = 0;

// Colors for each triangle (8 triangles)
float triangleColors[8][3] = {
    {1.0f, 1.0f, 1.0f},   // 0: White
    {0.0f, 1.0f, 1.0f},   // 1: Cyan
    {1.0f, 1.0f, 1.0f},   // 2: White
    {1.0f, 1.0f, 0.0f},   // 3: Yellow
    {1.0f, 1.0f, 1.0f},   // 4: White
    {1.0f, 0.0f, 0.0f},   // 5: Red
    {1.0f, 1.0f, 1.0f},   // 6: White
    {0.0f, 1.0f, 0.0f},   // 7: Green
};

// Color sets for key presses
// Key1: all white
float key1Colors[8][3] = {
    {1,1,1},{1,1,1},{1,1,1},{1,1,1},
    {1,1,1},{1,1,1},{1,1,1},{1,1,1}
};

// Key2: alternating white/cyan
float key2Colors[8][3] = {
    {1,0,1},{0,1,1},{1,0,1},{0,1,1},
    {1,0,1},{0,1,1},{1,0,1},{0,1,1}
};

// Key3: white + yellow/magenta mix
float key3Colors[8][3] = {
    {1,1,1},{0,1,0},{1,0,1},{1,1,0},
    {1,1,1},{0,0,1},{0,1,1},{1,0,0}
};

// Key4 (as in image): Magenta, Green, Cyan, Yellow, Yellow, Red, Blue, Green(center)
float key4Colors[8][3] = {
    {1,0,1},   // Magenta  (left triangle)
    {0,1,0},   // Green    (top-left)
    {0,1,1},   // Cyan     (top)
    {1,1,0},   // Yellow   (top-right / inner)
    {1,1,0},   // Yellow   (right outer)
    {1,0,0},   // Red      (bottom-right)
    {0,0,1},   // Blue     (bottom)
    {0,1,0},   // Green    (bottom-left)
};

void applyColors(float src[8][3]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 3; j++)
            triangleColors[i][j] = src[i][j];
}

void drawTriangleFan() {
    // Center of the fan
    float cx = 0.0f, cy = 0.0f;
    float outerR = 0.7f;   // outer radius (spike tips)
    float innerR = 0.25f;  // inner radius (between spikes)

    // We draw 8 triangles forming a pinwheel/star
    // Points alternate between outer (spike) and inner (notch)
    // Each triangle: center -> outer point -> inner point (or vice versa)

    // 8 spike tips at 45-degree intervals, starting at top (90 degrees)
    // 8 inner notches between them

    float outerAngles[8], innerAngles[8];
    for (int i = 0; i < 8; i++) {
        outerAngles[i] = (90.0f + i * 45.0f) * 3.14159f / 180.0f;
        innerAngles[i] = (90.0f + i * 45.0f + 22.5f) * 3.14159f / 180.0f;
    }

    // Draw 8 triangles: each spike = center + outer[i] + inner[i]
    // This creates the star/pinwheel shape
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 8; i++) {
        // Set color for this triangle
        glColor3fv(triangleColors[i]);

        // Center point
        glVertex2f(cx, cy);

        // Outer spike tip
        glVertex2f(cx + outerR * cos(outerAngles[i]),
            cy + outerR * sin(outerAngles[i]));

        // Inner notch point (next notch, creates the fan sweep)
        int next = (i + 1) % 8;
        glVertex2f(cx + innerR * cos(outerAngles[next]),
            cy + innerR * sin(outerAngles[next]));
    }
    glEnd();
}

void drawLabels() {
    // Labels for colored triangles (matching the image)
    const char* labels[] = {
        "White", "Cyan", "White", "Yellow",
        "White", "Red",  "White", "Green"
    };
    if (colorMode == 1) {
        const char* l[] = { "Magenta","Green","Cyan","Yellow","Yellow","Red","Blue","Green" };
        for (int i = 0; i < 8; i++) labels[i] = l[i];
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawTriangleFan();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        applyColors(key1Colors);
        colorMode = 0;
        break;
    case '2':
        applyColors(key2Colors);
        colorMode = 2;
        break;
    case '3':
        applyColors(key3Colors);
        colorMode = 3;
        break;
    case '4':
        applyColors(key4Colors);
        colorMode = 1;
        break;
    case 27: // ESC
        exit(0);
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Triangle Fan");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}