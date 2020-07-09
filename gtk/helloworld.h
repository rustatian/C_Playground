#ifndef FUNDAMENTALS_HELLOWORLD_H
#define FUNDAMENTALS_HELLOWORLD_H

#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/window.h>

class HelloWorld : public Gtk::Window {
public:
    HelloWorld();

    virtual ~HelloWorld();

protected:
    // signals
    void on_button_clicked();

    // member widgets
    Gtk::Button m_button;
};

#endif //FUNDAMENTALS_HELLOWORLD_H
