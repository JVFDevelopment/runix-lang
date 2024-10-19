# Runix Programming Language

![Runix Logo](images/logo/runixlogo.jfif)

**Runix** ```.rmx``` is a modern, lightweight, and extensible programming language designed for ease of use and flexibility, Its primary use case is in game development.


## Features

- **Simple Syntax**: Inspired by C with a futuristic twist.
- **Variables and Functions**: Easy-to-use variables and parameterized functions.
- **Conditionals and Loops**: Supports `if-then` statements and `while` loops.
- **Classes and Inheritance**: Object-oriented programming with class inheritance.
- **Interfaces**: Enforceable contracts for class methods.
- **Error Handling**: Basic error handling with try-catch blocks.
- **Game Development**: Core features for building 2D and 3D games, Including:
   ```
     - Game Loop
     - Graphics System
     - Input Handling
     - Physics Engine
     - Audio System
     - Asset Management
     - Game Objects
   ```


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

   ## Language Reference

   ### Basic Syntax

   ```markdown
   - Variables: `variable_name = value`
   - Functions: `function function_name(parameters) { ... }`
   - Conditionals: `if condition then { ... } else { ... }`
   - Loops: `while condition { ... }`
   ```

   ### Built-in Functions

   ```markdown
   - `print(message)`: Output a message to the console
   - `create_player()`: Create a player game object
   - `create_enemy()`: Create an enemy game object
   - `update_physics()`: Update the game's physics state
   - `render_frame()`: Render a new frame in the game
   - `play_audio()`: Play audio in the game
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

   ## Contributing

   We welcome contributions to Runix! Here's how you can help:

   ```markdown
   1. Fork the repository
   2. Create a new branch for your feature or bug fix
   3. Make your changes and commit them with clear, descriptive messages
   4. Push your changes to your fork
   5. Submit a pull request to the main repository
   ```
   Please ensure your code adheres to the existing style and includes appropriate tests and documentation. 
   You can also report issues or request new features via the issue tracker.
