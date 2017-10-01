#include "basic-gl-loop.hpp"

#include <GLUT/glut.h>
#include <stdexcept>

static m4c0::main * _main = nullptr;

m4c0::main::main() {
    if (_main != nullptr) throw std::runtime_error("Multiple main loop providers defined");
    _main = this;
}
m4c0::main::~main() {
    _main = nullptr;
}

void m4c0::main::reshape(int w, int h) {
    glViewport(0, 0, w, h);
}
void m4c0::main::frame() {
    glClearColor(0.4, 0.2, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void _display() {
    if (!_main) throw std::runtime_error("Missing main loop provider");
    _main->frame();
    glutSwapBuffers();
}

static void _idle() {
    if (!_main) throw std::runtime_error("Missing main loop provider");
}

static void _reshape(int w, int h) {
    if (!_main) throw std::runtime_error("Missing main loop provider");
    _main->reshape(w, h);
}

int main(int argc, char ** argv) {
    if (!_main) throw std::runtime_error("Missing main loop provider");

    glutInit(&argc, argv);

    glutCreateWindow(_main->title());
    glutShowWindow();

    glutDisplayFunc(_display);
    glutIdleFunc(_idle);
    glutReshapeFunc(_reshape);
    glutMainLoop();
    return 0;
}

