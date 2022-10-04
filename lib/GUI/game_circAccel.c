
#include "game_circAccel.h"
#include "stdbool.h"
#include "swipe.h"


#define GAME_CIRC_ACCEL_DEBUG


static unsigned short gameLevel = 0;


enum gameCircAccelLevel
{
  PORTAL_1 = 1,
  PORTAL_2,
  PORTAL_3,
  PORTAL_4,
  PORTAL_5,
  PORTAL_6,
  PORTAL_7,
  PORTAL_8,
  FINISH
};


static void btn_circAccelPower(void)
{
  SGUI_buttonSetColor(3, 2, GAME_CIRC_ACCEL_POWER_ON_COLOR);
  SGUI_buttonInUsage(3, 2, false);
  setSwipe(GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X0,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y0,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X1,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y1,
           GAME_CIRC_ACCEL_SWIPE_PORTAL_1_DIRECTION);
  SGUI_drawFrame(GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y0,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_X1,
                 GAME_CIRC_ACCEL_SWIPE_PORTAL_1_Y1,
                 0, 0, 1, 0x0000);
  useSwipe(true);
  gameLevel = PORTAL_1;
}


static void btn_clear(void)
{
  SGUI_buttonSetColor(3, 2, GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_buttonInUsage(3, 2, true);
  useSwipe(false);
  gameLevel = 0;
  
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
        gameLevel = FINISH;
        break;

      default:
        break;
    }
  }
}