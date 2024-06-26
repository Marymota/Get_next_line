# Get Next Line - Reading a line from a fd is way too tedious

## Summary

The Get Next Line project presents an opportunity to develop a highly useful function and explore the concept of static variables in C programming.

### Function: get_next_line

The mandatory part of the Get Next Line project involves implementing the get_next_line() function in C, which reads a line from a given file descriptor (fd). This function returns the read line, handles errors, and manages end-of-file conditions properly.
Repeated calls to get_next_line() enables reading a text file one line at a time. It includes the terminating \n character in the returned line, except at the end of the file.
The function's prototype is declared in the get_next_line.h header file, and necessary helper functions are implemented in get_next_line_utils.c.
Additionally, memory allocation and deallocation is managed using malloc and free.

## Bonus Part
`get_next_line()` is developed using only one static variable and can manage multiple file descriptors simultaneously.

---
# 42 School
This project is an integral part of the curriculum at [42 Lisboa](https://42lisboa.com/), emphasizing practical learning, collaboration, and problem-solving. It sets the stage for your journey into the world of programming, equipping you with essential skills and knowledge for future endeavors.
