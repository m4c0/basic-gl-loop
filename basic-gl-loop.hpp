#ifndef BASICGLLOOP_HPP
#define BASICGLLOOP_HPP

namespace m4c0 {
    class main {
    public:
        main();
        virtual ~main();

        virtual const char * title() = 0;
        virtual void frame();
        virtual void reshape(int w, int h);
    };
}

#endif

