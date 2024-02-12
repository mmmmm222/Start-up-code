_estack = ORIGIN(RAM)+LENGHT(RAM);
MEMORY
{
    RAM     (xrw):ORIGIN = 0x20000000 ,LENGHT = 64K
    FLASH   (rx) :ORIGIN = 0x08000000 ,LENGHT = 265K
}

SECTIONS
{
    .isr_vector :
    {
        *(.isr_vector)
        *(.isr_vector*)
    }>FLASH

    .init :
    {
        *(.init)
        *(.init*)
    }>FLASH

    .text :
    {
        *(.text)
        *(.text*)
    }>FLASH

    .rodata :
    {
        *(.rodata)
        *(.rodata*)
    }>FLASH

    _sdata_FLASH=LOADADDR(.data);

    .data :
    {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;

    }>RAM AT>FLASH

    .bss :
    {
        _sbss_RAM = .;
        *(.bss)
        *(.bss*)
        _ebss_RAM = .;
    }>RAM
}