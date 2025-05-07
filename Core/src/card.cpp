#include "../../main.h"

Card::Card(int card_num) : Ui("card_" + std::to_string(card_num)), is_back(false)
{
    num = card_num;

    rect = new Ui_Rect("card_rect_" + std::to_string(card_num), CARD_WIDTH, CARD_HEIGHT, COLOR_FAKEWHITE);
    suit = new Ui_Image("card_suit_" + std::to_string(card_num), ("res/image/suit_" + std::to_string(get_suit()) + ".png").c_str());
    point = new Ui_Text("card_point_" + std::to_string(card_num), get_letter().c_str(), shuhei24);

    rect->set_bd(4);
    rect->set_sccolor(COLOR_BLACK);
    suit->set_size(48, 48);
    if (get_suit() % 2 == 0) { point->set_color(COLOR_SUITBLACK); }
    else { point->set_color(COLOR_SUITRED); }
}

Card::~Card()
{
    delete rect;
    delete suit;
    delete point;
}

/**
 * @brief 设置卡牌编号
 * @param card_num 卡牌编号
 */
void Card::set_num(int card_num)
{
    num = card_num;
    delete suit;
    suit = new Ui_Image("card_suit_" + std::to_string(card_num), ("res/image/suit_" + std::to_string(get_suit()) + ".png").c_str());
    point->set_text(get_letter().c_str());
    suit->set_size(48, 48);
    if (get_suit() % 2 == 0) { point->set_color(COLOR_SUITBLACK); }
    else { point->set_color(COLOR_SUITRED); }
}

/**
 * @brief 获取卡牌点数
 * @return 点数，JQK 均为 10，A 为 11
 */
int Card::get_point(void)
{
    if (num % 13 == 0) return 11;    // A
    if (num % 13 >= 10) return 10;   // JQK
    return num % 13 + 1;             // 2-10
}

/**
 * @brief 获取卡牌花色
 * @return 花色编号，0：黑桃，1：红心，2：梅花，3：方块
 */
int Card::get_suit(void)
{
    return num / 13;
}

/**
 * @brief 获取卡牌字母
 * @return 卡牌字母
 */
std::string Card::get_letter(void)
{
    if (num % 13 == 0) return "A";
    if (num % 13 == 10) return "J";
    if (num % 13 == 11) return "Q";
    if (num % 13 == 12) return "K";
    return std::to_string(num % 13 + 1);
}

/**
 * @brief 设置卡牌位置
 * @param x 卡牌左上角 x 坐标
 * @param y 卡牌左上角 y 坐标
 */
void Card::set_topleft(float x, float y)
{
    rect->set_topleft(x, y);
    suit->set_topleft(x + 9, y + 20);
    point->set_topleft(x + 2, y);
}

/**
 * @brief 渲染函数
 */
void Card::render(void)
{
    if (is_back)
    {
        rect->render();
    }
    else
    {
        rect->render();
        suit->render();
        point->render();
    }
}

/**
 * @brief 显示卡牌背面
 */
void Card::show_back(void)
{
    is_back = true;
    rect->set_bgcolor(COLOR_GRAY);
}

/**
 * @brief 显示卡牌正面
 */
void Card::show_front(void)
{
    is_back = false;
    rect->set_bgcolor(COLOR_FAKEWHITE);
}


Card *CardPool::card_list[52];    // 卡牌列表
int CardPool::next_card = 0;      // 下一个发放的卡牌

/**
 * @brief 游戏卡牌池初始化
 */
void CardPool::Init(void)
{
    for (int i = 0; i < 52; i++)
    {
        card_list[i] = new Card(i);
    }
}

/**
 * @brief 游戏卡牌池释放
 */
void CardPool::Release(void)
{
    for (int i = 0; i < 52; i++)
    {
        delete card_list[i];
        card_list[i] = nullptr;
    }
}

/**
 * @brief 洗牌
 * @details 洗牌算法使用 Fisher-Yates 洗牌算法
 */
void CardPool::Shuffle(void)
{
    for (int i = 51; i > 0; i--)
    {
        int j = MyRandomInt(0, i);
        if (j == i) continue;
        std::swap(card_list[i], card_list[j]);    // 交换卡牌
    }
    next_card = 0;
}

/**
 * @brief 获取一张卡牌
 * @return 卡牌对象指针
 */
Card *CardPool::GetCard(void)
{
    return card_list[next_card++];
}

/**
 * @brief 获取安全卡牌几率
 * @param safe_num 安全卡牌点数
 * @return 安全卡牌几率
 */
float CardPool::GetSafeCardRation(int safe_num)
{
    int safe_card_num = 0;    // 安全卡牌数
    for (int i = next_card; i < 52; i++)
    {
        if (card_list[i]->get_point() <= safe_num) safe_card_num++;
    }
    return (float)safe_card_num / (52 - next_card);    // 安全卡牌几率
}

/**
 * @brief 设置卡牌顺序
 * @param card_order 卡牌顺序字符串
 */
void CardPool::SetCardOrder(std::string card_order)
{
    std::string card_num_str = "";
    int card_num = 0;
    int card_index = 0;
    int current_index = 0;
    for (int i = 0; i < card_order.length(); i++)
    {
        if (card_order[i] == ',')
        {
            card_num = std::stoi(card_num_str);
            card_index = GetCardIndex(card_num);
            if (card_index != i)
            {
                std::swap(card_list[current_index], card_list[card_index]);    // 交换卡牌
                current_index++;
            }
            card_num_str = "";
        }
        else
        {
            card_num_str += card_order[i];
        }
    }
}

/**
 * @brief 获取卡牌索引
 * @param card_num 卡牌编号
 * @return 卡牌索引
 */
int CardPool::GetCardIndex(int card_num)
{
    for (int i = 0; i < 52; i++)
    {
        if (card_list[i]->num == card_num) return i;
    }
    return -1;    // 未找到卡牌
}
