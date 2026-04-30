#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int len;
    int len_std;

    printf("--- Mandatory Specifiers ---\n");

    // Char & String
    len = ft_printf("Char: [%c] | String: [%s]\n", 'Z', "42 Antananarivo");
    len_std = printf("Std : [%c] | String: [%s]\n", 'Z', "42 Antananarivo");
    printf("Return values -> ft: %d | std: %d\n\n", len, len_std);

    // Integers
    len = ft_printf("Max Int: [%d] | Min Int: [%i]\n", INT_MAX, INT_MIN);
    len_std = printf("Std    : [%d] | Min Int: [%i]\n", INT_MAX, INT_MIN);
    printf("Return values -> ft: %d | std: %d\n\n", len, len_std);

    // Pointers & Hex
    len = ft_printf("Ptr: [%p] | Hex: [%x] [%X]\n", &len, 255, 255);
    len_std = printf("Std: [%p] | Hex: [%x] [%X]\n", &len, 255, 255);
    printf("Return values -> ft: %d | std: %d\n\n", len, len_std);
    
    // Edge cases: NULL pointer
    len = ft_printf("Ptr: [%p] | Hex: [%x] [%X]\n", NULL, 255, 255);
    len_std = printf("Std: [%p] | Hex: [%x] [%X]\n", NULL, 255, 255);
    printf("Return values -> ft: %d | std: %d\n\n", len, len_std);
    
    return (0);
}