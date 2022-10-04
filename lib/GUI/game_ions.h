
#ifndef GAME_IONS_H
#define GAME_IONS_H


#define GAME_IONS_BUTTONS 1


#define GAME_IONS_PAGE 1


#define GAME_IONS_L_SCORE_P GAME_IONS_PAGE
#define GAME_IONS_L_SCORE_X0 645
#define GAME_IONS_L_SCORE_Y0 545
#define GAME_IONS_L_SCORE_X1 GAME_IONS_L_SCORE_X0+40
#define GAME_IONS_L_SCORE_Y1 GAME_IONS_L_SCORE_Y0+40
#define GAME_IONS_L_SCORE_RX 0
#define GAME_IONS_L_SCORE_RY 0
#define GAME_IONS_L_SCORE_FW 0
#define GAME_IONS_L_SCORE_BC 0xFFFF
#define GAME_IONS_L_SCORE_FC 0x0000
#define GAME_IONS_L_SCORE_T "0"
#define GAME_IONS_L_SCORE_TS FONT_SIZE_32
#define GAME_IONS_L_SCORE_TC 0x4BC6
#define GAME_IONS_L_SCORE_TMX 2
#define GAME_IONS_L_SCORE_TMY 2
#define GAME_IONS_L_SCORE_ACT 0

#define GAME_IONS_B_CLEAR_P GAME_IONS_PAGE
#define GAME_IONS_B_CLEAR_X0 435
#define GAME_IONS_B_CLEAR_Y0 510
#define GAME_IONS_B_CLEAR_X1 GAME_IONS_B_CLEAR_X0+120
#define GAME_IONS_B_CLEAR_Y1 GAME_IONS_B_CLEAR_Y0+70
#define GAME_IONS_B_CLEAR_RX 10
#define GAME_IONS_B_CLEAR_RY 10
#define GAME_IONS_B_CLEAR_FW 2
#define GAME_IONS_B_CLEAR_BC 0xFFFF
#define GAME_IONS_B_CLEAR_FC 0x3823
#define GAME_IONS_B_CLEAR_T 0
#define GAME_IONS_B_CLEAR_TC 0
#define GAME_IONS_B_CLEAR_TMX 0
#define GAME_IONS_B_CLEAR_TMY 0
#define GAME_IONS_B_CLEAR_STATE 1
#define GAME_IONS_B_CLEAR_DELAY 500
#define GAME_IONS_B_CLEAR_ACT btn_clear

#define GAME_IONS_C_P GAME_IONS_PAGE
#define GAME_IONS_C_X0 395
#define GAME_IONS_C_Y0 145
#define GAME_IONS_C_X1 900
#define GAME_IONS_C_Y1 480
#define GAME_IONS_C_RX 10
#define GAME_IONS_C_RY 10
#define GAME_IONS_C_FW 2
#define GAME_IONS_C_CC 0xFFFF
#define GAME_IONS_C_FC 0x21E2
#define GAME_IONS_C_PW 20
#define GAME_IONS_C_PC 0x0000
#define GAME_IONS_C_ACT cnvs_drawStar


void game_ions_init(void);


#endif