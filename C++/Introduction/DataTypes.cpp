/*
 * Practice with taking in and printing different data types
 */
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a;
    long b;
    char c;
    float f;
    double d;
    scanf("%d %ld %c %f %lf", &a, &b, &c, &f, &d);
    // Use \n to create new lines, can't use spaces between b/c it messes w/ formatting
    printf("%d\n%ld\n%c\n%f\n%lf\n", a, b, c, f, d);
    return 0;
}