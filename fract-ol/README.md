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
	c = color(f)
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

## Color
- `M`: max iter
- `T`: threshold, which is 2
- `m`, `d(i, j)`: the least iter index `m` that `m < M`, `|z_m| > T`

### function
> A function `t = f(m)` that maps
> `[m1, m2]` to `[0, 1]`

- `s = (m - m1) / (m2 - m1)`, which is `0 <= s <= 1`
- `t = s^q` so `0 <= t <= 1`
- or `t = (1 - s)^q`
