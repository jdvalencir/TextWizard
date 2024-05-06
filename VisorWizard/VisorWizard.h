#ifndef VISORWIZARD_H
#define VISORWIZARD_H

#include <ncurses.h>
#include <optional>
#include <string>
#include <vector>

class VisorWizard {
    private:
        std::vector<std::string> lines;
        int cursorX, cursorY;

        // Create and destroy window
        void initializeWindow();
        void initializeWindow(const char * filename);
        void finalizeWindow();

        // Manage input
        void manageInput();
        void insertChar(char ch);
        void deleteChar();
        void moveCursor(int x, int y);
        

    public:
        VisorWizard(std::optional<const char*> filename = std::nullopt);
        ~VisorWizard();

};



#endif // VISORWIZARD_H