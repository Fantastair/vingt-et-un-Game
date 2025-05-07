#include "../../main.h"

/**
 * @brief 鼠标按下事件处理函数
 * @param x 鼠标X坐标
 * @param y 鼠标Y坐标
 * @param button 鼠标按键
 */
void Handle_MouseButtonDown(float x, float y, Uint8 button)
{
    if (button == SDL_BUTTON_LEFT)    // 如果是左键点击
    {
        for (auto it = UI_LIST.rbegin(); it != UI_LIST.rend(); ++it)
        {
            if ((*it)->clicked != nullptr)    // 如果元素有点击事件
            {
                if ((*it)->collidepoint(x, y))
                {
                    (*it)->clicked();    // 执行点击事件
                    break;
                }
            }
        }
    }
}

/**
 * @brief 开始游戏按钮点击事件处理函数
 */
void Clicked_StartGameButton(void)
{
    Ui::SetUiList(&game_setting_list);
}

/**
 * @brief 查看规则按钮点击事件处理函数
 */
void Clicked_GetRuleButton(void)
{
    Ui::SetUiList(&game_rule_list);
}

/**
 * @brief 返回按钮点击事件处理函数
 */
void Clicked_GameRuleBackButton(void)
{
    Ui::SetUiList(&start_menu_list);
}

/**
 * @brief 增加玩家人数按钮点击事件处理函数
 */
void Clicked_AddPlayerNumButton(void)
{
    if (GetPlayerNumSetting() < 7)
    {
        SetPlayerNumSetting(GetPlayerNumSetting() + 1);
        player_num_text->set_text(std::to_string(GetPlayerNumSetting()).c_str());
        mark_update();
    }
}

/**
 * @brief 减少玩家人数按钮点击事件处理函数
 */
void Clicked_SubPlayerNumButton(void)
{
    if (GetPlayerNumSetting() > 1)
    {
        SetPlayerNumSetting(GetPlayerNumSetting() - 1);
        player_num_text->set_text(std::to_string(GetPlayerNumSetting()).c_str());
        mark_update();
    }
}

/**
 * @brief 设置游戏难度按钮点击事件处理函数
 */
void Clicked_SetGameDifficultyButton(void)
{
    if (GetGameDifficultySetting() == 1)
    {
        SetGameDifficultySetting(2);
        game_difficulty_text_1     -> set_color(COLOR_FAKEWHITE);
        game_difficulty_text_2     -> set_color(COLOR_BUTTONYELLOW);
        game_difficulty_rect       -> set_topleft(830, 500);
        set_game_difficulty_button -> set_topleft(680, 500);
    }
    else
    {
        SetGameDifficultySetting(1);
        game_difficulty_text_1     -> set_color(COLOR_BUTTONYELLOW);
        game_difficulty_text_2     -> set_color(COLOR_FAKEWHITE);
        game_difficulty_rect       -> set_topleft(680, 500);
        set_game_difficulty_button -> set_topleft(830, 500);
    }
    mark_update();
}

/**
 * @brief 开始游戏按钮2点击事件处理函数
 */
void Clicked_StartGameButton2(void)
{
    Ui::SetUiList(&game_main_list);
    Game_Start();
}

/**
 * @brief 确认发牌按钮点击事件处理函数
 */
void Clicked_EnsureDealButton(void)
{
    ensure_deal_button->leave(&game_main_list);
    ensure_deal_text->leave(&game_main_list);
    mark_update();    // 更新界面
    Deal_Card();
}
