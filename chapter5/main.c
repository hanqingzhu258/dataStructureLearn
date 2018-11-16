#include <stdio.h>

#include "unit1.h"
#include "unit3.h"

void main() {

    //exa5-2
//    josephus(8,4);

    //test-unit3
    GLNode *g;
    char *str="((a,b),((a,b,c),d,e),f,g)";
    g=createGL(&str);
    dispGL(g);


}