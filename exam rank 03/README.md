# ExamRank02
Exam Rank 02 is very first exam for curriculum at 42.

```
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
```

```
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
```

```
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf with the following constraints:

- It will manage only the following conversions: s,d, and x

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Your function must not leak.


Exemples of the function output:

call: ft_printf("Hello %s\n", "toto");
out:Hello toto$

call: ft_printf("Magic %s is %d", "number", 42);
out:Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$

Warning: Your function must not have any leaks, this will be checked during moulinette
```

```
Assignment name   : get_next_line
Expected files    : get_next_line.c get_next_line.h
Allowed functions : read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char    *get_next_line(int fd);

Your function must return a line that has been read from the file descriptor
passed as parameter.

What we call a "line that has been read" is a succession of 0 to n characters
that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end
of the line that has been read.

When you've reached the EOF, you must store the current buffer in a char * and
return it. If the buffer is empty you must return NULL.

In case of error return NULL.

In case of not returning NULL, the pointer should be free-able.

Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be
used as the buffer size for the read calls in your functions.

Your function must be memory leak free.

When you've reached the EOF, your function should keep 0 memory allocated with
malloc except the line that has been returned.

Calling your function get_next_line in a loop will therefore allow you to read
the text available on a file descriptor one line at a time until the end of the
text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the
standard output, from a redirection etc.

No call to another function will be done on the file descriptor between 2 calls
of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading
from a binary file.

You should use the test.sh to help you test your get_next_line.

--------------------------------------------------------------------------------
```