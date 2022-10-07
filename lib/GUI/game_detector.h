
#ifndef GAME_DETECTOR_H
#define GAME_DETECTOR_H


#include "SGUI.h"


//#define GAME_DECETOR_DEBUG


#define GAME_DETECTOR_PAGE 4


#define GAME_DETECTOR_POWER_OFF_COLOR 0xAD55
#define GAME_DETECTOR_POWER_ON_COLOR 0x6DCA
#define GAME_DETECTOR_ACTIVE_COLOR 0x0000


#define GAME_DETECTOR_B_NEXT_P 4
#define GAME_DETECTOR_B_NEXT_X0 869
#define GAME_DETECTOR_B_NEXT_Y0 510
#define GAME_DETECTOR_B_NEXT_X1 GAME_DETECTOR_B_NEXT_X0+120
#define GAME_DETECTOR_B_NEXT_Y1 GAME_DETECTOR_B_NEXT_Y0+70
#define GAME_DETECTOR_B_NEXT_RX 10
#define GAME_DETECTOR_B_NEXT_RY 10
#define GAME_DETECTOR_B_NEXT_FW 2
#define GAME_DETECTOR_B_NEXT_BC 0x4BC6
#define GAME_DETECTOR_B_NEXT_FC 0xFFFF
#define GAME_DETECTOR_B_NEXT_T "������"
#define GAME_DETECTOR_B_NEXT_TS FONT_SIZE_32
#define GAME_DETECTOR_B_NEXT_TC 0
#define GAME_DETECTOR_B_NEXT_TMX 0
#define GAME_DETECTOR_B_NEXT_TMY 0
#define GAME_DETECTOR_B_NEXT_STATE 1
#define GAME_DETECTOR_B_NEXT_DELAY 500
#define GAME_DETECTOR_B_NEXT_ACT btn_next

#define GAME_DETECTOR_B_CLEAR_P 4
#define GAME_DETECTOR_B_CLEAR_X0 435
#define GAME_DETECTOR_B_CLEAR_Y0 510
#define GAME_DETECTOR_B_CLEAR_X1 GAME_DETECTOR_B_CLEAR_X0+150
#define GAME_DETECTOR_B_CLEAR_Y1 GAME_DETECTOR_B_CLEAR_Y0+70
#define GAME_DETECTOR_B_CLEAR_RX 10
#define GAME_DETECTOR_B_CLEAR_RY 10
#define GAME_DETECTOR_B_CLEAR_FW 2
#define GAME_DETECTOR_B_CLEAR_BC 0xFFFF
#define GAME_DETECTOR_B_CLEAR_FC 0x3823
#define GAME_DETECTOR_B_CLEAR_T "��������"
#define GAME_DETECTOR_B_CLEAR_TS FONT_SIZE_32
#define GAME_DETECTOR_B_CLEAR_TC 0
#define GAME_DETECTOR_B_CLEAR_TMX 0
#define GAME_DETECTOR_B_CLEAR_TMY 0
#define GAME_DETECTOR_B_CLEAR_STATE 1
#define GAME_DETECTOR_B_CLEAR_DELAY 500
#define GAME_DETECTOR_B_CLEAR_ACT btn_clear


#define GAME_DETECTOR_PORTAL_WIDTH_X 40
#define GAME_DETECTOR_PORTAL_SPACE_X GAME_DETECTOR_PORTAL_WIDTH_X*2


#define GAME_DETECTOR_PORTAL_SMALL_X0 450
#define GAME_DETECTOR_PORTAL_SMALL_Y0 220
#define GAME_DETECTOR_PORTAL_SMALL_X1 GAME_DETECTOR_PORTAL_SMALL_X0+GAME_DETECTOR_PORTAL_WIDTH_X
#define GAME_DETECTOR_PORTAL_SMALL_Y1 GAME_DETECTOR_PORTAL_SMALL_Y0+180
#define GAME_DETECTOR_PORTAL_SMALL_RX 5
#define GAME_DETECTOR_PORTAL_SMALL_RY 5
#define GAME_DETECTOR_PORTAL_SMALL_FW 4
#define GAME_DETECTOR_PORTAL_SMALL_FC GAME_DETECTOR_POWER_ON_COLOR

#define GAME_DETECTOR_SWIPE_PORTAL_SMALL_X0 GAME_DETECTOR_PORTAL_SMALL_X0
#define GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0 GAME_DETECTOR_PORTAL_SMALL_Y0
#define GAME_DETECTOR_SWIPE_PORTAL_SMALL_X1 GAME_DETECTOR_PORTAL_SMALL_X1
#define GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1 GAME_DETECTOR_PORTAL_SMALL_Y1
#define GAME_DETECTOR_SWIPE_PORTAL_SMALL_DIRECTION SWIPE_TOUCH

#define GAME_DETECTOR_B_START_ID 3
#define GAME_DETECTOR_B_START_P 4
#define GAME_DETECTOR_B_START_X0 GAME_DETECTOR_PORTAL_SMALL_X0
#define GAME_DETECTOR_B_START_Y0 GAME_DETECTOR_PORTAL_SMALL_Y0
#define GAME_DETECTOR_B_START_X1 GAME_DETECTOR_PORTAL_SMALL_X1
#define GAME_DETECTOR_B_START_Y1 GAME_DETECTOR_PORTAL_SMALL_Y1
#define GAME_DETECTOR_B_START_RX GAME_DETECTOR_PORTAL_SMALL_RX
#define GAME_DETECTOR_B_START_RY GAME_DETECTOR_PORTAL_SMALL_RY
#define GAME_DETECTOR_B_START_FW GAME_DETECTOR_PORTAL_SMALL_FW
#define GAME_DETECTOR_B_START_BC GAME_DETECTOR_POWER_OFF_COLOR
#define GAME_DETECTOR_B_START_FC GAME_DETECTOR_POWER_ON_COLOR
#define GAME_DETECTOR_B_START_T " "
#define GAME_DETECTOR_B_START_TS FONT_SIZE_32
#define GAME_DETECTOR_B_START_TC 0
#define GAME_DETECTOR_B_START_TMX 0
#define GAME_DETECTOR_B_START_TMY 0
#define GAME_DETECTOR_B_START_STATE 1
#define GAME_DETECTOR_B_START_DELAY 500
#define GAME_DETECTOR_B_START_ACT btn_start


#define GAME_DETECTOR_PORTAL_BIG_X0 GAME_DETECTOR_PORTAL_SMALL_X1+1
#define GAME_DETECTOR_PORTAL_BIG_Y0 200
#define GAME_DETECTOR_PORTAL_BIG_X1 GAME_DETECTOR_PORTAL_BIG_X0+GAME_DETECTOR_PORTAL_WIDTH_X
#define GAME_DETECTOR_PORTAL_BIG_Y1 GAME_DETECTOR_PORTAL_BIG_Y0+220
#define GAME_DETECTOR_PORTAL_BIG_RX 5
#define GAME_DETECTOR_PORTAL_BIG_RY 5
#define GAME_DETECTOR_PORTAL_BIG_FW 4
#define GAME_DETECTOR_PORTAL_BIG_FC GAME_DETECTOR_POWER_ON_COLOR

#define GAME_DETECTOR_SWIPE_PORTAL_BIG_X0 GAME_DETECTOR_PORTAL_BIG_X0
#define GAME_DETECTOR_SWIPE_PORTAL_BIG_Y0 GAME_DETECTOR_PORTAL_BIG_Y0
#define GAME_DETECTOR_SWIPE_PORTAL_BIG_X1 GAME_DETECTOR_PORTAL_BIG_X1
#define GAME_DETECTOR_SWIPE_PORTAL_BIG_Y1 GAME_DETECTOR_PORTAL_BIG_Y1
#define GAME_DETECTOR_SWIPE_PORTAL_BIG_DIRECTION SWIPE_TOUCH


#define GAME_DETECTOR_DETECTOR_X0 845
#define GAME_DETECTOR_DETECTOR_Y0 180
#define GAME_DETECTOR_DETECTOR_X1 GAME_DETECTOR_DETECTOR_X0+150
#define GAME_DETECTOR_DETECTOR_Y1 GAME_DETECTOR_DETECTOR_Y0+260
#define GAME_DETECTOR_DETECTOR_RX 5
#define GAME_DETECTOR_DETECTOR_RY 5
#define GAME_DETECTOR_DETECTOR_FW 4
#define GAME_DETECTOR_DETECTOR_FC 0x0000


#define GAME_DETECTOR_DETECTOR_X0 850
#define GAME_DETECTOR_DETECTOR_Y0 180
#define GAME_DETECTOR_DETECTOR_X1 GAME_DETECTOR_DETECTOR_X0+120
#define GAME_DETECTOR_DETECTOR_Y1 GAME_DETECTOR_DETECTOR_Y0+260
#define GAME_DETECTOR_DETECTOR_RX 5
#define GAME_DETECTOR_DETECTOR_RY 5
#define GAME_DETECTOR_DETECTOR_FW 4
#define GAME_DETECTOR_DETECTOR_FC GAME_DETECTOR_POWER_ON_COLOR


#define IONS 12
#define IONS_ROWS 4
#define IONS_COLUMNS 3
#define ION_COLOR_OFF GAME_DETECTOR_POWER_OFF_COLOR
#define ION_COLOR_CHARGED 0x619B
#define ION_COLOR_DETECTED 0x081F
#define IONS_COLUMN_SHIF_X GAME_DETECTOR_PORTAL_WIDTH_X
#define IONS_COLUMN_1_X GAME_DETECTOR_PORTAL_SMALL_X0-3*GAME_DETECTOR_PORTAL_WIDTH_X+8
#define IONS_COLUMN_2_X IONS_COLUMN_1_X+IONS_COLUMN_SHIF_X
#define IONS_COLUMN_3_X IONS_COLUMN_2_X+IONS_COLUMN_SHIF_X
#define IONS_Y GAME_DETECTOR_PORTAL_SMALL_Y0
#define IONS_ANIM_SPEED 60
#define IONS_ANIM_LEN 13
#define IONS_ANIM_PORTAL_START 1
#define IONS_ANIM_PORTAL_END 9
#define IONS_ANIM_DETECTOR_START 11
#define IONS_ANIM_DETECTOR_END 13


#define GAME_DETECTOR_HEADER_1_X IONS_COLUMN_1_X
#define GAME_DETECTOR_HEADER_2_X GAME_DETECTOR_PORTAL_SMALL_X0+GAME_DETECTOR_PORTAL_WIDTH_X
#define GAME_DETECTOR_HEADER_3_X GAME_DETECTOR_DETECTOR_X0
#define GAME_DETECTOR_HEADER_Y IONS_Y+215

#define GAME_DETECTOR_HEADER_1_TEXT "�����"
#define GAME_DETECTOR_HEADER_2_TEXT "��������������\n  � ���������"
#define GAME_DETECTOR_HEADER_3_TEXT "��������"


#define GAME_DETECTOR_STATUS_BAR_AREA_X0 GAME_DETECTOR_B_CLEAR_X1+2
#define GAME_DETECTOR_STATUS_BAR_AREA_Y0 500
#define GAME_DETECTOR_STATUS_BAR_AREA_X1 880
#define GAME_DETECTOR_STATUS_BAR_AREA_Y1 599

#define GAME_DETECTOR_STATUS_BAR_TEXT_X GAME_DETECTOR_STATUS_BAR_AREA_X0
#define GAME_DETECTOR_STATUS_BAR_TEXT_Y GAME_DETECTOR_STATUS_BAR_AREA_Y0
#define GAME_DETECTOR_STATUS_BAR_TEXT_ACT "    �������!\n    ��������\n ��������������!"
#define GAME_DETECTOR_STATUS_BAR_TEXT_DETECTOR "    �������!\n  ����� �����\n   � ������!"
#define GAME_DETECTOR_STATUS_BAR_TEXT_FREE "     ���� ����\n     ��������!"


void game_detector_init(void);
void game_detector_handler(void);
void game_detector_cleaner(void);


#endif
