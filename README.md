# fdf
’fil de fer' wireframe 3d model

this project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.

!!!!!add image of my own fdf

## how to install

follow the instructions of [official minilibx repo](https://github.com/42Paris/minilibx-linux) to build and include the 'libmlx.a' and 'mlx.h' to your system
    tl;dr: you should have the libmlx.a on your /usr/local/bin and mlx.h on /usr/local/include

# so cool! i wanna do it as well!!!

this project is so visual and interesting to develop that i needed to record everything needed to develop it. all you need is some C knowledge, refresh some maths, and a lot of patience.
i tried to gather all the useful information i found through the net and summarize it for me, so i hope this can help to anyone interested. 
if you are keen to know everything and as curious as me, make sure to check the resources i used to get to know more about the topics covered! enjoy :)

## preamble

mlx is a bit hard to comprehend, but only the math aside is another story. let me introduce you to concepts and vocabulary I came across during the realization of this project in order to succeed in it (or at least try it)

- rasterisation: taking an image described in vectors and convert it into a series of pixels which, when displayed together look, create the image which was represented via shapes

- aliasing (staircasing) effect: distortion that happens when a signal is reconstructed in a smaller resolution than the original sample

- bits per pixel (bpp): the amount of color information contained in each pixel in an image. also called 'depth of image'

- size line (line length): number of bytes used to store one line of the image in memory

- interpolation: process in which we use known values to guess unknown values

## minilibx

oh god. here we go.

to compile properly (on macOS) make sure to add `-lmlx -framework OpenGL -framework AppKit` flags!!! for other windows, good luck. if you are a linux user, check the flags on my makefile if it works for your distro :)

- `mlx_init()` initializes the graphic system to your computer. returns a pointer identifying your mlx unning instance

- `mlx_new_window()` creates a window and returns a pointer that identifies it on memory

- `mlx_key_hook()` given the window pointer of mlx, a function given as a parameter can handle the key event

- `mlx_loop()` mantains the window open until a SIGINT is sent. its always waiting for an event

- `mlx_get_data_addr()` used to obtain window info from the system. given the issue of pixel\_put, we need this info to create mlx images. we can obtain from this function:
	- bpp
	- line length: how many bytes does a word of the display memory (VRAM) is long
	- endian: how does the system manage the [order of bytes](https://en.wikipedia.org/wiki/Endianness)

- `mlx_put_image_to_window()` displays everything from the image memory into the screen

make sure to check the [official manual](https://github.com/42Paris/minilibx-linux/tree/master/man/man1) for more detailed information.

#### mlx images

a windows is made up of pixels. here, a pixel stores 4 different values: ALPHA and RGB color encoding.
- ALPHA: refers to the opacity of the pixel
- RGB: represents the color in 3 hexadecimal values determining the amount of red, green and blue respectively

(usually) each of these values occupies 1B of memory, so every pixel requires 4B of memory (ARGB econding). if this numbers do not ring a bell to you, get your bits per pixel with the `mlx_get_color_value()` function.

##### why use mlx images instead of pixel\_put?

using pixel put takes way longer than managing an image in memory. to display just one pixel it has to access the program, draw the pixel on the desired coordinate, and return an integer. 

we rather buffer everything onto an image where we input all the information we want, and then draw everything at once.

##### writing our own pixel\_put for mlx images
in order to write on the proper place of the window, we need to calculate where on memory is this pixel located

given two coordinates (a point, make sure its in bounds of the window size!!) and the mlx\_image memory direction, we can calculate the position in the window with:

	offset = (y * mlx->size_line) + (x * mlx->bpp/8);
	pixel_pos = mlx->img + offset;

'y' is the row where you want to write the pixel, multiplying it by the line length of a row, you get the total number of bytes in all preceding rows, getting where the row in memory is.

the 'x' coordinate represents the column in which the pixel is located. multiplying it by  bpp/8 gives the total number of bytes in all preceding pixels within the same row. the division by 8 is necessary because the bpp represents the number of bits per pixel, and each byte is 8 bits. (?)

## yea but how do i draw?

let me introduce you to Jack Elton Bresenham and his famous algorithm developed back then in 1965 back then at IBM.
his [line plotting algorithm](https://gitlab.cecs.anu.edu.au/pages/2018-S1/courses/comp1100/assignments/02/Bresenham.pdf) is a simple and rapid method that determines the points with a close approximation of a straight line between two points. the reason why I chose this algorithm is because of its efficiency. by only using substraction, addition and multiplication, you can draw almost anything. this will be the basis for the project (given that everything drawn in here are lines lol)

!!!!!add image coordinates

lets see how it works, and my implementation:

```
void    bresenham(t_fdf *fdf, t_point from, t_point to)
{
    t_point diff;
    t_point sign;
    t_point point;
    int     err;
    int     tmp;

	//the differences refer to how distant are the initial to the final points
    diff.x = ft_abs(to.x - from.x);
    diff.y = ft_abs(to.y - from.y);
	//the sign defines how should we advance inside the grid
    sign.x = -1;
    sign.y = -1;
    if (from.x < to.x)
        sign.x = 1;
    if (from.y < to.y)
        sign.y = 1;

    point.x = from.x;
    point.y = from.y;
    err = diff.x - diff.y; //decision parameter to know in which direction move (x or y) in each step (dx - dy its convention)
    //in each instance, the mesh point nearest to the desired line segment is selected
    while (point.x != to.x || point.y != to.y)
    {
        img_pixel_put(fdf->mlx, point.x, point.y); //paint
        tmp = err * 2; //used for optimization in the algo: removes redundant operations
        if (tmp > - diff.y) //if the dx portion on err is bigger than the dy
        {
            point.x += sign.x; //we have to diminish the error by getting closer to the direction of x
            err -= diff.y; //we reduce the error by "dy" factor because of increasing 1 nudge in the x direction
        }
        if (tmp < diff.x)
        {
            point.y += sign.y;
            err += diff.x;
        }
    }
}
```
the decision making inside the loop is based on HOW the error parameter is made

### great grid, but where is the z dimension??
TODO: explain isometric and orthogonemtric perspectives

### OMG can i color it??
TODO: gradient explanation

### lets get playful
TODO: explain mlx events and modifiable parameters

# resources
this could haven't happened without these golden archives:

[bresenham](https://digitalbunker.dev/bresenhams-line-algorithm/)
[mlx student docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
[mlx tutorial](https://github.com/Gontjarow/MiniLibX/tree/master/docs)
[rgb slider](http://www.cknuckles.com/rgbsliders.html)
[mlx images tuto](https://github.com/keuhdall/images_example)
[color linear gradient](https://github.com/VBrazhnik/FdF/wiki/How-to-create-linear-gradient%3F)
[isometric intro](https://stackoverflow.com/questions/1189830/isometric-projection-in-2d-coordinate-system)
[types of projections](https://www.firstinarchitecture.co.uk/architecture-drawing-projections/)
