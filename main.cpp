#include "basic-gl-loop.hpp"

#include <chrono>
#include <GLUT/glut.h>
#include <stdexcept>
#include <string>

using clk = std::chrono::high_resolution_clock;

static m4c0::main * _main = nullptr;
static int _frame_count = 0;
static clk::time_point _last_fps_update;

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
void m4c0::main::report_fps(float fps) {
    std::string title = this->title();
    title += " (" + std::to_string((int)fps) + " FPS)";
    glutSetWindowTitle(title.c_str());
}

static void _display() {
    if (!_main) throw std::runtime_error("Missing main loop provider");
    _main->frame();
    glutSwapBuffers();

    _frame_count++;

    auto now = clk::now();
    auto delta = std::chrono::duration_cast<std::chrono::seconds>(now - _last_fps_update);
    if (delta.count() > 1) {
        _main->report_fps((float)_frame_count / delta.count());
        _last_fps_update = now;
        _frame_count = 0;
    }
}

static void _idle() {
    glutPostRedisplay();
}

static void _reshape(int w, int h) {
    if (!_main) throw std::runtime_error("Missing main loop provider");
    _main->reshape(w, h);
}

int main(int argc, char ** argv) {
    if (!_main) throw std::runtime_error("Missing main loop provider");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(800, 600);

    glutCreateWindow(_main->title());
    glutShowWindow();

    glutDisplayFunc(_display);
    glutIdleFunc(_idle);
    glutReshapeFunc(_reshape);

    _last_fps_update = clk::now();
    glutMainLoop();
    return 0;
}

