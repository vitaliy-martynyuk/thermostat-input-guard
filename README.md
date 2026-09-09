# Thermostat Input Guard

A small C++ console utility simulating a thermostat's input panel: it reads
a target temperature and a mode code, recovering gracefully from garbage
input rather than crashing or hanging, and caps the number of retries
before giving up.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 9: detecting and recovering from failed stream extraction, and the
distinction between user errors (bad input — recoverable, handled by
retrying) and programmer errors (broken invariants — guarded with
`assert`, documented as preconditions/postconditions). Earlier
fundamentals (multi-file structure, validation, named constants, loops)
are used as supporting scaffolding, not the focus.

## What it does

- Prompts for a target temperature and a mode code (`H`/`C`/`F`)
- Detects failed or partial extraction from `std::cin` — including
  non-numeric garbage and trailing leftover characters after a valid
  read — clears the stream, and discards the bad input before reprompting
- Validates the parsed value against the expected range/set, independent
  of whether extraction itself succeeded
- Caps the number of retry attempts with a `constexpr` limit, exiting with
  a clear message and a non-zero status if it's exceeded
- Converts a validated mode code into its display label, guarding the
  should-be-impossible case with `assert` rather than a silent fallback
- Prints a final configuration summary once both values are accepted

## Project structure

```
main.cpp                    // program entry point, orchestrates the flow
io/
  io.h / io.cpp             // reading raw input, printing errors/config,
                            // and stream-failure recovery (recoverFromInputError)
validate/
  validate.h                // isTemperatureValid() / isModeValid() — pure predicates
input/
  input.h                   // setTemperature() / setMode() — read+validate+retry loops
consts/
  consts.h                  // mode codes, mode labels, and the code->label lookup
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp io/io.cpp
```

Or open `Thermostat Input Guard.slnx` in Visual Studio.

## Running

```bash
./app
```

Example session:

```
Enter target temperature: abc
Invalid input. Please enter a number.
Enter target temperature: 68.5

Enter mode (H = Heat, C = Cool, F = Fan): x
Invalid mode. Please enter H, C, or F.
Enter mode (H = Heat, C = Cool, F = Fan): H

Target: 68.5 degrees
Mode: Heat

Thermostat set successfully.
```

## Notes

`io::helpers::recoverFromInputError()` checks both outright extraction
failure and leftover unconsumed characters after an otherwise successful
read (e.g. typing `68.5abc`), clearing and flushing the stream in either
case before the caller retries. `consts::getModeLabel()` documents its
precondition (`mode` must already be validated) as a comment and backs it
with `assert` — an invalid mode reaching that function is a programmer
error, not a user error, and is treated differently on purpose. Retry
loops in `input.h` exit via `std::exit(1)` after exceeding the attempt
cap, signaling failure to the calling environment rather than a false
success.