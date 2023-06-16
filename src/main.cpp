#include <iostream>
#include <stdlib.h>

#include "guiTime.h"
#include "mathOperations.h" // Just testing how to call functions right now from the gui. 
// Gonna start with a switch statement, but would be cool to do a Enum setup to clean up the lines a bit. Or maybe a Struct or default constructor class call 


using namespace std;


int main() {

    //int operation_selected = 0;

    //operation_selected = guitime();
    /*switch(guitime()) {
        case 0: add(); break;
        case 1: subtract(); break;
        case 2: multiply(); break;
        case 3: divide(); break;
        default: exit(0);
    }*/
    guitime();

    return 0;
}