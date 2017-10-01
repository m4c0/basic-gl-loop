#include <GLUT/glut.h>

static void _display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
}

static void _idle() {
}

static void _reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);

    glutCreateWindow("");
    glutShowWindow();

    glutDisplayFunc(_display);
    glutIdleFunc(_idle);
    glutReshapeFunc(_reshape);
    glutMainLoop();
    return 0;
}

