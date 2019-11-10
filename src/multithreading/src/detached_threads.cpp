//
// Created by valery on 10/11/2019.
//

#include <string>
#include <thread>

void edit_document(std::string const& filename) {
    //open_document_and_display_gui();
    bool var = true; // just for syntax highlight
    while (var) { //while (!done_editing()
        // user_command cmd = get_user_input();
        std::thread t(edit_document, "new_name");
        t.detach();
        var = false;
    }
}