###Usage
```c
#include "color_print.h"

/* Initialize color-print module */
cp_state_ref  cp  = cp_init(); 

/* Print text */
cp_print(cp,CP_RED,"Red Text\n");

/*Close color-print module */
cp_close(cp);

```
