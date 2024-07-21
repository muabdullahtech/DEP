#include <iostream>
#include <fstream>
#include <string>

// Function to compress the file content using Run-Length Encoding
std::string compress(const std::string& input) {
    std::string compressed;
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        compressed += input[i];
        compressed += std::to_string(count);
    }
    return compressed;
}

// Function to decompress the file content using Run-Length Encoding
std::string decompress(const std::string& input) {
    std::string decompressed;
    int n = input.length();

    for (int i = 0; i < n; i++) {
        char ch = input[i];
        i++;
        int count = 0;
        while (i < n && isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }
        i--;
        decompressed.append(count, ch);
    }
    return decompressed;
}

// Function to read the file content
std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        exit(1);
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

// Function to write content to a file
void writeFile(const std::string& fileName, const std::string& content) {
    std::ofstream file(fileName);
    if (!file) {
        std::cerr << "Unable to open file " << fileName << std::endl;
        exit(1);
    }

    file << content;
    file.close();
}

int main() {
    std::string inputFileName, outputFileName;
    char choice;

    std::cout << "Enter 'c' to compress or 'd' to decompress: ";
    std::cin >> choice;
    std::cout << "Enter the input file name: ";
    std::cin >> inputFileName;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFileName;

    std::string fileContent = readFile(inputFileName);
    std::string result;

    if (choice == 'c') {
        result = compress(fileContent);
    } else if (choice == 'd') {
        result = decompress(fileContent);
    } else {
        std::cerr << "Invalid choice" << std::endl;
        return 1;
    }

    writeFile(outputFileName, result);
    std::cout << "Operation completed successfully." << std::endl;

    return 0;
}
