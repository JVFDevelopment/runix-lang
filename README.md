# Runix Programming Language

![Runix Logo](https://cdn.gencraft.com/prod/user/f8a7b39e-75b1-42d8-ac9a-616cc987b147/46f33db6-2797-40f8-a2e7-c33c1000e876/image/image0_0.jpg?Expires=1729118090&Signature=LKGaP2DTCIYpBldPGCgFd4uaT~p4M4PfAYLX7qTyJJH9q2ZFKy4kjv~32o56bV208QLd96nvoKx-t3gRkjbMipgQPeJ~~id9yypBCVTd5uic4FfDT5Dsl0k2zzkm7k9bu5K~NmyfbMAR5Y4SOAfLw9JyGD364qOG4V1ToKUy98peIMG68UQjinG3aRuQRbKidT7RKnii~cw8PBNm7yj5L-cZbcC2QuyVrSu9R6JSmYhWUk-N7GIoDnqlty5y1VWwEZdG4mLYjbhhb5zc4TUIVOrso5Hkg-llbeRMHtF20LYBDB1U5GhkQFjKTTdicf6IhyW8Ng9Fbf9t3wHjIOcUeQ__&Key-Pair-Id=K3RDDB1TZ8BHT8)

**Runix** is a modern, lightweight, and extensible programming language designed for ease of use and flexibility.


## Features

- **Simple Syntax**: Inspired by C with a futuristic twist.
- **Variables and Functions**: Easy-to-use variables and parameterized functions.
- **Conditionals and Loops**: Supports `if-then` statements and `while` loops.
- **Classes and Inheritance**: Object-oriented programming with class inheritance.
- **Interfaces**: Enforceable contracts for class methods.

---

## Example Code

### Hello, World

Here’s a simple "Hello, World" program in Runix that prints a message if a condition is met:

   ```runix
   if morning then {
     print("Good morning, world!")
   }
```

### Functions and Loops
This example demonstrates how to define and call functions, as well as how to implement a simple loop:
  ```runix
function greet(name) {
    print("Hello, " + name + "!")
}

i = 0
while i < 3 {
    greet("Runix")
    i = i + 1
}
```

### Classes and Inheritance
Runix supports object-oriented programming. Below is an example of how you can create classes, define methods, and use inheritance in Runix:
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
```

## Compilation
To compile the Runix interpreter, use the following command:
```runix
gcc -o runix runix.c lexer.c parser.c interpreter.c
```
This will compile the necessary C files to build the Runix interpreter.


### Running Runix Programs
Once compiled, you can run your Runix programs by passing the file path to the interpreter. For example:
```runix
./runix path/to/program.rnx
```
Here’s how you can run a specific program:

```runix
./runix examples/hello_world.rnx
```

### Contributing
Contributions are welcome! Feel free to fork the repository, make improvements, and submit pull requests. You can also report issues or request new features via the issue tracker.
