# unit-conversion

A command-line tool for converting physical quantities between the CGS (Centimetre-Gram-Second) and SI (International System of Units) unit systems.

## Supported quantities

| Quantity    | CGS unit | SI unit |
| ----------- | -------- | ------- |
| Length      | cm       | m       |
| Mass        | g        | kg      |
| Time        | s        | s       |
| Force       | dyn      | N       |
| Energy/Work | Erg      | J       |
| Power       | Erg/s    | W       |
| Pressure    | dyn/cm² | Pa      |

## Requirements

- C++23 compiler (GCC 13+ or Clang 17+)
- CMake 3.20+

## Build

Use the provided script (tho it may not work for everyone):

```bash
# Full rebuild + run
bash run.bash root

# Run only (assumes build already exists)
bash run.bash
```

## Usage

The program runs interactively in a loop:

1. Select conversion direction: `CGS -> SI` or `SI -> CGS`
2. Select the quantity to convert
3. Enter a positive numeric value
4. Repeat or exit

```
Select what type of conversion:
1. CGS -> SI
2. SI -> CGS
Enter a value (1-2): 1

Select what do you want to convert:
1. Length (cm -> m)
...
Enter a value (1-7): 1

Enter a value: 150
Converted value: 1.50 m

Would you like to convert another value ? (y/n):
```

## Project structure

```
.
├── include/
│   └── convert.h       # Quantity and UnitSystem classes
├── src/
│   └── main.cpp        # Entry point and input handling
└── CMakeLists.txt
```
