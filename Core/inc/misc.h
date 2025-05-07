#ifndef __MISC_H__
#define __MISC_H__

#define GAME_SETTINGS_FILE "settings.ini"    // 游戏设置文件名

void GameSettings_Init(void);       // 初始化游戏设置
void GameSettings_Release(void);    // 释放游戏设置

int GetPlayerNumSetting(void);                                                // 读取玩家人数设置
void SetPlayerNumSetting(int player_num);                                     // 修改玩家人数设置
int GetGameDifficultySetting(void);                                           // 读取游戏难度设置
void SetGameDifficultySetting(int game_difficulty);                           // 修改游戏难度设置
std::string GetPlayerNameSetting(int player_num);                             // 读取玩家名称设置
void SetPlayerNameSetting(int player_num, const std::string& player_name);    // 修改玩家名称设置

void GetPlayerPos(int player_num, float& x, float& y);    // 获取玩家位置

int MyRandomInt(int min, int max);    // 随机整数

#endif
