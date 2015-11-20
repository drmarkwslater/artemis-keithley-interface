## Artemis Keithley Interface ##

This is a UI for using the Keithley Interface. At present, only Windows is supported

### How to Install ###

1. Install [Qt](http://www.qt.io/)
2. Install [National Instruments GPIB libraries and Drivers](http://www.ni.com/product-documentation/5326/en/). 
3. Clone the git repo
4. Copy the `ni4882h` header file from `C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include` to the source folder of the repo (`artemis-keithley-interface/`)
5. We now need to create a library from the dll to link against so open a command prompt and `cd` to the repo directory
5. Run `C:\Qt\Tools\mingw492_32\bin\gendef C:\Windows\SysWOW64\ni4882.dll`
6. Run `C:\Qt\Tools\mingw492_32\bin\dlltool C:\Windows\SysWOW64\ni4882.dll\ni4882.dll -d ni4882.def -l libni4882.a`
7. You should now be able to open the project in Qt and build it!
