#include <dlfcn.h>
 
#include <stdlib.h>
#include <stdio.h>
 
typedef int (*Josh)(int, int);
 
 
int main(void) {
 const char *error;
 void *module;
 Josh func;
 
 /* Load dynamically loaded library */
 module = dlopen("./libdll.so", RTLD_LAZY);
 if (!module) {
   fprintf(stderr, "Couldn't open libdll.so: %s\n",
           dlerror());
   exit(1);
 }
 
 /* Get symbol */
 dlerror();
 func = dlsym(module, "_T03dll8JoshTests5Int32VAD_ADtXCfau");

 if ((error = dlerror())) 
 {
   fprintf(stderr, "Couldn't find hello: %s\n", error);
   exit(1);
 }
 
 /* Now call the function in the DL library */
 printf("Woah: %d", (*func)(5, 4));
 
 /* All done, close things cleanly */
 dlclose(module);
 return 0;
}
