MEMORY
{
  ram (rwx) : org = 0x20000000, len = 8K
  rom (rx) : org = 0x08000000, len = 128K
}

SECTIONS
{
    .  = 0x08000000;
    .text : { *(vectors) *(.text) *(.rodata) } >rom
    .  = 0x20000000;
    .data : { *(.data) } >ram AT > rom
    .bss : { *(.bss) } >ram AT > rom
} 
