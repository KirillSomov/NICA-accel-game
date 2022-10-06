
#ifndef GAME_CIRC_ACCEL_H
#define GAME_CIRC_ACCEL_H


#include "SGUI.h"


#define GAME_CIRC_ACCEL_POWER_OFF_COLOR 0xAD55
#define GAME_CIRC_ACCEL_POWER_ON_COLOR 0x6DCA


#define GAME_CIRC_ACCEL_B_NEXT_P 3
#define GAME_CIRC_ACCEL_B_NEXT_X0 869
#define GAME_CIRC_ACCEL_B_NEXT_Y0 510
#define GAME_CIRC_ACCEL_B_NEXT_X1 GAME_CIRC_ACCEL_B_NEXT_X0+120
#define GAME_CIRC_ACCEL_B_NEXT_Y1 GAME_CIRC_ACCEL_B_NEXT_Y0+70
#define GAME_CIRC_ACCEL_B_NEXT_RX 10
#define GAME_CIRC_ACCEL_B_NEXT_RY 10
#define GAME_CIRC_ACCEL_B_NEXT_FW 2
#define GAME_CIRC_ACCEL_B_NEXT_BC 0x4BC6
#define GAME_CIRC_ACCEL_B_NEXT_FC 0x21E2
#define GAME_CIRC_ACCEL_B_NEXT_T "������"
#define GAME_CIRC_ACCEL_B_NEXT_TS FONT_SIZE_32
#define GAME_CIRC_ACCEL_B_NEXT_TC 0xFFFF
#define GAME_CIRC_ACCEL_B_NEXT_TMX 5
#define GAME_CIRC_ACCEL_B_NEXT_TMY 5
#define GAME_CIRC_ACCEL_B_NEXT_STATE 1
#define GAME_CIRC_ACCEL_B_NEXT_DELAY 500
#define GAME_CIRC_ACCEL_B_NEXT_ACT btn_next

#define GAME_CIRC_ACCEL_B_POWER_P 3
#define GAME_CIRC_ACCEL_B_POWER_X0 560
#define GAME_CIRC_ACCEL_B_POWER_Y0 320
#define GAME_CIRC_ACCEL_B_POWER_X1 GAME_CIRC_ACCEL_B_POWER_X0+150
#define GAME_CIRC_ACCEL_B_POWER_Y1 GAME_CIRC_ACCEL_B_POWER_Y0+100
#define GAME_CIRC_ACCEL_B_POWER_RX 10
#define GAME_CIRC_ACCEL_B_POWER_RY 10
#define GAME_CIRC_ACCEL_B_POWER_FW 2
#define GAME_CIRC_ACCEL_B_POWER_BC GAME_CIRC_ACCEL_POWER_OFF_COLOR
#define GAME_CIRC_ACCEL_B_POWER_FC 0x0000
#define GAME_CIRC_ACCEL_B_POWER_T "�������\n�������"
#define GAME_CIRC_ACCEL_B_POWER_TS FONT_SIZE_32
#define GAME_CIRC_ACCEL_B_POWER_TC 0
#define GAME_CIRC_ACCEL_B_POWER_TMX 5
#define GAME_CIRC_ACCEL_B_POWER_TMY 5
#define GAME_CIRC_ACCEL_B_POWER_STATE 1
#define GAME_CIRC_ACCEL_B_POWER_DELAY 500
#define GAME_CIRC_ACCEL_B_POWER_ACT btn_circAccelPower

#define GAME_CIRC_ACCEL_B_CLEAR_P 3
#define GAME_CIRC_ACCEL_B_CLEAR_X0 870
#define GAME_CIRC_ACCEL_B_CLEAR_Y0 150
#define GAME_CIRC_ACCEL_B_CLEAR_X1 GAME_CIRC_ACCEL_B_CLEAR_X0+150
#define GAME_CIRC_ACCEL_B_CLEAR_Y1 GAME_CIRC_ACCEL_B_CLEAR_Y0+70
#define GAME_CIRC_ACCEL_B_CLEAR_RX 10
#define GAME_CIRC_ACCEL_B_CLEAR_RY 10
#define GAME_CIRC_ACCEL_B_CLEAR_FW 2
#define GAME_CIRC_ACCEL_B_CLEAR_BC 0xFFFF
#define GAME_CIRC_ACCEL_B_CLEAR_FC 0x3823
#define GAME_CIRC_ACCEL_B_CLEAR_T "��������"
#define GAME_CIRC_ACCEL_B_CLEAR_TS FONT_SIZE_32
#define GAME_CIRC_ACCEL_B_CLEAR_TC 0
#define GAME_CIRC_ACCEL_B_CLEAR_TMX 5
#define GAME_CIRC_ACCEL_B_CLEAR_TMY 5
#define GAME_CIRC_ACCEL_B_CLEAR_STATE 1
#define GAME_CIRC_ACCEL_B_CLEAR_DELAY 500
#define GAME_CIRC_ACCEL_B_CLEAR_ACT btn_clear


#define GAME_CIRC_ACCEL_PORTAL__X 490
#define GAME_CIRC_ACCEL_PORTAL__Y 245


#define GAME_CIRC_ACCEL_BOOSTER_X 630
#define GAME_CIRC_ACCEL_BOOSTER_Y 370
#define GAME_CIRC_ACCEL_BOOSTER_R 180
#define GAME_CIRC_ACCEL_BOOSTER_FW 30
#define GAME_CIRC_ACCEL_BOOSTER_C 0x0326

#define GAME_CIRC_ACCEL_PORTAL_R 45
#define GAME_CIRC_ACCEL_PORTAL_FW 2

#define GAME_CIRC_ACCEL_PORTAL_45 (unsigned short)((GAME_CIRC_ACCEL_BOOSTER_R-GAME_CIRC_ACCEL_BOOSTER_FW/2)*0.7f)
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45 (unsigned short)((GAME_CIRC_ACCEL_BOOSTER_R-GAME_CIRC_ACCEL_BOOSTER_FW/2-GAME_CIRC_ACCEL_PORTAL_R)*0.7f)


#define GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH 4
#define GAME_CIRC_ACCEL_SWIPE_LINE_COLOR 0x0000
#define GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR 0xFFFF


#define GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL (GAME_CIRC_ACCEL_PORTAL_R-10)
#define GAME_CIRC_ACCEL_SWIPE_AREA_B_POWER_X0
#define GAME_CIRC_ACCEL_SWIPE_AREA_B_POWER_Y0


#define GAME_CIRC_ACCEL_PORTAL_1_X GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_PORTAL_1_Y GAME_CIRC_ACCEL_BOOSTER_Y-GAME_CIRC_ACCEL_BOOSTER_R+GAME_CIRC_ACCEL_BOOSTER_FW/2

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X0 GAME_CIRC_ACCEL_BOOSTER_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y0 GAME_CIRC_ACCEL_PORTAL_1_Y+GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X1 GAME_CIRC_ACCEL_BOOSTER_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y1 GAME_CIRC_ACCEL_B_POWER_Y0
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_1_DIRECTION SWIPE_UP

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X0 GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y0 GAME_CIRC_ACCEL_B_POWER_Y0-1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X1 GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X0
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y1 GAME_CIRC_ACCEL_PORTAL_1_Y-GAME_CIRC_ACCEL_PORTAL_R


#define GAME_CIRC_ACCEL_PORTAL_2_X GAME_CIRC_ACCEL_BOOSTER_X+GAME_CIRC_ACCEL_PORTAL_45
#define GAME_CIRC_ACCEL_PORTAL_2_Y GAME_CIRC_ACCEL_BOOSTER_Y-GAME_CIRC_ACCEL_PORTAL_45

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X0 GAME_CIRC_ACCEL_BOOSTER_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y0 GAME_CIRC_ACCEL_PORTAL_2_Y+GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X1 GAME_CIRC_ACCEL_PORTAL_2_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y1 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_2_DIRECTION SWIPE_UP

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X0 GAME_CIRC_ACCEL_BOOSTER_X+25
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y0 GAME_CIRC_ACCEL_B_POWER_Y0-4
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X1 GAME_CIRC_ACCEL_BOOSTER_X+GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y1 GAME_CIRC_ACCEL_BOOSTER_Y-GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45


#define GAME_CIRC_ACCEL_PORTAL_3_X GAME_CIRC_ACCEL_BOOSTER_X+GAME_CIRC_ACCEL_BOOSTER_R-GAME_CIRC_ACCEL_BOOSTER_FW/2
#define GAME_CIRC_ACCEL_PORTAL_3_Y GAME_CIRC_ACCEL_BOOSTER_Y

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X0 GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y0 GAME_CIRC_ACCEL_BOOSTER_Y-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X1 GAME_CIRC_ACCEL_PORTAL_3_X-GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y1 GAME_CIRC_ACCEL_BOOSTER_Y+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_3_DIRECTION SWIPE_RIGHT

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X0 GAME_CIRC_ACCEL_B_POWER_X1+1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y0 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X1 GAME_CIRC_ACCEL_PORTAL_3_X-45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y1 GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y0


#define GAME_CIRC_ACCEL_PORTAL_4_X GAME_CIRC_ACCEL_PORTAL_2_X
#define GAME_CIRC_ACCEL_PORTAL_4_Y GAME_CIRC_ACCEL_BOOSTER_Y+GAME_CIRC_ACCEL_PORTAL_45

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X0 GAME_CIRC_ACCEL_BOOSTER_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y0 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X1 GAME_CIRC_ACCEL_PORTAL_4_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y1 GAME_CIRC_ACCEL_PORTAL_4_Y-GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_4_DIRECTION SWIPE_DOWN

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X0 GAME_CIRC_ACCEL_BOOSTER_X+25
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y0 GAME_CIRC_ACCEL_B_POWER_Y1+1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X1 GAME_CIRC_ACCEL_BOOSTER_X+GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y1 GAME_CIRC_ACCEL_BOOSTER_Y+GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45


#define GAME_CIRC_ACCEL_PORTAL_5_X GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_PORTAL_5_Y GAME_CIRC_ACCEL_BOOSTER_Y+GAME_CIRC_ACCEL_BOOSTER_R-GAME_CIRC_ACCEL_BOOSTER_FW/2

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X0 GAME_CIRC_ACCEL_BOOSTER_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y0 GAME_CIRC_ACCEL_BOOSTER_Y+1
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X1 GAME_CIRC_ACCEL_BOOSTER_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y1 GAME_CIRC_ACCEL_PORTAL_5_Y-GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_5_DIRECTION SWIPE_DOWN

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X0 GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y0 GAME_CIRC_ACCEL_B_POWER_Y1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X1 GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X0
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y1 GAME_CIRC_ACCEL_PORTAL_5_Y+GAME_CIRC_ACCEL_PORTAL_R


#define GAME_CIRC_ACCEL_PORTAL_6_X GAME_CIRC_ACCEL_BOOSTER_X-GAME_CIRC_ACCEL_PORTAL_45
#define GAME_CIRC_ACCEL_PORTAL_6_Y GAME_CIRC_ACCEL_BOOSTER_Y+GAME_CIRC_ACCEL_PORTAL_45

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X0 GAME_CIRC_ACCEL_PORTAL_6_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y0 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X1 GAME_CIRC_ACCEL_BOOSTER_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y1 GAME_CIRC_ACCEL_PORTAL_6_Y-GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_6_DIRECTION SWIPE_DOWN

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X0 GAME_CIRC_ACCEL_BOOSTER_X-25
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y0 GAME_CIRC_ACCEL_B_POWER_Y1+1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X1 GAME_CIRC_ACCEL_BOOSTER_X-GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y1 GAME_CIRC_ACCEL_BOOSTER_Y+GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45


#define GAME_CIRC_ACCEL_PORTAL_7_X GAME_CIRC_ACCEL_BOOSTER_X-GAME_CIRC_ACCEL_BOOSTER_R+GAME_CIRC_ACCEL_BOOSTER_FW/2
#define GAME_CIRC_ACCEL_PORTAL_7_Y GAME_CIRC_ACCEL_BOOSTER_Y

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X0 GAME_CIRC_ACCEL_PORTAL_7_X+GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y0 GAME_CIRC_ACCEL_BOOSTER_Y-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X1 GAME_CIRC_ACCEL_BOOSTER_X
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y1 GAME_CIRC_ACCEL_BOOSTER_Y+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_7_DIRECTION SWIPE_LEFT

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X0 GAME_CIRC_ACCEL_B_POWER_X0-1
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y0 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X1 GAME_CIRC_ACCEL_PORTAL_7_X+45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y1 GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y0


#define GAME_CIRC_ACCEL_PORTAL_8_X GAME_CIRC_ACCEL_PORTAL_6_X
#define GAME_CIRC_ACCEL_PORTAL_8_Y GAME_CIRC_ACCEL_BOOSTER_Y-GAME_CIRC_ACCEL_PORTAL_45

#define GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X0 GAME_CIRC_ACCEL_PORTAL_8_X-45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y0 GAME_CIRC_ACCEL_PORTAL_8_Y+GAME_CIRC_ACCEL_SWIPE_AREA_PORTAL
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X1 GAME_CIRC_ACCEL_BOOSTER_X+45
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y1 GAME_CIRC_ACCEL_BOOSTER_Y
#define GAME_CIRC_ACCEL_SWIPE_PORTAL_8_DIRECTION SWIPE_UP

#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X0 GAME_CIRC_ACCEL_BOOSTER_X-25
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y0 GAME_CIRC_ACCEL_B_POWER_Y0-4
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X1 GAME_CIRC_ACCEL_BOOSTER_X-GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45
#define GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y1 GAME_CIRC_ACCEL_BOOSTER_Y-GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_45


void game_circAccel_init(void);
void game_circAccel_handler(void);


#endif
