
#include "game_ions.h"
#include "SGUI.h"


static unsigned short ionsScore = 0;


static void btn_clear(void)
{
  SGUI_canvasClear(1, 0);
  ionsScore = 0;
  SGUI_labelSetText(1, 0, SGUI_intToStr(ionsScore), GAME_IONS_L_SCORE_TS, GAME_IONS_L_SCORE_TC);
}


static void cnvs_drawStar(void)
{
  unsigned short x, y;
  SGUI_getSampleTouch(&x, &y);
  SGUI_printString("*", x, y, FONT_SIZE_48, -1, 0x0000);
  SGUI_labelSetText(1, 0, SGUI_intToStr(++ionsScore), GAME_IONS_L_SCORE_TS, GAME_IONS_L_SCORE_TC);
  SGUI_canvasIdle(1, 0, 100);
}


void game_ions_init(void)
{
  SGUI_printString("Ваш пучок:", 630, 500, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_printString("ионов", 685, 545, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_createLabel(GAME_IONS_L_SCORE_P,
                   GAME_IONS_L_SCORE_X0,
                   GAME_IONS_L_SCORE_Y0,
                   GAME_IONS_L_SCORE_X1,
                   GAME_IONS_L_SCORE_Y1,
                   GAME_IONS_L_SCORE_RX,
                   GAME_IONS_L_SCORE_RY,
                   GAME_IONS_L_SCORE_FW,
                   GAME_IONS_L_SCORE_BC,
                   GAME_IONS_L_SCORE_FC,
                   GAME_IONS_L_SCORE_T,
                   GAME_IONS_L_SCORE_TS,
                   GAME_IONS_L_SCORE_TC,
                   GAME_IONS_L_SCORE_TMX,
                   GAME_IONS_L_SCORE_TMY,
                   GAME_IONS_L_SCORE_ACT);
  SGUI_createButton(GAME_IONS_B_CLEAR_P,
                    GAME_IONS_B_CLEAR_X0,
                    GAME_IONS_B_CLEAR_Y0,
                    GAME_IONS_B_CLEAR_X1,
                    GAME_IONS_B_CLEAR_Y1,
                    GAME_IONS_B_CLEAR_RX,
                    GAME_IONS_B_CLEAR_RY,
                    GAME_IONS_B_CLEAR_FW,
                    GAME_IONS_B_CLEAR_BC,
                    GAME_IONS_B_CLEAR_FC,
                    GAME_IONS_B_CLEAR_T,
                    GAME_IONS_B_CLEAR_TC,
                    GAME_IONS_B_CLEAR_TMX,
                    GAME_IONS_B_CLEAR_TMY,
                    GAME_IONS_B_CLEAR_STATE,
                    GAME_IONS_B_CLEAR_DELAY,
                    GAME_IONS_B_CLEAR_ACT);
  SGUI_createCanvas(GAME_IONS_C_P,
                    GAME_IONS_C_X0,
                    GAME_IONS_C_Y0,
                    GAME_IONS_C_X1,
                    GAME_IONS_C_Y1,
                    GAME_IONS_C_RX,
                    GAME_IONS_C_RY,
                    GAME_IONS_C_FW,
                    GAME_IONS_C_CC,
                    GAME_IONS_C_FC,
                    GAME_IONS_C_PW,
                    GAME_IONS_C_PC,
                    GAME_IONS_C_ACT);
  GUI.pages[1]->objList.ObjCanvasList[0].activeWindow.y1 = 440;
}
