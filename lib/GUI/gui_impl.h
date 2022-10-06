
#ifndef GUI_IMPL_H
#define GUI_IMPL_H


#include "SGUI.h"


#define DELAY_BETWEEN_PAGES 80


#define P0_L_HEADER_P
#define P0_L_HEADER_X0
#define P0_L_HEADER_Y0
#define P0_L_HEADER_X1
#define P0_L_HEADER_Y1
#define P0_L_HEADER_FW
#define P0_L_HEADER_LC
#define P0_L_HEADER_FC
#define P0_L_HEADER_T
#define P0_L_HEADER_TC
#define P0_L_HEADER_TMX
#define P0_L_HEADER_TMY
#define P0_L_HEADER_ACT

#define P0_B_START_P 0
#define P0_B_START_X0 309
#define P0_B_START_Y0 24
#define P0_B_START_X1 P0_B_START_X0+340 
#define P0_B_START_Y1 P0_B_START_Y0+87
#define P0_B_START_RX 10
#define P0_B_START_RY 10
#define P0_B_START_FW 2
#define P0_B_START_BC 0x4BC6
#define P0_B_START_FC 0x21E2
#define P0_B_START_T "������ ����"
#define P0_B_START_TS FONT_SIZE_48
#define P0_B_START_TC 0xFFFF
#define P0_B_START_TMX 5
#define P0_B_START_TMY 5
#define P0_B_START_STATE 1
#define P0_B_START_DELAY 500
#define P0_B_START_ACT btn_start

#define P0_PIC_IONS_SOURCE_P 0
#define P0_PIC_IONS_SOURCE_PIC &ions_source_8bpp
#define P0_PIC_IONS_SOURCE_X 344
#define P0_PIC_IONS_SOURCE_Y 234
#define P0_PIC_IONS_SOURCE_W 270
#define P0_PIC_IONS_SOURCE_H 123
#define P0_PIC_IONS_SOURCE_RX 10
#define P0_PIC_IONS_SOURCE_RY 10
#define P0_PIC_IONS_SOURCE_FW 2
#define P0_PIC_IONS_SOURCE_FC 0x21E2

#define P0_B_IONS_SOURCE_P P0_PIC_IONS_SOURCE_P
#define P0_B_IONS_SOURCE_X0 P0_PIC_IONS_SOURCE_X
#define P0_B_IONS_SOURCE_Y0 P0_PIC_IONS_SOURCE_Y
#define P0_B_IONS_SOURCE_X1 P0_B_IONS_SOURCE_X0+P0_PIC_IONS_SOURCE_W
#define P0_B_IONS_SOURCE_Y1 P0_B_IONS_SOURCE_Y0+P0_PIC_IONS_SOURCE_H
#define P0_B_IONS_SOURCE_RX P0_PIC_IONS_SOURCE_RX
#define P0_B_IONS_SOURCE_RY P0_PIC_IONS_SOURCE_RY
#define P0_B_IONS_SOURCE_FW P0_PIC_IONS_SOURCE_FW
#define P0_B_IONS_SOURCE_BC 0x4BC6
#define P0_B_IONS_SOURCE_FC 0x21E2
#define P0_B_IONS_SOURCE_T 0
#define P0_B_IONS_SOURCE_TS 0
#define P0_B_IONS_SOURCE_TC 0
#define P0_B_IONS_SOURCE_TMX 0
#define P0_B_IONS_SOURCE_TMY 0
#define P0_B_IONS_SOURCE_STATE 1
#define P0_B_IONS_SOURCE_DELAY 500
#define P0_B_IONS_SOURCE_ACT btn_picIonsSource

#define P0_PIC_LINEAR_BOOSTER_P 0
#define P0_PIC_LINEAR_BOOSTER_PIC &linear_booster_8bpp
#define P0_PIC_LINEAR_BOOSTER_X 687
#define P0_PIC_LINEAR_BOOSTER_Y 230
#define P0_PIC_LINEAR_BOOSTER_W 270
#define P0_PIC_LINEAR_BOOSTER_H 131
#define P0_PIC_LINEAR_BOOSTER_RX 10
#define P0_PIC_LINEAR_BOOSTER_RY 10
#define P0_PIC_LINEAR_BOOSTER_FW 2
#define P0_PIC_LINEAR_BOOSTER_FC 0x21E2

#define P0_B_LINEAR_BOOSTER_P P0_PIC_LINEAR_BOOSTER_P
#define P0_B_LINEAR_BOOSTER_X0 P0_PIC_LINEAR_BOOSTER_X-2
#define P0_B_LINEAR_BOOSTER_Y0 P0_PIC_LINEAR_BOOSTER_Y-2
#define P0_B_LINEAR_BOOSTER_X1 P0_B_LINEAR_BOOSTER_X0+P0_PIC_LINEAR_BOOSTER_W+4
#define P0_B_LINEAR_BOOSTER_Y1 P0_B_LINEAR_BOOSTER_Y0+P0_PIC_LINEAR_BOOSTER_H+4
#define P0_B_LINEAR_BOOSTER_RX P0_PIC_LINEAR_BOOSTER_RX
#define P0_B_LINEAR_BOOSTER_RY P0_PIC_LINEAR_BOOSTER_RY
#define P0_B_LINEAR_BOOSTER_FW P0_PIC_LINEAR_BOOSTER_FW
#define P0_B_LINEAR_BOOSTER_BC 0x4BC6
#define P0_B_LINEAR_BOOSTER_FC 0x21E2
#define P0_B_LINEAR_BOOSTER_T 0
#define P0_B_LINEAR_BOOSTER_TS 0
#define P0_B_LINEAR_BOOSTER_TC 0
#define P0_B_LINEAR_BOOSTER_TMX 0
#define P0_B_LINEAR_BOOSTER_TMY 0
#define P0_B_LINEAR_BOOSTER_STATE 1
#define P0_B_LINEAR_BOOSTER_DELAY 500
#define P0_B_LINEAR_BOOSTER_ACT btn_picLinearBooster

#define P0_PIC_CIRCLE_BOOSTER_P 0
#define P0_PIC_CIRCLE_BOOSTER_PIC &circle_booster_8bpp
#define P0_PIC_CIRCLE_BOOSTER_X 344
#define P0_PIC_CIRCLE_BOOSTER_Y 422
#define P0_PIC_CIRCLE_BOOSTER_W 270
#define P0_PIC_CIRCLE_BOOSTER_H 135
#define P0_PIC_CIRCLE_BOOSTER_RX 10
#define P0_PIC_CIRCLE_BOOSTER_RY 10
#define P0_PIC_CIRCLE_BOOSTER_FW 2
#define P0_PIC_CIRCLE_BOOSTER_FC 0x21E2

#define P0_B_CIRCLE_BOOSTER_P P0_PIC_CIRCLE_BOOSTER_P
#define P0_B_CIRCLE_BOOSTER_X0 P0_PIC_CIRCLE_BOOSTER_X-2
#define P0_B_CIRCLE_BOOSTER_Y0 P0_PIC_CIRCLE_BOOSTER_Y-2
#define P0_B_CIRCLE_BOOSTER_X1 P0_B_CIRCLE_BOOSTER_X0+P0_PIC_CIRCLE_BOOSTER_W+4
#define P0_B_CIRCLE_BOOSTER_Y1 P0_B_CIRCLE_BOOSTER_Y0+P0_PIC_CIRCLE_BOOSTER_H+4
#define P0_B_CIRCLE_BOOSTER_RX P0_PIC_CIRCLE_BOOSTER_RX
#define P0_B_CIRCLE_BOOSTER_RY P0_PIC_CIRCLE_BOOSTER_RY
#define P0_B_CIRCLE_BOOSTER_FW P0_PIC_CIRCLE_BOOSTER_FW
#define P0_B_CIRCLE_BOOSTER_BC 0x4BC6
#define P0_B_CIRCLE_BOOSTER_FC 0x21E2
#define P0_B_CIRCLE_BOOSTER_T 0
#define P0_B_CIRCLE_BOOSTER_TS 0
#define P0_B_CIRCLE_BOOSTER_TC 0
#define P0_B_CIRCLE_BOOSTER_TMX 0
#define P0_B_CIRCLE_BOOSTER_TMY 0
#define P0_B_CIRCLE_BOOSTER_STATE 1
#define P0_B_CIRCLE_BOOSTER_DELAY 500
#define P0_B_CIRCLE_BOOSTER_ACT btn_picCircleBooster

#define P0_PIC_DETECTOR_P 0
#define P0_PIC_DETECTOR_PIC &detector_8bpp
#define P0_PIC_DETECTOR_X 687
#define P0_PIC_DETECTOR_Y 422
#define P0_PIC_DETECTOR_W 270
#define P0_PIC_DETECTOR_H 135
#define P0_PIC_DETECTOR_RX 10
#define P0_PIC_DETECTOR_RY 10
#define P0_PIC_DETECTOR_FW 2
#define P0_PIC_DETECTOR_FC 0x21E2

#define P0_B_DETECTOR_P P0_PIC_DETECTOR_P
#define P0_B_DETECTOR_X0 P0_PIC_DETECTOR_X-2
#define P0_B_DETECTOR_Y0 P0_PIC_DETECTOR_Y-2
#define P0_B_DETECTOR_X1 P0_B_DETECTOR_X0+P0_PIC_DETECTOR_W+4
#define P0_B_DETECTOR_Y1 P0_B_DETECTOR_Y0+P0_PIC_DETECTOR_H+4
#define P0_B_DETECTOR_RX P0_PIC_DETECTOR_RX
#define P0_B_DETECTOR_RY P0_PIC_DETECTOR_RY
#define P0_B_DETECTOR_FW P0_PIC_DETECTOR_FW
#define P0_B_DETECTOR_BC 0x4BC6
#define P0_B_DETECTOR_FC 0x21E2
#define P0_B_DETECTOR_T 0
#define P0_B_DETECTOR_TS 0
#define P0_B_DETECTOR_TC 0
#define P0_B_DETECTOR_TMX 0
#define P0_B_DETECTOR_TMY 0
#define P0_B_DETECTOR_STATE 1
#define P0_B_DETECTOR_DELAY 500
#define P0_B_DETECTOR_ACT btn_picDetector

#define P0_PIC_JINR_P 0
#define P0_PIC_JINR_PIC &jinr_building_main_8bpp
#define P0_PIC_JINR_X 0
#define P0_PIC_JINR_Y 0
#define P0_PIC_JINR_W 270
#define P0_PIC_JINR_H 232
#define P0_PIC_JINR_RX 0
#define P0_PIC_JINR_RY 0
#define P0_PIC_JINR_FW 0
#define P0_PIC_JINR_FC 0

#define P0_PIC_NICA_P 0
#define P0_PIC_NICA_PIC &nica_logo_8bpp
#define P0_PIC_NICA_X 722
#define P0_PIC_NICA_Y 15
#define P0_PIC_NICA_W 196
#define P0_PIC_NICA_H 96
#define P0_PIC_NICA_RX 0
#define P0_PIC_NICA_RY 0
#define P0_PIC_NICA_FW 0
#define P0_PIC_NICA_FC 0


// PAGE 1
#define P1_B_BACK_TO_START_P 1
#define P1_B_BACK_TO_START_X0 305
#define P1_B_BACK_TO_START_Y0 510
#define P1_B_BACK_TO_START_X1 P1_B_BACK_TO_START_X0+120
#define P1_B_BACK_TO_START_Y1 P1_B_BACK_TO_START_Y0+70
#define P1_B_BACK_TO_START_RX 10
#define P1_B_BACK_TO_START_RY 10
#define P1_B_BACK_TO_START_FW 2
#define P1_B_BACK_TO_START_BC 0x4BC6
#define P1_B_BACK_TO_START_FC 0x21E2
#define P1_B_BACK_TO_START_T "�����"
#define P1_B_BACK_TO_START_TS FONT_SIZE_32
#define P1_B_BACK_TO_START_TC 0xFFFF
#define P1_B_BACK_TO_START_TMX 5
#define P1_B_BACK_TO_START_TMY 5
#define P1_B_BACK_TO_START_STATE 1
#define P1_B_BACK_TO_START_DELAY 500
#define P1_B_BACK_TO_START_ACT btn_backToStart

#define P1_PIC_IONS_SOURCE_P 1
#define P1_PIC_IONS_SOURCE_PIC &ions_source_8bpp
#define P1_PIC_IONS_SOURCE_X 0
#define P1_PIC_IONS_SOURCE_Y 0
#define P1_PIC_IONS_SOURCE_W 270
#define P1_PIC_IONS_SOURCE_H 123
#define P1_PIC_IONS_SOURCE_RX 0
#define P1_PIC_IONS_SOURCE_RY 0
#define P1_PIC_IONS_SOURCE_FW 0
#define P1_PIC_IONS_SOURCE_FC 0


// PAGE 2
#define P2_B_BACK_TO_START_P 2
#define P2_B_BACK_TO_START_X0 305
#define P2_B_BACK_TO_START_Y0 510
#define P2_B_BACK_TO_START_X1 P2_B_BACK_TO_START_X0+120
#define P2_B_BACK_TO_START_Y1 P2_B_BACK_TO_START_Y0+70
#define P2_B_BACK_TO_START_RX 10
#define P2_B_BACK_TO_START_RY 10
#define P2_B_BACK_TO_START_FW 2
#define P2_B_BACK_TO_START_BC 0x4BC6
#define P2_B_BACK_TO_START_FC 0x21E2
#define P2_B_BACK_TO_START_T "�����"
#define P2_B_BACK_TO_START_TS FONT_SIZE_32
#define P2_B_BACK_TO_START_TC 0xFFFF
#define P2_B_BACK_TO_START_TMX 5
#define P2_B_BACK_TO_START_TMY 5
#define P2_B_BACK_TO_START_STATE 1
#define P2_B_BACK_TO_START_DELAY 500
#define P2_B_BACK_TO_START_ACT btn_backToStart

#define P2_PIC_LINEAR_BOOSTER_P 2
#define P2_PIC_LINEAR_BOOSTER_PIC &linear_booster_8bpp
#define P2_PIC_LINEAR_BOOSTER_X 0
#define P2_PIC_LINEAR_BOOSTER_Y 0
#define P2_PIC_LINEAR_BOOSTER_W 270
#define P2_PIC_LINEAR_BOOSTER_H 131
#define P2_PIC_LINEAR_BOOSTER_RX 0
#define P2_PIC_LINEAR_BOOSTER_RY 0
#define P2_PIC_LINEAR_BOOSTER_FW 0
#define P2_PIC_LINEAR_BOOSTER_FC 0


// PAGE 3
#define P3_B_BACK_TO_START_P 3
#define P3_B_BACK_TO_START_X0 305
#define P3_B_BACK_TO_START_Y0 510
#define P3_B_BACK_TO_START_X1 P3_B_BACK_TO_START_X0+120
#define P3_B_BACK_TO_START_Y1 P3_B_BACK_TO_START_Y0+70
#define P3_B_BACK_TO_START_RX 10
#define P3_B_BACK_TO_START_RY 10
#define P3_B_BACK_TO_START_FW 2
#define P3_B_BACK_TO_START_BC 0x4BC6
#define P3_B_BACK_TO_START_FC 0x21E2
#define P3_B_BACK_TO_START_T "�����"
#define P3_B_BACK_TO_START_TS FONT_SIZE_32
#define P3_B_BACK_TO_START_TC 0xFFFF
#define P3_B_BACK_TO_START_TMX 5
#define P3_B_BACK_TO_START_TMY 5
#define P3_B_BACK_TO_START_STATE 1
#define P3_B_BACK_TO_START_DELAY 500
#define P3_B_BACK_TO_START_ACT btn_backToStart

#define P3_PIC_CIRCLE_BOOSTER_P 3
#define P3_PIC_CIRCLE_BOOSTER_PIC &circle_booster_8bpp
#define P3_PIC_CIRCLE_BOOSTER_X 0
#define P3_PIC_CIRCLE_BOOSTER_Y 0
#define P3_PIC_CIRCLE_BOOSTER_W 270
#define P3_PIC_CIRCLE_BOOSTER_H 135
#define P3_PIC_CIRCLE_BOOSTER_RX 0
#define P3_PIC_CIRCLE_BOOSTER_RY 0
#define P3_PIC_CIRCLE_BOOSTER_FW 0
#define P3_PIC_CIRCLE_BOOSTER_FC 0


// PAGE 4
#define P4_B_BACK_TO_START_P 4
#define P4_B_BACK_TO_START_X0 305
#define P4_B_BACK_TO_START_Y0 510
#define P4_B_BACK_TO_START_X1 P4_B_BACK_TO_START_X0+120
#define P4_B_BACK_TO_START_Y1 P4_B_BACK_TO_START_Y0+70
#define P4_B_BACK_TO_START_RX 10
#define P4_B_BACK_TO_START_RY 10
#define P4_B_BACK_TO_START_FW 2
#define P4_B_BACK_TO_START_BC 0x4BC6
#define P4_B_BACK_TO_START_FC 0x21E2
#define P4_B_BACK_TO_START_T "�����"
#define P4_B_BACK_TO_START_TS FONT_SIZE_32
#define P4_B_BACK_TO_START_TC 0xFFFF
#define P4_B_BACK_TO_START_TMX 5
#define P4_B_BACK_TO_START_TMY 5
#define P4_B_BACK_TO_START_STATE 1
#define P4_B_BACK_TO_START_DELAY 500
#define P4_B_BACK_TO_START_ACT btn_backToStart

#define P4_PIC_DETECTOR_P 4
#define P4_PIC_DETECTOR_PIC &detector_8bpp
#define P4_PIC_DETECTOR_X 0
#define P4_PIC_DETECTOR_Y 0
#define P4_PIC_DETECTOR_W 270
#define P4_PIC_DETECTOR_H 135
#define P4_PIC_DETECTOR_RX 0
#define P4_PIC_DETECTOR_RY 0
#define P4_PIC_DETECTOR_FW 0
#define P4_PIC_DETECTOR_FC 0


enum GAME_MODE
{
  GAME_MODE_FREE,
  GAME_MODE_GAME
};


void gui_init(void);


#endif
