#include "ops.h"

int main(){
Calculator* pCalc = new Calculator;
pCalc -> launch();

while (pCalc -> run()){

    pCalc -> readinput();
    pCalc -> writeOutput();
}


return 0;

}

