#include <stdio.h>
#include "tutorial_config.h"
#include "math.h"

int main (void)
{
    printf("Hola, este es el tutorial de Cmake\n");
    printf("La versión es: %d.%d\n", Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
    printf("Sumar 5 + 7 = %d\n", operation(5, 7) );

}