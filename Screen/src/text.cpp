#include "../../main.h"

std::string game_rule_string_1 = "21点纸牌游戏（Blackjack）是一种非常受欢迎的纸牌游戏，起源于1700年左右的法国赌场，当时的游戏名为\"vingt-et-un\"（法文中21之意）。该游戏的目标是通过手中的牌点数接近或达到21点，但不能超过21点。玩家和庄家从一副52张牌（不包括大小王）中抽牌，最终点数更接近21点的玩家获胜。";
std::string game_rule_string_2 = "游戏流程：开局每人发两张牌，除了庄家的一张牌牌面朝下，其他牌的牌面均朝上，每位玩家依次行动，庄家询问玩家是否要牌直到玩家拒绝，然后询问下一位玩家。所有玩家行动完毕后，庄家开始要牌，直到庄家的点数达到17点或以上。最后，点数更接近21点的一方获胜。";
std::string game_rule_string_3 = "牌面点数：A为1点或11点，2-10为其本身点数，J、Q、K均为10点。";
std::string game_rule_string_4 = "爆牌：如果玩家或庄家的点数超过21点，则称为\"爆牌\"，该方立即输掉本局游戏。";

Ui_Text
    *author_sign,                   // 作者签名
    *result_text,                   // 结算赢家名称文本
    *replay_text,                   // 重新开始文本
    *get_rule_text,                 // 查看规则文本
    *no_action_text,                // 停牌文本
    *start_game_text,               // 开始游戏文本
    *player_num_text,               // 玩家人数文本
    *action_tip_text,               // 行动提示文本
    *yes_action_text,               // 要牌文本
    *ensure_deal_text,              // 确认发牌文本
    *import_game_text,              // 导入游戏文本
    *export_game_text,              // 导出游戏文本
    *game_rule_text_1,              // 游戏规则文本1
    *game_rule_text_2,              // 游戏规则文本2
    *game_rule_text_3,              // 游戏规则文本3
    *game_rule_text_4,              // 游戏规则文本4
    *start_game_text_2,             // 开始游戏文本2
    *add_player_num_text,           // 增加玩家人数文本
    *sub_player_num_text,           // 减少玩家人数文本
    *game_rule_back_text,           // 返回按钮文本
    *game_rule_title_text,          // 游戏规则标题文本
    *game_rule_title_text_1,        // 游戏规则标题文本1
    *game_rule_title_text_2,        // 游戏规则标题文本2
    *game_rule_title_text_3,        // 游戏规则标题文本3
    *game_difficulty_text_1,        // 游戏难度文本1
    *game_difficulty_text_2,        // 游戏难度文本2
    *go_to_result_page_text,        // 前往结算页面文本
    *acting_player_name_text,       // 行动玩家名称文本
    *set_game_player_num_text,      // 设置玩家人数文本
    *set_game_difficulty_text,      // 设置游戏难度文本
    *go_back_to_start_menu_text     // 返回开始菜单文本
;

/**
 * * @brief 初始化文本
 */
void Text_Init(void)
{
    // 创建文本对象
    author_sign                = new Ui_Text("author_sign", "Written By Fantastair @2025", shuhei16);
    start_game_text            = new Ui_Text("start_game_text", "开始游戏", deyi64);
    get_rule_text              = new Ui_Text("get_rule_text", "游戏规则", deyi64);
    game_rule_back_text        = new Ui_Text("game_rule_back_text", "返回", deyi24);
    game_rule_title_text       = new Ui_Text("game_rule_title_text", "游戏规则", shuhei72);
    game_rule_title_text_1     = new Ui_Text("game_rule_title_text_1", "游戏流程", shuhei32);
    game_rule_title_text_2     = new Ui_Text("game_rule_title_text_2", "牌面点数", shuhei32);
    game_rule_title_text_3     = new Ui_Text("game_rule_title_text_3", "爆牌", shuhei32);
    game_rule_text_1           = new Ui_Text("game_rule_text_1", game_rule_string_1.c_str(), shuhei32);
    game_rule_text_2           = new Ui_Text("game_rule_text_2", game_rule_string_2.c_str(), shuhei32);
    game_rule_text_3           = new Ui_Text("game_rule_text_3", game_rule_string_3.c_str(), shuhei32);
    game_rule_text_4           = new Ui_Text("game_rule_text_4", game_rule_string_4.c_str(), shuhei32);
    set_game_player_num_text   = new Ui_Text("set_game_player_num_text", "设置玩家人数", deyi64);
    player_num_text            = new Ui_Text("player_num_text", std::to_string(GetPlayerNumSetting()).c_str(), deyi64);
    add_player_num_text        = new Ui_Text("add_player_num_text", "+", deyi64);
    sub_player_num_text        = new Ui_Text("sub_player_num_text", "-", deyi64);
    set_game_difficulty_text   = new Ui_Text("set_game_difficulty_text", "设置游戏难度", deyi64);
    game_difficulty_text_1     = new Ui_Text("game_difficulty_text_1", "简单", deyi64);
    game_difficulty_text_2     = new Ui_Text("game_difficulty_text_2", "困难", deyi64);
    start_game_text_2          = new Ui_Text("start_game_text_2", "开          始          游          戏", deyi64);
    ensure_deal_text           = new Ui_Text("ensure_deal_text", "发牌", deyi24);
    acting_player_name_text    = new Ui_Text("acting_player_name_text", "玩家", deyi48);
    action_tip_text            = new Ui_Text("action_tip_text", "要牌吗？", deyi48);
    yes_action_text            = new Ui_Text("yes_action_text", "要牌", deyi32);
    no_action_text             = new Ui_Text("no_action_text", "停牌", deyi32);
    go_to_result_page_text     = new Ui_Text("go_to_result_page_text", "胜负已分！        继续 >>", deyi64);
    result_text                = new Ui_Text("result_winner_name_text", "玩家胜利", shuhei128);
    replay_text                = new Ui_Text("replay_text", "再玩一局", deyi64);
    go_back_to_start_menu_text = new Ui_Text("go_back_to_start_menu_text", "返回菜单", deyi64);
    import_game_text           = new Ui_Text("import_game_text", "导入", deyi24);
    export_game_text           = new Ui_Text("export_game_text", "导出", deyi24);
    // 设置文本颜色
    author_sign                -> set_color(COLOR_FAKEWHITE);
    start_game_text            -> set_color(COLOR_BUTTONYELLOW);
    get_rule_text              -> set_color(COLOR_BUTTONYELLOW);
    game_rule_back_text        -> set_color(COLOR_BUTTONYELLOW);
    game_rule_title_text       -> set_color(COLOR_TITLEORANGE);
    game_rule_title_text_1     -> set_color(COLOR_TITLEORANGE);
    game_rule_title_text_2     -> set_color(COLOR_TITLEORANGE);
    game_rule_title_text_3     -> set_color(COLOR_TITLEORANGE);
    game_rule_text_1           -> set_color(COLOR_FAKEWHITE);
    game_rule_text_2           -> set_color(COLOR_FAKEWHITE);
    game_rule_text_3           -> set_color(COLOR_FAKEWHITE);
    game_rule_text_4           -> set_color(COLOR_FAKEWHITE);
    set_game_player_num_text   -> set_color(COLOR_FAKEWHITE);
    player_num_text            -> set_color(COLOR_FAKEWHITE);
    add_player_num_text        -> set_color(COLOR_FAKEWHITE);
    sub_player_num_text        -> set_color(COLOR_FAKEWHITE);
    set_game_difficulty_text   -> set_color(COLOR_FAKEWHITE);
    start_game_text_2          -> set_color(COLOR_BUTTONYELLOW);
    ensure_deal_text           -> set_color(COLOR_BUTTONYELLOW);
    acting_player_name_text    -> set_color(COLOR_BUTTONYELLOW);
    action_tip_text            -> set_color(COLOR_FAKEWHITE);
    yes_action_text            -> set_color(COLOR_BUTTONYELLOW);
    no_action_text             -> set_color(COLOR_BUTTONYELLOW);
    go_to_result_page_text     -> set_color(COLOR_BUTTONYELLOW);
    replay_text                -> set_color(COLOR_BUTTONYELLOW);
    go_back_to_start_menu_text -> set_color(COLOR_BUTTONYELLOW);
    import_game_text           -> set_color(COLOR_BUTTONYELLOW);
    export_game_text           -> set_color(COLOR_BUTTONYELLOW);
    if (GetGameDifficultySetting() == 1)
    {
        game_difficulty_text_1 -> set_color(COLOR_BUTTONYELLOW);
        game_difficulty_text_2 -> set_color(COLOR_FAKEWHITE);
    }
    else
    {
        game_difficulty_text_1 -> set_color(COLOR_FAKEWHITE);
        game_difficulty_text_2 -> set_color(COLOR_BUTTONYELLOW);
    }
    // 设置文本换行宽度
    TTF_SetTextWrapWidth(game_rule_text_1->text, 1100);
    TTF_SetTextWrapWidth(game_rule_text_2->text, 1100);
    TTF_SetTextWrapWidth(game_rule_text_3->text, 1100);
    TTF_SetTextWrapWidth(game_rule_text_4->text, 1100);
}

/**
 * @brief 释放文本
 */
void Text_Release(void)
{
    delete
        start_game_text,
        get_rule_text,
        game_rule_back_text,
        game_rule_title_text,
        game_rule_title_text_1,
        game_rule_title_text_2,
        game_rule_title_text_3,
        game_rule_text_1,
        game_rule_text_2,
        game_rule_text_3,
        game_rule_text_4,
        set_game_player_num_text,
        player_num_text,
        add_player_num_text,
        sub_player_num_text,
        set_game_difficulty_text,
        game_difficulty_text_1,
        game_difficulty_text_2,
        start_game_text_2,
        ensure_deal_text,
        acting_player_name_text,
        action_tip_text,
        yes_action_text,
        no_action_text,
        go_to_result_page_text,
        result_text,
        replay_text,
        go_back_to_start_menu_text,
        import_game_text,
        export_game_text,
        author_sign
    ;
}
