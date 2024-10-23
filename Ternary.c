#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*Use of a ternary operation in a print statement. This will not compile.
*/


void print_led_status(led){
    printf("%s", led == "LED_OFF" ? "LED_OFF " : "LED_ON");
}
