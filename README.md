# Runix Programming Language

![Runix Logo](images/logo/runixlogo.jfif)

**Runix** is a modern, lightweight, and extensible programming language designed for ease of use and flexibility.


## Features

- **Simple Syntax**: Inspired by C with a futuristic twist.
- **Variables and Functions**: Easy-to-use variables and parameterized functions.
- **Conditionals and Loops**: Supports `if-then` statements and `while` loops.
- **Classes and Inheritance**: Object-oriented programming with class inheritance.
- **Interfaces**: Enforceable contracts for class methods.
- **Error Handling**: Basic error handling with try-catch blocks.
- **Game Development**: Core features for building 2D and 3D games

## New Game Development Features
**Runix now includes core game development components:**

- **Game Loop**: A game loop that continuously updates the game state and renders graphics.
- **Graphics System**: Functions to initialize and render graphics.
- **Input Handling**: Support for keyboard input and other devices.
- **Physics Engine**: Basic object movement, collisions, and physical interactions.
- **Audio System**: Play sounds and music during gameplay.
- **Asset Management**: Load and manage textures, sounds, and other resources.
- **Game Objects**: Create and manage in-game entities like players and enemies.


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
## Game Development Examples/Features:

## Game Loop
```runix
while game_running {
    handle_input()
    update_game_state()
    render_frame()
}
```

## Input Handling
```runix
if key_down("SPACE") then {
    player.jump()
}
```

## Physics Engine
```runix
if player.collides_with(enemy) {
    player.take_damage()
}
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
