#include "../../main.h"

UI_LIST_TYPE
    start_menu_list,      // 开始界面
    game_rule_list,       // 游戏规则界面
    game_setting_list,    // 游戏设置界面
    game_result_list,     // 游戏结算界面
    game_main_list        // 游戏主界面
;

void layout_init(void)
{
    // 布局开始界面
    // 设置元素位置
    decoration_1      -> set_topleft(1100, 320);
    decoration_2      -> set_topleft(-100, 120);
    author_sign       -> set_topleft(1040, 700);
    title             -> set_topleft(320 , 40);
    start_game_button -> set_topleft(500 , 390);
    start_game_text   -> set_topleft(530 , 400);
    get_rule_button   -> set_topleft(500 , 520);
    get_rule_text     -> set_topleft(530 , 530);
    // 加入渲染队列
    decoration_1      -> join(&start_menu_list);
    decoration_2      -> join(&start_menu_list);
    bg_shadow         -> join(&start_menu_list);
    author_sign       -> join(&start_menu_list);
    title             -> join(&start_menu_list);
    start_game_button -> join(&start_menu_list);
    start_game_text   -> join(&start_menu_list);
    get_rule_button   -> join(&start_menu_list);
    get_rule_text     -> join(&start_menu_list);

    // 布局游戏规则界面
    // 设置元素位置
    game_rule_back_button  -> set_topleft(20 , 20);
    game_rule_back_text    -> set_topleft(30 , 25);
    game_rule_title_text   -> set_topleft(500, 40);
    game_rule_text_1       -> set_topleft(100, 160);
    game_rule_text_2       -> set_topleft(100, 340);
    game_rule_text_3       -> set_topleft(100, 520);
    game_rule_text_4       -> set_topleft(100, 580);
    game_rule_title_text_1 -> set_topleft(100, 340);
    game_rule_title_text_2 -> set_topleft(100, 520);
    game_rule_title_text_3 -> set_topleft(100, 580);
    // 加入渲染队列
    decoration_1           -> join(&game_rule_list);
    decoration_2           -> join(&game_rule_list);
    bg_shadow              -> join(&game_rule_list);
    author_sign            -> join(&game_rule_list);
    game_rule_back_button  -> join(&game_rule_list);
    game_rule_back_text    -> join(&game_rule_list);
    game_rule_title_text   -> join(&game_rule_list);
    game_rule_text_1       -> join(&game_rule_list);
    game_rule_text_2       -> join(&game_rule_list);
    game_rule_text_3       -> join(&game_rule_list);
    game_rule_text_4       -> join(&game_rule_list);
    game_rule_title_text_1 -> join(&game_rule_list);
    game_rule_title_text_2 -> join(&game_rule_list);
    game_rule_title_text_3 -> join(&game_rule_list);

    // 布局游戏设置界面
    // 设置元素位置
    set_game_player_num_text   -> set_topleft(300, 400);
    player_num_text            -> set_topleft(814, 400);
    add_player_num_text        -> set_topleft(944, 400);
    sub_player_num_text        -> set_topleft(694, 400);
    add_player_num_button      -> set_topleft(940, 424);
    sub_player_num_button      -> set_topleft(684, 424);
    set_game_difficulty_text   -> set_topleft(300, 500);
    game_difficulty_text_1     -> set_topleft(700, 500);
    game_difficulty_text_2     -> set_topleft(856, 500);
    start_game_text_2          -> set_topleft(370, 620);
    start_game_button_2        -> set_topleft(350, 620);
    import_game_button         -> set_topleft(20, 660);
    import_game_text           -> set_topleft(30, 665);
    if (GetGameDifficultySetting() == 1)
    {
        game_difficulty_rect       -> set_topleft(680, 500);
        set_game_difficulty_button -> set_topleft(830, 500);
    }
    else
    {
        game_difficulty_rect       -> set_topleft(830, 500);
        set_game_difficulty_button -> set_topleft(680, 500);
    }
    // 加入渲染队列
    decoration_1               -> join(&game_setting_list);
    decoration_2               -> join(&game_setting_list);
    bg_shadow                  -> join(&game_setting_list);
    author_sign                -> join(&game_setting_list);
    title                      -> join(&game_setting_list);
    set_game_player_num_text   -> join(&game_setting_list);
    player_num_text            -> join(&game_setting_list);
    add_player_num_button      -> join(&game_setting_list);
    sub_player_num_button      -> join(&game_setting_list);
    add_player_num_text        -> join(&game_setting_list);
    sub_player_num_text        -> join(&game_setting_list);
    set_game_difficulty_text   -> join(&game_setting_list);
    set_game_difficulty_button -> join(&game_setting_list);
    game_difficulty_rect       -> join(&game_setting_list);
    game_difficulty_text_1     -> join(&game_setting_list);
    game_difficulty_text_2     -> join(&game_setting_list);
    start_game_button_2        -> join(&game_setting_list);
    start_game_text_2          -> join(&game_setting_list);
    import_game_button         -> join(&game_setting_list);
    import_game_text           -> join(&game_setting_list);

    // 布局游戏主界面
    // 设置元素位置
    card_pool_img            -> set_topleft(50, 50);
    ensure_deal_button       -> set_topleft(175, 75);
    ensure_deal_text         -> set_topleft(195, 80);
    ask_action_box           -> set_topleft(180, 50);
    action_tip_text          -> set_topleft(380, 60);
    ask_box_pointer          -> set_topleft(536, 100);
    yes_action_button        -> set_topleft(220, 140);
    yes_action_text          -> set_topleft(233, 142);
    no_action_button         -> set_topleft(420, 140);
    no_action_text           -> set_topleft(433, 142);
    go_to_result_page_button -> set_topleft(4, 624);
    go_to_result_page_text   -> set_topleft(320, 630);
    export_game_button     -> set_topleft(1200, 20);
    export_game_text       -> set_topleft(1210, 25);
    // 加入渲染队列
    decoration_1      -> join(&game_main_list);
    decoration_2      -> join(&game_main_list);
    bg_shadow         -> join(&game_main_list);
    author_sign       -> join(&game_main_list);
    card_pool_img     -> join(&game_main_list);

    // 布局游戏结算界面
    // 设置元素位置
    result_player_head           -> set_topleft(200, 72);
    result_computer_head         -> set_topleft(100, 72);
    result_text                  -> set_topleft(500, 120);
    go_back_to_start_menu_button -> set_topleft(500 , 390);
    go_back_to_start_menu_text   -> set_topleft(530 , 400);
    replay_button                -> set_topleft(500 , 520);
    replay_text                  -> set_topleft(530 , 530);
    // 加入渲染队列
    decoration_1                 -> join(&game_result_list);
    decoration_2                 -> join(&game_result_list);
    bg_shadow                    -> join(&game_result_list);
    author_sign                  -> join(&game_result_list);
    result_text                  -> join(&game_result_list);
    go_back_to_start_menu_button -> join(&game_result_list);
    go_back_to_start_menu_text   -> join(&game_result_list);
    replay_button                -> join(&game_result_list);
    replay_text                  -> join(&game_result_list);
}


/**
 * @brief 释放布局
 */
void layout_release(void)
{
    start_menu_list.clear();
    game_rule_list.clear();
    game_setting_list.clear();
    game_result_list.clear();
    game_main_list.clear();
}
