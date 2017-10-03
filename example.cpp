/*
 * basic-gl-loop - Simple library to provide a very basic GL application
 * Copyright (C) 2017 - Eduardo Costa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "m4c0-bgl-loop.hpp"

#include <iostream>

/// !brief Example class for the 'main loop provider'
///
/// This is a simple example of how to use this class. All overrides (except
/// "title") are optional and used only as example. They are also nice to
/// understand when those calls happens, and what happens if you don't call the
/// parent class (which is also optional).
static class _ : m4c0::main {
public:
    const char * title() override { return "Hello World"; }

    void start() override {
        std::cout << "Started" << std::endl;
    }
    void reshape(int w, int h) override {
        std::cout << "Reshape " << w << "x" << h << std::endl;
        m4c0::main::reshape(w, h);
    }
    void frame() override {
        std::cout << "Frame" << std::endl;
        m4c0::main::frame();
    }
    void report_fps(float fps) override {
        std::cout << "Current FPS was " << fps << std::endl;
        m4c0::main::report_fps(fps);
    }
} _main;

