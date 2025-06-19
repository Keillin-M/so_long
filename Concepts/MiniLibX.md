# 🚀🎨 MiniLibX
## 🤔 What is MiniLibX? 
**MiniLibX** (aka mlx) is a tiny, simple graphics library mainly used in Unix-like systems (Linux/macOS). It helps you open windows, draw pixels/shapes, display images, and handle keyboard/mouse input. Perfect for learning basic graphical programming!

## 💡 Why use MiniLibX?
- Lightweight & easy to learn
- Great for beginners to understand graphics fundamentals
- Commonly used in programming schools like 42

## 🎯 What can you do with MiniLibX? 🎯
- Open a window
- Draw pixels & simple shapes
- Display images
- Handle keyboard & mouse events
- Close windows cleanly

## 🔧 How does it work? 
1. Initialize the library (mlx_init())
2. Create a window (mlx_new_window())
3. Draw pixels or images (mlx_pixel_put())
4. Listen to events like keypresses (mlx_hook())
5. Keep window open (mlx_loop())
6. Close window when done (mlx_destroy_window())

## 💻 Simple example in C
```c
#include "mlx.h"

int main() {
    void *mlx;
    void *win;

    mlx = mlx_init();                     // Initialize MiniLibX 🚀
    win = mlx_new_window(mlx, 800, 600, "My Window");  // Open 800x600 window 🪟
    
    mlx_pixel_put(mlx, win, 400, 300, 0x00FF00);  // Draw green pixel at (400, 300) 🌈
    
    mlx_loop(mlx);                       // Start event loop 🔄

    return 0;
}
```
## 📚 Key functions to know 
| Function               | What it does                            |
| ---------------------- | --------------------------------------- | 
| `mlx_init()`           | Initialize MiniLibX                     | 
| `mlx_new_window()`     | Create a new window                     | 
| `mlx_pixel_put()`      | Draw a pixel                            | 
| `mlx_hook()`           | Set event handlers (keyboard/mouse)     | 
| `mlx_loop()`           | Start the event loop (keep window open) | 
| `mlx_destroy_window()` | Close and destroy window                | 


## 📝 Tips for beginners:
- MiniLibX is minimal — you need to handle some things yourself (like more complex graphics or animations).
- It's often used in C programming classes and projects.
- Try starting with just opening a window and drawing a pixel, then move on to handling keyboard inputs or drawing images.
- Remember that MiniLibX may behave differently depending on your OS, especially between Linux and macOS.

