Test code for shared libs with static data. Tested on MacOSX, should work out of the box on Linux. Not tested on Windows.

Build:
```
mkdir build
cd build
cmake ..
make
```

Typical output: 
```
ncgalopp@ncgalopp-mac03:~/code/sharedextern/build (master)$ ./seapp 
Initializing...
se_get_context: 0x7fd780404bf0
app: 0x7fd780404bf0
se_get_context: 0x7fd780404bf0
se_util_run: 0x7fd780404bf0 : 5
Using context: 0x7fd780404bf0
```
