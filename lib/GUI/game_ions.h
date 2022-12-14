
#ifndef GAME_IONS_H
#define GAME_IONS_H


//#define GAME_IONS_DEBUG


#define GAME_IONS_PAGE 1


#define GAME_IONS_BUTTONS 1


#define WIN_IONS_SCORE 12
#ifdef GAME_IONS_DEBUG
#define MAX_IONS_SCORE 20
#else
#define MAX_IONS_SCORE 99
#endif
#define GAME_IONS_WIN_COLOR 0xFB00


#define GAME_IONS_L_SCORE_P GAME_IONS_PAGE
#define GAME_IONS_L_SCORE_X0 625
#define GAME_IONS_L_SCORE_Y0 545
#define GAME_IONS_L_SCORE_X1 GAME_IONS_L_SCORE_X0+60
#define GAME_IONS_L_SCORE_Y1 GAME_IONS_L_SCORE_Y0+40
#define GAME_IONS_L_SCORE_RX 0
#define GAME_IONS_L_SCORE_RY 0
#define GAME_IONS_L_SCORE_FW 0
#define GAME_IONS_L_SCORE_BC 0xFFFF
#define GAME_IONS_L_SCORE_FC 0x0000
#define GAME_IONS_L_SCORE_T "0"
#define GAME_IONS_L_SCORE_TS FONT_SIZE_32
#define GAME_IONS_L_SCORE_TC TEXT_COLOR
#define GAME_IONS_L_SCORE_TMX 2
#define GAME_IONS_L_SCORE_TMY 2
#define GAME_IONS_L_SCORE_ACT 0

#define GAME_IONS_B_NEXT_P 1
#define GAME_IONS_B_NEXT_X0 885
#define GAME_IONS_B_NEXT_Y0 510
#define GAME_IONS_B_NEXT_X1 GAME_IONS_B_NEXT_X0+120
#define GAME_IONS_B_NEXT_Y1 GAME_IONS_B_NEXT_Y0+70
#define GAME_IONS_B_NEXT_RX 10
#define GAME_IONS_B_NEXT_RY 10
#define GAME_IONS_B_NEXT_FW 2
#define GAME_IONS_B_NEXT_BC 0x4BC6
#define GAME_IONS_B_NEXT_FC 0x21E2
#define GAME_IONS_B_NEXT_T "??????"
#define GAME_IONS_B_NEXT_TS FONT_SIZE_32
#define GAME_IONS_B_NEXT_TC 0xFFFF
#define GAME_IONS_B_NEXT_TMX 0
#define GAME_IONS_B_NEXT_TMY 0
#define GAME_IONS_B_NEXT_STATE 1
#define GAME_IONS_B_NEXT_DELAY 500
#define GAME_IONS_B_NEXT_ACT btn_next

#define GAME_IONS_B_CLEAR_P GAME_IONS_PAGE
#define GAME_IONS_B_CLEAR_X0 435
#define GAME_IONS_B_CLEAR_Y0 510
#define GAME_IONS_B_CLEAR_X1 GAME_IONS_B_CLEAR_X0+150
#define GAME_IONS_B_CLEAR_Y1 GAME_IONS_B_CLEAR_Y0+70
#define GAME_IONS_B_CLEAR_RX 10
#define GAME_IONS_B_CLEAR_RY 10
#define GAME_IONS_B_CLEAR_FW 2
#define GAME_IONS_B_CLEAR_BC 0xFFFF
#define GAME_IONS_B_CLEAR_FC 0x3823
#define GAME_IONS_B_CLEAR_T "????????"
#define GAME_IONS_B_CLEAR_TS FONT_SIZE_32
#define GAME_IONS_B_CLEAR_TC 0
#define GAME_IONS_B_CLEAR_TMX 5
#define GAME_IONS_B_CLEAR_TMY 5
#define GAME_IONS_B_CLEAR_STATE 1
#define GAME_IONS_B_CLEAR_DELAY 500
#define GAME_IONS_B_CLEAR_ACT btn_clear

#define GAME_IONS_C_ID 0
#define GAME_IONS_C_P GAME_IONS_PAGE
#define GAME_IONS_C_X0 395
#define GAME_IONS_C_Y0 135
#define GAME_IONS_C_X1 900
#define GAME_IONS_C_Y1 480
#define GAME_IONS_C_RX 10
#define GAME_IONS_C_RY 10
#define GAME_IONS_C_FW 8
#define GAME_IONS_C_CC 0xFFFF
#define GAME_IONS_C_FC 0x21E2
#define GAME_IONS_C_PW 20
#define GAME_IONS_C_PC 0x0000
#define GAME_IONS_C_ACT cnvs_drawStar


#define GAME_IONS_STATUS_BAR_AREA_X0 GAME_IONS_B_CLEAR_X1+5
#define GAME_IONS_STATUS_BAR_AREA_Y0 490
#define GAME_IONS_STATUS_BAR_AREA_X1 880
#define GAME_IONS_STATUS_BAR_AREA_Y1 599

#define GAME_IONS_STATUS_BAR_TEXT_X GAME_IONS_STATUS_BAR_AREA_X0
#define GAME_IONS_STATUS_BAR_TEXT_Y GAME_IONS_STATUS_BAR_AREA_Y0


#define GAME_IONS_T_SCORE_HEADER_X GAME_IONS_STATUS_BAR_AREA_X0
#define GAME_IONS_T_SCORE_HEADER_Y GAME_IONS_STATUS_BAR_AREA_Y0+10
#define GAME_IONS_T_SCORE_HEADER_T "  ??? ?????:"


void game_ions_init(void);
void game_ions_handler(void);
void game_ions_cleaner(void);


#endif
