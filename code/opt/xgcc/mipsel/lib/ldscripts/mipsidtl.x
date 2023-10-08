/* Default linker script, for normal executables */
OUTPUT_FORMAT("ecoff-littlemips", "ecoff-bigmips",
	      "ecoff-littlemips")
SEARCH_DIR("/opt/xgcc/mipsel-ecoff/lib");
ENTRY (start)
SECTIONS
{
  . = 0xa0012000;
  .text : {
     _ftext = . ;
    *(.init)
     eprol  =  .;
    *(.text)
    *(.fini)
     etext  =  .;
     _etext  =  .;
  }
  . = .;
  .rdata : {
    *(.rdata)
  }
   _fdata = ALIGN(16);
  .data : {
    *(.data)
    CONSTRUCTORS
  }
   HIDDEN (_gp = ALIGN (16) + 0x8000);
  .lit8 : {
    *(.lit8)
  }
  .lit4 : {
    *(.lit4)
  }
  .sdata : {
    *(.sdata)
  }
   edata  =  .;
   _edata  =  .;
   _fbss = .;
  .sbss : {
    *(.sbss)
    *(.scommon)
  }
  .bss : {
    *(.bss)
    *(COMMON)
  }
   end = .;
   _end = .;
}
