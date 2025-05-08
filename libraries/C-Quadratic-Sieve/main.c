// This version of the factorization software (all files) is released into the public domain.
// The software is provided "as it" without any warranty, express or implied.

// The goal of the software is to factor integers (from the command line or a file), with no dependency.
// The manager performs trial divisions, checks whether numbers are perfect powers, tests their primality.
// For large numbers, the Quadratic Sieve is employed, and the output can be formatted as JSON or CSV.

#include "avl-trees.c"				// the binary search trees (originally a separate project)
#include "big-num.c"				// the 64+bit integers (originally a separate project)
#include "headers.h"				// the headers
#include "manager.c"				// the factorization manager and i/o utils
#include "basic-math.c"				// the math shortcuts and functions (math.h isn't used)
#include "64-bits-factorization.c"	// the factorization for small numbers (Pollard's Rho)
#include "quadratic-sieve.c"		// the Quadratic Sieve (essential part of this project)
#include "block-lanczos.c"			// the Lanczos Block algorithm (essential part of this project)

int main(int argc, const char *argv[]) {

	// Default state (the integer factorization software don't use global variables).
	state state = {0};

	// Random number generator consistent across platforms.
	state.params.rand.seed = 0x2236b69a7d223bd;

	// The software is silent when there is no terminal.
	state.params.tty = isatty(STDOUT_FILENO) != 0 ;
	state.params.verbose = state.params.tty;

	// Read the command line arguments.
	for (int i = 1; i < argc; ++i)
		if (!(i + 3 < argc && read_key_and_3_values(argv + i, &state) && (i += 3)))
			if (!(i + 2 < argc && read_key_and_2_values(argv + i, &state) && (i += 2)))
				if (!(i + 1 < argc && read_key_value(argv + i, &state) && ++i))
					if (!(validate_string_number(argv[i], &state) || read_flags(argv + i, &state)))
						fprintf(stderr, "%s: Unknown argument '%s'.\n", argv[0], (state.code = 2, argv[i]));

	state.params.rand.seed += !state.params.rand.seed; // Optional.

	if (state.params.help)
		print_help(argv[0]); // Option --help or -h was found.
	else if (state.code == 0 && *state.params.demand)
		generate_input_file(&state); // Generate a factorization demand.
	else if (state.code == 0 && prepare_file_descriptors(&state))
		process_multi(argc, argv, &state); // Process the request(s).
	else
		fprintf(stderr, "Use '--help' for more information about Factorization Software v2.0.0, released February 1, 2025.\n");

	return state.code;
}

// Compilation for Windows is done with "gcc -Wall -pedantic -O2 -std=c99 main.c -o factor.exe"
// Compilation for macOS is done with "clang -Wall -pedantic -O2 -std=c99 main.c -o factor"
// Compilation for Linux is done with "gcc -Wall -pedantic -O2 -std=c99 main.c -o factor"
// Usage: ./factor 51460938795049063955433175628971167803839994111348342302522016010379
