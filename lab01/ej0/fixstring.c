#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i=0;
    while(s[i]!='\0'){
        i=i+1;
    }
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool res=true;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            res=false;
        }
        i=i+1;
    }
    return (res && s1[i] == s2[i]);  // Ambos deben haber terminado al mismo tiempo
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    unsigned int i = 0;
    bool less_eq = true;     // Suponemos que sí lo es (por defecto)
    bool decided = false;    // Para marcar si ya decidimos el resultado

    while ((s1[i] != '\0' || s2[i] != '\0') && !decided) {
        if (s1[i] < s2[i]) {
            less_eq = true;
            decided = true;  // Ya está decidido, no hace falta seguir
        } else if (s1[i] > s2[i]) { // Si son iguales no hago nada
            less_eq = false;
            decided = true;
        }
        i=i+1;
    }

    return less_eq;
}








