#include "VisorWizard.h"
// #include "FileMangerWizard/FileManagerWizard.h"

VisorWizard::VisorWizard(std::optional<const char *> filename): cursorX(0), cursorY(0){
    if(filename.has_value()){
        // FileManagerWizard fileManager(filename.value());
        // fileManager.loadFile();
        // fileManager.printFile();
        // getch();
        // endwin();
    } else {
        initializeWindow();
    }
};

VisorWizard::~VisorWizard(){
    finalizeWindow();
};

void VisorWizard::initializeWindow(){
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    manageInput();
};

// void VisorWizard::init(const char * filename){
//     init();
//     FileManagerWizard fileManager(filename);
//     fileManager.loadFile();
//     fileManager.printFile();
//     getch();
//     endwin();
// }


void VisorWizard::finalizeWindow(){
    endwin();
};

void VisorWizard::manageInput(){
    int ch;
    while((ch = getch()) != KEY_F(1)){
        switch(ch){
            case KEY_UP:
                moveCursor(cursorX, cursorY - 1);
                break;
            case KEY_DOWN:
                moveCursor(cursorX, cursorY + 1);
                break;
            case KEY_LEFT:
                moveCursor(cursorX - 1, cursorY);
                break;
            case KEY_RIGHT:
                moveCursor(cursorX + 1, cursorY);  
                break;
            case KEY_BACKSPACE:
                deleteChar();
                break;
            case KEY_DC:
                printw("Delete");
                break;
            case '\n':
                break;
            default:
                printw("Char: %c", ch);
                insertChar(ch);
                break;
        }
    }
}; 

void::VisorWizard::insertChar(char ch){
    mvaddch(cursorY, cursorX, ch);
    cursorX++;
    move(cursorY, cursorX);
};

void::VisorWizard::deleteChar(){
    if(cursorX > 0){
        cursorX--;
        mvaddch(cursorY, cursorX, ' ');
        move(cursorY, cursorX);
    }
};

void::VisorWizard::moveCursor(int x, int y){
    // Check if the cursor is in the window
    if(y < 0 || y >= LINES || x < 0 || x >= COLS) return;
    cursorX = x;
    cursorY = y;
    move(cursorY, cursorX);
};
