#include <stdio.h>
#include <stdlib.h>

static int separa (int v[], int p, int r) {
   int c = v[r]; 
   int t, j = p;
   for (int k = p; k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j; 
      } 
   t = v[j], v[j] = v[r], v[r] = t;
   return j; 
}

void quicksort (int v[], int p, int r){
   if (p < r) {                
      int j = separa (v, p, r);
      quicksort (v, p, j-1);   
      quicksort (v, j+1, r);   
   }
}

int main() {
    int v[] = {42, 543, 312, 123, 23, 65, 3, 21, 43, 5, 9, 10, 4, 6};
    int n = sizeof(v) / sizeof(v[0]);

    quicksort(v, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}