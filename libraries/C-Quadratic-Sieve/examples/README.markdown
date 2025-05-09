# Factoring with Examples

This repository contains examples for the factorization software implemented in C99.

### **Example 1: Factorizing a Single Number**  

#### **Description**  
This example shows how to factorize a single integer using the command line. It is the simplest use case, requiring only a single input number.  

#### **Command**  
```sh
./factor 19984426027
```

#### **Expected Output**  
```
Number: 19984426027
Factors: 2609 (prime), 7659803 (prime)
```

#### **Estimated Execution Time**  
- **Small numbers (< 10 digits)**: Instantaneous (< 1ms)  
- **Medium numbers (10-20 digits)**: A few milliseconds  
- **Larger numbers (20+ digits)**: May take several seconds, depending on system performance


### **Example 2: Batch Factorization with Formatted Output**  

#### **Description**  
This example demonstrates how to factorize multiple numbers at once using a CSV file for input and outputting the results in JSON format.  

#### **Step 1: Create a CSV File with Numbers**  
Save the following content into a file named `numbers.csv` :  
```csv
number
8724560842712761
1054113196579
16420344313080856219
```

#### **Step 2: Run the Factorization Command**  
```sh
./factor --input-file numbers.csv --output-file results.json --output-json
```

#### **Step 3: Expected Output (JSON Format)**  
The file `results.json` will contain:  
```json
[
    {
        "input": "8724560842712761",
        "factors": [
            {
                "num": "50350709",
                "power": 1,
                "prime": true
            },
            {
                "num": "173275829",
                "power": 1,
                "prime": true
            }
        ]
    },
    {
        "input": "1054113196579",
        "factors": [
            {
                "num": "574061",
                "power": 1,
                "prime": true
            },
            {
                "num": "1836239",
                "power": 1,
                "prime": true
            }
        ]
    },
    {
        "input": "16420344313080856219",
        "factors": [
            {
                "num": "2818298627",
                "power": 1,
                "prime": true
            },
            {
                "num": "5826332297",
                "power": 1,
                "prime": true
            }
        ]
    }
]
```

#### **Estimated Execution Time**  
- **Small numbers (< 40 digits)**: < 10ms per number  
- **Medium numbers (40-50 digits)**: ~50-500ms per number  
- **Larger numbers (50+ digits)**: Seconds to minutes depending on size  

[![JSON and CSV outputs](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/json-csv-outputs.yaml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/json-csv-outputs.yaml)

### **Example 3: Performance Testing with Verbose Mode**  

#### **Description**  
This example demonstrates how to measure factorization duration using the built-in sample generator and the `--verbose` flag.  

#### **Step 1: Generate Sample Numbers**  
The software includes a built-in number generator for testing. To generate sample numbers ranging from 160-bit to 170-bit :  
```sh
./factor --output-file samples.txt --demand 160 170
```
This will create a file `samples.txt` containing randomly generated numbers.  

#### **Step 2: Factorize with Verbose Output**  
```sh
./factor --input-file samples.txt --output-csv-extended --verbose
```

#### **Example Output**  
```
Input,Factors,Duration (s),Status
970828022003505936120432238511677690597589467441,862581166155627167535991;1125491791491710864140951,0.78,Complete
2086406388863752695965309556355652837229505631537,633752683273;975197319919;1786083708037;1890100011323,0.92,Complete
4280235387371318063459108170832613950507275975111,2636608609;2803158277;4712074321;7176059173;17126799919,0.88,Complete
6494633904271230836113631999988115181187309501817,12147540175903939;14959610428019507;35739300434784929,1.01,Complete
21930195429545742297464174971886987006885972983531,11812382252033213;27077271183173293;68564626561566659,1.30,Complete
29447134592470659234469395350520272018450188218679,3918570249540888276417937;7514765007956862825053767,1.00,Complete
64223711357857183154677810298142648753919754001437,6135804809;6309830291;10160051123;10871543317;15018241753,1.29,Complete
127115475310662894070375018892455085745914751989351,8611828128708078766995667;14760568071129443844657053,1.44,Complete
278609420101595761857371941567551084276952402596391,35604665702448649;56143657267766681;139376060256706439,1.38,Complete
389933227669568350926042901360705553769677628343139,53933569161841253;82014348625803199;88153841639766937,1.37,Complete
1398669393771812236968586666424604574890601703315653,33888282791642142309277129;41272949779466715194601757,1.52,Complete

The results are completely accurate and verified in 12.89 s.
```

#### **Estimated Execution Time**  
Higher `--verbose` levels provide more insights :
- **Verbose level 0 (`--verbose 0`)** → Just factorization, no other messages.  
- **Verbose level 1 (`--verbose 1`)** → Basic progress updates (the default).  
- **Verbose level 2 (`--verbose 2`)** → Status message with execution times.  
- **Verbose level 3 (`--verbose 3`)** → Maintenance messages for developers.
- **Verbose level 4 (`--verbose 4`)** → Full debug mode (Quadratic Sieve in-depth analysis).

#### **Notes**
- The factorization time will vary based on system performance and input size.
- Baseline benchmark measurements are available [here](../performance#performance-graphical-overview) for this software release.

### OEIS Data Processing for Factorization

To factorize the OEIS list of choice, Windows users should use **PowerShell**, while macOS and Linux users should use the **Terminal**.

#### Windows (PowerShell Script)
Run `Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope Process` to be able to proceed, then content of `oeis-factoring.ps1` file should be :
```powershell
$oeis = "002182" # Select the Highly composite numbers from OEIS
$url = "https://oeis.org/A$oeis/b$oeis.txt"
$output = "oeis-$oeis.txt"

# Download the file
Invoke-WebRequest -Uri $url -OutFile "oeis-raw.txt"

# Prune the file
Get-Content "oeis-raw.txt" | ForEach-Object {
    if ($_ -match "^\s*\d+\s+(\S+)") { $matches[1] }
} | Set-Content $output

Write-Host "The file is ready for factoring at $output"
```

#### macOS (Bash Script)
Run `chmod 0700 oeis-factoring.sh` after creating the file `oeis-factoring.sh` with :
```bash
#!/bin/bash

oeis="002182" # Select the Highly composite numbers from OEIS
url="https://oeis.org/A$oeis/b$oeis.txt"
output="oeis-$oeis.txt"

# Download the file
curl -s "$url" -o "oeis-raw.txt"

# Prune the file
awk '{if ($1 ~ /^[0-9]+$/) print $2}' oeis-raw.txt > "$output"

echo "The file is ready for factoring at $output"
```

#### Linux (Bash Script)
Run `chmod 0700 oeis-factoring.sh` after creating the file `oeis-factoring.sh` with :
```bash
#!/bin/bash

oeis="002182" # Select the Highly composite numbers from OEIS
url="https://oeis.org/A$oeis/b$oeis.txt"
output="oeis-$oeis.txt"

# Download the file
wget -q "$url" -O "oeis-raw.txt"

# Prune the file
awk '{if ($1 ~ /^[0-9]+$/) print $2}' oeis-raw.txt > "$output"

echo "The file is ready for factoring at $output"
```

#### Usage
- Navigate to the directory containing the script using the `cd` command.
- Execute the script using `.\oeis-factoring.ps1` (Windows) or `./oeis-factoring.sh` (macOS and Linux).
- Once downloaded, use the factorization tool with `./factor --input-file oeis-002182.txt --output-csv --verbose 2`.
- This will factorize the entire dataset from OEIS and output the results in CSV format.

As a workflow : [![Factorize OEIS Sequences 1](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/factorize-oeis-1.yaml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/factorize-oeis-1.yaml) [![Factorize OEIS Sequences 2](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/factorize-oeis-2.yaml/badge.svg)](https://github.com/michel-leonard/C-Quadratic-Sieve/actions/workflows/factorize-oeis-2.yaml)

#### A Playground for Factorization Tests

Since every number is worth factoring, you can explore the **OEIS** dataset to [evaluate](../performance#factorization-software-performance-logs) the factorization tool.

|OEIS ID|Number of entries|Factorization duration|
|:--:|:--:|:--:|
|[005575](https://oeis.org/A005575/b005575.txt)|898|25 s|
|[002559](https://oeis.org/A002559/b002559.txt)|1000|23 s|
|[005709](https://oeis.org/A005709/b005709.txt)|495|21 s|
|[001270](https://oeis.org/A001270/b001270.txt)|1248|15 s|
|[002590](https://oeis.org/A002590/b002590.txt)|274|14 s|
|[005710](https://oeis.org/A005710/b005710.txt)|494|13 s|
|[002779](https://oeis.org/A002779/b002779.txt)|941|11 s|
|[001611](https://oeis.org/A001611/b001611.txt)|250|9 s|
|[004534](https://oeis.org/A004534/b004534.txt)|5000|8 s|
|[000585](https://oeis.org/A000585/b000585.txt)|8|6 s|
|[003424](https://oeis.org/A003424/b003424.txt)|4738|3 s|
|[003381](https://oeis.org/A003381/b003381.txt)|8000|2 s|

A [Bash script](../.github/workflows/scripts/oeis-automatic.sh) is available to make this factorization task interactive during **15 minutes** on Linux.
