# Factorization software using Quadratic Sieve

This **general-purpose integer factorization software** is released into the public domain. It is provided "as is" without any warranty, express or implied.

## Status

Ready to be deployed in production environments as a single-threaded stateless factorizer.

## Version

This document describes the factorization software v2.0.0, which was released on 1 February 2025.

## The Classic C99 Implementation

- is immediately compatible with Microsoft Windows, macOS and Linux.
- is thread-safe and simply has no dependencies, not even `math.h`.
- uses Pollard's Rho algorithm for factoring 64-bit integers.
- uses it's own Big Number library for handling large numbers.
- includes a **Self-Initializing Quadratic Sieve** (SIQS) which employs the Block Lanczos algorithm.
- uses AVL trees to assist the Quadratic Sieve in data management.
- reads from files or the command line, and writes to stdout or a file.
- is capable of batch factoring numbers with JSON or CSV formats.
- has a testing feature and produces reproducible results.

Enjoy mathematics applied to software, and factor all numbers up to 50 digits, 75 digits and [more](#speed-of-the-factorizer).

## Table of Contents

- [Get Started](#get-started)
  - [Running the Software](#running-the-software)
- [Command Line Options](#command-line-options)
- [Quadratic Sieve parameters](#quadratic-sieve-parameters)
- [Speed of the Factorizer](#speed-of-the-factorizer)
  - [Default Target Performance](#default-target-performance)
  - [Demonstrated Performance](#demonstrated-performance)
- [Batch processing](#batch-processing)
  - [Example with the command line](#example-with-the-command-line)
  - [Example with files](#example-with-files)
- [Testing the Software](#testing-the-software)
  - [Examples with the built-in generator](#examples-with-the-built-in-generator)
  - [Examples on Linux](#examples-on-linux)
    - [Example to search for maintenance cases](#example-to-search-for-maintenance-cases)
    - [Example to follow a long factorization](#example-to-follow-a-long-factorization)
    - [Example with Valgrind](#example-with-valgrind)
  - [Simulate Factorization Demands](#simulate-factorization-demands)
- [The Factorization Manager](#the-factorization-manager)
  - [Mathematical Verification](#mathematical-verification)
- [Memory Management](#memory-management)
  - [Troubleshooting](#troubleshooting)
- [Libraries](#libraries)
  - [AVL Binary Search Trees](#avl-binary-search-trees)
  - [Big Numbers](#big-numbers)
  - [Block Lanczos](#block-lanczos)
- [Project Files](#project-files)
  - [Computational Reproducibility](#computational-reproducibility)
- [The file quadratic-sieve.c](#the-file-quadratic-sievec)
  - [preparation_part_1](#preparation_part_1)
  - [preparation_part_2 .. 3](#preparation_part_2--3)
  - [qs_parametrize, preparation_part_4](#qs_parametrize-preparation_part_4)
  - [preparation_part_5 .. 6](#preparation_part_5--6)
  - [Polynomial `AX^2 + 2BX + C` coefficients](#polynomial-ax2--2bx--c-coefficients)
  - [get_started_iteration](#get_started_iteration)
  - [iteration_part_1](#iteration_part_1)
  - [iteration_part_2 .. 3](#iteration_part_2--3)
  - [iteration_part_4 .. 5](#iteration_part_4--5)
  - [iteration_part_6](#iteration_part_6)
  - [iteration_part_7 .. 8](#iteration_part_7--8)
  - [register_relations](#register_relations)
    - [Single Large-Prime Variation](#single-large-prime-variation)
  - [inner_continuation_condition](#inner_continuation_condition)
  - [block_lanczos](#block_lanczos)
  - [finalization_part_1](#finalization_part_1)
  - [qs_register_divisor](#qs_register_divisor)
  - [outer_continuation_condition](#outer_continuation_condition)
  - [finalization_part_2](#finalization_part_2)
- [For most programming languages](#for-most-programming-languages)
- [Online Tools](#online-tools)
- [Interactions](#interactions)
  - [Thank You](#thank-you)
  - [Discussions](#discussions)
  - [Any issue ?](#any-issue-)

## Get Started

[![Cross-platform software](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/cross-platform.yaml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/cross-platform.yaml)

Windows users can download the provided `factor.exe` file for convenience, navigate to its folder as shown below, and proceed with factorization.  

Otherwise, to build the executable, macOS and Linux users should use the **Terminal**, while Windows users should use **PowerShell**. The procedure takes just a few minutes :

1. Open a Terminal or PowerShell.  
2. Navigate to the directory containing the source code using the `cd` command.  
3. Compile the software using the command `gcc -Wall -pedantic -O2 -std=c99 main.c -o factor`.
   
If `gcc` is not installed on Windows, you can install [MinGW](https://winlibs.com/), which provides it. Then, simply replace `factor` with `factor.exe` in the command above.
  
- **macOS users**: Replace `gcc` with `clang`, which acts the same and is available natively.
- **Linux users**: Install `gcc` with `sudo apt update && sudo apt install gcc`.  

### Running the Software  

Compilation takes a few seconds, then you can start the factorizations :
- **Windows**: `./factor.exe 2840222005804112554242019945562782034485263657432907`
- **macOS** and **Linux**: `./factor 2840222005804112554242019945562782034485263657432907`

The software will quickly display the factors in the default format :  
```
Number: 2840222005804112554242019945562782034485263657432907
Factors: 186565459987 (prime), 123384476380949634131^2
```

[Back to TOC](#table-of-contents)

## Command Line Options

These options are designed to facilitate the interaction with the software :

| Name | Short | Goal | Example |
|:---:|:---:|:---:|---|
| `--help` | `-h` | Print the help. | `-h` |
| `--input-file` | `-i` | Factor the entire file. | `-i input.txt` |
| `--output-file` | `-o` | Write results to a file. | `-o output.txt` |
| `--output-json` | `-j` | Format results as JSON. | `-j` |
| `--output-json-extended` | `-J` | Format the results as JSON with details on the duration and completeness of each factorization. | `-J` (uppercase) |
| `--output-csv` | `-c` | Format results as CSV. | `-c` |
| `--output-csv-extended` | `-C` | Format the results as CSV with details on the duration and completeness of each factorization. | `-C` (uppercase) |
| `--verbose` | `-v` | Show more or less details, `1` for task progress, `2` for status message, `3` for maintenance messages, `4` for detailed information. The default is `1` when you have a terminal, `0` otherwise.| • `-v 0` <br>• `-v 1` <br>• `-v 2` <br>• `-v 3` <br>• `-v 4` |
| `--force` | `-f` | Overrides the limits at which the software refuses to factor: 8,191 digits for a number and 220-bit for the Quadratic Sieve. | `-f` |
| `--timeout` | `-t` | Interrupt the Quadratic Sieve after a specified duration in seconds. | `-t 1` |
| `--rand-seed` | `-r` | Specify a custom (64-bit) XorShift seed value. This option always provides a new seed value when `0` is specified. | • `-r 0`<br>• `-r 123` |
| `--demand` | `-d` | Designed for testing, this option creates a suitable input file named `demand.txt`, containing non-trivial sample numbers. Its parameters, all optional, are `-d <bits-min> <bits-max> <count>`. | • `-d` <br>• `-d 220` <br>• `-d 120 170` <br>• `-d 16 64 2000` |

Run `./factor --help` to display the built-in manual.

[Back to TOC](#table-of-contents)

## Quadratic Sieve parameters

The Quadratic Sieve accepts custom parameters to override the default ones :

|Quadratic Sieve option|Typical range of values and goal|
|--|--|
|`--qs-multiplier <value>`|From `1` to `150`, test a multiplier intended to optimize runtime and factorization success.|
|`--qs-base-size <value>`|From `1000` to `50000`, test a factor base size.|
|`--qs-large-prime <value>`|From `300000` to `30000000`, test a limit for the partial relations collection.|
|`--qs-alloc-mb <value>`|From `1` to a few hundred, test a memory allocation in Megabytes.|
|`--qs-sieve <value>`|With `31744` as a default value, test a half sieve size.|
|`--qs-threshold <value>`|From `60` to `110`, test a compromise between rejecting good relations and checking unusable ones.|
|`--qs-error-bits <value>`|From `15` to `35`, test a tolerance for small errors (due to approximations of logarithms) in the smoothness test during relations collection.|
|`--qs-laziness <value>`|From `80` to `120`, test a percentage for collecting more/fewer relations than recommended.|

These technical parameters can be used to review the software configuration, manually or even automatically. Developers can [browse](quadratic-sieve.c#L83) the source to see their implementation, and users have `--verbose 4` to trace.

[Back to TOC](#table-of-contents)

## Speed of the Factorizer

The software is designed to be a **general-purpose factorizer** for integers, also supporting negative numbers. Featuring an algorithm that handles large numbers (e.g. a highly composite 1500-bit number or 10,000!), its performance varies mainly depending on the structure of the number.

### Default Target Performance

The software deploying a Quadratic Sieve is evaluated according to the RSA integers :

|Number of bits|Number of decimal digits|Factorization duration|
|:--:|:--:|:--:|
|100|31|50 milliseconds|
|150|46|250 milliseconds|
|200|68|7 seconds|
|250|75|5 minutes|
|300|91|2 hours|

[Visualize](performance#performance-graphical-overview) runtime variations across different bit sizes recorded during software development, and notice that each additional 10 bits (or 3 decimal digits) in the input number approximately doubles the factorization time.

### Demonstrated Performance
  - [Successfully](https://github.com/michel-leonard/C-Quadratic-Sieve/discussions/8#discussion-7939649) factors RSA numbers greater than 300 bits.
  - Factored the **321-bit RSA** number related to the [bank card case](https://www.enseignement.polytechnique.fr/profs/informatique/Eric.Goubault/Cours09/qs.pdf).
  - Factored RSA-100, a 330-bit number.

> [!NOTE]
> RSA numbers are integers having exactly two prime factors of comparable size; these factors are carefully selected for their resistance to pre-quantum factorization attempts.

[Back to TOC](#table-of-contents)

## Batch processing

The software can factor multiple numbers in a row at no extra cost, either from the command line or from a file.

### Example with the command line

```sh
./factor 20 21 22 23
```

### Example with files

Contents of the file `example.csv` :
```sh
number
20
21
22
23
```

Command to quietly generate the `example-factored.json` file :
```sh
./factor --input-file "example.csv" --output-file "example-factored.json" --verbose 0 --output-json
```

Additionally, the **idempotence** of the software ensures that CSV output files are also valid input files.

[Back to TOC](#table-of-contents)

## Testing the Software

The software has been extensively tested during its preparation and has a **production ready** status. The built-in generator, consistent across all platforms, produces reproducible samples in a `demand.txt` file. This feature is designed to perform targeted and automated factorization testing.

- See [Mathematical Verification](#mathematical-verification) for details about assumptions made by the factorization manager.
- The software returns an exit code of `0` if and only if the results are completely accurate and verified.
- A verbosity level of `2` or higher explicitly indicates whether the results are completely accurate and verified.

### Examples with the built-in generator

Example of a test command that factors 10 numbers of 150-bit based on seed `1`, taking a few seconds :
```sh
./factor --demand 150 150 10 --rand-seed 1
./factor -i demand.txt -c -v 3
```

Example of a verbose test command that factors `1392602085554410049903335201603514917187205908900868592635698356747`, a 220-bit number in 20 seconds :
```sh
./factor --demand 220
./factor -i demand.txt -v 4
```

Example of a test command that factors sample numbers ranging from 120-bit to 170-bit, taking 20 seconds :
```sh
./factor --demand 120 170
./factor -i demand.txt -C -v 3
```

Example of a test command that factors traditional integers ranging from 16-bit to 64-bit, taking 20 seconds :
```sh
./factor --demand 16 64 2000 --rand-seed 1
./factor -i demand.txt -c -v 3
```

Example of a test command that shows in one minute that the Quadratic Sieve is likely to select a multiplier that fits better than 1 (meaning no multiplier), which speeds up the average execution time by a factor of 2 :
```sh
./factor --demand 170 170 10
./factor -v 3 -c -i demand.txt
./factor -v 3 -c -i demand.txt --qs-multiplier 1
```

Example of the test command that generated the provided sample `.csv` and `.json` files, an operation that took 11 minutes per file on the evaluation machine :
```sh
./factor --demand --output-file example.txt
./factor --input-file example.txt --output-file example-result.csv --output-csv
./factor --input-file example.txt --output-file example-result.json --output-json
```

### Examples on Linux

The use cases here are for Ubuntu, tools like `valgrind` and `wget` are not available in the same way on Windows.

#### Example to search for maintenance cases
Example of a test command that logs both outputs to a file for later analysis, taking 10 seconds :
```sh
./factor --demand 50 150 --rand-seed 1
./factor --input-file demand.txt --output-csv --verbose 3 > maintenance.log 2>&1
# Perform a basic search for numbers showing debugs
grep -FA 1 Maintenance maintenance.log
```

#### Example to follow a long factorization
Example of a test command that follows a long factorization in the background, taking 2 minutes :
```sh
./factor --demand 240
nohup ./factor --input-file demand.txt --force --verbose 4 &
# Press ENTER, then track data added as the file grows
tail --follow nohup.out
```

#### Example with Valgrind
Example of a command that checks using [valgrind](https://valgrind.org/) if the memory is well freed :
```sh
./factor --demand 50 150
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./factor -i demand.txt -c -v 3
```

This cleanliness should apply to any use case, like the one above which after a few minutes shows :

```
HEAP SUMMARY:
   in use at exit: 0 bytes in 0 blocks
 total heap usage: 107 allocs, 107 frees, 101,104,453 bytes allocated
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### Simulate Factorization Demands

Your suggestions for tests in case of challenge are welcome, in this section users can easily :
- update the `--demand <bits-min> <bits-max> <count>`.
- update the `--rand-seed <value>` (or explicitly leave it at `0` to choose the Unix timestamp).

This allows the software to be directed in various testing situations.

[![Factorize small numbers](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/small-numbers.yml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/small-numbers.yml) [![Factorize medium-sized numbers](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/medium-sized-numbers.yml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/medium-sized-numbers.yml) [![Factorize large numbers](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/large-numbers.yml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/large-numbers.yml)

[Back to TOC](#table-of-contents)

## The Factorization Manager

Before starting, the input integers are parsed; if an error is detected, the factorization will not start and users will be notified via standard error. Note that `0` is an erroneous input because the factorization of zero is undefined.

The Factorization Manager, in order :
- prepares in [memory](#memory-management) a lightweight and reusable structure suitable for all tasks.
- performs preliminary checks (e.g. trial division, perfect power) before invoking the algorithms.
- factorize (recursively if necessary) each number by coordinating the available algorithms.
- writes each factorization result in the desired format (CSV, JSON) either to the terminal or to a file.
- interprets the exit code while displaying the factorization duration when `--verbose <value>` is `2` or higher.
- returns an exit code of `0` when the results are completely accurate and verified, non-zero otherwise.

### Mathematical Verification

An exit code of `0` indicates that *the results are completely accurate and verified*. This means that :
- the product of the factors is equal to the factored number, with verification performed for each number.
- all numbers have been fully factored using a [good confiance level](big-num.c#L727) when testing for primality.

Only correct results are displayed, the software does mathematical double-checks at the risk of fatal error.

[Back to TOC](#table-of-contents)

## Memory Management

Memory allocations are passed to `assert`, in case of memory allocation errors (e.g. insufficient memory available) the software will exit with a specific message, and it is recommended to restart your device.

- The [manager](#the-factorization-manager) allocates a few memory (a structure/session) based on the largest number.
- The Quadratic Sieve manages its memory independently, based on its input bit size.
- The Block Lanczos algorithm transparently takes memory over the Quadratic Sieve.
- Memory used by the Quadratic Sieve is freed as soon as it has completed.
- The manager reuse its session, freed when all factorizations are done.
- Valgrind was used to check for memory leaks, no leaks were found.

| Commonly required memory | Purpose |
|:---:|:---:|
|15 Kilobytes|complete a common 64-bit factorization|
|150 Kilobytes|complete a highly composite number factorization|
|2 Megabytes|complete a 150-bit Quadratic Sieve|
|10 Megabytes|complete a 175-bit Quadratic Sieve|
|25 Megabytes|complete a 200-bit Quadratic Sieve|
|25 Megabytes extra|for every 25 extra bits subjected to the Quadratic Sieve|

### Troubleshooting

Memory problem troubleshooting tips are :
- make the Quadratic Sieve verbose with `--verbose 4`.
- choose a new multiplier for the Quadratic Sieve with `--qs-multiplier <value>`.
- choose a new seed for the random number generator with `--rand-seed <value>`.
- raise an issue on GitHub to get an investigation and a fix in the source code.

[Back to TOC](#table-of-contents)

## Libraries

The software consists of the assembly of 3 projects ([AVL](https://github.com/michel-leonard/AVL-trees-C), [cint](https://github.com/michel-leonard/C-integers), Quadratic Sieve with Block Lanczos).

### AVL Binary Search Trees

The `avl` functions (released "as is", into the public domain, without any warranty, express or implied) manage thousands of integers in AVL trees, making Quadratic Sieve relations storage and retrieval straightforward. This solution guarantees worst-case `O(log n)` time complexity for all operations (search, insert, delete).

[Back to TOC](#table-of-contents)

### Big Numbers

The `cint` library (released "as is", into the public domain, without any warranty, express or implied) is provided for handling large integers. It includes a variety of basic and advanced mathematical functions to support calculations. This solution used to operate the Quadratic Sieve does not use global variables, it's stateless and thread-safe.

[Back to TOC](#table-of-contents)

### Block Lanczos

The Block Lanczos algorithm (released "as is", into the public domain, without any warranty, express or implied) solve a large, sparse system of linear equations, and identify dependencies among the rows of the matrix formed by the smooth relations collected by the Quadratic Sieve. This self-managing solution is necessary so that, through a method similar to Fermat's, the Quadratic Sieve can exploit a congruence of squares that leads to a factorization of **N**.

[Back to TOC](#table-of-contents)

## Project Files

The software's source code is organized into the following files :

| Filename                | Purpose                                                                                                               |
|-------------------------|-----------------------------------------------------------------------------------------------------------------------|
| `64-bits-factorization.c` | Contains functions for factoring classical integers, including Pollard's Rho algorithm and a [deterministic ](64-bits-factorization.c#L26) Miller-Rabin primality checker. |
| `avl-trees.c`           | Contains the AVL Trees functions, originally a separate project from the integer factorization project.               |
| `basic-math.c`          | Includes a prime number generator capable of yielding the first 326,983 prime numbers, along with the Kronecker symbol function, Tonelli-Shanks function, and modular inverse function. |
| `big-num.c`             | Contains the `cint` library, also initially a separate project from the integer factorization project.               |
| `block-lanczos.c`       | Provides the linear algebra part of the Quadratic Sieve, including a matrix reducer and a manager for this task.     |
| `headers.h`             | Contains definitions for types, structures, functions, and `DEBUG` macros used throughout the project.               |
| `main.c`                | Contains the program's entry point and transfers control to the factorization manager after about 30 lines.          |
| `manager.c`             | Includes I/O functions (parser, formatter), help documentation, shortcuts used by Quadratic Sieve, a sample data generator used for testing, and the factorization manager. |
| `quadratic-sieve.c`     | Contains the Quadratic Sieve implementation, divided into around thirty functions, with a main function that manages the factorization process in about 30 lines. Search for "debug" in this file to find the debugging elements displayed. |

### Computational Reproducibility

The reproducibility of the calculations makes them easier to verify and understand by users, for this purpose the [XorShift](https://www.jstatsoft.org/article/view/v008i14/916) generator is [implemented](basic-math.c#L1), with a distribution that can be changed at runtime using `--rand-seed <value>`.

The software :
- is single-threaded and thread-safe (no global variables are used).
- does not retain any state from one factorization to another (stateless architecture).
- produces reproducible results regardless of the order in which the factorizations are batched.
- includes [log files](performance#factorization-software-performance-logs) from its development phase, which contain reproducible calculations.

[Back to TOC](#table-of-contents)

## The file quadratic-sieve.c

The Self-Initializing Quadratic Sieve (SIQS) is a fast algorithm for factoring large semiprimes, based on the Multiple Polynomial Quadratic Sieve (MPQS). A suitable structure for this implementation was chosen as follows :

- the ~40 lines function that allows to see the algorithm **structure**.
- the 2 important loop **conditions**.
- the algorithm **parameters**.
- the **functions** approximately in the order they are called.

[Back to TOC](#table-of-contents)

### preparation_part_1

Handshake between the Quadratic Sieve and the factorization manager, during which it appropriates resources.

[Back to TOC](#table-of-contents)

### preparation_part_2 .. 3

The input **N** is duplicated and called "**kN**" after this function complete. The algorithm :

- operates on numbers larger than 115 bits and may multiply **N** by a prime to reach this size.
- applies a multiplier to **N**, a small constant in `[1, 127]` that improves runtime and **memory efficiency**.

To find a good multiplier `k` such that **kN** factor easier, the `preparation_part_3_default_proposition` function try values of `k` such that **kN** is a square modulo a large number of small primes. These primes will then be factor base primes, and the more small factor base primes, the faster relations will accumulate, since they hit the sieving interval more often. A `preparation_part_3_alternative_proposition` is also provided for further investigation purposes.
 
| Variable | Information |
|:----------:|:-------------:|
| **N** | Prime factors are removed from **N**, and **N** is updated until `N = 1`. |
| **kN** | The algorithm computes with **kN**, which remains constant. |

See how multipliers impact the execution of `./factor 10146246660331135529849066552891483667878618078493758287` :

| Option used | Makes the algorithm factoring | Comment on the multiplier | Took |
|:---:|:---:|:---:|:---:|
|`--qs-multiplier 7`| `kN` = `7` * `N`|**Selected by the algorithm**|3.1 s|
|`--qs-multiplier 1`| `kN` = `1` * `N`|No multiplier|6.3 s|
|`--qs-multiplier 113`| `kN` = `113` * `N`|Large multipliers are sometimes good|8.2 s|
|`--qs-multiplier 29`| `kN` = `29` * `N`|One of the worst|19.4 s|
|`--qs-multiplier 35`| `kN` = `35` * `N`|One of the worst|26.3 s|

> [!IMPORTANT]
> If a factorization seems longer than normal, use the `--verbose 4` option to see the proposed multipliers and try combining them with `--qs-multiplier <value>` to accelerate the process using the correct one. The proposed method finds a balance that improves the average runtime by a factor 2. The Quadratic Sieve best multiplier (known as Knuth-Schroeppel) can be up to **10 times faster** than the worst in addition to saving a lot of [memory](#troubleshooting).

[Back to TOC](#table-of-contents)

### qs_parametrize, preparation_part_4

*Correct parameter setting improves factorization speed.*

- Define the parameters of the algorithm based on the size of **N** in bits.
- Allocates a block of memory for the Quadratic Sieve computations.
- Prepare constants, variables, buffers, data arrays, all in a structure named **qs_sheet**.

There is a nested structure inside the **qs_sheet** called **mem** :

- it holds the **mem.base** pointer to the beginning of allocated memory.
- it holds a **mem.now** void* pointer which is relative to **mem.base** and represents the remaining memory.
  
**qs_sheet** holds 3 AVL tree manager :

- one to store the full (smooth) relations.
- one to store partial relations awaiting pairing (single large-prime variation).
- one to store the known divisors of **N**.

**Note for users**: it is possible to override the value of [algorithm parameters](#quadratic-sieve-parameters) at runtime for investigation or troubleshooting purposes. Users comments and analysis are welcome in the discussion.

**Note for developers**: the void* **mem.now** pointer can be used like a `calloc`, just update its value after storing something, or zero out the memory without updating in case of temporary needs. This technique is used all over the Quadratic Sieve (and in its Block Lanczos algorithm).

[Back to TOC](#table-of-contents)

### preparation_part_5 .. 6

Constructs the factor base by filling the **base** array with suitable prime numbers :
- verify that **kN** is a square mod prime, ignore it otherwise.
- associates the prime with square root of **kN** mod prime.
- associates the prime with its size (rounded logarithm to base 2).
  
Computes **D** the optimal value of the hypercube, later used to generate the polynomial coefficient **A**.

[Back to TOC](#table-of-contents)

### Polynomial `AX^2 + 2BX + C` coefficients

The next steps are to efficiently construct several polynomials, along with their resolution data, suitable for sieving.

| Coefficient | is a constant after  | is a constant until|
|:---:|:---:|:---:|
| **A** | `iteration_part_1` |`inner_continuation_condition` completion
| **B** | `iteration_part_4` |for loop final expression
| **C** | `iteration_part_6` |for loop final expression

> [!NOTE]
> A custom `--rand-seed <value>`produces another set of polynomial curves that affects the Quadratic Sieve solving procedure, this should not improve speed, but may be useful for debugging or testing.

[Back to TOC](#table-of-contents)

### get_started_iteration

This small utility function is not more mathematical than technical, it :
- can restore relations that were discarded to (unsuccessfully) proceed linear algebra with Block Lanczos.
- performs analysis, and can be used to save/restore factorization to file or other periodic actions.

[Back to TOC](#table-of-contents)

### iteration_part_1

Produces the coefficient **A** using the random number generator across the factor base to construct a product that approach the ideal value **D**. The algorithm always works (due to the fairly large factor base, and the quality of the PRNG) with distinct values ​​of **A**, this is required. 

[Back to TOC](#table-of-contents)

### iteration_part_2 .. 3

Produces a template for the **B** coefficient alongside the data for polynomials that depend only on **A** and the factor base primes (and not on the current **B** coefficient). This data is later used to generate polynomial values ​​which will be multiples of the factor base.

[Back to TOC](#table-of-contents)

### iteration_part_4 .. 5

Since SIQS is based on MPQS, the polynomial curves are iteratively materialized using a Gray code. The coefficient **B** is produced using this technique through the previously prepared data. The algorithm also calculates the sieve offset for all the factor base prime. The generated values ​​of **B** as well as the values ​​of **A** are always distinct.

[Back to TOC](#table-of-contents)

### iteration_part_6

Produce the coefficient **C** as `C = (B * B - kN) / A`. Because the previous steps went well, division never has a remainder, that's all it takes to be ready for sieving.

[Back to TOC](#table-of-contents)

### iteration_part_7 .. 8

These steps concern the sieving process itself. The sieve is named **M**, and filling the sieve consists of taking an interval `[−M/2, +M/2]` and efficiency determining for which **X** in `[−M/2, +M/2]` a given prime number divides `AX^2 + 2BX + C`. To achieve this task the resolution data produced between `iteration_part_3` and `iteration_part_6` is used.

The sieve phase dominates the run time of the algorithm; it takes most of the time when **N** becomes large.

[Back to TOC](#table-of-contents)

### register_relations

This function evaluates the previously filled sieve to find relations, iterates over values ​​of **X** in `[-M/2, +M/2]` and beyond a threshold, computes `f(X)` to check the regularity of the candidate. When the function finds interesting to define the variable **X** , calculates the value of the polynomial in **X** then divides the value with the factor base, it thus tries to establish relations. The assertion `(A * X + B)^2 = A * f(X) + kN` remains valid when this operation begins.

Buffered knowledge is then structured by `register_regular_relation` and `register_partial_relation` :
- `register_regular_relation` immediately build a matrix of regular smooth `qs_relation*` using AVL tree.
- `register_partial_relation` combine partial `qs_relation*` together using AVL tree (single large-prime variation).

The AVL tree is used in `register_partial_relation` to identify partial relations sharing the same variation (within the last prime cofactors), to retrieve the data associated with this cycle and to process the single large-prime variation.

#### Single Large-Prime Variation

*In short: when the sieve reports two partial relations sharing the same large prime, the `register_partial_relation` function merges them (with a minor loss of efficiency) to obtain a regular smooth relation.*

During the execution of `register_relations`, after trial division by the factor base primes, if the quotient remains greater than 1 but is less than the large prime bound, the software uses `register_partial_relation` to save this interesting **1-partial relation** in a separate location from full (smooth) relations.

Any two partial relations that share the same variation together yield a suitable smooth relation. So, when the large prime collected matches a prime from another **1-partial relation** (detected via the AVL tree), the software **combines these two relations** and then passes the result to `register_regular_relation`, which saves all regular relations. 

As shown below, the single large-prime variation often speeds things up by a factor of 2.

|N bits| Relations added regularly | Relations added by Single Large-Prime Variation | Relations needs
|:---:|:---:|:---:|:---:|
| 150 | 2551 | 3| 2554
| 170 | 3168 | 659 | 3827
| 190 | 3212 | 1786 | 4998
| 210 | 3409 | 3012 | 6421
| 230 | 5659 | 4686 | 10345
| 250 | 10051 | 9793 | 19844
| 270 | 14026 | 15484 | 29510
| 290 | 12820 | 20201 | 33021
| 310 | 22522 | 22488 | 45008

> [!NOTE]
> When a third match arrives, a dependency problem appears in linear algebra. This more complex case known as **Double Large-Prime Variation** is still an opportunity (at the cost of some non-trivial extra programming) to speed up difficult factorizations by another factor 2, but is not implemented in this simple version.

[Back to TOC](#table-of-contents)

### inner_continuation_condition

Decides whether the sieving continues or stops, the relation counter is the main condition.

- Continue means keeps randomly trying various polynomials through another `get_started_iteration`.
- Stop means let Block Lanczos examine the matrix formed by the relations to find its eigenvalues.

[Back to TOC](#table-of-contents)

### block_lanczos

The Block Lanczos algorithm is likely to quickly report the success of the Quadratic Sieve, just having to find in its smooth relations a subset of all the exponent vectors such that the sum of their exponent vectors is the zero vector :

- the process need memory, **block-lanczos.c** have its own array builder.
- all memory taken in **mem.now** is zeroed and reusable after calculations.
- finding the matrix eigenvalues is usually fast, it can still take 700+ iterations with large **N**.
- the algorithm is probabilistic with high success rate, generally it is lucky enough.

A built-in manager coordinates attempts and reduces the matrix formed by the **Y field of the relations** as necessary. The `reduce_matrix` function process is limited to removing columns that contain a singleton row, and then resizing the matrix to have a few more columns than rows. This step is not intended to speed up the algorithm (although it does); it is just that without it, there are factorizations for which the large-scale structural eigenproblem remains.

[Back to TOC](#table-of-contents)

### finalization_part_1

The `finalization_part_1` function performs the **square root + GCD** step of the Quadratic Sieve based on the `lanczos_block` answer, which classically leads by exploiting a difference of squares mod **N** to reveal divisors of **N**. The `qs_register_divisor` function it calls takes care of inferences that actually lead to a complete factorization of **N**.

[Back to TOC](#table-of-contents)

### qs_register_divisor

The `qs_register_divisor` function :
- performs checks (such as primality, perfect power and GCD between divisors).
- registers the prime factors of **N** to the factorization manager's routine.
- displays details about how it infers when `--verbose 4` is used.

[Back to TOC](#table-of-contents)

### outer_continuation_condition

This function is used to decide if the algorithm should return the control, or return to sieving.

- The normal case is to return the control, complete answer was found.
- An unusual case is when **N** is not fully factored (maybe the parameters were wrong).

> [!NOTE]
> When a prime factor has been found at this stage, the algorithm prefers to resign itself so that the manager can, with a better-sized Quadratic Sieve, continue the factorization of **N** recursively. Otherwise, before giving up the algorithm returns to `get_started_iteration` and searches for up to **50%** more relations.

[Back to TOC](#table-of-contents)

### finalization_part_2

The Quadratic Sieve algorithm gracefully resigns to the factorization manager.

[Back to TOC](#table-of-contents)

## For most programming languages

Users can set the software as a support tool in most languages. Here is an example for a PHP/JSON application :

```php
<?php

// We must factor an array of numbers.
$numbers = array(
	'32077677441073603974168813573464241602309',
	'-37591720365997281829030157222946707796343835483',
	'37235529565343195291273612090240230075203335881564807',
);

// We call the factorization software.
$result = '' ;
$fp = popen('./factor -j ' . implode(' ', $numbers), 'r');
 while(!feof($fp))
	$result .= fread($fp, 8192);
pclose($fp);

// We optionally decode the JSON string into a PHP array.
$result = json_decode($result, true) ;

// We use the results.
print_r($result);
```

[Back to TOC](#table-of-contents)

## Online Tools

- [Dario Alpern's Integer Factorization Calculator](https://www.alpertron.com.ar/ECM.HTM): This tool processes the factorization directly in the browser.
- [Number Empire Factoring Calculator](https://www.numberempire.com/factoringcalculator.php): This tool performs factorization on the server.

[Back to TOC](#table-of-contents)

## Interactions

This integer factorization software, whose source code is entirely in the **public domain**, is designed to help :
- reduce licensing costs and improve transparency and security.
- benefit from flexibility and interoperability.
- with teaching and research.
- in office automation.

### Thank You

There are many people to thank :

- Carl Pomerance
- Jason Papadopoulos
- [William Hart](https://flintlib.org/authors.html)
- my professors at University of Franche-Comté ❤️
- GitHub users building the community

### Discussions

GitHub users can exchange their views on this version or motivate a multi-threaded rewrite.

### Any issue ?

You can report any issues, and we'll investigate to correct the source files.

[Back to TOC](#table-of-contents)
