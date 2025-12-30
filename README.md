# 🕹️ Cub3D

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-black?style=for-the-badge&logo=42" alt="42 Project" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-green?style=for-the-badge&logo=opengl" alt="Graphics" />
</p>

## 📖 Overview

**Cub3D** is a 42 Cursus project that explores the foundations of 3D graphics using the **Raycasting** technique—the same logic used in legendary games like *Wolfenstein 3D*. The goal is to create a dynamic perspective inside a maze, converting a 2D map into a 3D simulated environment.

> "A journey into the math behind the pixels."

---

## 🛠️ Technical Features

### The Engine
* **DDA Algorithm:** Precise wall collision detection using the Digital Differential Analyzer.
* **Texture Mapping:** Perspective-correct textures for North, South, East, and West walls.
* **Performance:** Optimized rendering loop to ensure smooth 60+ FPS.

### The Parser
* **Robust Validation:** Strict `.cub` file verification.
* **Flood-Fill Logic:** Ensuring maps are fully enclosed by walls.
* **Error Management:** Clean exits with custom error messages and **zero memory leaks**.

### The Extras (Bonuses)
* **Minimap:** Real-time top-down view of the player's position.
* **Collision System:** Smooth movement that prevents "wall-clipping".
* **Mouse Look:** Full 360° camera control with the mouse.

---

## 🚀 Installation & Usage

### 1. Prerequisites
You will need `cc`, `make`, and the `X11` libraries (or `MLX42`/`MiniLibX` depending on your version).

### 2. Compile
```bash
git clone [https://github.com/your-username/cub3d.git](https://github.com/your-username/cub3d.git)
cd cub3d
make
```
### 3. Run
```bash
./cub3D maps/subject.cub
```
## 🎮 Controls

| Key | Action |
| :--- | :--- |
| **W, A, S, D** | Movement (Forward, Left, Back, Right) |
| **← / →** | Rotate Camera |
| **ESC / X Button** | Exit Game |
| **Mouse** | Smooth Rotation (Bonus) |

## 🏗️ Project Architecture

The project is structured into three main modules:

* **🔍 Parser:** Responsible for reading the `.cub` file, validating map boundaries (closed by walls), checking for valid RGB colors, and ensuring all texture paths are accessible.
* **📐 Raycaster:** The mathematical heart of the project. It implements the **DDA (Digital Differential Analyzer)** algorithm to calculate the precise distance between the player and the nearest wall for every vertical slice of the screen.
* **🖼️ Renderer:** Handles the graphical output using the **MiniLibX/MLX42** library. It manages the image buffer, applies textures with perspective correction, and renders the floor and ceiling colors.



---

## 👤 Authors

* **Gabriel Freire Simón** - [GitHub Profile](https://github.com/ByteGab)
* **Gabriel Dan Omandam** - [GitHub Profile](https://github.com/gomandam)

<p align="right">(<a href="#top">back to top</a>)</p>
