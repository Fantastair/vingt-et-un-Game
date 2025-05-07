#include "../../main.h"

Ui_Rect
    *replay_button,                   // 重新开始按钮
    *ask_action_box,                  // 询问行动框
    *get_rule_button,                 // 查看规则按钮
    *no_action_button,                // 停牌行动按钮
    *yes_action_button,               // 要牌行动按钮
    *start_game_button,               // 开始游戏按钮
    *ensure_deal_button,              // 确认发牌按钮
    *import_game_button,              // 导入游戏按钮
    *export_game_button,             // 导出游戏按钮
    *start_game_button_2,             // 开始游戏按钮2
    *game_difficulty_rect,            // 游戏难度矩形
    *game_rule_back_button,           // 返回按钮
    *add_player_num_button,           // 增加玩家人数按钮
    *sub_player_num_button,           // 减少玩家人数按钮
    *go_to_result_page_button,        // 前往结算页面按钮
    *set_game_difficulty_button,      // 设置游戏难度按钮
    *go_back_to_start_menu_button     // 返回开始菜单按钮
;


/**
 * @brief 矩形初始化
 */
void Rect_Init(void)
{
    // 创建矩形对象
    start_game_button            = new Ui_Rect("start_game_button", 280, 100, COLOR_BUTTONPURPLE);
    get_rule_button              = new Ui_Rect("get_rule_button", 280, 100, COLOR_BUTTONPURPLE);    
    game_rule_back_button        = new Ui_Rect("game_rule_back_button", 60, 40, COLOR_BUTTONPURPLE);
    add_player_num_button        = new Ui_Rect("add_player_num_button", 40, 40, COLOR_BUTTONPURPLE);
    sub_player_num_button        = new Ui_Rect("sub_player_num_button", 40, 40, COLOR_BUTTONPURPLE);
    set_game_difficulty_button   = new Ui_Rect("set_game_difficulty_button", 150, 80, COLOR_BUTTONBLUE);
    game_difficulty_rect         = new Ui_Rect("game_difficulty_rect", 150, 80, COLOR_BUTTONPURPLE);
    start_game_button_2          = new Ui_Rect("start_game_button_2", 600, 72, COLOR_BUTTONPURPLE);
    ensure_deal_button           = new Ui_Rect("ensure_deal_button", 80, 40, COLOR_BUTTONPURPLE);
    ask_action_box               = new Ui_Rect("ask_action_box", 360, 160, COLOR_BUTTONPURPLE);
    yes_action_button            = new Ui_Rect("yes_action_button", 80, 40, COLOR_BUTTONPURPLE);
    no_action_button             = new Ui_Rect("no_action_button", 80, 40, COLOR_BUTTONPURPLE);
    go_to_result_page_button     = new Ui_Rect("go_to_result_page_button", 1272, 92, COLOR_BUTTONPURPLE);
    go_back_to_start_menu_button = new Ui_Rect("go_back_to_start_menu_button", 280, 100, COLOR_BUTTONPURPLE);
    replay_button                = new Ui_Rect("replay_button", 280, 100, COLOR_BUTTONPURPLE);
    import_game_button           = new Ui_Rect("import_game_button", 60, 40, COLOR_BUTTONPURPLE);
    export_game_button           = new Ui_Rect("export_game_button", 60, 40, COLOR_BUTTONPURPLE);
    // 设置矩形边框宽度
    start_game_button            -> set_bd(4);
    get_rule_button              -> set_bd(4);
    game_rule_back_button        -> set_bd(2);
    add_player_num_button        -> set_bd(4);
    sub_player_num_button        -> set_bd(4);
    game_difficulty_rect         -> set_bd(4);
    start_game_button_2          -> set_bd(4);
    ensure_deal_button           -> set_bd(2);
    ask_action_box               -> set_bd(4);
    yes_action_button            -> set_bd(2);
    no_action_button             -> set_bd(2);
    go_to_result_page_button     -> set_bd(4);
    go_back_to_start_menu_button -> set_bd(4);
    replay_button                -> set_bd(4);
    import_game_button           -> set_bd(2);
    export_game_button           -> set_bd(2);
    // 设置矩形边框颜色
    start_game_button            -> set_sccolor(COLOR_BUTTONYELLOW);
    get_rule_button              -> set_sccolor(COLOR_BUTTONYELLOW);
    game_rule_back_button        -> set_sccolor(COLOR_BUTTONYELLOW);
    add_player_num_button        -> set_sccolor(COLOR_BUTTONYELLOW);
    sub_player_num_button        -> set_sccolor(COLOR_BUTTONYELLOW);
    game_difficulty_rect         -> set_sccolor(COLOR_BUTTONYELLOW);
    start_game_button_2          -> set_sccolor(COLOR_BUTTONYELLOW);
    ensure_deal_button           -> set_sccolor(COLOR_BUTTONYELLOW);
    ask_action_box               -> set_sccolor(COLOR_BUTTONYELLOW);
    yes_action_button            -> set_sccolor(COLOR_BUTTONYELLOW);
    no_action_button             -> set_sccolor(COLOR_BUTTONYELLOW);
    go_to_result_page_button     -> set_sccolor(COLOR_BUTTONYELLOW);
    go_back_to_start_menu_button -> set_sccolor(COLOR_BUTTONYELLOW);
    replay_button                -> set_sccolor(COLOR_BUTTONYELLOW);
    import_game_button           -> set_sccolor(COLOR_BUTTONYELLOW);
    export_game_button           -> set_sccolor(COLOR_BUTTONYELLOW);
    // 绑定事件处理函数
    start_game_button            -> bind_click(Clicked_StartGameButton);
    start_game_button_2          -> bind_click(Clicked_StartGameButton2);
    get_rule_button              -> bind_click(Clicked_GetRuleButton);
    game_rule_back_button        -> bind_click(Clicked_GameRuleBackButton);
    add_player_num_button        -> bind_click(Clicked_AddPlayerNumButton);
    sub_player_num_button        -> bind_click(Clicked_SubPlayerNumButton);
    set_game_difficulty_button   -> bind_click(Clicked_SetGameDifficultyButton);
    ensure_deal_button           -> bind_click(Clicked_EnsureDealButton);
    yes_action_button            -> bind_click(Yes_Action);
    no_action_button             -> bind_click(No_Action);
    go_to_result_page_button     -> bind_click(GoToResultPage);
    go_back_to_start_menu_button -> bind_click(BackToMainMenu);
    replay_button                -> bind_click(PlayAgain);
    import_game_button           -> bind_click(ImportGame);
    export_game_button           -> bind_click(ExportGame);
}

/**
 * @brief 矩形释放
 */
void Rect_Release(void)
{
    delete
        add_player_num_button,
        sub_player_num_button,
        start_game_button, 
        get_rule_button,
        set_game_difficulty_button,
        game_difficulty_rect,
        start_game_button_2,
        ensure_deal_button,
        ask_action_box,
        yes_action_button,
        no_action_button,
        go_to_result_page_button,
        import_game_button,
        export_game_button,
        go_back_to_start_menu_button,
        replay_button,
        game_rule_back_button
    ;
}
