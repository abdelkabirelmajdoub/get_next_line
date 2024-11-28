# Get Next Line

This project is part of the 42 School curriculum and aims to implement a function called `get_next_line` that reads a line from a file descriptor. The function handles both standard input and files, supporting efficient reading with a specified buffer size.

## Project Overview

The `get_next_line` function is designed to:

- Read from a file descriptor one line at a time.
- Handle any file descriptor, including standard input (`stdin`).
- Efficiently manage memory while handling files of arbitrary sizes.

### Function Prototype

```c
char *get_next_line(int fd);
```

### Expected Behavior

- The function reads a single line from the given file descriptor `fd`.
- A line is defined as ending with a newline character (`\n`) or EOF.
- Each call to `get_next_line` should return the next line from the file until the end is reached.
- When the end of the file is reached, `get_next_line` returns `NULL`.

### Key Features

- **Buffer Management:** The function uses a defined `BUFFER_SIZE` for efficient reading.
- **Static Storage:** Data is stored statically between function calls to retain unprocessed portions of the file.
- **Dynamic Memory Allocation:** Lines are dynamically allocated to fit their size.
- **Multiple File Descriptors:** The function handles multiple file descriptors simultaneously.

## Usage

To use the `get_next_line` function:

1. Include the header file in your project:
   ```c
   #include "get_next_line.h"
   ```

2. Compile the implementation:
   ```sh
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
   ```

3. Call the function with a valid file descriptor:
   ```c
   int fd = open("example.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
   close(fd);
   ```

## File Structure

```
|-- get_next_line.c
|-- get_next_line.h
|-- get_next_line_utils.c
|-- README.md
```

### Files Description

- **`get_next_line.c`:** Core implementation of the `get_next_line` function.
- **`get_next_line_utils.c`:** Utility functions to assist `get_next_line`.
- **`get_next_line.h`:** Header file containing prototypes and necessary includes.

## Testing

Test `get_next_line` by creating input files or providing data through `stdin`. Ensure to:

- Test with different `BUFFER_SIZE` values.
- Handle edge cases like empty files or very large inputs.
- Test with multiple file descriptors simultaneously.

## Notes

- The behavior of `get_next_line` is undefined if `BUFFER_SIZE` is set to 0 or a negative value.
- Proper error handling is expected in cases like invalid file descriptors.

## License

This project follows the 42 School project licensing policies. For external use, ensure compliance with their terms and conditions.

---

For further questions or suggestions, feel free to open an issue or contribute!

