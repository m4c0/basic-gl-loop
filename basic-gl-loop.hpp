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
#ifndef BASICGLLOOP_HPP
#define BASICGLLOOP_HPP

namespace m4c0 {
    class main {
    public:
        main();
        virtual ~main();

        main(const main &) = delete;
        main & operator=(const main &) = delete;
        main(main &&) = delete;
        main & operator=(main &&) = delete;

        virtual const char * title() = 0;
        virtual void frame();
        virtual void reshape(int w, int h);

        virtual void report_fps(float fps);
    };
}

#endif

