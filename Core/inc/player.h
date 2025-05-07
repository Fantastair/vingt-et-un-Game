#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../main.h"

#define PLAYER_HEAD_SIZE 100

/**
 * @brief 游戏玩家类
 */
class Player : public Ui
{
    public:
        Ui_Image *head;                                // 玩家头像
        Ui_Text *name;                                 // 玩家名称
        Ui_Image *full_medal;                          // 爆牌图标
        Ui_Image *born_with_21_medal;                  // 天生 21 点图标
        std::list<Card*> hand_cards;                   // 玩家手牌列表
        int num;                                       // 玩家编号
        int show_medal_flag;                           // 图标显示标志，0：不显示，1：显示爆牌图标，2：显示天生 21 点图标

        Player(int player_num);
        virtual ~Player();

        virtual void render(void);                     // 渲染函数
        virtual void set_topleft(float x, float y);    // 设置玩家位置
        virtual void show_medal(int medal_flag);       // 显示图标

        virtual void GetCard(Card *card);              // 玩家获取一张卡牌
        virtual int CalcCardValue(void);               // 计算手牌点数
        virtual int CalcMinCardValue(void);            // 计算手牌最小点数
        virtual void return_cards(void);               // 归还手牌
};

/**
 * @brief 游戏电脑类
 * @details 继承自 Player 类，表示庄家
 */
class Computer : public Player
{
    public:
        Computer();
        virtual ~Computer();

        virtual void render(void);
};


#endif
