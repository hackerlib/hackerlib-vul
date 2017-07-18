==11521==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fff390a6fe0 at pc 0x000000979496 bp 0x7fff390a6eb0 sp 0x7fff390a6ea8
READ of size 1 at 0x7fff390a6fe0 thread T0
    #0 0x979495 in cabd_read_string /home/fuzz/afl-test/clamav-devel/libclamav/libmspack-0.5alpha/mspack/cabd.c:530:42
    #1 0x979495 in cabd_read_headers /home/fuzz/afl-test/clamav-devel/libclamav/libmspack-0.5alpha/mspack/cabd.c:393
    #2 0x9744ed in cabd_open /home/fuzz/afl-test/clamav-devel/libclamav/libmspack-0.5alpha/mspack/cabd.c:203:15
    #3 0x60601e in cli_scanmscab /home/fuzz/afl-test/clamav-devel/libclamav/libmspack.c:329:10
    #4 0x547b70 in cli_scanraw /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:2239:32
    #5 0x5403ea in magic_scandesc /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3097:8
    #6 0x536b93 in cli_base_scandesc /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3234:11
    #7 0x5450bf in cli_magic_scandesc /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3243:12
    #8 0x5450bf in scan_common /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3475
    #9 0x543160 in cl_scandesc_callback /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3593:12
    #10 0x543160 in cl_scandesc /home/fuzz/afl-test/clamav-devel/libclamav/scanners.c:3259
    #11 0x4ee83c in main /home/fuzz/afl-test/ex1.c:80:15
    #12 0x7f5bc8f5282f in __libc_start_main /build/glibc-bfm8X4/glibc-2.23/csu/../csu/libc-start.c:291
    #13 0x41ce28 in _start (/home/fuzz/afl-test/clamavfuzz+0x41ce28)

Address 0x7fff390a6fe0 is located in stack of thread T0 at offset 288 in frame
    #0 0x978c2f in cabd_read_headers /home/fuzz/afl-test/clamav-devel/libclamav/libmspack-0.5alpha/mspack/cabd.c:309

  This frame has 2 object(s):
    [32, 288) 'buf.i' <== Memory access at offset 288 overflows this variable
    [352, 416) 'buf'
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/fuzz/afl-test/clamav-devel/libclamav/libmspack-0.5alpha/mspack/cabd.c:530:42 in cabd_read_string
Shadow bytes around the buggy address:
  0x10006720cda0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720cdb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720cdc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720cdd0: 00 00 00 00 00 00 00 00 f1 f1 f1 f1 00 00 00 00
  0x10006720cde0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x10006720cdf0: 00 00 00 00 00 00 00 00 00 00 00 00[f2]f2 f2 f2
  0x10006720ce00: f2 f2 f2 f2 00 00 00 00 00 00 00 00 f3 f3 f3 f3
  0x10006720ce10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720ce20: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720ce30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x10006720ce40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Heap right redzone:      fb
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack partial redzone:   f4
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==11521==ABORTING

