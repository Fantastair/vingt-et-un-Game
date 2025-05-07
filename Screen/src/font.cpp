#include "../../main.h"

TTF_Font
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

/**
 * @brief 字体初始化
 */
void Font_Init(void)
{
    deyi24    = TTF_OpenFont("res/font/deyi.ttf", 24);
    deyi32    = TTF_OpenFont("res/font/deyi.ttf", 32);
    deyi48    = TTF_OpenFont("res/font/deyi.ttf", 48);
    deyi64    = TTF_OpenFont("res/font/deyi.ttf", 64);
    shuhei16  = TTF_OpenFont("res/font/shuhei.ttf", 16);
    shuhei24  = TTF_OpenFont("res/font/shuhei.ttf", 24);
    shuhei32  = TTF_OpenFont("res/font/shuhei.ttf", 32);
    shuhei72  = TTF_OpenFont("res/font/shuhei.ttf", 72);
    shuhei128 = TTF_OpenFont("res/font/shuhei.ttf", 128);
}

/**
 * @brief 释放字体
 */
void Font_Release(void)
{
    TTF_CloseFont(deyi24);
    TTF_CloseFont(deyi32);
    TTF_CloseFont(deyi48);
    TTF_CloseFont(deyi64);
    TTF_CloseFont(shuhei16);
    TTF_CloseFont(shuhei24);
    TTF_CloseFont(shuhei32);
    TTF_CloseFont(shuhei72);
    TTF_CloseFont(shuhei128);
}

