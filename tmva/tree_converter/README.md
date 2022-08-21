Program for reading and converting my Highland analysis output files into flat trees suitable for input into TMVA macros. 

This is intended for particle gun MC ONLY. Each particle type sample must be run through the program separately, and the particle type must be specified in defaultAntiNumuCC1pi.C (this requires recompiling the program each time). If the Highland output variables are changed, the variables and branch addresses must be updated in defaultAntiNumuCC1pi.h.

You may need to create 'bin' and 'output' directories here for it to work.

Originally created by using MakeClass on the microtree default tree from a Highland output file:

```
root outputFile.root
default->MakeClass(“defaultAntiNumuCC1pi”)
```

This produces the .C and .h files which I then edited as needed. When you need to update the variable lists in the header file, you can run this again with a different name (e.g. `default->MakeClass(“defaultAntiNumuCC1pi_forupdate”)` and copy the lists of variables and branches over.

This process can also be used when you need to write custom analysis code.
