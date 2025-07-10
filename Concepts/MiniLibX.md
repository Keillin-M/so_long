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

    mlx = mlx_init();                     // Initialize MiniLibX 
    win = mlx_new_window(mlx, 800, 600, "My Window");  // Open 800x600 window 
    
    mlx_pixel_put(mlx, win, 400, 300, 0x00FF00);  // Draw green pixel at (400, 300) 
    
    mlx_loop(mlx);                       // Start event loop 

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

## 🖌️ Writing Pixels to an Image — Explained Simply

### ❌ Why not use mlx_pixel_put directly?
- mlx_pixel_put writes a single pixel directly to the window in real time.
- This might sound simple, but it's very slow — especially if you're drawing many pixels.

Imagine painting a huge picture one dot at a time, and showing it to your friend after every dot.
Exhausting, right?

### ✅ A Better Way: Draw to an Image Buffer First
Instead of drawing pixels live to the screen:

- 📦 Draw all your pixels to a memory buffer (an image).
- 🖼️ Once you're done, display the full image to the window in one go.

It's like painting the entire picture on a canvas offscreen, then hanging the finished painting on the wall — fast and smooth!

### 🪜 Step-by-Step Guide
### 🧱 Step 1: Create an Image Buffer
```c
void *mlx = mlx_init();
void *img = mlx_new_image(mlx, 1920, 1080);
```
This creates a blank image in memory (1920x1080 pixels).

### 🔍 Step 2: Access the Image Data
You need to know where in memory the image pixels are stored, so you can write colors there.
```c
char *addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
```
What do these mean?
| Variable      | Meaning                               |
| ------------- | ------------------------------------- |
| `addr`        | Pointer to the start of pixel data    |
| `bpp`         | Bits per pixel (usually 32 = 4 bytes) |
| `line_length` | Bytes per row (can include padding!)  |
| `endian`      | Byte order (not critical for now)     |

❗ Don’t just multiply width × bpp. Always use line_length to get pixel positions — memory alignment can add extra bytes per row.

### 📍 Step 3: Find the Pixel's Memory Position
To draw a pixel at (x, y):
```c
int offset = (y * line_length) + (x * (bpp / 8));
```
- Multiply row (y) by line_length to get the row's start
- Add the pixel offset in that row

### 🎨 Step 4: Set the Pixel Color

```c
*(unsigned int *)(addr + offset) = color;
```
For example:
```c
*(unsigned int *)(addr + offset) = 0x00FF00; // Green
```
### 🖥️ Step 5: Display the Final Image
```c
mlx_put_image_to_window(mlx, win, img, 0, 0);
```
### 🧰 Custom Pixel Function Example
```c
typedef struct s_data {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}
```
Now you can use my_mlx_pixel_put() just like mlx_pixel_put, but it's way faster!

### ✨ Bonus: Avoid Screen Tearing with Double Buffering
- If you're seeing flickering or tearing when redrawing:
- Keep two image buffers.
- Draw everything on the hidden buffer.
- Once the frame is ready, swap the buffers and display the new image.

🧠 The user only sees fully rendered frames — buttery smooth animations!

## 🧵 TL;DR for Beginners
- ❌ Don’t use mlx_pixel_put for lots of pixels.
- ✅ Draw to an image buffer in memory.
- 🖼️ Use mlx_put_image_to_window() to display the full image.
- ⚙️ For smooth animations, use double buffering.
