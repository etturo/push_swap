*This project has been created as part of the 42 curriculum by eturini.*

```red
    ______   ______              ____     ____     ____    _   __   ______   ______ 
   / ____/  /_  __/             / __ \   / __ \   /  _/   / | / /  /_  __/  / ____/ 
  / /_       / /               / /_/ /  / /_/ /   / /    /  |/ /    / /    / /_     
 / __/      / /    ________   / ____/  / _, _/  _/ /    / /|  /    / /    / __/     
/_/        /_/    /_______/  /_/      /_/ |_|  /___/   /_/ |_/    /_/    /_/        
```

# ft_printf

## Description

This project is a re-implementation of the standard C `printf()` function. The function takes a format string and a variable number of arguments, then prints the formatted output to standard output.

Supported conversions:
- `%c` - character
- `%s` - string
- `%p` - pointer
- `%d` / `%i` - signed integer
- `%u` - unsigned integer
- `%x` - hexadecimal lowercase
- `%X` - hexadecimal uppercase
- `%%` - percent sign

The function returns the number of characters printed.

## Instructions

Compile the library:
```
make
```

Other commands:
- `make clean` - remove object files
- `make fclean` - remove object files and library
- `make re` - recompile

Compile with:
```
cc -Wall -Werror -Wextra *.c
```

Run with:
```
./a.out
```

But first you have to write a main, because all mains, written for tests, were deleted.

## Algorithm

The main function `ft_printf` loops through the format string. When it finds `%`, it calls `handle_format` to check the next character and print the corresponding argument.

For printing numbers I use recursion: the function calls itself with `n / 10` until the number is less than 10, then prints each digit from left to right using the modulo operator.

For hexadecimal I use a string "0123456789abcdef" as a lookup table - the digit value is used as index to get the correct character.

I pass a pointer to a counter through all functions so each one can increment it when printing characters.

## Resources

- man printf -> https://cplusplus.com/reference/cstdio/printf/ and https://linux.die.net/man/3/printf
- man stdarg
- 42 docs

### AI Usage

I used AI to help debug some issues with format parsing.
