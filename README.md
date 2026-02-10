# 🕹️ Cub3D

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-black?style=for-the-badge&logo=42" alt="42 Project" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-green?style=for-the-badge&logo=opengl" alt="Graphics" />
  <img src="https://img.shields.io/badge/Score-101%2F100-success?style=for-the-badge" alt="Score" />
</p>

## 📖 Overview

**Cub3D** is a 42 Cursus project that explores the foundations of 3D graphics using the **Raycasting** technique—the same logic used in legendary games like *Wolfenstein 3D*. The goal is to create a dynamic perspective inside a maze, converting a 2D map into a 3D simulated environment.

> "A journey into the math behind the pixels."

This project is divided into two main components: a **robust parser** that validates and loads map data, and a **raycasting engine** that renders the 3D world in real-time.

---

## 📚 Documentation

For a complete technical breakdown with detailed flowcharts, implementation explanations, and step-by-step guides, check out our comprehensive **Notion documentation**:

🔗 **[Cub3D - Technical Documentation (Notion)](https://www.notion.so/Cub3d-2806a32e0f3480e3a91ff8ad1ab42b4c?source=copy_link)**

The Notion includes:
- Detailed flowcharts for each parsing phase
- Mathematical explanations of the DDA algorithm
- Texture mapping implementation details
- Movement and collision system breakdown
- Visual diagrams of the rendering pipeline

---

## 🛠️ Technical Features

### 🧠 The Engine

* **DDA Algorithm:** Precise wall collision detection using the Digital Differential Analyzer
* **Raycasting Logic:** Implementation based on [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
* **Texture Mapping:** Perspective-correct textures for all four wall faces (North, South, East, West)
* **Optimized Rendering:** Independent X/Y axis rendering with efficient pixel manipulation
* **Performance:** Smooth 60+ FPS with optimized rendering loop

### 🔍 The Parser

The parser is structured in **7 modular phases**, each with a specific responsibility:

1. **Parser Map** - File extension and accessibility validation
2. **Parser Game** - Line-by-line file reading using `get_next_line`
3. **Parser Info** - Configuration extraction (textures and colors)
4. **Parser Verify** - Texture `.xpm` validation and RGB color range checking (0-255)
5. **Parser Matrix** - Linked list to 2D array conversion
6. **Parser Check** - Character validation and empty line detection
7. **Parser Flood** - Recursive flood-fill to ensure map enclosure

**Validation Features:**
* Strict `.cub` file verification
* Flood-fill algorithm ensuring maps are fully enclosed by walls
* Detection of split maps (empty lines in between)
* Clean exits with custom error messages
* **Zero memory leaks** - Verified with Valgrind

### 🎮 Movement & Controls

#### Rotation System
* 2D rotation matrix for view direction
* Rotation in radians (positive = right, negative = left)
* Applies transformation to both direction vector and camera plane
* Preserves perpendicularity between vectors

#### Collision Detection
* Independent X/Y axis movement validation
* Wall-sliding mechanic (smooth movement along walls)
* Per-axis collision check: only updates valid positions
* Prevents wall-clipping and glitching through walls

### 🖼️ Rendering Pipeline

The rendering process follows these steps:

1. **Draw Floor & Ceiling** - Paints the base canvas with configured colors
2. **Ray Initialization** - For each screen column, cast a ray
3. **DDA Traversal** - Find wall intersection using Digital Differential Analyzer
4. **Distance Calculation** - Compute perpendicular wall distance (prevents fish-eye effect)
5. **Height Calculation** - `line_height = screen_height / perp_wall_dist`
6. **Texture Selection** - Determine wall face (N/S/E/W) based on ray direction
7. **Texture Mapping** - Calculate texture X coordinate and draw vertical stripe
8. **Frame Display** - Push complete image to window

---

## 🚀 Installation & Usage

### 1. Prerequisites

You will need:
* `cc` (or `gcc`/`clang`)
* `make`
* `X11` libraries (or `MLX42`/`MiniLibX` depending on your implementation)

### 2. Compile

```bash
git clone https://github.com/ByteGab/cub3d.git
cd cub3d
make
```

### 3. Run

```bash
./cub3D maps/subject.cub
```

### 4. Debug (Valgrind)

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D maps/subject.cub
```

---

## 🎮 Controls

| Key | Action |
|:----|:-------|
| **W, A, S, D** | Movement (Forward, Left, Back, Right) |
| **← / →** | Rotate Camera |
| **ESC / X Button** | Exit Game |

---

## 🏗️ Project Architecture

The project is structured into **three main modules**:

### 🔍 Parser
Responsible for reading the `.cub` file, validating map boundaries (closed by walls), checking for valid RGB colors, and ensuring all texture paths are accessible. The parser uses a **linked list** during reading to preserve empty lines, allowing detection of split maps.

**Key Functions:**
* `init_game` - Initializes all pointers to NULL (prevents Valgrind errors)
* `load_map_data` - Orchestrates all validation modules
* `parse_game` - Reads file descriptor line by line
* `parse_info` - Extracts NO, SO, WE, EA, F, C configuration
* `parse_verify` - Validates textures and colors
* `parse_matrix` - Converts linked list to 2D array
* `check_map_spaces` - Validates map characters and detects empty lines
* `flood_fill` - Recursive map enclosure validation

### 📐 Raycaster
The mathematical heart of the project. Implements the **DDA (Digital Differential Analyzer)** algorithm to calculate the precise distance between the player and the nearest wall for every vertical slice of the screen.

**Key Components:**
* Ray direction calculation per screen column
* Step and initial side distance computation
* DDA loop for grid traversal
* Wall side detection (horizontal vs vertical)
* Perpendicular distance calculation (fish-eye correction)

### 🖼️ Renderer
Handles the graphical output using the **MiniLibX/MLX42** library. Manages the image buffer, applies textures with perspective correction, and renders floor and ceiling colors.

**Key Functions:**
* `draw_floor_ceiling` - Base canvas with configured colors
* `calculate_height` - Wall line height based on distance
* `calculate_tex_x` - Texture selection and X coordinate
* `draw_stripe` - Vertical textured line rendering
* `get_texture_color` - Pixel color extraction from texture
* `render_frame` - Main orchestration function

---

## 📁 Map Format (.cub)

The map file must follow this structure:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

**Rules:**
* Textures: `NO`, `SO`, `WE`, `EA` followed by path to `.xpm` file
* Floor color: `F R,G,B` (0-255)
* Ceiling color: `C R,G,B` (0-255)
* Map characters: `0` (floor), `1` (wall), `N/S/E/W` (player spawn + direction)
* Map must be enclosed by walls
* Only one player spawn allowed

---

## 🧪 Testing & Validation

### Common Edge Cases

✅ Map enclosed by walls  
✅ Invalid RGB values (>255 or <0)  
✅ Missing textures  
✅ Empty lines in middle of map  
✅ Multiple player spawns  
✅ Invalid characters in map  
✅ Map not rectangular (different row lengths)  
✅ Memory leaks with Valgrind  

---

## 🎯 Bonus Features

* ✅ **Wall Collision System** - Smooth movement preventing wall-clipping

---

## 🔧 Implementation Details

### Main Flow

1. **Argument Check** - Validates command-line arguments
2. **File Check** - Extension and existence before memory allocation
3. **Initialization** - `init_game` sets all pointers to NULL
4. **Raw Parsing** - File read into memory
5. **Data Loading** - Sequential validation modules
6. **Game Launch** - Graphical window initialization
7. **Game Loop** - Rendering and event handling
8. **Cleanup** - `free_resources` ensures zero leaks

### Memory Management

* All allocations are tracked and freed properly
* Double-free prevention with NULL checks
* Valgrind clean with `--leak-check=full`
* Error handling with graceful exits

---

## 📖 Learning Resources

* [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - The definitive guide to raycasting
* [Permadi's Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - Mathematical foundations
* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library reference

---

## 👥 Authors

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/ByteGab">
        <img src="https://github.com/ByteGab.png" width="100px;" alt="Gabriel Freire"/>
        <br />
        <sub><b>Gabriel Freire Simón</b></sub>
      </a>
      <br />
      <sub>Parser & Engine</sub>
    </td>
    <td align="center">
      <a href="https://github.com/gomandam">
        <img src="https://github.com/gomandam.png" width="100px;" alt="Gabriel Dan"/>
        <br />
        <sub><b>Gabriel Dan Omandam</b></sub>
      </a>
      <br />
      <sub>Renderer & Textures</sub>
    </td>
  </tr>
</table>

---
<p align="center">
  Made with ☕ and 🧠 at 42 Madrid
</p>

<p align="right">(<a href="#top">back to top</a>)</p>
