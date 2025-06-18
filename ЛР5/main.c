#include "fraction.h"
#include <stdio.h>
#include <windows.h>

int main() {
    // Установка кодировки
    SetConsoleOutputCP(CP_UTF8);
    
    // Объявление переменных (единожды!)
    Fraction a = create_fraction(3, 4);
    Fraction b = create_fraction(2, 5);
    
    // Работа с дробями
    printf("Дробь A: "); print_fraction(a); printf("\n");
    printf("Дробь B: "); print_fraction(b); printf("\n\n");
    
    printf("A + B = "); print_fraction(add_fractions(a, b)); printf("\n");
    printf("A - B = "); print_fraction(subtract_fractions(a, b)); printf("\n");
    printf("A * B = "); print_fraction(multiply_fractions(a, b)); printf("\n");
    printf("A / B = "); print_fraction(divide_fractions(a, b)); printf("\n");
    
    printf("\nДесятичное представление A: %.2f\n", to_decimal(a));
    
    return 0;
}