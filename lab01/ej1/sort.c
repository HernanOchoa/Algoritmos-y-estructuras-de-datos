#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    /* needs implementation */
    
    if(i<length){ // para que no se pase del largo 
        unsigned int j = i;

        while (j > 0u && goes_before(a[j], a[j - 1u])) {
            // Intercambiar los elementos
            int temp = a[j];
            a[j] = a[j - 1u];
            a[j - 1u] = temp;
            j--;
        }
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a, i)); // Invariante
        insert(a, i, length);
    }
}
