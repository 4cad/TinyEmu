#pragma once

#include <stdint.h>

// Reference https://en.wikipedia.org/wiki/Executable_and_Linkable_Format 

// Lets ignore 32 bit for now.
class ElfFileHeader64 {
public:
	uint32_t MagicNumber; // 0x7F 45 4c 46
	uint8_t BitFormat; // 1 = 32 bit, 2 = 64 bit
	uint8_t Endianness; // 1 = little, 2 = big
	uint8_t Version1;    // Should be 1
	uint8_t ABI_Major; // 0x03 is linux - see reference doc for others
	uint8_t ABI_Minor; // usually ABI version of dynamic linker
	uint8_t _pad1[7];

	uint16_t FileType;       // e.g. 0x02 is executable, 0x02 is dynamic libary
	uint16_t InstructionSet; // e.g. 0x03 is x86, 0x08 is MIPS, 0x3E is x86-64

	uint32_t Version2;       // Should be 1
	uint64_t EntryPointOffset;    
	uint64_t ProgramHeaderOffset; // Usually right after header - offset 0x34 for 32 bit, 0x40 for 64 bit
	uint64_t SectionHeaderOffset;

	uint32_t Flags; // architecture dependent
	uint16_t HeaderSize; // 64 bytes for 64-bit, 52 bytes for 32-bit
	uint16_t ProgramHeaderEntrySize;
	uint16_t ProgramHeaderEntryCount;
	uint16_t SectionHeaderEntrySize;
	uint16_t SectionHeaderEntryCount;
	uint16_t SectionNamesEntryIndex;
};

class ElfProgramHeader64 {
	uint32_t PType;
	uint32_t Flags; // Meaning varies depending on the segment type
	uint64_t FileOffset;
	uint64_t VirtualAddr;

	uint64_t PhysicalAddr; // Only relevant for systems where physical address is relevant
	uint64_t FileSizeBytes; // Length in bytes of the segment as stored in the ELF file
	uint64_t MemorySizeBytes; // Length in bytes of the segment in virtual memory
	uint64_t Alignment; // Must be a positive, integral power of 2. VirtualAddress must be equivalent to Offset mod align.
};

class ElfSegmentHeader64 {
	uint32_t NameOffset; // Offset ot a string in the ".shstrtab" section
	uint32_t SType;
	uint64_t Flags;
	uint64_t VirtualAddr; // Not all sections are loaded into memory, if they are this is their address
	uint64_t FileOffset;
	uint64_t FileSizeBytes;

	uint32_t LinkIdx;
	uint32_t Info; // Used for various purposes depending on the SType

	uint64_t Align; // Must be a power of two
	uint64_t EntrySizeBytes; // The size of each entry in the section if the section contains fixed-size entries. Otherwise 0
};