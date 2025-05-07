#ifndef __RULE_H__
#define __RULE_H__

extern Ui_Text
    *start_game_text,
    *get_rule_text,
    *game_rule_back_text,
    *game_rule_title_text,
    *game_rule_title_text_1,
    *game_rule_title_text_2,
    *game_rule_title_text_3,
    *game_rule_text_1,
    *game_rule_text_2,
    *game_rule_text_3,
    *game_rule_text_4,
    *set_game_player_num_text,
    *player_num_text,
    *add_player_num_text,
    *sub_player_num_text,
    *set_game_difficulty_text,
    *game_difficulty_text_1,
    *game_difficulty_text_2,
    *start_game_text_2,
    *ensure_deal_text,
    *acting_player_name_text,
    *action_tip_text,
    *yes_action_text,
    *no_action_text,
    *go_to_result_page_text,
    *result_text,
    *replay_text,
    *author_sign,
    *import_game_text,
    *export_game_text,
    *go_back_to_start_menu_text
;

void Text_Init(void);
void Text_Release(void);

#endif
