# My Planck Keyboard Layout

The Planck is a 40% computer keyboard with an [ortholinear][olkb] layout
(the keys are arranged in columns rather than being staggered as on a traditional typewriter keyboard).
The keys are laid out in a 4 by 12 grid, sometimes with a 2-unit wide spacebar on the bottom row (the so-called MIT layout), for a total of 48 or 47 keys.

The board's microcontroller is programmed through the free/libre [Quantum MK firmware][qmk], which allows for a great
deal of flexibility in implementing keyboard layouts. The keymap is organized into layers that can be switched between
by holding or tapping function keys.

[olkb]: https://olkb.com/reference/primer/
[qmk]: https://github.com/qmk/qmk_firmware

## Building
Checkout the [QMK Firmware][qmk] code and create a symbolic link to this directoryC in the `qmk_firmware/keyboards/planck/keymaps` directory.

```
    ln -s `pwd`/planck ~/Projects/qmk_firmware/keyboards/planck/keymaps/mattfair
```

To compile from the QMK Firmware directory run:
```
    make planck/rev4:mattfair
```

----------

You can find the latest version of my keymap file at <https://github.com/mattfair/dots/tree/master/planck>.
My keymap was derived from [Noah Fredrick's][noahfrederick] keymap layout and inspiration from other [QMK Planck Layouts][qmk_plank_layouts].

[qmk_plank_layouts]: https://github.com/qmk/qmk_firmware/tree/master/keyboards/planck
[noahfrederick]:https://github.com/noahfrederick/dots/tree/master/planck> 
