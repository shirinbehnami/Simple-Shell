# Simple-Shell
This project is a simple shell implementation in C, designed for OS course to understand the fundamentals of operating systems and shell programming.

## How to use?
To utilize the Simple-Shell, follow these steps:
```
$ sudo apt install libreadline-dev make
$ make
$ ./shell
```
## How to Contribute?
###  1- Explore the Project:
Take a moment to explore the current state of the shell by reviewing the [feature list](#feature-list). If you have ideas for improvement that are not yet implemented or wish to suggest features inspired by your experience with Linux shells, reach out to me to discuss and potentially add them to the feature list.

### 2- Contact for Contributions:
If you have suggestions, bug reports, or new features in mind that are not covered in the feature list, please contact me via [Email](mailto:s.behnami@ec.iut.ac.ir) or Telegram. We can discuss the proposed changes and add a record to the feature list table. Students contributing to the project will earn extra points.

### 3- Forking and Pull Requests:
Please follow these general steps:

 - Forking the repository
 - Creating a new branch for your changes.
 - Implementing your feature or bug fix.
 - Testing thoroughly to ensure the changes work as expected.
 - Creating a pull request with a clear description of your changes.

## Feature list
| Feature                 | Comment                                       | Status             |
|-------------------------|-----------------------------------------------|--------------------|
| Command Execution       | Execute basic shell commands.                  | ✅          |
| Pipe handling        | Facilitate command pipelines for efficient communication            | ✅       |
| Alias Support        | Enable users to define custom aliases for commands.        | ⬜       |
| Backslash Character  | Preserve the literal value of the following character, unless it is an exception (like \n) or a special shell character.         | ⬜       |
| MultiPipe Integration        | Generalize the pipeline to execute multiple pipes in a single input line.        | ⬜       |
| Standard project structure        |  Refactor some parts and Add separate header files and Makefile       | ⬜       |
| & Operator        |  Implement command execution using the & operator for improved efficiency and multitasking     | ⬜       |



## Bugs
| Bug              | Example                                      | Status             |
|-------------------------|-----------------------------------------------|--------------------|
| Pipe Shows no output when there's no second process      |    `echo 123 \|`              | ⬜           |


**Legend:**
- ⬜ In Progress: Feature partially implemented.
- ✅ Done: Feature successfully implemented.
