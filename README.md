# fdf
’fil de fer' wireframe 3d model

this project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

!!!!!add image

## how to install

follow the instructions of [official minilibx repo](https://github.com/42Paris/minilibx-linux) to build and include the 'libmlx.a' and 'mlx.h' to your system

## how to draw

mlx is a bit hard to comprehend, but only the math aside is another story. let me introduce you to concepts and vocabulary I came across during the realization of this project in order to succeed in it (or at least ty it)

- rasterisation: taking an image described in vectors and convert it into a series of pixels which, when displayed together look, create the image which was represented via shapes

- aliasing (staircasing) effect: distortion that happens when a signal is reconstructed in a smaller resolution than the original sample

- bits per pixel (bpp): the amount of color information contained in each pixel in an image. also called 'depth of image'

- size line: number of bytes used to store one line of the image in memory

### bresenham

Bresenham's line algorithm: simple and rapid method that determines the points with a close approximation of a straight line between two points

!!!!!add image coordinates

## minilibx

oh god. here we go.

to compile properly make sure to add `-lmlx -framework OpenGL -framework AppKit` flags!!!

- `mlx_init()` initializes the graphic system to your computer. returns a pointer identifying your mlx unning instance

- `mlx_new_window()` creates a window and returns a pointer that identifies it on memory

- `mlx_loop()` mantains the window open until a SIGINT is sent. its always waiting for an event

### mlx images

a windows is made up of pixels. a pixel stores 4 different values: ALPHA and RGB color encoding.
- ALPHA: refers to the opacity of the pixel
- RGB: represents the color in 3 hexadecimal values determining the amount of red, green and blue respectively

(usually) each of these values occupies 1B of memory, so every pixel requires 4B of memory (ARGB econding). if this numbers do not ring a bell to you, get your bits per pixel with the `mlx_get_color_value()` function.

when a 

#### why use mlx images instead of pixel\_put?

using pixel put takes way longer than managing an image in memory. to display just one pixel it has to access the program, draw the pixel on the desired coordinate, and return an integer. 

we rather buffer everything onto an image where we input all the information we want, and then draw everything at once.
