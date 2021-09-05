#include <iostream>
#include <iomanip>

#include "PrintUtils.h"
#include "ElfHeader.h"


using namespace std;

void P(const char* name, uint64_t t) {
	std::cout << "\t" << name << ":\t0x" << setw(16) << setfill('0') << std::hex << t << std::endl;
}

void P(const char* name, uint32_t t) {
	std::cout << "\t" << name << ":\t0x" << setw(8) << setfill('0') << std::hex << (uint64_t)t << std::endl;
}

void P(const char* name, uint16_t t) {
	std::cout << "\t" << name << ":\t0x" << setw(4) << setfill('0') << std::hex << (uint64_t)t << std::endl;
}

void P(const char* name, uint8_t t) {
	std::cout << "\t" << name << ":\t0x" << setw(2) << setfill('0') << std::hex << (uint64_t)t << std::endl;
}

void Print(const ElfFileHeader64& h)
{
	/*
	uint32_t MagicNumber; // 0x7F 45 4c 46
	uint8_t BitFormat; // 1 = 32 bit, 2 = 64 bit
	uint8_t Endianness; // 1 = little, 2 = big
	uint8_t Version;    // Should be 1
	uint8_t ABI_Major; // 0x03 is linux - see reference doc for others
	uint8_t ABI_Minor; // usually ABI version of dynamic linker
	uint8_t _pad1[7];

	uint16_t FileType;       // e.g. 0x02 is executable, 0x02 is dynamic libary
	uint16_t InstructionSet; // e.g. 0x03 is x86, 0x08 is MIPS, 0x3E is x86-64

	uint32_t Version;       // Should be 1
	uint64_t EntryPointPtr;
	uint64_t ProgramHeaderPtr; // Usually right after header - offset 0x34 for 32 bit, 0x40 for 64 bit
	uint64_t SectionHeaderPtr;

	uint32_t Flags; // architecture dependent
	uint16_t HeaderSize; // 64 bytes for 64-bit, 52 bytes for 32-bit
	uint16_t ProgramHeaderEntrySize;
	uint16_t ProgramHeaderEntryCount;
	uint16_t SectionHeaderEntrySize;
	uint16_t SectionHeaderEntryCount;
	uint16_t SectionNamesEntryIndex;
	*/
	std::cout << "==== ELFHeader64 ====" << std::endl;
	P("MagicNumber", h.MagicNumber);
	P("BitFormat", h.BitFormat);
	P("Version1", h.Version1);
	P("ABI_Major", h.ABI_Major);
	P("ABI_Minor", h.ABI_Minor);

	P("FileType", h.FileType);
	P("InstructionSet", h.InstructionSet);

	P("Version2", h.Version2);
	P("EntryPointPtr", h.EntryPointOffset);
	P("ProgramHeaderPtr", h.ProgramHeaderOffset);
	P("SectionHeaderPtr", h.SectionHeaderOffset);

	P("Flags     ", h.Flags);
	P("HeaderSize", h.HeaderSize);
	P("ProgramHeaderEntrySize " , h.ProgramHeaderEntrySize);
	P("ProgramHeaderEntryCount", h.ProgramHeaderEntryCount);
	P("SectionHeaderEntrySize ", h.SectionHeaderEntrySize);
	P("SectionHeaderEntryCount", h.SectionHeaderEntryCount);
	P("SectionNamesEntryIndex ", h.SectionNamesEntryIndex);
	std::cout << "=====================" << std::endl;
}