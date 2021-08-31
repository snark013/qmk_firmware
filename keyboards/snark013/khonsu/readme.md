# Khonsu

<img src="https://github.com/snark013/khonsu/raw/main/imgs/keyboard.png" width="800" />

A split keyboard with 3x7 vertically staggered keys, two extra keys for brackets and international layouts and thumb keys.

- 7 underglow RGB led's per side (SK6812 Mini)

* Keyboard Maintainer: [Alexander Petrov](https://github.com/snark013)
* Hardware Supported: Arduino Pro Micro / Alvaro / nRFMicro
* Hardware Availability: [KiCAD project, files to print and documentation](https://github.com/snark013/khonsu)

Make firmware .hex for this keyboard (after setting up your build environment):

    make snark013/khonsu/ver1:default

Example of flashing this keyboard (or use [QMK Toolbox](https://github.com/qmk/qmk_toolbox)):

    make snark013/khonsu/ver1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
