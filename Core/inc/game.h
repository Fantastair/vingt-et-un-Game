#ifndef __GAME_H__
#define __GAME_H__

void Game_Init(void);
void Game_Release(void);
void Game_Start(void);
void Game_End(void);

void Deal_Card(void);
void handle_action(void);

void Yes_Action(void);
void No_Action(void);
void Maker_AskCard(void);
void Maker_No_Action(void);

void Announce_End(void);
void GoToResultPage(void);
void Check_Result(void);

void BackToMainMenu(void);
void PlayAgain(void);

void ImportGame(void);
void ExportGame(void);

#endif
