#ifndef __LAYOUT_H__
#define __LAYOUT_H__

extern UI_LIST_TYPE
    start_menu_list,      // 开始界面
    game_rule_list,       // 游戏规则界面
    game_setting_list,    // 游戏设置界面
    game_result_list,     // 游戏结算界面
    game_main_list       // 游戏主界面
;

void layout_init(void);
void layout_release(void);

#endif
