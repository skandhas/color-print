#include <stdio.h>
#include "color_print.h"

int main(int argc, char *argv[])
{
  typedef struct{
    enum cp_color color;
    const char * text;
  }out_struct;

  int i = 0;
  out_struct sample[]={
    {CP_RED,"Red Text\n"},
    {CP_BLUE,"Blue Text\n"},
    {CP_GREEN,"Green Text\n"},
    {CP_YELLOW,"Yellow Text\n"}
  };

  cp_state_ref  cp  = cp_init(); 
   
  for (i = 0; i < sizeof(sample)/sizeof(out_struct); ++i){
    cp_print(cp,sample[i].color,sample[i].text);
    printf ("Normal Text\n"); 
  }
  
  cp_close(cp);
  return 0;
}
