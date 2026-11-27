_This project has been created as part of the 42 curriculum by ajose-al._

# Description
> Get Next Line - Reading a line from a file descriptor is way too tedious.

This project consists of a C function that returns a line read from a file descriptor.
```c
char *get_next_line(int fd);
```
Working on this subject was a very fulfilling experience that allowed me to work more closely with file descriptors and memory management as a whole; introducing static variables; that are stored in `.bss` (when zero-initialized) and `.data` (when non-zero-initialized).

During the various iterations of this project I also explored writting a realloc procedure, to avoid the extreme complexity of strjoin. I ended up giving up on that already working solution because of this project requirement:
> Add all the helper functions you need in the `get_next_line_utils.c` file.

# Instructions
#### Compile your Program with `get_next_line`.
> with `get_next_line.h`, `get_next_line.c` and `get_next_line_utils.c` files inside your working directory.
```c
#include "get_next_line.h"
```
```bash
cc -Wall -Werror -Wextra get_next_line_utils.c get_next_line.c your_program_file.c
```

# Resources
- https://www.man7.org/linux/man-pages/man2/open.2.html
- https://www.man7.org/linux/man-pages/man2/read.2.html

## AI Usage
Although I'm not against AI; I do not directly use or recommend its usage for learning.

This project was indirectly aided by AI in the form of development and testing tools creation and modification by me and other people.

