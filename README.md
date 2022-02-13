# ![get_next_line Score](https://badge42.herokuapp.com/api/project/dangonza/get_next_line) get_next_line
A project from @42School. Please use this code only as reference. Copying it could mean a -42 Project Score, and a [Bad Reputation](https://open.spotify.com/track/2x0WlnmfG39ZuDmstl9xfX?si=c5a41815e8b94066).<br>
### Project Description:
This project is about programming a function that returns a line read from a file descriptor.
May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. It is time to start working on this function, which will be essential for your future projects.

### Project limitations:

```
Function Name         get_next_line
Prototype             char *get_next_line(int fd);
Turn in Files         get_next_line.c
                      get_next_line_utils.c
                      get_next_line.h
                  
Parameters            fd  ->  The file descriptor to read from
Return Value          Read line: correct behaviour
                      NULL: there is nothing left to read, or an error occurred
                  
External functions    read, malloc, free
Description           Write a function that returns a line read from a file descriptor
```

### Notes:
  -  The returned line should include the terminating `\n` character, except if the end of file was reached and does not end with a `\n` character.
  -  You will compile your code as follows (a buffer size of `42` is used as an example):<br>
   `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c`
  -  Try to read as little as possible each time `get_next_line()` is called. Don't read the whole file and then process each line.
  
### Bonus:
  - [X] Develop `get_next_line()` usign only one static variable.
  - [X] Your `get_next_line()` can manage multiple file descriptors at the same time.
  
### Molinette evaluation:
```diff
+       basic_tests: GNL OK
-       bonus_tests: GNL KO  :(
```
[Tripouille's Test](https://github.com/Tripouille/gnlTester) works fine!
