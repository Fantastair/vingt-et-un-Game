#include "../../main.h"

Ui_Image
    *title,                   // 游戏标题
    *bg_shadow,               // 背景阴影
    *decoration_1,            // 装饰物1
    *decoration_2,            // 装饰物2
    *card_pool_img,           // 牌堆
    *ask_box_pointer,         // 对话框角标
    *result_player_head,      // 结算玩家头像
    *result_computer_head     // 结算庄家头像
;

/**
 * * @brief 图片初始化
 */
void Image_Init(void)
{
    // 创建图片对象
    title                = new Ui_Image("game_title", "res/image/game_title.png");                 // 游戏标题
    bg_shadow            = new Ui_Image("bg_shadow", "res/image/bg_shadow.png");                   // 背景阴影
    decoration_1         = new Ui_Image("decoration_1", "res/image/decoration_1.png");             // 装饰物1
    decoration_2         = new Ui_Image("decoration_2", "res/image/decoration_2.png");             // 装饰物2
    card_pool_img        = new Ui_Image("card_pool_img", "res/image/icon.png");                    // 牌堆
    ask_box_pointer      = new Ui_Image("ask_box_pointer", "res/image/chat_box.png");              // 对话框角标
    result_player_head   = new Ui_Image("result_player_head", "res/image/player_head.png");        // 结算玩家头像
    result_computer_head = new Ui_Image("result_computer_head", "res/image/computer_head.png");    // 结算庄家头像
    // 设置图片大小
    card_pool_img  -> set_size(100, 100);    // 设置牌堆大小
    ask_box_pointer-> set_size(32, 32);      // 设置对话框角标大小
}

/**
 * @brief 图片释放
 */
void Image_Release(void)
{
    delete 
        title,
        bg_shadow,
        decoration_1,
        decoration_2,
        card_pool_img,
        ask_box_pointer,
        result_player_head,
        result_computer_head
    ;
}
