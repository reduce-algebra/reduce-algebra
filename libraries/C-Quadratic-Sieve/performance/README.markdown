# Factorization Software Performance Logs

This repository contains performance logs and related insights for the **Self-Initializing Quadratic Sieve (SIQS)** implemented in C99.

## Test Parameters

- **Number of test series:** 10
- **Bit range:** 30-bit to 260-bit numbers
- **Samples per series:** 231
- **Total factored samples:** 2310
- **Random seed:** 1 to 10
- **Verbose mode:** `--verbose 4`

## Purpose of Performance Logs

Log files are accessible to users and AIs involved in log-based optimization :

1. **Analysis of Factorization Performance**
   - Provides data for assessing execution times and efficiency across different bit sizes.
   
2. **Understanding Verbose Output**
   - Shows detailed data of factorization steps.
   - Includes maintenance messages and progress markers.
   - Beyond 220-bit numbers, displays `.` progress indicators (one per percentage point).

3. **Debugging and Maintenance**
   - Helps diagnose issues, optimize the factorization process, and contribute to the roadmap.

## Log Format

Each of the 10 log files corresponds to a test series and follows a structured format, looking like :

```
Pollard's Rho on 12704968156416643609 (64-bit).
- Recursively applying Pollard's Rho on 3456542582621 (42-bit).
Number: 12704968156416643609
Factors: 1599319 (prime), 2161259 (prime), 3675629 (prime)
Status: fully factored in 0.00 s
```
and, depending on whether the number is larger than 64-bit :
```
Quadratic Sieve on 274214221909627030485191027629589890383646061615642553769.
Suggested multipliers are [1, 41, 61, 13, 73, 33, 97].
Suggested multipliers are [1, 49, 9, 121, 25, 41, 94], so use 1.
N is a 188-bit number, and kN is a 188-bit number using 7 words.
The algorithm use the seed 0 and targets 7775 relations.
The iterative list contains 9, 1280, 2560 and 5120.
The single large-prime variation is being processed under 2882288.
Other params include sieve=63488, error_bits=21, threshold=76 and s=7.
The underlying calculations use 496-bit variables.
Allocated 13 MB of memory with a 1029 KB structure.
The factor base of 8016 suitable primes ends with 178037.
[x] Maintenance of linear algebra reduces the relations from 7782 to 5762.
Linear algebra passed on 4th attempt after 92 iterations.
- New divisor 24982208481367522431959043863 shown.
  - This prime factor reduces N to 94-bit.
  - And allows us for N to get 10976380335395255021697900863.
  - The factorization is complete since it's a prime.
The sieve reported 6530 partials which added 1062 smooth relations.
The algorithm completed with 3296 polynomials and 7782 relations.
Used 6 MB of memory during 4.63 second(s).
Number: 274214221909627030485191027629589890383646061615642553769
Factors: 10976380335395255021697900863 (prime), 24982208481367522431959043863 (prime)
Status: fully factored in 4.68 s
```

## Reproductibility

Adjust the `--rand-seed <value>` with the name of the provided files to reproduce the tests using :
```sh
./factor --demand 30 260 --rand-seed 1                    # Generate the samples
./factor --input-file demand.txt --verbose 4 --force      # Factorize
```

> [!WARNING]
> Full reproducibility (and resulting comparability) is not ensured, as it may depend on the software version.

## Performance Graphical Overview

The set of log files was sampled using Python to provide insight into execution times when **N** varies between 40 bits and 260 bits.

![The software factorize small numbers](images/factorization-duration-1.png)
![The software fFactorize medium numbers](images/factorization-duration-2.png)
![The software factorize large numbers](images/factorization-duration-3.png)
![The software factorize very large numbers](images/factorization-duration-4.png)

A logarithmic scale can be used to present the exponential relationship between **bit size** and **factorization duration** :

![Evolution of factorization durations between 120 bits ans 260 bits using a logarithmic scale](images/factorization-duration-equation.png)

> [!NOTE]
> The shown equation is `seconds = 8.92e-6 * 2.72 ** (6.98e-2 * bits)`. Numbers were processed by the software over weeks without difficulty, and the **275KB** log files available in this directory were each produced after **3 hours** of calculations on the test machine.

## Hardware

Michel Leonard's test machine ran various benchmarks to measure the software's performance in February 2025, with the following signature :
```
Linux 5.4.0-200-generic (Ubuntu 20.04.6 LTS)
Total disk space: 49G (ext4)
Total RAM: 1.9Gi RAM
Processor: DO-Regular, 1 cores, 2200 MHz
Virtualization: QEMU virtual machine (BIOS SeaBIOS rel-1.16.3)
```

## Discussions

Use GitHub [Discussions](https://github.com/michel-leonard/C-Quadratic-Sieve/discussions) to share your results and analyses.
