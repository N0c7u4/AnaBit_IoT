copy mach3.sys mach3.orig
del mach3.sys
REM.exe *Mach3
copy mach3.noapic mach3.sys
IN.exe  .\Mach3.inf *Mach3