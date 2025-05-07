#ifndef __FONT_H__
#define __FONT_H__
#include "../../main.h"

extern TTF_Font
    *deyi24,
    *deyi32,
    *deyi48,
    *deyi64,
    *shuhei16,
    *shuhei24,
    *shuhei32,
    *shuhei72,
    *shuhei128
;

void Font_Init(void);
void Font_Release(void);

#endif
