#ifndef __RECT_H__
#define __RECT_H__

extern Ui_Rect
    *replay_button,                   // 重新开始按钮
    *import_game_button,              // 导入游戏按钮
    *export_game_button,              // 导出游戏按钮
    *add_player_num_button,           // 增加玩家人数按钮
    *sub_player_num_button,           // 减少玩家人数按钮
    *start_game_button,               // 开始游戏按钮
    *get_rule_button,                 // 查看规则按钮
    *set_game_difficulty_button,      // 设置游戏难度按钮
    *game_difficulty_rect,            // 游戏难度矩形
    *start_game_button_2,             // 开始游戏按钮2
    *ensure_deal_button,              // 确认发牌按钮
    *ask_action_box,                  // 询问行动框
    *yes_action_button,               // 要牌行动按钮
    *no_action_button,                // 停牌行动按钮
    *go_to_result_page_button,        // 前往结算页面按钮
    *go_back_to_start_menu_button,    // 返回开始菜单按钮
    *game_rule_back_button            // 返回按钮
;

void Rect_Init(void);       // 矩形初始化
void Rect_Release(void);    // 矩形释放

#endif
