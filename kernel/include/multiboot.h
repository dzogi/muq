/**
 * Multiboot-related structures
 * Code originated from:
 * http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#Example-OS-code
 * GPL-2
 */

#ifndef __MULTIBOOT_H
# define __MULTIBOOT_H
 
/* The Multiboot header. */

struct multiboot_header {
	u32_t magic;
	u32_t flags;
	u32_t checksum;
	u32_t header_addr;
	u32_t load_addr;
	u32_t load_end_addr;
	u32_t bss_end_addr;
	u32_t entry_addr;
};

/* The symbol table for a.out. */
struct aout_symbol_table {
	u32_t tabsize;
	u32_t strsize;
	u32_t addr;
	u32_t reserved;
};

/* The section header table for ELF. */
struct elf_section_header_table
{
	u32_t num;
	u32_t size;
	u32_t addr;
	u32_t shndx;
};

/* The Multiboot information. */
struct multiboot_info
{
	u32_t flags;
	u32_t mem_lower;
	u32_t mem_upper;
	u32_t boot_device;
	u32_t cmdline;
	u32_t mods_count;
	u32_t mods_addr;
	union
	{
	 struct aout_symbol_table aout_sym;
	 struct elf_section_header_table elf_sec;
	} u;
	u32_t mmap_length;
	u32_t mmap_addr;
};

/* The module structure. */
struct module
{
	u32_t mod_start;
	u32_t mod_end;
	u32_t string;
	u32_t reserved;
};

/* The memory map. Be careful that the offset 0 is base_addr_low but no size. */
struct memory_map
{
	u32_t size;
	u32_t base_addr_low;
	u32_t base_addr_high;
	u32_t length_low;
	u32_t length_high;
	u32_t type;
};

#endif /* __MULTIBOOT_H */

