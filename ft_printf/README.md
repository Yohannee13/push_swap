*This project has been created as part of the 42 curriculum by yoandria.*

# ft_printf

## Description

The goal of this project is to recreate the C standard library's `printf` function without implementing its buffer management. This project teaches the use of variadic arguments in C, which are incredibly useful for handling an unknown number of input parameters gracefully. The primary objective is to replicate the behavior of standard `printf` for a specific set of conversion specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

## Instructions

The project is provided as source code that explicitly adheres to the 42 Norm requirements.

### Compilation

To compile the library, execute the `make` command from the root of the repository. This relies on the provided `Makefile` which specifies strictly formatted flags (`-Wall -Wextra -Werror`) and utilizes `ar` to securely package everything into a linked static archive, explicitly verifying that tools like `libtool` remain unused.

```bash
make
```

### Installation & Execution

By running `make`, the static library file `libftprintf.a` will be generated. You can link this library against your own project sources.
Example compilation against your standalone files:

```bash
cc my_program.c -L. -lftprintf -o my_program
./my_program
```

Use `make clean` to iteratively discard object files during partial re-builds, `make fclean` to effectively delete both objects and the generated `.a` wrapper, and `make re` to conduct a comprehensive fresh compile.

## Architecture: Algorithm and Data Structure

**1. Chosen Data Structure**:
The core data structure maneuvering this functionality is the `va_list` structure defined in `<stdarg.h>`. It holds internal macros facilitating iterative navigation among arguments given via `...`. Since `ft_printf` demands real-time decoding instead of strict indexing arrays, variables aren't placed into arbitrary lists natively. Instead, they dynamically scale via `va_start` fetching logic inside the variadic wrapper, significantly streamlining memory allocation and bypassing entirely any needs for pre-initialized dynamic structs like `malloc`.

**2. Algorithmic Choice**:
A dynamic **dispatcher pattern coupled with direct System File Descriptors IO write calls** is applied format-by-format per sequence read from the literal string formatting block.

- By processing the continuous stream sequentially inside a discrete state loop (detecting `%` flags gracefully scaling back logic if simply encountering literal spaces and texts), we map cleanly to helper functions routing matching string types instantly out through `.c` extensions via `write(1, content, x)`.
- "Base-conversion algorithms (handling `%x`, `%p`, `%d` variables) rely upon **recursion** to naturally produce digits in the correct left-to-right order. By recursing on the higher-order digits first and printing the current digit after the recursive call returns, the call stack itself acts as an implicit reversal mechanism — eliminating the need for temporary buffers or string reversal."

## Resources

- [C Variadic Functions (man stdarg)](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [C System Calls using `write`](https://man7.org/linux/man-pages/man2/write.2.html)

### Use of AI

Ai was used to review code and file structure in order to ensure that the code was clean and efficient.
It was also used to help on the debugging side by spotting critical areas in the code where errors could happened and suggest better ways to handle them.

## Testing

To verify the correct behavior of the library, you can use the provided test script in the `Makefile`.

### 1. Create a `main.c`

Create a file named `main.c` at the root of the repository with the following code:

```c
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
```

### 2. Run the tests

Execute the following commands in your terminal:

```bash
# Compile the library and the test program
make test

# Run the executable
./test_printf
```

The `make test` rule handles the compilation of your `main.c` and links it automatically with `libftprintf.a`.

### 3. Cleanup

To remove the test executable and object files:

```bash
make fclean
```
