## Artemis Keithley Interface ##

This is a UI for using the Keithley Interface. At present, only Windows is supported

### How to Install ###

1. Install [Qt](http://www.qt.io/)
2. Install [National Instruments GPIB libraries and Drivers](http://www.ni.com/product-documentation/5326/en/). 
3. Clone the git repo
4. Copy the `ni4882h` header file from `C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include` to the source folder of the repo (`artemis-keithley-interface/`)
5. Now copy the `gpib-32.obj` file from `C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\lib32\msvc` to the source folder of the repo (`artemis-keithley-interface/`)
6. You should now be able to build and run the project.



