#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define WINDOW_WIDTH 1280              // 窗口宽度
#define WINDOW_HEIGHT 720              // 窗口高度

extern SDL_Renderer *renderer;         // 渲染器指针
extern SDL_Window *window;             // 窗口指针
extern TTF_TextEngine *text_engine;    // 文本引擎指针

extern SDL_Color bg_color;             // 背景颜色

extern bool update_flag;               // 更新标志

void Display_Init(void);
void Display_Quit(void);

void Display_Mainloop(void);

void Display_SetBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void mark_update(void);

#endif
