#include "main.h"
#include <Windows.h>

// 关于这里的形参为什么没有给出参数名称，因为没有用到，为了避免编译警告，所以去掉了参数名称
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    srand(static_cast<unsigned int>(time(nullptr)));    // 设置随机数种子

    GameSettings_Init();       // 游戏设置读取
    Display_Init();            // 窗口初始化
    Image_Init();              // 图片初始化
    Font_Init();               // 字体初始化
    Text_Init();               // 文本初始化
    Rect_Init();               // 矩形初始化
    layout_init();             // 布局初始化
    Game_Init();               // 游戏初始化

    Display_Mainloop();        // 主循环

    Game_Release();            // 游戏释放
    layout_release();          // 布局释放
    Rect_Release();            // 矩形释放
    Text_Release();            // 文本释放
    Font_Release();            // 字体释放
    Image_Release();           // 图片释放
    Display_Quit();            // 窗口释放
    GameSettings_Release();    // 游戏设置写入

    return 0;
}
