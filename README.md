# 🌐 FDF – Wireframe 3D Landscape Renderer

### A C graphics project to render 3D wireframe landscapes

---

## 📖 Introduction

This project, called **FDF** (short for *fil de fer*, French for *wireframe model*), is about building a simple **3D wireframe representation of landscapes**.

It reads a `.fdf` file containing coordinates and altitudes, then renders a 3D isometric projection of the map using the **MiniLibX** graphical library.

- **Language**: C
- **Libraries**: [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx), `libft`
- **Purpose**:
  - Learn the basics of computer graphics programming
  - Understand projections and coordinate transformations
  - Handle graphical window management and rendering in C

---

## 🖼️ Visualization

Below is a conceptual example of how the program takes a map file and turns it into a 3D wireframe landscape:

```
Input map file (.fdf)
0  0  0  0  0
0  5  5  0  0
0  5 10  5  0
0  0  5  0  0

       ↓ Processed with FDF ↓

Rendered 3D isometric wireframe
        /\
      /----\    /\
    /  ---/--\
  /   /
```

*(You can later replace this with a real screenshot of the rendered wireframe.)*

---

## 📂 Project Structure

```
fdf/
│── includes/           # Header files (.h)
│── src/                # Source code (.c)
│   ├── main.c          # Entry point
│   ├── render.c        # Rendering and drawing functions
│   ├── parse.c         # Parsing of .fdf map files
│   ├── hooks.c         # Input and event handling
│   ├── hooks_bonus.c   # Extra controls for bonus features
│   └── ...
│── maps/               # Example .fdf maps
│── libft/              # Custom library (libft)
│── Makefile            # Build instructions
```

---

## 🚀 User Instructions

### 1. Clone the repository

```bash
git clone https://github.com/luccaseabracruz/fdf.git
cd fdf
```

### 2. Build the project

**Mandatory part**

```bash
make
```

Compiles the project with the basic requirements (isometric projection, reading .fdf files, and rendering).

**Bonus part**

```bash
make bonus
```

Compiles the project with extended functionality defined in `hooks_bonus.c`.

### 3. Run the program

```bash
./fdf maps/42.fdf
```

### 4. Controls

#### 🔹 Mandatory Features

- **ESC** → Exit program
- **Window close button (X)** → Exit program

#### 🔹 Bonus Features (when compiled with `make bonus`)

From `hooks_bonus.c`, you can interact with the wireframe model:

- **Arrow Keys (↑ ↓ ← →)** → Move (translate) the model across the window
- **+ / - keys** → Zoom in / Zoom out
- **Q / E keys** → Rotate the model (left/right)
- **W / S keys** → Rotate the model (up/down)
- **A / D keys** → Rotate the model (sideways, Z-axis)
- **P key** → Switch projection (isometric ↔ parallel)

---

## 🛠️ Notes

- Only properly formatted `.fdf` files are supported.
- The project uses **MiniLibX**, so make sure it is installed on your system.
- Bonus features will only be available if the project is compiled with `make bonus`.

---

## 📝 License

This project is part of the 42 School curriculum.

---

## 👤 Author

**Luccas Seabra Cruz**

- GitHub: [@luccaseabracruz](https://github.com/luccaseabracruz)