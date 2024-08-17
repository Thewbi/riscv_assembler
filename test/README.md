# Building on Windows

Download https://cmocka.org/files/1.1/cmocka-1.1.7.tar.xz and extract it to the folder
riscv_assembler\test

Install a gcc toolchain using cygwin

Install GnuWin32 to C:\GnuWin32
This is very important because the path to GnuWin32 is not allowed to contain any spaces.

If you have old installations in the folder C:\Program Files (x86)\GnuWin32, make absolutely
sure to remove the folder C:\Program Files (x86)\GnuWin32. CMake will auto-detect that folder
and choke itself to death on the whitespace in the path.

Add the path C:\GnuWin32\bin to your PATH variable in the system environment variables.
Restart all terminals to make the change to the environment variables stick.

Execute

```
make install
```

If the build succeeds, 

copy cmocka-1.1.7/build/cmocka-1.1.7/build/output/bin/cygcmocka-0.dll next to this README.md

copy cmocka-1.1.7\build\cmocka-1.1.7\build\output\lib\libcmocka.dll.a to the test/lib folder

copy cmocka-1.1.7\build\cmocka-1.1.7\build\output\include\cmocka.h to the test/include folder
copy cmocka-1.1.7\build\cmocka-1.1.7\build\output\include\cmocka_pbc.h to the test/include folder

Execute 

```
make
```

The file cmockatest.exe is compiled.
Run cmockatest.exe to run your tests.