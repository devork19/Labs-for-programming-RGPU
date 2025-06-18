#ifndef FRACTION_H 
#define FRACTION_H

typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction create_fraction(int num, int den);
void print_fraction(Fraction f);
Fraction add_fractions(Fraction a, Fraction b);
Fraction subtract_fractions(Fraction a, Fraction b);
Fraction multiply_fractions(Fraction a, Fraction b);
Fraction divide_fractions(Fraction a, Fraction b);
Fraction reduce_fraction(Fraction f);
int compare_fractions(Fraction a, Fraction b);
double to_decimal(Fraction f);

#endif