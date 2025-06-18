#include "fraction.h"
#include <stdio.h>  //  для fprintf/printf
#include <stdlib.h> // Для abs() и exit()
#include <math.h>   // Для fabs()

static int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b) { int temp = b; b = a % b; a = temp; }
    return a;
}

Fraction create_fraction(int num, int den) {
    if (den == 0) {
        fprintf(stderr, "Ошибка: Знаменатель не может быть нулем!\n");
        exit(EXIT_FAILURE);
    }
    Fraction f = {num, den};
    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    return reduce_fraction(f);
}

void print_fraction(Fraction f) {
    if (f.denominator == 1) printf("%d", f.numerator);
    else printf("%d/%d", f.numerator, f.denominator);
}

Fraction reduce_fraction(Fraction f) {
    int d = gcd(f.numerator, f.denominator);
    return (Fraction){f.numerator/d, f.denominator/d};
}

Fraction add_fractions(Fraction a, Fraction b) {
    return reduce_fraction((Fraction){
        a.numerator*b.denominator + b.numerator*a.denominator,
        a.denominator*b.denominator
    });
}
Fraction subtract_fractions(Fraction a, Fraction b) {
    return reduce_fraction((Fraction){
        a.numerator * b.denominator - b.numerator * a.denominator,
        a.denominator * b.denominator
    });
}

Fraction multiply_fractions(Fraction a, Fraction b) {
    return reduce_fraction((Fraction){
        a.numerator * b.numerator,
        a.denominator * b.denominator
    });
}

Fraction divide_fractions(Fraction a, Fraction b) {
    if (b.numerator == 0) {
        fprintf(stderr, "Ошибка: Деление на ноль!\n");
        exit(EXIT_FAILURE);
    }
    return reduce_fraction((Fraction){
        a.numerator * b.denominator,
        a.denominator * b.numerator
    });
}

double to_decimal(Fraction f) {
    return (double)f.numerator / f.denominator;
}