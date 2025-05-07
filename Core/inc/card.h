#ifndef __CARD_H__
#define __CARD_H__

#include "../../main.h"

#define CARD_WIDTH  63
#define CARD_HEIGHT 88

/**
 * @brief 游戏卡牌类
 */
class Card : public Ui
{
    public:
        int num;                                       // 卡牌编号，0 ~ 51
        bool is_back;                                  // 是否为背面

        Ui_Rect *rect;                                 // 卡牌矩形区域
        Ui_Image *suit;                                // 卡牌花色
        Ui_Text *point;                                // 卡牌点数

        Card(int card_num);
        virtual ~Card();

        virtual void render(void);                     // 渲染函数
        virtual void set_topleft(float x, float y);    // 设置卡牌位置
        void show_back(void);                          // 显示背面
        void show_front(void);                         // 显示正面

        void set_num(int card_num);                    // 设置卡牌编号
        int get_suit(void);                            // 获取卡牌花色
        int get_point(void);                           // 获取卡牌点数
        std::string get_letter(void);                  // 获取卡牌字母
};

/**
 * @brief 游戏卡牌池
 * @details 管理卡牌的发放和回收，辅助电脑决策
 */
class CardPool
{
    public:
        static Card *card_list[52];                          // 卡牌列表
        static int next_card;                                // 下一个发放的卡牌

        static void Init(void);                              // 初始化卡牌池
        static void Release(void);                           // 释放卡牌池
        static void Shuffle(void);                           // 洗牌
        static void SetCardOrder(std::string card_order);    // 设置卡牌顺序
        static Card *GetCard(void);                          // 获取一张卡牌
        static float GetSafeCardRation(int safe_num);        // 获取安全卡牌几率
        static int GetCardIndex(int card_num);               // 获取卡牌索引
};

#endif
