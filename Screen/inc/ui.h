#ifndef __UI_H__
#define __UI_H__
#include "../../main.h"

#define UI_LIST_TYPE std::list<Ui*>    // 元素列表类型
#define UI_LIST (*(Ui::ui_list))    // 元素列表

/**
 * @brief 显示元素
 */
class Ui
{
    public:
        static UI_LIST_TYPE *ui_list;                   // 显示队列指针
        static void SetUiList(UI_LIST_TYPE *list);      // 设置元素列表

        std::string id;                                 // 元素唯一ID
        void (*clicked)(void);                          // 点击事件函数指针

        Ui(std::string id);
        virtual ~Ui();

        virtual void render(void) = 0;                  // 渲染函数
        virtual void join(UI_LIST_TYPE *list);          // 加入元素列表
        virtual void leave(UI_LIST_TYPE *list);         // 离开元素列表
        virtual void bind_click(void (*func)(void));    // 绑定点击事件函数
        virtual bool collidepoint(float x, float y);    // 碰撞检测函数

        bool operator==(const Ui &other) const;
        bool operator!=(const Ui &other) const;
        bool operator==(std::string other) const;
        bool operator!=(std::string other) const;
};

/**
 * @brief 图像元素
 * @details 从图像文件加载
 */
class Ui_Image : public Ui
{
    public:
        SDL_Texture *img;
        SDL_FRect rect;

        Ui_Image(std::string id, const char *path);
        virtual ~Ui_Image();

        virtual void render(void);
        virtual void set_size(float w, float h);        // 设置大小
        virtual void set_topleft(float x, float y);     // 设置左上角坐标
        virtual bool collidepoint(float x, float y);    // 碰撞检测函数
};

/**
 * @brief 文本元素
 */
class Ui_Text : public Ui
{
    public:
    TTF_Text *text;                                                // 文本对象
    float top, left;                                               // 文本左上角坐标

    Ui_Text(std::string id, const char *text, TTF_Font *font);
    virtual ~Ui_Text();

    virtual void render(void);                                     // 渲染文本
    virtual void set_topleft(float x, float y);                    // 设置左上角坐标
    virtual void set_text(const char *text);                       // 设置文本内容
    virtual void set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);    // 设置文本颜色
    virtual void set_font(TTF_Font *font);                         // 设置文本字体
};


class Ui_Rect : public Ui
{
    public:
        SDL_FRect rect;    // 矩形区域
        SDL_Color bg;      // 矩形背景色
        SDL_Color sc;      // 矩形边框颜色
        float bd;          // 边框宽度

        Ui_Rect(std::string id, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        virtual ~Ui_Rect();

        virtual void render(void);
        virtual void set_size(float w, float h);                         // 设置大小
        virtual void set_topleft(float x, float y);                      // 设置左上角坐标
        virtual void set_bgcolor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);    // 设置背景颜色
        virtual void set_sccolor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);    // 设置边框颜色
        virtual void set_bd(float w);                                    // 设置边框宽度
        virtual bool collidepoint(float x, float y);                     // 碰撞检测函数
};

#endif
