#include "../../main.h"

Player::Player(int player_num) : Ui("player_" + std::to_string(player_num)), num(player_num), show_medal_flag(0)
{
    if (player_num == 0) return;
    player_num--;
    head = new Ui_Image("player_head_" + std::to_string(player_num), "res/image/player_head.png");
    name = new Ui_Text("player_name_" + std::to_string(player_num), GetPlayerNameSetting(player_num).c_str(), deyi24);
    full_medal = new Ui_Image("full_medal_" + std::to_string(player_num), "res/image/full.png");
    born_with_21_medal = new Ui_Image("born_with_21_medal_" + std::to_string(player_num), "res/image/born_with_21.png");

    head->set_size(PLAYER_HEAD_SIZE, PLAYER_HEAD_SIZE);    // 设置头像大小
    name->set_color(COLOR_FAKEWHITE);                      // 设置文本颜色
    full_medal->set_size(100, 100);                        // 设置爆牌图标大小
    born_with_21_medal->set_size(100, 100);                // 设置天生 21 点图标大小
}

Player::~Player()
{
    delete head;
    delete name;
    delete full_medal;
    delete born_with_21_medal;
}

/**
 * @brief 渲染函数
 */
void Player::render(void)
{
    head->render();    // 渲染头像
    name->render();    // 渲染名称
    float x, y;
    GetPlayerPos(num - 1, x, y);    // 获取玩家位置
    x -= 25.0f * (hand_cards.size() - 1) / 2.0f + CARD_WIDTH / 2;
    y -= PLAYER_HEAD_SIZE / 2 + 25 * hand_cards.size() + CARD_HEIGHT;
    for (auto card : hand_cards)    // 渲染手牌
    {
        card->set_topleft(x, y);    // 设置卡牌位置
        card->render();             // 渲染卡牌
        x += 25;
        y += 25;
    }
    if (show_medal_flag == 1)         // 显示爆牌图标
    {
        full_medal->render();
    }
    else if (show_medal_flag == 2)    // 显示天生 21 点图标
    {
        born_with_21_medal->render();
    }
}

/**
 * @brief 玩家获取一张卡牌
 */
void Player::GetCard(Card *card)
{
    hand_cards.push_back(card);     // 加入手牌列表
}

/**
 * @brief 玩家归还手牌
 */
void Player::return_cards(void)
{
    hand_cards.clear();    // 清空手牌列表
}

/**
 * @brief 设置玩家位置
 * @param x 玩家左上角 x 坐标
 * @param y 玩家左上角 y 坐标
 */
void Player::set_topleft(float x, float y)
{
    head->set_topleft(x - PLAYER_HEAD_SIZE / 2, y - PLAYER_HEAD_SIZE / 2);    // 设置头像位置
    int w, h;
    TTF_GetTextSize(name->text, &w, &h);
    name->set_topleft(x - w / 2, y + PLAYER_HEAD_SIZE / 2);                   // 设置名称位置
    full_medal->set_topleft(x - 50, y - 50);                                  // 设置爆牌图标位置
    born_with_21_medal->set_topleft(x - 50, y - 50);                          // 设置天生 21 点图标位置
}

/**
 * @brief 计算手牌点数
 * @details 当手牌不超过 21 点时，A 为 11 点；否则部分 A 会按照 1 点计算，以保证手牌点数不超过 21 点
 */
int Player::CalcCardValue(void)
{
    int value = 0;                                   // 点数
    int A_count = 0;                                 // A 的数量
    for (auto card : hand_cards)                     // 遍历手牌
    {
        if (card->get_letter() == "A") A_count++;    // 统计 A 的数量
        value += card->get_point();                  // 计算点数
    }
    if (value > 21)                                  // 如果点数超过 21 点
    {
        for (int i = 0; i < A_count; i++)            // 将部分 A 按照 1 点计算
        {
            value -= 10;
            if (value <= 21) break;                  // 如果点数不超过 21 点，停止计算
        }
    }
    if (value > 21) show_medal(1);                                    // 如果点数超过 21 点，显示爆牌图标
    else if (value == 21 && hand_cards.size() == 2) show_medal(2);    // 如果点数为 21 点且手牌数量为 2，显示天生 21 点图标
    else show_medal(0);                                               // 否则不显示图标
    return value;
}

/**
 * @brief 计算手牌最小点数
 * @details 所有 A 都按照 1 点计算
 */
int Player::CalcMinCardValue(void)
{
    int value = 0;                                   // 点数
    for (auto card : hand_cards)                     // 遍历手牌
    {
        if (card->get_letter() == "A") value += 1;   // A 按照 1 点计算
        else value += card->get_point();              // 计算点数
    }
    return value;
}

/**
 * @brief 显示图标
 * @param medal_flag 图标显示标志，0：不显示，1：显示爆牌图标，2：显示天生 21 点图标
 */
void Player::show_medal(int medal_flag)
{
    show_medal_flag = medal_flag;    // 设置图标显示标志
}

Computer::Computer() : Player(0)
{
    head = new Ui_Image("computer_head", "res/image/computer_head.png");
    name = new Ui_Text("computer_name", "庄家", deyi24);
    full_medal = new Ui_Image("full_medal_" + std::to_string(num), "res/image/full.png");
    born_with_21_medal = new Ui_Image("born_with_21_medal_" + std::to_string(num), "res/image/born_with_21.png");

    head->set_size(PLAYER_HEAD_SIZE, PLAYER_HEAD_SIZE);
    name->set_color(COLOR_BUTTONYELLOW);
    head->set_topleft(640 - PLAYER_HEAD_SIZE / 2, 120 - PLAYER_HEAD_SIZE / 2);
    int w, h;
    TTF_GetTextSize(name->text, &w, &h);
    name->set_topleft(640 - (float)w / 2, 120 - PLAYER_HEAD_SIZE + 25);
    full_medal->set_size(100, 100);
    born_with_21_medal->set_size(100, 100);
    full_medal->set_topleft(640 - 50, 120 - 50);
    born_with_21_medal->set_topleft(640 - 50, 120 - 50);
}

Computer::~Computer()
{

}


/**
 * @brief 渲染函数
 */
void Computer::render(void)
{
    head->render();
    name->render();
    float x = 640, y = 120;
    x -= 25.0f * (hand_cards.size() - 1) / 2.0f + CARD_WIDTH / 2;
    y += PLAYER_HEAD_SIZE / 2;
    for (auto card : hand_cards)
    {
        card->set_topleft(x, y);
        card->render();
        x += 25;
        y += 25;
    }
    if (show_medal_flag == 1)
    {
        full_medal->render();
    }
    else if (show_medal_flag == 2)
    {
        born_with_21_medal->render();
    }
}
