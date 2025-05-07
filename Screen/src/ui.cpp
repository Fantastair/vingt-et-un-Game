#include "../../main.h"

std::list<Ui*> *Ui::ui_list;    // 初始化元素列表

/**
 * @brief 构造函数
 * @param id 元素ID
 * @details id为元素的唯一标识符，用于在列表中查找和比较元素
 */
Ui::Ui(std::string id) : id(id), clicked(nullptr) {}
Ui::~Ui() {}

bool Ui::operator==(const Ui &other) const { return this->id == other.id; }    // 重载==运算符，比较元素ID是否相同
bool Ui::operator!=(const Ui &other) const { return this->id != other.id; }    // 重载!=运算符，比较元素ID是否相同
bool Ui::operator==(std::string other) const { return this->id == other; }     // 重载==运算符，比较元素ID是否相同
bool Ui::operator!=(std::string other) const { return this->id != other; }     // 重载!=运算符，比较元素ID是否相同

/**
 * @brief 设置元素列表
 * @param list 元素列表指针
 */
void Ui::SetUiList(UI_LIST_TYPE *list)
{
    Ui::ui_list = list;
    mark_update();
}

void Ui::join(UI_LIST_TYPE *list) { list->push_back(this); }         // 加入元素列表
void Ui::leave(UI_LIST_TYPE *list) { list->remove(this); }           // 离开元素列表
void Ui::bind_click(void (*func)(void)) { this->clicked = func; }    // 绑定点击事件函数
bool Ui::collidepoint(float, float) { return false; }                // 碰撞检测函数

/**
 * @brief 构造函数
 * @param id 元素ID
 * @param path 图像文件路径
 */
Ui_Image::Ui_Image(std::string id, const char *path) : Ui(id)
{
    this->img = IMG_LoadTexture(renderer, path);
    this->rect = {0, 0, (float)(this->img->w), (float)(this->img->h)};    // 设置矩形区域
}

Ui_Image::~Ui_Image()
{
    SDL_DestroyTexture(this->img);
    this->img = NULL;
}

/**
 * @brief 渲染函数
 */
void Ui_Image::render(void)
{
    SDL_RenderTexture(renderer, this->img, NULL, &(this->rect));
}

void Ui_Image::set_size(float w, float h) { this->rect.w = w; this->rect.h = h; }       // 设置大小
void Ui_Image::set_topleft(float x, float y) { this->rect.x = x; this->rect.y = y; }    // 设置左上角坐标

/**
 * @brief 碰撞检测函数
 * @param x X 坐标
 * @param y Y 坐标
 */
bool Ui_Image::collidepoint(float x, float y)
{
    return (this->rect.x <= x && this->rect.x + this->rect.w >= x && this->rect.y <= y && this->rect.y + this->rect.h >= y);
}

/**
 * @brief 构造函数
 * @param i 元素ID
 * @param t 文本内容
 * @param f 字体对象
 */
Ui_Text::Ui_Text(std::string i, const char *t, TTF_Font *f) : Ui(i)
{
    this->text = TTF_CreateText(text_engine, f, t, 0);          // 创建文本对象
    this->top = 0;                                              // 初始化左上角坐标
    this->left = 0;                                             // 初始化左上角坐标
}

/**
 * @brief 析构函数
 */
Ui_Text::~Ui_Text()
{
    TTF_DestroyText(this->text);
    this->text = NULL;
}

/**
 * @brief 渲染函数
 */
void Ui_Text::render(void)
{
    TTF_DrawRendererText(this->text, this->left, this->top);
}

/**
 * @brief 设置左上角坐标
 * @param x 左上角坐标X
 * @param y 左上角坐标Y
 */
void Ui_Text::set_topleft(float x, float y)
{
    this->left = x;
    this->top = y;
}

/**
 * @brief 设置文本内容
 * @param text 文本内容
 */
void Ui_Text::set_text(const char *t)
{
    TTF_SetTextString(this->text, t, 0);
}

/**
 * @brief 设置文本颜色
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 * @param a 透明度分量
 */
void Ui_Text::set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    TTF_SetTextColor(this->text, r, g, b, a);
}

/**
 * @brief 设置文本字体
 * @param font 字体对象
 */
void Ui_Text::set_font(TTF_Font *font)
{
    TTF_SetTextFont(this->text, font);
}

/**
 * @brief 构造函数
 * @param id 元素ID
 * @param w 矩形宽度
 * @param h 矩形高度
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 * @param a 透明度分量
 */
Ui_Rect::Ui_Rect(std::string id, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) : Ui(id)
{
    this->rect = {0, 0, w, h};
    this->bg = {r, g, b, a};
    this->sc = {0, 0, 0, 255};
    this->bd = 0;
}

Ui_Rect::~Ui_Rect() {}

/**
 * @brief 渲染函数
 */
void Ui_Rect::render(void)
{
    SDL_SetRenderDrawColor(renderer, this->bg.r, this->bg.g, this->bg.b, this->bg.a);
    SDL_RenderFillRect(renderer, &(this->rect));

    if (this->bd > 0)    // 如果边框宽度大于0，则绘制边框
    {
        SDL_FRect temp_rect;
        SDL_SetRenderDrawColor(renderer, this->sc.r, this->sc.g, this->sc.b, this->sc.a);
        temp_rect = {this->rect.x - this->bd, this->rect.y - this->bd, this->rect.w + this->bd * 2, this->bd};
        SDL_RenderFillRect(renderer, &temp_rect);
        temp_rect = {this->rect.x - this->bd, this->rect.y + this->rect.h, this->rect.w + this->bd * 2, this->bd};
        SDL_RenderFillRect(renderer, &temp_rect);
        temp_rect = {this->rect.x - this->bd, this->rect.y, this->bd, this->rect.h};
        SDL_RenderFillRect(renderer, &temp_rect);
        temp_rect = {this->rect.x + this->rect.w, this->rect.y, this->bd, this->rect.h};
        SDL_RenderFillRect(renderer, &temp_rect);
    }

    SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);    // 恢复背景颜色
}

/**
 * @brief 设置大小
 * @param w 矩形宽度
 * @param h 矩形高度
 */
void Ui_Rect::set_size(float w, float h) { this->rect.w = w; this->rect.h = h; }

/**
 * @brief 设置左上角坐标
 * @param x 左上角坐标X
 * @param y 左上角坐标Y
 */
void Ui_Rect::set_topleft(float x, float y) { this->rect.x = x; this->rect.y = y; }

/**
 * @brief 设置背景颜色
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 * @param a 透明度分量
 */
void Ui_Rect::set_bgcolor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) { this->bg = {r, g, b, a}; }

/**
 * @brief 设置边框颜色
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 * @param a 透明度分量
 */
void Ui_Rect::set_sccolor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) { this->sc = {r, g, b, a}; }

/**
 * @brief 设置边框宽度
 * @param w 边框宽度
 */
void Ui_Rect::set_bd(float w) { this->bd = w; }

/**
 * @brief 碰撞检测函数
 * @param x X 坐标
 * @param y Y 坐标
 */
bool Ui_Rect::collidepoint(float x, float y)
{
    return (this->rect.x <= x && this->rect.x + this->rect.w >= x && this->rect.y <= y && this->rect.y + this->rect.h >= y);
}
