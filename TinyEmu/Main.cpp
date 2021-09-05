#include <fstream>
#include <iterator>
#include <vector>

#include <iostream>

#include "ElfHeader.h"
#include "PrintUtils.h"

int main() {
	const char* program = "C:\\Hacking\\Sandbox\\a.out";

    std::ifstream input(program, std::ios::binary);

    std::vector<char> bytes(
        (std::istreambuf_iterator<char>(input)),
        (std::istreambuf_iterator<char>()));

    input.close();

    std::cout << "Loaded " << bytes.size() << " bytes into memory." << std::endl;

    std::vector<size_t> buffer(bytes.size(), 0); // 8x bigger than it needs to be... but whatevs
    memcpy(buffer.data(), bytes.data(), bytes.size());

    ElfFileHeader64* header = (ElfFileHeader64*)buffer.data();
    Print(*header);
}