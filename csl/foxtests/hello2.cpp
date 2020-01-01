
#include <fx.h>
#include <iostream>
#include <iomanip>
#include <fxkeys.h>
using namespace std;

class Window : public FX::FXMainWindow {

    FXDECLARE(Window)
protected:
    Window() {
        ;
    }
public:

    Window(FXApp* a);
    long onKeyPress(FXObject*, FXSelector, void* ptr);

    virtual ~Window() {
        ;
    }

    virtual void create() {
        FXMainWindow::create();
        show(PLACEMENT_SCREEN);
    }
};

FXDEFMAP(Window) WindowMap[] = {
    FXMAPFUNC(SEL_KEYPRESS, 0, Window::onKeyPress)

};

FXIMPLEMENT(Window, FX::FXMainWindow, WindowMap, ARRAYNUMBER(WindowMap))

long Window::onKeyPress(FXObject*, FXSelector, void* ptr) {
    FXEvent *ev = (FXEvent *)ptr;
    const char *t = ev->text.text();
    if (*t == 0) return 1;
    cout << "ONKEYPRESS" << "  " << t << ": " << std::hex;
    while (*t != 0) cout << " " << std::setw(2) << ((int)*t++ & 0xff);
    cout << endl;
    return 1;
}

Window::Window(FXApp* a) : FXMainWindow(a, "example", NULL, NULL,
DECOR_TITLE | DECOR_MINIMIZE | DECOR_CLOSE | LAYOUT_FILL_X |
LAYOUT_FILL_Y | LAYOUT_FIX_WIDTH, 0, 0, 640, 480) {

}

Window *g_window;

int main(int argc, char *argv[]) {
    FXApp application("example", "example");
    application.init(argc, argv);
    g_window = new Window(&application);
    application.create();
    return application.run();
}


