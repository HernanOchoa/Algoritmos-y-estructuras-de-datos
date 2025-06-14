#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */
 unsigned int piv;
 piv = partition(a, izq, der);
 if (piv>izq) {
        quick_sort_rec(a, izq, piv-1u); // Pivot puede ser 0
  }      
  if (piv<der){
        quick_sort_rec(a, piv+1u, der);
  }
 
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

