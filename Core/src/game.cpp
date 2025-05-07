#include "../../main.h"

Player *player_list[7];         // 玩家列表
Computer *computer;             // 庄家

int next_act_player_num = 1;    // 行动的玩家编号
int action_num = 0;             // 行动编号，0 表示无动作，1 表示要牌，2 表示停牌

bool importing = false;         // 是否正在导入游戏对局


/**
 * @brief 游戏初始化
 */
void Game_Init(void)
{
    CardPool::Init();                          // 卡牌池初始化
    computer = new Computer();                 // 创建庄家对象
    for (int i = 0; i < 7; i++)
    {
        player_list[i] = new Player(i + 1);    // 创建玩家对象
    }
}

/**
 * @brief 游戏释放
 */
void Game_Release(void)
{
    for (int i = 0; i < 7; i++)
    {
        delete player_list[i];     // 释放玩家对象
    }
    delete computer;               // 释放庄家对象
    CardPool::Release();           // 卡牌池释放
}

std::list<std::string> histroy;    // 游戏对局记录

/**
 * @brief 游戏开始
 */
void Game_Start(void)
{
    computer->join(&game_main_list);              // 加入游戏主界面
    int player_num = GetPlayerNumSetting();       // 获取玩家数量设置
    for (int i = 0; i < player_num; i++)
    {
        float x, y;
        GetPlayerPos(i, x, y);                    // 获取玩家位置
        player_list[i]->set_topleft(x, y);        // 设置玩家位置
        player_list[i]->join(&game_main_list);    // 加入游戏主界面
    }
    ensure_deal_button->join(&game_main_list);    // 加入确认发牌按钮
    ensure_deal_text->join(&game_main_list);      // 加入确认发牌文本
    next_act_player_num = 1;                      // 玩家 1 下一个行动

    if (importing) { return; }
    CardPool::Shuffle();                                                                   // 洗牌
    histroy.clear();                                                                       // 清空游戏对局记录
    histroy.push_back("player_num=" + std::to_string(GetPlayerNumSetting()));              // 记录玩家数量
    histroy.push_back("game_difficulty=" + std::to_string(GetGameDifficultySetting()));    // 记录游戏难度
    std::string card_list = "card_list=";                                                  // 记录卡牌列表
    for (auto card : CardPool::card_list)
    {
        card_list += std::to_string(card->num) + ",";
    }
    histroy.push_back(card_list);
}

/**
 * @brief 游戏结束
 */
void Game_End(void)
{
    computer->leave(&game_main_list);              // 离开游戏主界面
    computer->return_cards();                      // 归还手牌
    computer->show_medal(0);                       // 隐藏图标
    int player_num = GetPlayerNumSetting();        // 获取玩家数量设置
    for (int i = 0; i < player_num; i++)
    {
        player_list[i]->leave(&game_main_list);    // 离开游戏主界面
        player_list[i]->return_cards();            // 归还手牌
        player_list[i]->show_medal(0);             // 隐藏图标
    }
}

/**
 * @brief 发牌
 */
void Deal_Card(void)
{
    CardPool::next_card = 0;
    computer->GetCard(CardPool::GetCard());              // 庄家发牌
    computer->hand_cards.front()->show_back();           // 显示背面
    for (int i = 0; i < GetPlayerNumSetting(); i++)
    {
        player_list[i]->GetCard(CardPool::GetCard());    // 玩家发牌
    }
    computer->GetCard(CardPool::GetCard());              // 庄家发第二张牌
    for (int i = 0; i < GetPlayerNumSetting(); i++)
    {
        player_list[i]->GetCard(CardPool::GetCard());    // 玩家发第二张牌
    }
    mark_update();

    // 检查开场胜负
    if (computer->CalcCardValue() == 21) { Announce_End(); return; }    // 庄家开场 21 点，游戏结束
    for (int i = 0; i < GetPlayerNumSetting(); i++)
    {
        if (player_list[i]->CalcCardValue() == 21)
        {
            Announce_End();
            return;
        }    // 玩家开场 21 点，游戏结束
    }

    ask_action_box->join(&game_main_list);
    ask_box_pointer->join(&game_main_list);
    action_tip_text->join(&game_main_list);
    acting_player_name_text->set_text(GetPlayerNameSetting(next_act_player_num - 1).c_str());
    int w, h;
    TTF_GetTextSize(acting_player_name_text->text, &w, &h);
    acting_player_name_text->set_topleft(280.0f - w / 2.0f, 60);
    acting_player_name_text->join(&game_main_list);
    yes_action_button->join(&game_main_list);
    yes_action_text->join(&game_main_list);
    no_action_button->join(&game_main_list);
    no_action_text->join(&game_main_list);
    export_game_button->join(&game_main_list);
    export_game_text->join(&game_main_list);
}

/**
 * * @brief 处理玩家行动
 */
void handle_action(void)
{
    if (action_num == 0) { return; }    // 无动作
    else if (action_num == 1)           // 要牌
    {
        player_list[next_act_player_num - 1]->GetCard(CardPool::GetCard());    // 发一张牌给玩家
        int point = player_list[next_act_player_num - 1]->CalcCardValue();    // 计算点数
        if (point > 21)    // 爆牌
        {
            // 自动停牌
            action_num = 2;
            handle_action();
            mark_update();
            return;
        }
        mark_update();
        action_num = 0;
    }
    else if (action_num == 2)           // 停牌
    {
        next_act_player_num++;    // 下一个玩家行动
        if (next_act_player_num > GetPlayerNumSetting())        // 所有玩家都行动完毕
        {
            action_num = 3;
            ask_action_box->leave(&game_main_list);
            ask_box_pointer->leave(&game_main_list);
            acting_player_name_text->leave(&game_main_list);
            action_tip_text->leave(&game_main_list);
            yes_action_button->leave(&game_main_list);
            yes_action_text->leave(&game_main_list);
            no_action_button->leave(&game_main_list);
            no_action_text->leave(&game_main_list);
            export_game_button->leave(&game_main_list);
            export_game_text->leave(&game_main_list);
            computer->hand_cards.front()->show_front();
            mark_update();
            return;
        }
        acting_player_name_text->set_text(GetPlayerNameSetting(next_act_player_num - 1).c_str());
        int w, h;
        TTF_GetTextSize(acting_player_name_text->text, &w, &h);
        acting_player_name_text->set_topleft(280.0f - w / 2.0f, 60);
        mark_update();
        action_num = 0;
    }
    else if (action_num == 3)    // 庄家行动
    {
        SDL_Delay(1000);    // 延时 1 秒
        if (computer->CalcCardValue() < 17)    // 庄家手牌点数至少 17 点
        {
            Maker_AskCard();    // 庄家要牌
        }
        else if (GetGameDifficultySetting() == 1)    // 简单模式，随机决定要牌停牌
        {
            int flag = MyRandomInt(1, 2);
            if (flag == 1)    // 要牌
            {
                Maker_AskCard();
            }
            else if (flag == 2)    // 停牌
            {
                Maker_No_Action();
            }
        }
        else if (GetGameDifficultySetting() == 2)    // 困难模式
        {
            float safe_card_ratio = CardPool::GetSafeCardRation(21 - computer->CalcMinCardValue());    // 获取安全卡牌几率
            if (safe_card_ratio >= 0.5)    // 安全卡牌几率大于 50%
            {
                Maker_AskCard();
            }
            else    // 安全卡牌几率小于等于 50%
            {
                Maker_No_Action();
            }
        }
    }
}


/**
 * @brief 要牌
 */
void Yes_Action(void)
{
    action_num = 1;
    histroy.push_back("action=1");    // 记录玩家要牌
}

/**
 * @brief 停牌
 */
void No_Action(void)
{
    action_num = 2;
    histroy.push_back("action=2");    // 记录玩家停牌
}

/**
 * @brief 宣布游戏结束
 */
void Announce_End(void)
{
    computer->hand_cards.front()->show_front();
    go_to_result_page_button->join(&game_main_list);
    go_to_result_page_text->join(&game_main_list);
    mark_update();
}

/**
 * @brief 庄家要牌
 */
void Maker_AskCard(void)
{
    // 庄家要牌
    computer->GetCard(CardPool::GetCard());    // 发一张牌给庄家
    int point = computer->CalcCardValue();     // 计算点数
    if (point > 21)    // 爆牌
    {
        action_num = 0;
        Announce_End();
        return;
    }
    mark_update();
}

/**
 * @brief 停牌结算
 */
void Maker_No_Action(void)
{
    action_num = 0;
    Announce_End();
}

void GoToResultPage(void)
{
    Ui::SetUiList(&game_result_list);
    go_to_result_page_button->leave(&game_main_list);
    go_to_result_page_text->leave(&game_main_list);
    Check_Result();
}

/**
 * @brief 结算
 */
void Check_Result(void)
{
    // 统计数据
    int points[8];
    points[0] = computer->CalcCardValue();                  // 庄家点数
    for (int i = 0; i < GetPlayerNumSetting(); i++)
    {
        points[i + 1] = player_list[i]->CalcCardValue();    // 玩家点数
    }
    
    // 分析胜负
    int result_flag;                                       // 结算结果，0 表示平局，1 表示玩家胜利，2 表示庄家胜利
    if (points[0] > 21)                                    // 庄家爆牌
    {
        result_flag = 0;                                   // 平局
        for (int i = 0; i < GetPlayerNumSetting(); i++)
        {
            if (points[i + 1] <= 21)                       // 有玩家未爆牌
            {
                result_flag = 1;                           // 玩家胜利
                break;
            }
        }
    }
    else if (points[0] == 21)                              // 庄家达到 21 点
    {
        result_flag = 2;                                   // 庄家胜利
        for (int i = 0; i < GetPlayerNumSetting(); i++)
        {
            if (points[i + 1] == 21)                       // 有玩家达到 21 点
            {
                result_flag = 0;                           // 平局
                break;
            }
        }
    }
    else                                                   // 庄家未爆牌且未达到 21 点
    {
        int max_point = 0;                                 // 最大点数
        for (int i = 0; i < GetPlayerNumSetting(); i++)
        {
            if (points[i + 1] > max_point && points[i + 1] <= 21)
            {
                max_point = points[i + 1];
            }
        }

        if (max_point > points[0]) { result_flag = 1; }          // 玩家胜利
        else if (max_point == points[0]) { result_flag = 0; }    // 平局
        else { result_flag = 2; }                                // 庄家胜利
    }
    
    // 显示结果
    if (result_flag == 0)
    {
        result_text->set_text("平局！");
        result_text->set_color(COLOR_FAKEWHITE);
        result_computer_head->join(&game_result_list);
        result_player_head->join(&game_result_list);
    }
    else if (result_flag == 1)
    {
        result_text->set_text("玩家胜利！");
        result_text->set_color(COLOR_BUTTONYELLOW);
        result_player_head->join(&game_result_list);
    }
    else if (result_flag == 2)
    {
        result_text->set_text("庄家胜利！");
        result_text->set_color(COLOR_TITLEORANGE);
        result_computer_head->join(&game_result_list);
    }
}

/**
 * @brief 返回主菜单
 */
void BackToMainMenu(void)
{
    Game_End();
    Ui::SetUiList(&start_menu_list);
    result_computer_head->leave(&game_result_list);
    result_player_head->leave(&game_result_list);
}

/**
 * @brief 再开一局
 */
void PlayAgain(void)
{
    Game_End();
    Ui::SetUiList(&start_menu_list);
    Clicked_StartGameButton();
    result_computer_head->leave(&game_result_list);
    result_player_head->leave(&game_result_list);
}

/**
 * @brief 导入游戏对局回调函数
 */ 
void SDLCALL ImportGameCallback(void*, const char * const *filelist, int)
{
    if (filelist == NULL || filelist[0] == NULL)    // 检查文件列表是否为空
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "未选择文件", NULL);
        return;
    }
    std::ifstream game_file;
    game_file.open(filelist[0], std::ios::in);
    if (!game_file.is_open())
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "文件打开失败", NULL);
        return;
    }    
    histroy.clear();
    std::string line;
    while (std::getline(game_file, line))
    {
        histroy.push_back(line);
    }    
    game_file.close();

    importing = true;    // 设置正在导入游戏对局

    line = histroy.front();                                         // 读取玩家数量
    histroy.pop_front();
    int player_num = std::stoi(line.substr(line.find('=') + 1));    // 获取玩家数量
    int offset = GetPlayerNumSetting() - player_num;                // 计算偏移量
    if (offset > 0)                                                 // 玩家数量减少
    {
        for (int i = 0; i < offset; i++)
        {
            Clicked_SubPlayerNumButton();                           // 减少玩家数量
        }
    }
    else if (offset < 0)                                            // 玩家数量增加
    {
        for (int i = 0; i < -offset; i++)
        {
            Clicked_AddPlayerNumButton();                           // 增加玩家数量
        }
    }
    line = histroy.front();                                              // 读取游戏难度
    histroy.pop_front();
    int game_difficulty = std::stoi(line.substr(line.find('=') + 1));    // 获取游戏难度
    if (game_difficulty != GetGameDifficultySetting())                   // 游戏难度不一致
    {
        Clicked_SetGameDifficultyButton();                               // 修改游戏难度
    }
    line = histroy.front();                                     // 读取卡牌列表
    histroy.pop_front();
    std::string card_list = line.substr(line.find('=') + 1);    // 获取卡牌列表
    CardPool::SetCardOrder(card_list);                          // 设置卡牌顺序
    Clicked_StartGameButton2();                                 // 开始游戏
    Clicked_EnsureDealButton();                                 // 确认发牌
    if (histroy.empty()) { importing = false; return; }         // 游戏对局记录为空
    for (auto &l : histroy)                                     // 读取玩家行动
    {
        if (l.find("action=1") != std::string::npos)            // 玩家要牌
        {
            action_num = 1;
            handle_action();
        }
        else if (l.find("action=2") != std::string::npos)       // 玩家停牌
        {
            action_num = 2;
            handle_action();
        }
    }
    histroy.push_front("card_list=" + card_list);
    histroy.push_front("game_difficulty=" + std::to_string(GetGameDifficultySetting()));
    histroy.push_front("player_num=" + std::to_string(GetPlayerNumSetting()));

    importing = false;    // 设置导入游戏对局完成
}

/**
 * @brief 导入游戏对局
 */ 
void ImportGame(void)
{
    SDL_DialogFileFilter filter = { "21Game Record", "21g" };
    SDL_ShowOpenFileDialog(ImportGameCallback, NULL, NULL, &filter, 1, NULL, false);    // 显示文件选择对话框
}

/**
 * @brief 导出游戏对局回调函数
 */
void SDLCALL ExportGameCallback(void*, const char * const *filelist, int)
{
    if (filelist == NULL || filelist[0] == NULL)    // 检查文件列表是否为空
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "未选择文件", NULL);
        return;
    }
    std::string file_name = filelist[0];    // 获取文件名
    if (file_name.substr(file_name.find_last_of('.') + 1) != "21g")
    {
        file_name += ".21g";    // 添加文件后缀
    }
    std::ofstream game_file;
    game_file.open(filelist[0], std::ios::out | std::ios::trunc);
    if (!game_file.is_open())
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "文件打开失败", NULL);
        return;
    }    
    for (const auto &line : histroy)
    {
        game_file << line << std::endl;
    }    
    game_file.close();
}

/**
 * @brief 导出游戏对局
 */
void ExportGame(void)
{
    SDL_DialogFileFilter filter = { "21Game Record", "21g" };
    SDL_ShowSaveFileDialog(ExportGameCallback, NULL, NULL, &filter, 1, NULL);
}
