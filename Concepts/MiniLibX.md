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

Writing Pixels to an Image — Explained Simply
Why not use mlx_pixel_put directly?
mlx_pixel_put puts a pixel directly to the window right away.

This is very slow because it redraws the window for every single pixel.

Imagine painting a huge picture one dot at a time and showing the picture every time you add a dot — that’s inefficient!

So, what’s the better way?
Instead of drawing pixels directly to the window, draw them to an image buffer first (a block of memory).

Once the whole image is ready (all pixels are drawn in memory), push that entire image to the window at once.

This is like painting the whole picture on a canvas offscreen first, then hanging the canvas on the wall all at once — much faster and smoother.

Step 1: Create an image buffer
You create an empty image with the size of your window (e.g., 1920x1080 pixels):

c
Copy
Edit
void *mlx = mlx_init();
void *img = mlx_new_image(mlx, 1920, 1080);
Step 2: Get the image data address
You need to know where in memory the image pixels are stored, so you can write colors there.

Use this function:

c
Copy
Edit
char *addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
addr points to the start of pixel data.

bpp = bits per pixel (how many bits describe one pixel, usually 32 bits or 4 bytes).

line_length = how many bytes each row of pixels uses in memory.

endian = tells you byte order (mostly not important for beginners).

Important detail: Why not just multiply by window width?
Pixels in memory are stored row by row.

Sometimes, the number of bytes per row (line_length) is larger than the window width times bytes per pixel (due to memory alignment or padding).

So, you always use line_length to calculate pixel positions.

Step 3: Calculate the pixel's memory position
To find the exact spot in memory for pixel at (x, y):

c
Copy
Edit
int offset = (y * line_length) + (x * (bpp / 8));
Multiply the row number y by line_length (bytes per row).

Add the column number x times bytes per pixel (bpp / 8).

Step 4: Write the pixel color
c
Copy
Edit
*(unsigned int *)(addr + offset) = color;
You write a 32-bit color value (like 0x00FF00 for green) into the memory at that offset.

This changes the pixel color in the image buffer.

Step 5: Display the image
After setting all pixels you want in the image, push it to the window:

c
Copy
Edit
mlx_put_image_to_window(mlx, win, img, 0, 0);
This draws the whole image at once, very fast and smooth.

Example function to put pixels (like mlx_pixel_put, but faster):
c
Copy
Edit
typedef struct s_data {
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
}   t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}
Bonus: Avoid screen tearing
If you draw pixels directly on the image shown on the screen, you might see flickering or tearing.

To fix this, use double buffering:

Have two (or more) image buffers.

Draw to a hidden image buffer.

When ready, swap the hidden image with the visible one.

This way, the user only sees fully drawn frames.

TL;DR for beginners:
Don’t use mlx_pixel_put for many pixels; it’s slow.

Create an image buffer, write pixels there by calculating their position in memory.

Push the entire image to the window once done.

Use double buffering if you want smooth animations without flickering.
