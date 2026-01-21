# Interprocess-Communication-OS
A C++ program demonstrating Unix-style pipelines using pipe(), fork(), dup2(), and exec() system calls on Linux.

Overview
The program creates two processes using fork(), connects them using pipe(), redirects standard input/output using dup2(), and executes external commands using exec().
It mimics the behavior of a shell pipeline without using the shell itself.

Concepts Covered
Process creation using fork()
Inter-process communication using pipe()
File descriptor redirection with dup2()
Program execution using exec()
Parent–child process relationship
Unix process and I/O model

How It Works
A pipe is created to allow communication between two processes.
The child process executes cat and writes its output to the pipe.
The parent process executes grep and reads input from the pipe.
The final output is printed to standard output, just like a shell pipeline.
