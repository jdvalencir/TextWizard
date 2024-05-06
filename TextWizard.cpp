#include <iostream>
#include "./VisorWizard/VisorWizard.h"
using namespace std;

int main(int argc, char ** argv){


    if(argc == 1) VisorWizard visor = VisorWizard();
    // else if(argc == 2) visor.init(argv[1]);
    else { 
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        return 1;
    }    
    return 0;
}
