/*
 * Use pointers to find and print the sum and absolute diference of
 * two different numbers
 */
#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int tempa = *a;
    int tempb = *b;
    (*a) = tempa + tempb;
    // If using algorithm library
    //(*b) = abs(tempa - tempb); 
    (*b) = tempa - tempb;
    if ((*b) < 0) {
        (*b) *= -1;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
