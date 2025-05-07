#include "../../main.h"

SDL_Window *window = NULL;             // 窗口指针
SDL_Renderer *renderer = NULL;         // 渲染器指针
TTF_TextEngine *text_engine = NULL;    // 文本引擎指针

SDL_Color bg_color;                    // 背景颜色

bool update_flag = true;               // 更新标志

/**
 * @brief 窗口初始化
 */
void Display_Init(void)
{
    SDL_Init(SDL_INIT_VIDEO);    
    TTF_Init();

    window = SDL_CreateWindow("21点", WINDOW_WIDTH, WINDOW_HEIGHT, 0);    // 创建窗口
    renderer = SDL_CreateRenderer(window, NULL);                                // 创建渲染器
    text_engine = TTF_CreateRendererTextEngine(renderer);                       // 创建文本引擎

    SDL_SetWindowIcon(window, IMG_Load("res/icon.png"));                        // 设置窗口图标
    Display_SetBgColor(COLOR_BGBLUE);                                           // 设置背景颜色
    Ui::SetUiList(&start_menu_list);                                            // 设置元素列表
}

#define FPS_ 60                            // 帧率
Uint64 frame_time_ = 1000000000 / FPS_;    // 每帧时间，单位纳秒

/**
 * @brief 窗口主循环
 */
void Display_Mainloop(void)
{
    while (true)
    {
        auto st_ = SDL_GetTicksNS();    // 获取当前时间戳

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) { goto end; }        // 用户关闭窗口
            else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)    // 用户鼠标按下
            {
                Handle_MouseButtonDown(event.button.x, event.button.y, event.button.button);
            }
        }

        handle_action();    // 处理玩家行动

        if (update_flag)    // 更新标志为真，表示需要更新界面
        {
            // 填充背景色
            SDL_RenderClear(renderer);

            // 渲染元素
            for (auto &ui : UI_LIST) { if (ui != nullptr) ui->render(); }

            // 更新屏幕
            SDL_RenderPresent(renderer);

            update_flag = false;
        }

        Uint64 elapsed_time_ = SDL_GetTicksNS() - st_;    // 计算帧间隔时间
        if (elapsed_time_ < frame_time_)                // 如果帧间隔时间小于设定的帧时间
        {
            SDL_DelayNS(frame_time_ - elapsed_time_);
        }
    }
    end:;
}

/**
 * @brief 设置背景颜色
 * @param r 红色分量
 * @param g 绿色分量
 * @param b 蓝色分量
 * @param a 透明度分量
 */
void Display_SetBgColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    bg_color.r = r;
    bg_color.g = g;
    bg_color.b = b;
    bg_color.a = a;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Display_Quit(void)
{
    SDL_DestroyRenderer(renderer);    // 销毁渲染器
    SDL_DestroyWindow(window);        // 销毁窗口
    SDL_Quit();                       // 退出SDL
}

/**
 * @brief 设置更新标志为真
 */
void mark_update(void)
{
    update_flag = true;
}
