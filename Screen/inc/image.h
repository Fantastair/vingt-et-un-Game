#ifndef __IMAGE_H__
#define __IMAGE_H__

extern Ui_Image
    *title,                   // 游戏标题
    *bg_shadow,               // 背景阴影
    *decoration_1,            // 装饰物1
    *decoration_2,            // 装饰物2
    *card_pool_img,           // 牌堆
    *ask_box_pointer,         // 对话框角标
    *result_player_head,      // 结算玩家头像
    *result_computer_head     // 结算庄家头像
;

void Image_Init(void);       // 图片初始化
void Image_Release(void);    // 图片释放

#endif
