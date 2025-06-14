#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
   
    unsigned int ppiv,i,j;
    ppiv=izq;
    i=izq+1u;
    j=der;
    while(i<=j){
        if (goes_before(a[i], a[ppiv])) {
            i++;
        } else if (goes_before(a[ppiv], a[j])) {
            j--;
        } else if (a[i] > a[ppiv] && a[j] < a[ppiv]) {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    
    swap(a, ppiv, j);
    ppiv=j;
    return ppiv;
    
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
unsigned int piv;
    piv = partition(a, izq, der);
    if (piv>izq) {u
        quick_sort_rec(a, izq, piv-1u); // Pivot puede ser 0
    }      
    if (piv<der){
        quick_sort_rec(a, piv+1u, der);
    }
 

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

