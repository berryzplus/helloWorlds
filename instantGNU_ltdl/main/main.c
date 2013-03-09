#include <stdio.h>
#include "ltdl.h"

/*
   configure.inでAM_CONFIG_HEADER(include/config.h)を指定すると,
   configure時にconfig.hが生成される。
*/
#include "config.h"

typedef void (*T_FUNC)();

int main(int argc,char** argv){
/*
  void* hlib = 0;
*/
  lt_dlhandle hlib = 0;
  T_FUNC hfun = 0;
  if(argc != 3){
    fprintf(stderr,"Usage: %s libfilename functionname\n",argv[0]);
    exit(1);
  }
  lt_dlinit();

/*  hlib = dlopen(argv[1],RTLD_LAZY);*/
  hlib = lt_dlopenext(argv[1]);
  if(!hlib){
    fprintf(stderr,"Error:cannot open %s.\n",argv[1]);
    exit(2);
  }
/*  hfun = (T_FUNC)dlsym(hlib,argv[2]);*/
  hfun = (T_FUNC)lt_dlsym(hlib,argv[2]);
  if(!hfun){
    fprintf(stderr,"Error:cannot resolve '%s'.\n",argv[2]);
    exit(3);
  }
  /* CONFIGDATEはconfigure時にdefineされる。*/
  printf("configured in %s\n", "CONFIGDATE");
  hfun();
}
