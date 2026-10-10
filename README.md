<div align="center">

# 🎨 Computer Graphics with OpenGL

**A collection of interactive 2D graphics exercises built with C++ and OpenGL/GLUT**

**C++ · OpenGL · GLUT · 2D Graphics · Transformations · Keyboard Input**

</div>

---

## ✨ Overview

This repository brings together coursework exercises demonstrating how to draw geometric shapes, construct scenes, respond to keyboard input, and apply 2D transformations. Each source file is a **standalone example**, not a single combined application.

## 🖼️ Project gallery

| Example | What it demonstrates | Source |
| --- | --- | --- |
| 🌅 Nile & Pyramids | A Nile scene with a boat, sail, sun, desert and tree, drawn from OpenGL primitives | [Assignment 1](Assignments/Assignment-1.cpp) |
| 🤖 Robot Transformations | A robot built from rectangles and circles with keyboard-driven movement, rotation and scaling | [Assignment 2](Assignments/Assignment-2.cpp) |
| ⭐ Star Shape | Four triangles forming a star-like arrangement with configurable colors | [Star Shape](Star-Shape/Star-Shape.cpp) |
| ⌨️ Keyboard Interaction | A rectangle that can translate, rotate, scale and change color | [Keyboard Function](Keyboard-Interaction/Keyboard-Function.cpp) |
| 🎨 Triangle Color Controls | Eight triangles with independently selected colors via keys 1–4 | [Lab Exam – Keyboard Colors](Lab-Exam/LapExam-Keyboard-Colors.cpp) |
| 🌈 Triangle Color Presets | Eight-triangle fan with four keyboard-selectable color palettes | [Lab Exam – Original](Lab-Exam/LabExam-Original.cpp) |

> Screenshots are not included yet. Add real screenshots after running the programs; the source code alone does not establish verified visual output.

## 🎮 Keyboard controls

### Robot Transformations — Assignment 2

| Key | Action |
| --- | --- |
| Arrow keys | Move robot up, down, left or right |
| `r` | Rotate robot by 10 degrees |
| `+` / `-` | Increase / decrease scale |
| `Esc` | Exit |

### Keyboard Interaction

| Key | Action |
| --- | --- |
| `W` / `A` / `S` / `D` | Move the rectangle (use lowercase keys) |
| `+` / `-` | Scale |
| `R` / `T` | Rotate (use lowercase keys) |
| `F1` / `F2` / `F3` | Set red / green / blue |

### Triangle exercises

- **Star Shape:** keys `1`–`4` change the four triangles' colors.
- **Lab Exam – Keyboard Colors:** keys `1`–`4` recolor specific triangles red, green, blue or magenta.
- **Lab Exam – Original:** keys `1`–`4` select different eight-triangle color palettes; `Esc` exits.

## 🛠️ Technologies and concepts

- **Language:** C++
- **Graphics:** OpenGL immediate-mode API and GLUT/freeglut
- **Concepts:** primitives, vertex coordinates, RGB colors, orthographic projection, keyboard callbacks, translation, rotation and scaling

These examples use the classic OpenGL fixed-function style for educational purposes, not modern shader-based OpenGL.

## 🚀 How to run

**Requirements:** a C++ compiler, OpenGL development libraries, and GLUT or freeglut. The commands below are examples for **Ubuntu/Debian Linux**.

```bash
sudo apt update
sudo apt install g++ freeglut3-dev
```

Compile and run an individual exercise:

```bash
g++ Assignments/Assignment-2.cpp -o robot -lglut -lGLU -lGL
./robot
```

For Windows, configure a C++ project with the OpenGL and freeglut headers/libraries in Visual Studio or another compatible IDE. Do **not** compile all examples together because multiple files define `main()`.

## 📁 Repository structure

```text
Computer-Graphics-OpenGL/
├── Assignments/
│   ├── Assignment-1.cpp
│   └── Assignment-2.cpp
├── Keyboard-Interaction/
│   └── Keyboard-Function.cpp
├── Star-Shape/
│   └── Star-Shape.cpp
├── Lab-Exam/
│   ├── LabExam-Original.cpp
│   └── LapExam-Keyboard-Colors.cpp
├── Additional-Exercises/
│   └── Program.cs
├── .gitignore
└── README.md
```

## ⚠️ Known limitations

- `Additional-Exercises/Program.cs` contains **C++/GLUT code despite its .cs extension**; it is not a C# program. It resembles the keyboard-interaction example and is retained as an original coursework artifact.
- The `Star-Shape` and `Keyboard-Interaction` sources use a Windows-style GLUT include path (`GL\\glut.h`); on Linux this may need to be changed to `GL/glut.h`.
- Some examples set transformations or projection inside display callbacks and use repeated redraws; these are learning exercises and may benefit from further graphics-state cleanup.
- Programs have **not been compiled or run during this documentation update**.

## 🤝 Attribution

A portfolio collection of academic exercises, some of which may include collaborative work. Original contributors should be credited where applicable.

---

<div align="center">

*Learning computer graphics, one primitive at a time.*

</div>
