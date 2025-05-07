#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "../inc/misc.h"

std::list<std::string> game_settings_temp;

/**
 * @brief 初始化游戏设置
 * @details 读取游戏设置文件，将内容缓存
 */
void GameSettings_Init(void)
{
    std::ifstream settings_file;
    settings_file.open(GAME_SETTINGS_FILE, std::ios::in);
    std::string line;
    while (std::getline(settings_file, line))
    {
        game_settings_temp.push_back(line);
    }
    settings_file.close();
}

/**
 * @brief 释放游戏设置
 * @details 释放游戏设置缓存，将缓存写入文件
 */
void GameSettings_Release(void)
{
    std::ofstream settings_file;
    settings_file.open(GAME_SETTINGS_FILE, std::ios::out | std::ios::trunc);
    for (const auto& line : game_settings_temp)
    {
        settings_file << line << std::endl;
    }
    settings_file.close();
}

/**
 * @brief 读取玩家人数设置
 * @details 读取非法的玩家人数设置是安全的，会自动修正为1-7之间的值
 * @return 玩家人数设置
 */
int GetPlayerNumSetting(void)
{
    int player_num = 0;
    for (const auto& line : game_settings_temp)
    {
        if (line.find("player_num") != std::string::npos)
        {
            player_num = std::stoi(line.substr(line.find("=") + 1));
            break;
        }
    }

    if (player_num < 1)
    {
        SetPlayerNumSetting(1);    // 如果玩家人数小于1，则设置为1
        return 1;
    }
    else if (player_num > 7)
    {
        SetPlayerNumSetting(7);    // 如果玩家人数大于7，则设置为7
        return 7;
    }
    else
    {
        return player_num;
    }
}

/**
 * @brief 修改玩家人数设置
 * @param player_num 玩家人数设置
 * @details 修改非法的玩家人数设置是安全的，会自动修正为1-7之间的值
 */
void SetPlayerNumSetting(int player_num)
{
    if (player_num < 1) { player_num = 1; }         // 如果玩家人数小于1，则设置为1
    else if (player_num > 7) { player_num = 7; }    // 如果玩家人数大于7，则设置为7

    for (auto& line : game_settings_temp)
    {
        if (line.find("player_num") != std::string::npos)
        {
            line = "player_num=" + std::to_string(player_num);
            break;
        }
    }
}

/**
 * @brief 获取游戏难度设置
 * @details 读取非法的游戏难度设置是安全的，会自动修正为1-2之间的值
 * @return 游戏难度设置，1表示简单，2表示困难
 */
int GetGameDifficultySetting(void)
{
    int game_difficulty = 0;
    for (const auto& line : game_settings_temp)
    {
        if (line.find("game_difficulty") != std::string::npos)
        {
            game_difficulty = std::stoi(line.substr(line.find("=") + 1));
            break;
        }
    }

    if (game_difficulty < 1)
    {
        SetGameDifficultySetting(1);    // 如果游戏难度小于1，则设置为1
        return 1;
    }
    else if (game_difficulty > 2)
    {
        SetGameDifficultySetting(2);    // 如果游戏难度大于2，则设置为2
        return 2;
    }
    else
    {
        return game_difficulty;
    }
}

/**
 * @brief 修改游戏难度设置
 * @param game_difficulty 游戏难度设置，1表示简单，2表示困难
 * @details 修改非法的游戏难度设置是安全的，会自动修正为1-2之间的值
 */
void SetGameDifficultySetting(int game_difficulty)
{
    if (game_difficulty < 1) { game_difficulty = 1; }         // 如果游戏难度小于1，则设置为1
    else if (game_difficulty > 2) { game_difficulty = 2; }    // 如果游戏难度大于2，则设置为2

    for (auto& line : game_settings_temp)
    {
        if (line.find("game_difficulty") != std::string::npos)
        {
            line = "game_difficulty=" + std::to_string(game_difficulty);
            break;
        }
    }
}

/**
 * @brief 获取玩家名称设置
 * @param player_num 玩家编号
 * @return 玩家名称设置
 */
std::string GetPlayerNameSetting(int player_num)
{
    std::string player_name = "player_name_" + std::to_string(player_num);
    for (const auto& line : game_settings_temp)
    {
        if (line.find(player_name) != std::string::npos)
        {
            return line.substr(line.find("=") + 1);
        }
    }
    return "玩家 - " + std::to_string(player_num + 1);    // 如果没有找到，则返回默认值
}

/**
 * @brief 修改玩家名称设置
 * @param player_num 玩家编号
 * @param player_name 玩家名称设置
 */
void SetPlayerNameSetting(int player_num, const std::string& player_name)
{
    std::string player_name_key = "player_name_" + std::to_string(player_num);
    for (auto& line : game_settings_temp)
    {
        if (line.find(player_name_key) != std::string::npos)
        {
            line = player_name_key + "=" + player_name;
            break;
        }
    }
}

float player_pos[7][7][2] = {
    { {640, 590} },
    { {400, 590}, {880, 590} },
    { {200, 570}, {640, 610}, {1080, 570} },
    { {180, 570}, {470, 610}, {810, 610}, {1100, 570} },
    { {150, 530}, {390, 605}, {640, 630}, {890, 605}, {1130, 530} },
    { {120, 490}, {300, 580}, {520, 610}, {760, 610}, {980, 580}, {1160, 490} },
    { {100, 470}, {240, 570}, {430, 615}, {640, 630}, {850, 605}, {1040, 570}, {1180, 470} },
};

/**
 * @brief 获取玩家位置
 * @param player_num 玩家编号
 * @param x 玩家左上角 x 坐标
 * @param y 玩家左上角 y 坐标
 */
void GetPlayerPos(int player_num, float &x, float &y)
{
    x = player_pos[GetPlayerNumSetting() - 1][player_num][0];
    y = player_pos[GetPlayerNumSetting() - 1][player_num][1];
}

/**
 * @brief 随机整数
 * @param min 最小值
 * @param max 最大值
 */
int MyRandomInt(int min, int max)
{
    int result = rand();
    srand(result);
    return result % (max - min + 1) + min;
}
