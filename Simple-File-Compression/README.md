# File Compression and Decompression using Run-Length Encoding

This C++ program provides functionality to compress and decompress files using Run-Length Encoding (RLE). It reads the content of an input file, processes the content according to the chosen operation (compression or decompression), and writes the result to an output file.

## Features

- **Compression**: Converts the input file content into a compressed format using Run-Length Encoding.
- **Decompression**: Converts the compressed file content back to its original form.
- **File I/O**: Reads from and writes to files specified by the user.

## Requirements

- C++ compiler

## Usage

1. **Compile the program**:
    ```sh
    g++ -o file_compressor main.cpp
    ```

2. **Run the program**:
    ```sh
    ./file_compressor
    ```

3. **Follow the prompts**:
    - Enter 'c' to compress or 'd' to decompress.
    - Enter the input file name.
    - Enter the output file name.

## Example

### Compress a file

Suppose `example.txt` contains:
```
aaabbbbcc
```
Run the program and choose to compress:
```
Enter 'c' to compress or 'd' to decompress: c
Enter the input file name: example.txt
Enter the output file name: compressed.txt
```

The `compressed.txt` file will contain:
```
a3b4c2
```

### Decompress a file

Suppose `compressed.txt` contains:
```
a3b4c2
```
Run the program and choose to decompress:
```
Enter 'c' to compress or 'd' to decompress: d
Enter the input file name: compressed.txt
Enter the output file name: decompressed.txt
```

The `decompressed.txt` file will contain:
```
aaabbbbcc
```

## Code Overview

- **compress**: Compresses the file content using Run-Length Encoding.
- **decompress**: Decompresses the file content from Run-Length Encoding.
- **readFile**: Reads the content of a file and returns it as a string.
- **writeFile**: Writes a string to a specified file.
