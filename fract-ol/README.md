# /fract-ol

- [42 Docs / Libs / MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html)

## Args
```
./fractol [-m (m|j)] [-j <float num> <float num>] [-c]
```

## Math
- `z = z^2 + c`

Mandelbrot set
- `z = 0`
- `c = Point of Interest`

Julia set
- `z = Point of Interest`
- `c = Constant`

## Graphics
```py
draw_fract_pixel: pixel a
	max_iter;
	p = pixel_to_point(a)
	f = fract_sequence(p, max_iter)
	c = colorize(f)
	draw_pixel(a, c)

draw_fract:
	for each a in window
		draw_fract_pixel(a)

draw_fract_step:
	step;
	max_step;
	step_w;
	step_h;
	pixel_count;
	max_pixel_count;
	o = {.x = step / step_w, .y = step % step_w}
	for each a in grid(o)
		draw_fract_pixel(a)
```
