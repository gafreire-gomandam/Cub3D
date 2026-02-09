*This project has been created as part of the 42 curriculum by gafreire and gomandam.*

# Cub3D

## Description

Cub3D is a project that introduces the fundamentals of 3D graphics programming through raycasting. Inspired by classic games like Wolfenstein 3D, this project creates a dynamic first-person perspective within a maze environment, transforming a 2D map into an immersive 3D experience.

The project explores core concepts of computer graphics including the DDA (Digital Differential Analyzer) algorithm for precise collision detection, perspective-correct texture mapping, and optimized rendering techniques to achieve smooth performance.

### Technical Implementation

The implementation consists of three main components:

**Parser**: A robust configuration file parser that validates and processes `.cub` scene files. The parser handles:
- Four directional wall textures (North, South, East, West) in `.xpm` format
- Floor and ceiling RGB color values (0-255 range)
- Map validation ensuring the maze is properly enclosed by walls
- Flood-fill algorithm to detect open boundaries
- Player spawn position and orientation detection (N, S, E, W)
- Error handling for invalid configurations, duplicate identifiers, missing textures, and malformed maps

**Raycasting Engine**: The mathematical core implementing the DDA algorithm to calculate ray-wall intersections. For each vertical screen column, the engine:
- Casts a ray from the player's position through the game world
- Calculates the precise distance to the nearest wall
- Determines wall height based on distance (perspective projection)
- Identifies which texture to apply based on wall orientation

**Renderer**: Graphics output using MiniLibX library that:
- Manages the frame buffer and image rendering
- Applies texture mapping with perspective correction
- Renders floor and ceiling with configured colors
- Handles window events (keyboard input, window close)
- Optimizes rendering loop for 60+ FPS performance

## Instructions

### Prerequisites

The project requires:
- A C compiler (`cc` or `gcc`)
- `make` build automation tool
- X11 development libraries (on Linux)
- MiniLibX graphics library

### Compilation

```bash
git clone https://github.com/ByteGab/cub3d.git
cd cub3d
make
```

The Makefile includes standard rules:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Recompiles the entire project

### Execution

```bash
./cub3D maps/subject.cub
```

The program accepts a single argument: a `.cub` scene configuration file containing texture paths, colors, and the map layout.

### Scene File Format

A valid `.cub` file must include (in any order except the map, which must be last):

```
NO ./textures/north_wall.xpm
SO ./textures/south_wall.xpm
WE ./textures/west_wall.xpm
EA ./textures/east_wall.xpm

F 220,100,0
C 225,30,0

111111
100001
1010N1
111111
```

- **NO, SO, WE, EA**: Paths to wall texture files (must be `.xpm` format)
- **F**: Floor color in RGB format (0-255 for each channel)
- **C**: Ceiling color in RGB format (0-255 for each channel)
- **Map**: Grid composed of `0` (floor), `1` (wall), `N/S/E/W` (player start position and orientation), and spaces (void)

### Controls

- **W, A, S, D**: Move forward, strafe left, move backward, and strafe right
- **Arrow keys (← →)**: Rotate camera left and right
- **ESC**: Exit the program
- **Window close button (X)**: Exit the program

## Resources

### Documentation and Tutorials

- **Lode's Raycasting Tutorial**: [https://lodev.org/cgtutor/raycasting.html](https://lodev.org/cgtutor/raycasting.html) - Comprehensive guide explaining the mathematics and implementation of raycasting, including:
  - DDA (Digital Differential Analyzer) algorithm for ray-grid intersection
  - Perspective projection and wall height calculation
  - Texture mapping techniques for realistic wall rendering
  - Performance optimization strategies for real-time rendering

- **MiniLibX Documentation**: Graphics library API documentation for window management, image rendering, and event handling

### AI Usage

AI was used in this project for the following purposes:

- **Texture Asset Generation**: AI image generation tools were employed to create custom wall textures (`.xpm` files) for the maze environment, providing visually distinct textures for different wall orientations.

- **Concept Explanation and Learning**: AI served as an educational aid to clarify complex mathematical concepts including:
  - Ray-casting algorithm fundamentals and geometric calculations
  - DDA algorithm implementation and optimization
  - Perspective projection mathematics
  - Texture mapping coordinate transformations
  
  The AI helped simplify technical documentation and provide alternative explanations for challenging topics, making the learning process more accessible.

- **Documentation Creation**: AI assisted in structuring and writing this README file, organizing project information in a clear and comprehensive manner.
