
#include "gui_impl.h"
#include "game_ions.h"
#include "SGUI.h"
#include "Timer.h"


enum gameLinAccelLevel
{
  START = 0,
  FINISH
};


static unsigned short gameLevel = START;
static unsigned short ionsScore = 0;
extern unsigned short gameMode;


static void btn_clear(void)
{
  SGUI_buttonInUsage(GAME_IONS_B_NEXT_P, 1, false);
  SGUI_buttonVisibility(GAME_IONS_B_NEXT_P, 1, false);  
  SGUI_canvasClear(1, 0);
  SGUI_canvasSetFrameColor(GAME_IONS_C_P, GAME_IONS_C_ID, GAME_IONS_C_FC);
  ionsScore = 0;
  gameLevel = START;
  SGUI_drawFilledFrame(GAME_IONS_STATUS_BAR_AREA_X0,
                       GAME_IONS_STATUS_BAR_AREA_Y0,
                       GAME_IONS_STATUS_BAR_AREA_X1,
                       GAME_IONS_STATUS_BAR_AREA_Y1,
                       0, 0, 0, 0xFFFF, 0xFFFF);
  SGUI_printString(GAME_IONS_T_SCORE_HEADER_T, GAME_IONS_T_SCORE_HEADER_X, GAME_IONS_T_SCORE_HEADER_Y, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
  SGUI_printString("ионов", 685, 545, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
  SGUI_labelSetText(1, 0, SGUI_intToStr(ionsScore), GAME_IONS_L_SCORE_TS, GAME_IONS_L_SCORE_TC);
  SGUI_canvasActive(GAME_IONS_C_P, GAME_IONS_C_ID, true);
}


static void btn_next(void)
{
  SGUI_idle(DELAY_BETWEEN_PAGES);
  SGUI_showPage(2);
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
  SGUI_printString(GAME_IONS_T_SCORE_HEADER_T, GAME_IONS_T_SCORE_HEADER_X, GAME_IONS_T_SCORE_HEADER_Y, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
  SGUI_printString("ионов", 685, 545, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
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
  SGUI_createButton(GAME_IONS_B_NEXT_P,
                    GAME_IONS_B_NEXT_X0,
                    GAME_IONS_B_NEXT_Y0,
                    GAME_IONS_B_NEXT_X1,
                    GAME_IONS_B_NEXT_Y1,
                    GAME_IONS_B_NEXT_RX,
                    GAME_IONS_B_NEXT_RY,
                    GAME_IONS_B_NEXT_FW,
                    GAME_IONS_B_NEXT_BC,
                    GAME_IONS_B_NEXT_FC,
                    GAME_IONS_B_NEXT_T,
                    GAME_IONS_B_NEXT_TS,
                    GAME_IONS_B_NEXT_TC,
                    GAME_IONS_B_NEXT_TMX,
                    GAME_IONS_B_NEXT_TMY,
                    GAME_IONS_B_NEXT_STATE,
                    GAME_IONS_B_NEXT_DELAY,
                    GAME_IONS_B_NEXT_ACT);
  SGUI_buttonInUsage(GAME_IONS_B_NEXT_P, 1, false);
  SGUI_buttonVisibility(GAME_IONS_B_NEXT_P, 1, false);
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
                    GAME_IONS_B_CLEAR_TS,
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


void game_ions_handler(void)
{
  if(gameLevel == START)
  {
    if(gameMode == GAME_MODE_GAME)
    {
      if(ionsScore >= WIN_IONS_SCORE)
      {
        ionsScore = 0;
        gameLevel = FINISH;
        SGUI_canvasActive(GAME_IONS_C_P, GAME_IONS_C_ID, false);
        SGUI_canvasSetFrameColor(GAME_IONS_C_P, GAME_IONS_C_ID, GAME_IONS_WIN_COLOR);
        SGUI_drawFilledFrame(GAME_IONS_STATUS_BAR_AREA_X0,
                             GAME_IONS_STATUS_BAR_AREA_Y0,
                             GAME_IONS_STATUS_BAR_AREA_X1,
                             GAME_IONS_STATUS_BAR_AREA_Y1,
                             0, 0, 0, 0xFFFF, 0xFFFF);
        SGUI_printString("  Пучок получен!", GAME_IONS_T_SCORE_HEADER_X, GAME_IONS_T_SCORE_HEADER_Y, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
        SGUI_printString("Вперёд к линейному\n    ускорителю!", GAME_IONS_T_SCORE_HEADER_X, GAME_IONS_T_SCORE_HEADER_Y+33, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
        delay_ms(1000);
        SGUI_buttonVisibility(GAME_IONS_B_NEXT_P, 1, true);
        SGUI_buttonInUsage(GAME_IONS_B_NEXT_P, 1, true);
      }
    }
    else
    {
      if(ionsScore >= MAX_IONS_SCORE)
      {
        gameLevel = FINISH;
        SGUI_canvasActive(GAME_IONS_C_P, GAME_IONS_C_ID, false);
        SGUI_canvasSetFrameColor(GAME_IONS_C_P, GAME_IONS_C_ID, GAME_IONS_WIN_COLOR);
        SGUI_drawFilledFrame(GAME_IONS_STATUS_BAR_AREA_X0,
                             GAME_IONS_STATUS_BAR_AREA_Y0,
                             GAME_IONS_STATUS_BAR_AREA_X1,
                             GAME_IONS_STATUS_BAR_AREA_Y1,
                             0, 0, 0, 0xFFFF, 0xFFFF);
        SGUI_printString("Ионы\n  закончились:)", GAME_IONS_T_SCORE_HEADER_X, GAME_IONS_T_SCORE_HEADER_Y+20, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
      }
    }
  }
}


void game_ions_cleaner(void)
{
  SGUI_setPage(GAME_IONS_PAGE);
  btn_clear();
  SGUI_setPage(GUI.currentPage);
}
