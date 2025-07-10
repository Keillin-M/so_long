# 🎮 so_long
A simple 2D game built with C and MiniLibX

Welcome to **so_long** — a tiny 2D top-down game where your mission is to collect stuff and escape the map... without dying! Built in pure C using the good ol’ 🧪 MiniLibX graphics library.

## 🚀 Project Overview
so_long is a project from the 42 curriculum. The goal? Build a simple graphical game from scratch using C and MiniLibX.

## 🧩 Get all the collectables
🚪 Reach the exit
🐮 Avoid the enemies
🧱 No walking through walls, cheater.

## 🧠 Key Concepts Covered
- Basic 2D rendering with MiniLibX
- Handling player movement & key events
- Reading and validating map files
- Simple game state management
- Collision detection
- Creating a tile-based map system
- 👾 (Bonus) Adding enemies

## 🗺️ Map Format
The game map is a .ber file made of characters:
```c
1 - Wall  
0 - Floor  
C - Collectible  
E - Exit  
P - Player start position  
```
Example:
```c
111111
1P0C01
100001
1C0E11
111111
```
## 🕹️ Controls
| Key   | Action     |
| ----- | ---------- |
| W / ↑ | Move up    |
| A / ← | Move left  |
| S / ↓ | Move down  |
| D / → | Move right |
| ESC   | Quit game  |

## 🛠️ Technologies
- Language: C
- Graphics: MiniLibX
- OS: Linux

## 📦 How to Run
1. Clone the repo:
```bash
git clone https://github.com/Keillin-M/so_long.git
cd so_long
```
2. Compile:
```bash
make
```
3. Run the game:
```bash
./so_long maps/map4.ber
```
## 💡 Lessons Learned
- C is low-level, but super satisfying when stuff works.
- You will forget a newline somewhere and suffer.
- MiniLibX is like a chill intro to graphics programming.
- Reading maps from files is sneakily tricky (hello, buffer overflows - thankfully I had that covered in get_next_line!).
- Memory management is everything (don't leak! So many things to destroy..).

## ✨ Bonus Features
- 👾 Enemies that move around independently
- 🔁 Animations and sprite updates
- You lose with you touch the enemy

## 📸 Screenshots
![image](https://github.com/user-attachments/assets/25b157c9-ca94-4d36-b33c-f3f60d57af14)

![image](https://github.com/user-attachments/assets/8dcbdc2d-b705-46af-bbdd-5e134d92aa1b)

## 🙌 Credits
- Created as part of the 42 School curriculum.
- Graphics powered by the minimalist MiniLibX.
- Credit for sprites: Cup Nooble (https://cupnooble.itch.io/).
