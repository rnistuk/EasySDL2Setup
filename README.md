# EasySDL2Setup
A CLion, or cmake, project that will make it easy to start a project that uses 
the SDL2 library. SDL2 provides low-level access to audio, keyboard, mouse, 
joystick, and graphics.

SDL2 is my go to library when I need to visualize some functionality but don't 
want to go to the bother of too much set up. 

## Getting Started

Use brew to install SDL2 (SDL2: stable 2.0.12)
From the EasySDL2Setup directory follow the following steps to build the project

```commandline
mkdir build
cd build
cmake ..
make
``` 
the application `demo` will be in build in the `build/sdl_application` directory.

```commandline
cd sdl_application
./demo
```

### Next Steps
I've deliberately made this project as simple as possible, there are a number of 
things that could be done to make it better:
* encapsulate the draw and setup functions into a class
* SDL_Window and SDL_Renderer could be turned into std::shared_ptr 
* encapsulate SDL_Window and SDL_Renderer into their own classes
* ...

### Prerequisites

The following applications were used to create and build this demo.
* macOS Catalina(Version 10.15.4) 
* CLion 2020.1.1, c++17, 
* cmake 3.17.2 
* GNU Make 3.81.

## Built With

* [JetBrains CLion](https://www.jetbrains.com/clion/) 
* [SDL2](https://www.libsdl.org/download-2.0.php) - Simple Direct Media Layer

## Contributing

I'd be happy to hear any suggestions to make this project more useful.


## Authors

* **Rich Nistuk** - *Initial work* - [rnistuk](https://github.com/rnistuk)


## Acknowledgments

* [The Coding Train](https://www.youtube.com/channel/UCvjgXvBlbQiydffZU7m1_aw) - I'm using Daniel Shiffman's book, The Nature of Code, to create demos to test my SDL2 wrapper.

