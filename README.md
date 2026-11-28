_This project has been created as part of the 42 curriculum by ajose-al._

# Description
> Get Next Line - Reading a line from a file descriptor is way too tedious.

This project consists of a C function that returns a line read from a file descriptor.
```c
char *get_next_line(int fd);
```
Working on this subject was a very fulfilling experience that allowed me to work more closely with file descriptors and memory management as a whole, introducing static variables; that get stored into `.bss` (when zero-initialized) and `.data` (when non-zero-initialized) memory sections.

During the various iterations of this project I also explored writting a duplicating size realloc procedure, to avoid the extreme realocation complexity of strjoin. Unfortunatly, I ended up giving up on that already working solution because of this specific project requirement (that defines a limit of 1 function on the main file and 5 functions on the utils file):
> Add all the helper functions you need in the `get_next_line_utils.c` file.

For the bonus part, my original approach was to dinamically allocate the buffer on `static t_read_data data[1024];` with a `data.left_overs` pointer so I would not fall into `MAX_FDS * BUFFER_SIZE` massive memory allocation problem (because when the program touches a byte of statically allocated memory during runtime, it will only be freed when the program stops executing; it's basically worse than having small memory leaks). Anyways, the function allowed to free all `left_overs` allocated memory blocks by passing `-1` as fd argument. Once again, the code size requirements of the project's subject made me abandon that version of the code.

Anyways, very simple but awesome project to work on!

# Instructions
#### Compile your Program with `get_next_line`.
> with `get_next_line.h`, `get_next_line.c` and `get_next_line_utils.c` files inside your working directory.
```c
#include "get_next_line.h"
```
```bash
cc -Wall -Werror -Wextra get_next_line_utils.c get_next_line.c your_program_file.c
```
#### Compile your Program with `get_next_line` bonus part.
> with `get_next_line_bonus.h`, `get_next_line_bonus.c` and `get_next_line_utils_bonus.c` files inside your working directory.
```c
#include "get_next_line_bonus.h"
```
```bash
cc -Wall -Werror -Wextra get_next_line_utils_bonus.c get_next_line_bonus.c your_program_file.c
```

# Resources
- https://www.man7.org/linux/man-pages/man2/open.2.html
- https://www.man7.org/linux/man-pages/man2/read.2.html

## AI Usage
Although I'm not against AI; I do not directly use or recommend its usage for learning things you take seriously.

This project was indirectly aided by AI in the form of development and testing tools creation and modification by me and other people.

