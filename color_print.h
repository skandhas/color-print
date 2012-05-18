#pragma once 

#if defined(__cplusplus)
extern "C" {
#endif

/* Colors */
enum  cp_color {
  CP_BLACK        = 0,
  CP_DARK_BLUE    = 1,
  CP_DARK_GREEN   = 2,
  CP_DARK_GYAN    = 3,
  CP_DARK_RED     = 4,
  CP_DARK_MAGENTA = 5,
  CP_DARK_YELLOW  = 6,
  CP_GRAY         = 7,
  CP_DARK_GRAY    = 8,
  CP_BLUE         = 9,
  CP_GREEN        = 10,
  CP_CYAN         = 11,
  CP_RED          = 12,
  CP_MAGENTA      = 13,
  CP_YELLOW       = 14,
  CP_WHITE        = 15  
};

/* Color-Print State */
struct cp_state;
typedef struct cp_state * cp_state_t;

/* Module Functions */
cp_state_t cp_init();
int cp_print( cp_state_t, enum cp_color, const char * );
void cp_close(cp_state_t );

#if defined(__cplusplus)
}
#endif
