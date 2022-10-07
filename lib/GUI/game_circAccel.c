
#include "gui_impl.h"
#include "game_circAccel.h"
#include "stdbool.h"
#include "swipe.h"
#include "Timer.h"


//#define GAME_CIRC_ACCEL_DEBUG


static unsigned short gameLevel = 0;
extern unsigned short gameMode;

enum gameCircAccelLevel
{
  START = 0,
  PORTAL_1,
  PORTAL_2,
  PORTAL_3,
  PORTAL_4,
  PORTAL_5,
  PORTAL_6,
  PORTAL_7,
  PORTAL_8,
  BOOST_1,
  BOOST_2,
  BOOST_3,
  BOOST_4,
  BOOST_5,
  BOOST_6,
  BOOST_7,
  BOOST_8,
  FINISH
};


static void clearStatusBar(void)
{
  SGUI_drawFilledFrame(GAME_CIRC_ACCEL_STATUS_BAR_AREA_X0,
                       GAME_CIRC_ACCEL_STATUS_BAR_AREA_Y0,
                       GAME_CIRC_ACCEL_STATUS_BAR_AREA_X1,
                       GAME_CIRC_ACCEL_STATUS_BAR_AREA_Y1,
                       0, 0, 0, 0xFFFF, 0xFFFF); 
}


static void btn_next(void)
{
  SGUI_showPage(4);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void btn_circAccelPower(void)
{
  SGUI_buttonSetColor(3, 2, GAME_CIRC_ACCEL_POWER_ON_COLOR);
  SGUI_buttonInUsage(3, 2, false);
  clearStatusBar();
  SGUI_printString(GAME_CIRC_ACCEL_STATUS_BAR_TEXT_POWER,
                   GAME_CIRC_ACCEL_STATUS_BAR_TEXT_X,
                   GAME_CIRC_ACCEL_STATUS_BAR_TEXT_Y,
                   FONT_SIZE_32, 0xFFFF, 0x0000);
  setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X0,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y0,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X1,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y1,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
  SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y1,
                 0, 0, 1, 0x0000);
#endif
  useSwipe(true);
  gameLevel = PORTAL_1;
}


static void btn_clear(void)
{
  SGUI_buttonInUsage(GAME_CIRC_ACCEL_B_NEXT_P, 1, false);
  SGUI_buttonVisibility(GAME_CIRC_ACCEL_B_NEXT_P, 1, false);
  SGUI_buttonSetColor(3, 2, GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_buttonInUsage(3, 2, true);
  useSwipe(false);
  clearStatusBar();
  gameLevel = START;
  
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_1_X,
                        GAME_CIRC_ACCEL_PORTAL_1_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_2_X,
                        GAME_CIRC_ACCEL_PORTAL_2_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_3_X,
                        GAME_CIRC_ACCEL_PORTAL_3_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_4_X,
                        GAME_CIRC_ACCEL_PORTAL_4_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_5_X,
                        GAME_CIRC_ACCEL_PORTAL_5_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_6_X,
                        GAME_CIRC_ACCEL_PORTAL_6_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_7_X,
                        GAME_CIRC_ACCEL_PORTAL_7_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y0,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X1,
                GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y1,
                GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                GAME_CIRC_ACCEL_SWIPE_LINE_CLEAR_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_8_X,
                        GAME_CIRC_ACCEL_PORTAL_8_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
}


void game_circAccel_init(void)
{
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_BOOSTER_X,
                        GAME_CIRC_ACCEL_BOOSTER_Y,
                        GAME_CIRC_ACCEL_BOOSTER_R,
                        GAME_CIRC_ACCEL_BOOSTER_FW,
                        GAME_CIRC_ACCEL_BOOSTER_C,
                        0xFFFF);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_1_X,
                        GAME_CIRC_ACCEL_PORTAL_1_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_2_X,
                        GAME_CIRC_ACCEL_PORTAL_2_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_3_X,
                        GAME_CIRC_ACCEL_PORTAL_3_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_4_X,
                        GAME_CIRC_ACCEL_PORTAL_4_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_5_X,
                        GAME_CIRC_ACCEL_PORTAL_5_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_6_X,
                        GAME_CIRC_ACCEL_PORTAL_6_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_7_X,
                        GAME_CIRC_ACCEL_PORTAL_7_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_8_X,
                        GAME_CIRC_ACCEL_PORTAL_8_Y,
                        GAME_CIRC_ACCEL_PORTAL_R,
                        GAME_CIRC_ACCEL_PORTAL_FW,
                        0x0000,            
                        GAME_CIRC_ACCEL_POWER_OFF_COLOR);

  SGUI_createButton(GAME_CIRC_ACCEL_B_NEXT_P,
                    GAME_CIRC_ACCEL_B_NEXT_X0,
                    GAME_CIRC_ACCEL_B_NEXT_Y0,
                    GAME_CIRC_ACCEL_B_NEXT_X1,
                    GAME_CIRC_ACCEL_B_NEXT_Y1,
                    GAME_CIRC_ACCEL_B_NEXT_RX,
                    GAME_CIRC_ACCEL_B_NEXT_RY,
                    GAME_CIRC_ACCEL_B_NEXT_FW,
                    GAME_CIRC_ACCEL_B_NEXT_BC,
                    GAME_CIRC_ACCEL_B_NEXT_FC,
                    GAME_CIRC_ACCEL_B_NEXT_T,
                    GAME_CIRC_ACCEL_B_NEXT_TS,
                    GAME_CIRC_ACCEL_B_NEXT_TC,
                    GAME_CIRC_ACCEL_B_NEXT_TMX,
                    GAME_CIRC_ACCEL_B_NEXT_TMY,
                    GAME_CIRC_ACCEL_B_NEXT_STATE,
                    GAME_CIRC_ACCEL_B_NEXT_DELAY,
                    GAME_CIRC_ACCEL_B_NEXT_ACT);
  SGUI_createButton(GAME_CIRC_ACCEL_B_POWER_P,
                    GAME_CIRC_ACCEL_B_POWER_X0,
                    GAME_CIRC_ACCEL_B_POWER_Y0,
                    GAME_CIRC_ACCEL_B_POWER_X1,
                    GAME_CIRC_ACCEL_B_POWER_Y1,
                    GAME_CIRC_ACCEL_B_POWER_RX,
                    GAME_CIRC_ACCEL_B_POWER_RY,
                    GAME_CIRC_ACCEL_B_POWER_FW,
                    GAME_CIRC_ACCEL_B_POWER_BC,
                    GAME_CIRC_ACCEL_B_POWER_FC,
                    GAME_CIRC_ACCEL_B_POWER_T,
                    GAME_CIRC_ACCEL_B_POWER_TS,
                    GAME_CIRC_ACCEL_B_POWER_TC,
                    GAME_CIRC_ACCEL_B_POWER_TMX,
                    GAME_CIRC_ACCEL_B_POWER_TMY,
                    GAME_CIRC_ACCEL_B_POWER_STATE,
                    GAME_CIRC_ACCEL_B_POWER_DELAY,
                    GAME_CIRC_ACCEL_B_POWER_ACT);
  SGUI_createButton(GAME_CIRC_ACCEL_B_CLEAR_P,
                    GAME_CIRC_ACCEL_B_CLEAR_X0,
                    GAME_CIRC_ACCEL_B_CLEAR_Y0,
                    GAME_CIRC_ACCEL_B_CLEAR_X1,
                    GAME_CIRC_ACCEL_B_CLEAR_Y1,
                    GAME_CIRC_ACCEL_B_CLEAR_RX,
                    GAME_CIRC_ACCEL_B_CLEAR_RY,
                    GAME_CIRC_ACCEL_B_CLEAR_FW,
                    GAME_CIRC_ACCEL_B_CLEAR_BC,
                    GAME_CIRC_ACCEL_B_CLEAR_FC,
                    GAME_CIRC_ACCEL_B_CLEAR_T,
                    GAME_CIRC_ACCEL_B_CLEAR_TS,
                    GAME_CIRC_ACCEL_B_CLEAR_TC,
                    GAME_CIRC_ACCEL_B_CLEAR_TMX,
                    GAME_CIRC_ACCEL_B_CLEAR_TMY,
                    GAME_CIRC_ACCEL_B_CLEAR_STATE,
                    GAME_CIRC_ACCEL_B_CLEAR_DELAY,
                    GAME_CIRC_ACCEL_B_CLEAR_ACT);
}


void game_circAccel_handler(void)
{
  if(isSwipe())
  {
    switch(gameLevel)
    {
      case PORTAL_1:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_1_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_1_X,
                              GAME_CIRC_ACCEL_PORTAL_1_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_2_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_2_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_2_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_2;
        break;

      case PORTAL_2:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_2_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_2_X,
                              GAME_CIRC_ACCEL_PORTAL_2_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_3_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_3_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_3_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_3;
        break;

      case PORTAL_3:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_3_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_3_X,
                              GAME_CIRC_ACCEL_PORTAL_3_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_4_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_4_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_4_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_4;
        break;

      case PORTAL_4:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_4_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_4_X,
                              GAME_CIRC_ACCEL_PORTAL_4_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_5_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_5_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_5_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_5;
        break;

      case PORTAL_5:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_5_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_5_X,
                              GAME_CIRC_ACCEL_PORTAL_5_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_6_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_6_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_6_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_6;
        break;

      case PORTAL_6:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_6_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_6_X,
                              GAME_CIRC_ACCEL_PORTAL_6_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_7_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_7_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_7_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_7;
        break;

      case PORTAL_7:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_7_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_7_X,
                              GAME_CIRC_ACCEL_PORTAL_7_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_8_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y0,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_8_X1,
                       GAME_CIRC_ACCEL_SWIPE_PORTAL_8_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = PORTAL_8;
        break;

      case PORTAL_8:
        SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y0,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_X1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_PORTAL_8_Y1,
                      GAME_CIRC_ACCEL_SWIPE_LINE_WIDTH,
                      GAME_CIRC_ACCEL_SWIPE_LINE_COLOR);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_8_X,
                              GAME_CIRC_ACCEL_PORTAL_8_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,            
                              GAME_CIRC_ACCEL_POWER_ON_COLOR);
        clearStatusBar();
        SGUI_printString(GAME_CIRC_ACCEL_STATUS_BAR_TEXT_PORTAL,
                         GAME_CIRC_ACCEL_STATUS_BAR_TEXT_X,
                         GAME_CIRC_ACCEL_STATUS_BAR_TEXT_Y,
                         FONT_SIZE_32, 0xFFFF, 0x0000);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_1_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_1_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_1_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_1_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_1_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_1_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_1_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_1_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_1_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_1;
        break;

      case BOOST_1:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_2_X,
                              GAME_CIRC_ACCEL_PORTAL_2_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_2_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_2_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_2_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_2_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_2_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_2_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_2_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_2_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_2_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_2;
        break;

      case BOOST_2:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_3_X,
                              GAME_CIRC_ACCEL_PORTAL_3_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_3_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_3_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_3_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_3_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_3_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_3_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_3_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_3_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_3_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_3;
        break;

      case BOOST_3:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_4_X,
                              GAME_CIRC_ACCEL_PORTAL_4_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_4_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_4_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_4_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_4_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_4_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_4_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_4_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_4_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_4_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_4;
        break;

      case BOOST_4:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_5_X,
                              GAME_CIRC_ACCEL_PORTAL_5_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_5_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_5_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_5_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_5_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_5_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_5_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_5_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_5_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_5_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_5;
        break;

      case BOOST_5:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_6_X,
                              GAME_CIRC_ACCEL_PORTAL_6_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_6_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_6_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_6_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_6_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_6_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_6_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_6_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_6_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_6_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_6;
        break;

      case BOOST_6:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_7_X,
                              GAME_CIRC_ACCEL_PORTAL_7_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_7_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_7_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_7_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_7_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_7_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_7_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_7_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_7_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_7_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_7;
        break;

      case BOOST_7:
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_8_X,
                              GAME_CIRC_ACCEL_PORTAL_8_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        setSwipe(GAME_CIRC_ACCEL_SWIPE_BOOST_8_X0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_8_Y0,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_8_X1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_8_Y1,
                 GAME_CIRC_ACCEL_SWIPE_BOOST_8_DIRECTION);
#ifdef GAME_CIRC_ACCEL_DEBUG
        SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_BOOST_8_X0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_8_Y0,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_8_X1,
                       GAME_CIRC_ACCEL_SWIPE_BOOST_8_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = BOOST_8;
        break;

      case BOOST_8:
        useSwipe(false);
        SGUI_drawFilledCircle(GAME_CIRC_ACCEL_PORTAL_1_X,
                              GAME_CIRC_ACCEL_PORTAL_1_Y,
                              GAME_CIRC_ACCEL_PORTAL_R,
                              GAME_CIRC_ACCEL_PORTAL_FW,
                              0x0000,
                              GAME_CIRC_ACCEL_BOOST_COLOR);
        clearStatusBar();
        SGUI_printString(GAME_CIRC_ACCEL_STATUS_BAR_TEXT_BOOST,
                         GAME_CIRC_ACCEL_STATUS_BAR_TEXT_X,
                         GAME_CIRC_ACCEL_STATUS_BAR_TEXT_Y,
                         FONT_SIZE_32, 0xFFFF, 0x0000);
        delay_ms(1000);
        if(gameMode == GAME_MODE_GAME)
        {
          clearStatusBar();
          SGUI_printString(GAME_CIRC_ACCEL_STATUS_BAR_TEXT_NEXT,
                           GAME_CIRC_ACCEL_STATUS_BAR_TEXT_X,
                           GAME_CIRC_ACCEL_STATUS_BAR_TEXT_Y,
                           FONT_SIZE_32, 0xFFFF, 0x0000);
          delay_ms(1000);          
          SGUI_buttonVisibility(GAME_CIRC_ACCEL_B_NEXT_P, 1, true);
          SGUI_buttonInUsage(GAME_CIRC_ACCEL_B_NEXT_P, 1, true);
        }
        else
        {
          clearStatusBar();
          SGUI_printString(GAME_CIRC_ACCEL_STATUS_BAR_TEXT_FREE,
                           GAME_CIRC_ACCEL_STATUS_BAR_TEXT_X,
                           GAME_CIRC_ACCEL_STATUS_BAR_TEXT_Y,
                           FONT_SIZE_32, 0xFFFF, 0x0000);
        }
        gameLevel = FINISH;
        break;

      case FINISH:
        break;

      default:
        break;
    }
  }
}


void game_circAccel_cleaner(void)
{
  SGUI_setPage(GAME_CIRC_ACCEL_PAGE);
  btn_clear();
  SGUI_setPage(GUI.currentPage);
}
