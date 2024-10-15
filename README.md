# Runix Programming Language

**Runix** is a modern, lightweight, and extensible programming language designed for ease of use and flexibility. Inspired by C-like syntax, Runix is a minimalistic yet powerful language for building small to medium-scale applications with a focus on clarity and functionality.

## Features

- **Simple Syntax**: Inspired by C with a futuristic twist.
- **Variables and Functions**: Easy-to-use variables and parameterized functions.
- **Conditionals and Loops**: Supports `if-then` statements and `while` loops.
- **Classes and Inheritance**: Object-oriented programming with class inheritance.
- **Interfaces**: Enforceable contracts for class methods.
   ```runix
    while i < 3 {
    greet("Runix")
    i = i + 1
    }

### Classes and Inheritance
     ```runix
     class Animal {
    function speak() {
        print("Animal speaks")
      }
    }

    class Dog extends Animal {
    function speak() {
        print("Dog barks")
      }
    }

    d = Dog()
    d.speak()  // Output: Dog barks

### Compilation
    ```bash
    gcc -o runix runix.c lexer.c parser.c interpreter.c

### Running Runix Programs
    ```bash
    ./runix path/to/program.rnx

### Licensing 
Runix is open-source and available under the MIT License. 


## Example Code

### Hello, World
 
  ```runix
   if morning then {
     print("Good morning, world!")
    }



