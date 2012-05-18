#include <assert.h>
#include <stdio.h>
#include <windows.h>
#include "color_print.h"

struct cp_state
{
  int      default_color;
  int      current_color;
  HANDLE   std_output;
};

static int
cp_apply(cp_state_t cp)
{
  return SetConsoleTextAttribute(cp->std_output,cp->current_color) == TRUE ? 0:(-1);
} 

cp_state_t 
cp_init()
{
  HANDLE     std_output;
  cp_state_t cp; 
  CONSOLE_SCREEN_BUFFER_INFO screen_buff;
  
  std_output = GetStdHandle(STD_OUTPUT_HANDLE);

  if (std_output == INVALID_HANDLE_VALUE)
    return 0;

  if(!GetConsoleScreenBufferInfo(std_output,&screen_buff))
    return 0;

  cp = malloc(sizeof(struct cp_state)); 
  assert(cp);

  cp->std_output = std_output;
  cp->default_color = cp->current_color = screen_buff.wAttributes;

  return cp;
}

int 
cp_print(cp_state_t cp, enum cp_color color, const char * text)
{
  assert(cp);

  cp->current_color = color;
  cp_apply(cp);
  return printf("%s",text);
}

void
cp_reset(struct cp_state * cp)
{
  assert(cp);

  cp->current_color = cp->default_color ;
  cp_apply(cp);
}

void 
cp_close(cp_state_t cp)
{
  assert(cp);

  cp_reset(cp);
     
  if (cp){
    free(cp);
  }
  
}

