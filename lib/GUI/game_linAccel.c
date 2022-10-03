
#include "game_linAccel.h"
#include "stdbool.h"
#include "swipe.h"


static unsigned short gameLevel = 0;


static void btn_linAccelPower(void)
{
  SGUI_buttonSetColor(2, 2, GAME_LIN_ACCEL_POWER_ON_COLOR);
  SGUI_buttonInUsage(2, 2, false);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_LEFT_PORTAL_X0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_X1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RX,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RY,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FW,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FC,
                       GAME_LIN_ACCEL_POWER_ON_COLOR);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_RIGHT_PORTAL_X0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_X1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RX,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RY,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FW,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FC,
                       GAME_LIN_ACCEL_POWER_ON_COLOR);
  setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_1_X0,
           GAME_LIN_ACCEL_SWIPE_PORTAL_1_Y0,
           GAME_LIN_ACCEL_SWIPE_PORTAL_1_X1,
           GAME_LIN_ACCEL_SWIPE_PORTAL_1_Y1,
           GAME_LIN_ACCEL_SWIPE_PORTAL_1_DIRECTION);
  SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_1_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_1_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_1_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_1_Y1,
                 0, 0, 1, 0x0000);
  useSwipe(true);
  gameLevel = PORTAL_1;
}


static void btn_clear(void)
{
  SGUI_buttonSetColor(2, 2, GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_buttonInUsage(2, 2, true);
  useSwipe(false);
  gameLevel = 0;
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_LEFT_PORTAL_X0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_X1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RX,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RY,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FW,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_RIGHT_PORTAL_X0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_X1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RX,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RY,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FW,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  for(int i = 0; i < 6; i++)
  {
    SGUI_drawFilledFrame(GAME_LIN_ACCEL_SWIPE_LINE_BOOST_X0 + i*115 + 1,
                        GAME_LIN_ACCEL_SWIPE_LINE_BOOST_Y0,
                        GAME_LIN_ACCEL_SWIPE_LINE_BOOST_X0 + i*115 + 34,
                        GAME_LIN_ACCEL_SWIPE_LINE_BOOST_Y1,
                        0, 0, 0, 0,
                        0xFFFF);
  }                       
  SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_X0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_Y0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_X1,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_Y1,
                4, 0xFFFF);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_1_X0,
                       GAME_LIN_ACCEL_PORTAL_1_Y0,
                       GAME_LIN_ACCEL_PORTAL_1_X1,
                       GAME_LIN_ACCEL_PORTAL_1_Y1,
                       GAME_LIN_ACCEL_PORTAL_1_RX,
                       GAME_LIN_ACCEL_PORTAL_1_RY,
                       GAME_LIN_ACCEL_PORTAL_1_FW,
                       GAME_LIN_ACCEL_PORTAL_1_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_X0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_Y0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_X1,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_Y1,
                4, 0xFFFF);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_2_X0,
                       GAME_LIN_ACCEL_PORTAL_2_Y0,
                       GAME_LIN_ACCEL_PORTAL_2_X1,
                       GAME_LIN_ACCEL_PORTAL_2_Y1,
                       GAME_LIN_ACCEL_PORTAL_2_RX,
                       GAME_LIN_ACCEL_PORTAL_2_RY,
                       GAME_LIN_ACCEL_PORTAL_2_FW,
                       GAME_LIN_ACCEL_PORTAL_2_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_X0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_Y0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_X1,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_Y1,
                4, 0xFFFF);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_3_X0,
                       GAME_LIN_ACCEL_PORTAL_3_Y0,
                       GAME_LIN_ACCEL_PORTAL_3_X1,
                       GAME_LIN_ACCEL_PORTAL_3_Y1,
                       GAME_LIN_ACCEL_PORTAL_3_RX,
                       GAME_LIN_ACCEL_PORTAL_3_RY,
                       GAME_LIN_ACCEL_PORTAL_3_FW,
                       GAME_LIN_ACCEL_PORTAL_3_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_X0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_Y0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_X1,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_Y1,
                4, 0xFFFF);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_4_X0,
                       GAME_LIN_ACCEL_PORTAL_4_Y0,
                       GAME_LIN_ACCEL_PORTAL_4_X1,
                       GAME_LIN_ACCEL_PORTAL_4_Y1,
                       GAME_LIN_ACCEL_PORTAL_4_RX,
                       GAME_LIN_ACCEL_PORTAL_4_RY,
                       GAME_LIN_ACCEL_PORTAL_4_FW,
                       GAME_LIN_ACCEL_PORTAL_4_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
  SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_X0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_Y0,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_X1,
                GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_Y1,
                4, 0xFFFF);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_5_X0,
                       GAME_LIN_ACCEL_PORTAL_5_Y0,
                       GAME_LIN_ACCEL_PORTAL_5_X1,
                       GAME_LIN_ACCEL_PORTAL_5_Y1,
                       GAME_LIN_ACCEL_PORTAL_5_RX,
                       GAME_LIN_ACCEL_PORTAL_5_RY,
                       GAME_LIN_ACCEL_PORTAL_5_FW,
                       GAME_LIN_ACCEL_PORTAL_5_FC,
                       GAME_LIN_ACCEL_POWER_OFF_COLOR);
}


void game_linAccel_init(void)
{
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_LEFT_PORTAL_X0+20,
                       GAME_LIN_ACCEL_B_POWER_Y0+50,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_X0+20,
                       GAME_LIN_ACCEL_B_POWER_Y0+50+2,
                       0,
                       0,
                       0,
                       0,
                       0x0000);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_LEFT_PORTAL_X0+20,
                       GAME_LIN_ACCEL_B_POWER_Y0+50,
                       GAME_LIN_ACCEL_LEFT_PORTAL_X0+20+2,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y0,
                       0,
                       0,
                       0,
                       0,
                       0x0000);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_RIGHT_PORTAL_X0+20,
                       GAME_LIN_ACCEL_B_POWER_Y0+50,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_X0+20+2,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y0,
                       0,
                       0,
                       0,
                       0,
                       0x0000);                       
  
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_LEFT_PORTAL_X0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y0,
                       GAME_LIN_ACCEL_LEFT_PORTAL_X1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_Y1,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RX,
                       GAME_LIN_ACCEL_LEFT_PORTAL_RY,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FW,
                       GAME_LIN_ACCEL_LEFT_PORTAL_FC,
                       GAME_LIN_ACCEL_LEFT_PORTAL_C);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_RIGHT_PORTAL_X0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y0,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_X1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_Y1,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RX,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_RY,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FW,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_FC,
                       GAME_LIN_ACCEL_RIGHT_PORTAL_C);

  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_1_X0,
                       GAME_LIN_ACCEL_PORTAL_1_Y0,
                       GAME_LIN_ACCEL_PORTAL_1_X1,
                       GAME_LIN_ACCEL_PORTAL_1_Y1,
                       GAME_LIN_ACCEL_PORTAL_1_RX,
                       GAME_LIN_ACCEL_PORTAL_1_RY,
                       GAME_LIN_ACCEL_PORTAL_1_FW,
                       GAME_LIN_ACCEL_PORTAL_1_FC,
                       GAME_LIN_ACCEL_PORTAL_1_C);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_2_X0,
                       GAME_LIN_ACCEL_PORTAL_2_Y0,
                       GAME_LIN_ACCEL_PORTAL_2_X1,
                       GAME_LIN_ACCEL_PORTAL_2_Y1,
                       GAME_LIN_ACCEL_PORTAL_2_RX,
                       GAME_LIN_ACCEL_PORTAL_2_RY,
                       GAME_LIN_ACCEL_PORTAL_2_FW,
                       GAME_LIN_ACCEL_PORTAL_2_FC,
                       GAME_LIN_ACCEL_PORTAL_2_C);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_3_X0,
                       GAME_LIN_ACCEL_PORTAL_3_Y0,
                       GAME_LIN_ACCEL_PORTAL_3_X1,
                       GAME_LIN_ACCEL_PORTAL_3_Y1,
                       GAME_LIN_ACCEL_PORTAL_3_RX,
                       GAME_LIN_ACCEL_PORTAL_3_RY,
                       GAME_LIN_ACCEL_PORTAL_3_FW,
                       GAME_LIN_ACCEL_PORTAL_3_FC,
                       GAME_LIN_ACCEL_PORTAL_3_C);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_4_X0,
                       GAME_LIN_ACCEL_PORTAL_4_Y0,
                       GAME_LIN_ACCEL_PORTAL_4_X1,
                       GAME_LIN_ACCEL_PORTAL_4_Y1,
                       GAME_LIN_ACCEL_PORTAL_4_RX,
                       GAME_LIN_ACCEL_PORTAL_4_RY,
                       GAME_LIN_ACCEL_PORTAL_4_FW,
                       GAME_LIN_ACCEL_PORTAL_4_FC,
                       GAME_LIN_ACCEL_PORTAL_4_C);
  SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_5_X0,
                       GAME_LIN_ACCEL_PORTAL_5_Y0,
                       GAME_LIN_ACCEL_PORTAL_5_X1,
                       GAME_LIN_ACCEL_PORTAL_5_Y1,
                       GAME_LIN_ACCEL_PORTAL_5_RX,
                       GAME_LIN_ACCEL_PORTAL_5_RY,
                       GAME_LIN_ACCEL_PORTAL_5_FW,
                       GAME_LIN_ACCEL_PORTAL_5_FC,
                       GAME_LIN_ACCEL_PORTAL_5_C);

  SGUI_createButton(GAME_LIN_ACCEL_B_POWER_P,
                    GAME_LIN_ACCEL_B_POWER_X0,
                    GAME_LIN_ACCEL_B_POWER_Y0,
                    GAME_LIN_ACCEL_B_POWER_X1,
                    GAME_LIN_ACCEL_B_POWER_Y1,
                    GAME_LIN_ACCEL_B_POWER_RX,
                    GAME_LIN_ACCEL_B_POWER_RY,
                    GAME_LIN_ACCEL_B_POWER_FW,
                    GAME_LIN_ACCEL_B_POWER_BC,
                    GAME_LIN_ACCEL_B_POWER_FC,
                    GAME_LIN_ACCEL_B_POWER_T,
                    GAME_LIN_ACCEL_B_POWER_TC,
                    GAME_LIN_ACCEL_B_POWER_TMX,
                    GAME_LIN_ACCEL_B_POWER_TMY,
                    GAME_LIN_ACCEL_B_POWER_STATE,
                    GAME_LIN_ACCEL_B_POWER_DELAY,
                    GAME_LIN_ACCEL_B_POWER_ACT);
  SGUI_createButton(GAME_LIN_ACCEL_B_CLEAR_P,
                    GAME_LIN_ACCEL_B_CLEAR_X0,
                    GAME_LIN_ACCEL_B_CLEAR_Y0,
                    GAME_LIN_ACCEL_B_CLEAR_X1,
                    GAME_LIN_ACCEL_B_CLEAR_Y1,
                    GAME_LIN_ACCEL_B_CLEAR_RX,
                    GAME_LIN_ACCEL_B_CLEAR_RY,
                    GAME_LIN_ACCEL_B_CLEAR_FW,
                    GAME_LIN_ACCEL_B_CLEAR_BC,
                    GAME_LIN_ACCEL_B_CLEAR_FC,
                    GAME_LIN_ACCEL_B_CLEAR_T,
                    GAME_LIN_ACCEL_B_CLEAR_TC,
                    GAME_LIN_ACCEL_B_CLEAR_TMX,
                    GAME_LIN_ACCEL_B_CLEAR_TMY,
                    GAME_LIN_ACCEL_B_CLEAR_STATE,
                    GAME_LIN_ACCEL_B_CLEAR_DELAY,
                    GAME_LIN_ACCEL_B_CLEAR_ACT);                    
}


void game_linAccel_handler(void)
{
  if(isSwipe())
  {
    switch(gameLevel)
    {
      case PORTAL_1:
        SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_X0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_Y0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_X1,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_1_Y1,
                      4, 0x0000);
        SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_1_X0,
                             GAME_LIN_ACCEL_PORTAL_1_Y0,
                             GAME_LIN_ACCEL_PORTAL_1_X1,
                             GAME_LIN_ACCEL_PORTAL_1_Y1,
                             GAME_LIN_ACCEL_PORTAL_1_RX,
                             GAME_LIN_ACCEL_PORTAL_1_RY,
                             GAME_LIN_ACCEL_PORTAL_1_FW,
                             GAME_LIN_ACCEL_PORTAL_1_FC,
                             GAME_LIN_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_2_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_2_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_2_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_2_Y1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_2_DIRECTION);
        SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_2_X0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_2_Y0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_2_X1,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_2_Y1,
                       0, 0, 1, 0x0000);
        gameLevel = PORTAL_2;
        break;

      case PORTAL_2:
        SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_X0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_Y0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_X1,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_2_Y1,
                      4, 0x0000);
        SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_2_X0,
                             GAME_LIN_ACCEL_PORTAL_2_Y0,
                             GAME_LIN_ACCEL_PORTAL_2_X1,
                             GAME_LIN_ACCEL_PORTAL_2_Y1,
                             GAME_LIN_ACCEL_PORTAL_2_RX,
                             GAME_LIN_ACCEL_PORTAL_2_RY,
                             GAME_LIN_ACCEL_PORTAL_2_FW,
                             GAME_LIN_ACCEL_PORTAL_2_FC,
                             GAME_LIN_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_3_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_3_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_3_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_3_Y1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_3_DIRECTION);
        SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_3_X0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_3_Y0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_3_X1,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_3_Y1,
                       0, 0, 1, 0x0000);
        gameLevel = PORTAL_3;
        break;

      case PORTAL_3:
        SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_X0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_Y0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_X1,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_3_Y1,
                      4, 0x0000);
        SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_3_X0,
                             GAME_LIN_ACCEL_PORTAL_3_Y0,
                             GAME_LIN_ACCEL_PORTAL_3_X1,
                             GAME_LIN_ACCEL_PORTAL_3_Y1,
                             GAME_LIN_ACCEL_PORTAL_3_RX,
                             GAME_LIN_ACCEL_PORTAL_3_RY,
                             GAME_LIN_ACCEL_PORTAL_3_FW,
                             GAME_LIN_ACCEL_PORTAL_3_FC,
                             GAME_LIN_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_4_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_4_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_4_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_4_Y1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_4_DIRECTION);
        SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_4_X0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_4_Y0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_4_X1,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_4_Y1,
                       0, 0, 1, 0x0000);
        gameLevel = PORTAL_4;
        break;

      case PORTAL_4:
        SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_X0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_Y0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_X1,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_4_Y1,
                      4, 0x0000);
        SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_4_X0,
                             GAME_LIN_ACCEL_PORTAL_4_Y0,
                             GAME_LIN_ACCEL_PORTAL_4_X1,
                             GAME_LIN_ACCEL_PORTAL_4_Y1,
                             GAME_LIN_ACCEL_PORTAL_4_RX,
                             GAME_LIN_ACCEL_PORTAL_4_RY,
                             GAME_LIN_ACCEL_PORTAL_4_FW,
                             GAME_LIN_ACCEL_PORTAL_4_FC,
                             GAME_LIN_ACCEL_POWER_ON_COLOR);
        setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_5_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_DIRECTION);
        SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_5_X0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_X1,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y1,
                       0, 0, 1, 0x0000);
        gameLevel = PORTAL_5;
        break;

      case PORTAL_5:
        SGUI_drawLine(GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_X0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_Y0,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_X1,
                      GAME_LIN_ACCEL_SWIPE_LINE_PORTAL_5_Y1,
                      4, 0x0000);
        SGUI_drawFilledFrame(GAME_LIN_ACCEL_PORTAL_5_X0,
                             GAME_LIN_ACCEL_PORTAL_5_Y0,
                             GAME_LIN_ACCEL_PORTAL_5_X1,
                             GAME_LIN_ACCEL_PORTAL_5_Y1,
                             GAME_LIN_ACCEL_PORTAL_5_RX,
                             GAME_LIN_ACCEL_PORTAL_5_RY,
                             GAME_LIN_ACCEL_PORTAL_5_FW,
                             GAME_LIN_ACCEL_PORTAL_5_FC,
                             GAME_LIN_ACCEL_POWER_ON_COLOR);
        for(int i = 0; i < 6; i++)
        {
          SGUI_drawFilledFrame(GAME_LIN_ACCEL_SWIPE_LINE_BOOST_X0 + i*115 + 1,
                              GAME_LIN_ACCEL_SWIPE_LINE_BOOST_Y0,
                              GAME_LIN_ACCEL_SWIPE_LINE_BOOST_X0 + i*115 + 34,
                              GAME_LIN_ACCEL_SWIPE_LINE_BOOST_Y1,
                              0, 0, 0, 0,
                              GAME_LIN_ACCEL_SWIPE_LINE_BOOST_COLOR);
        }
        /*setSwipe(GAME_LIN_ACCEL_SWIPE_PORTAL_5_X0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y0,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_X1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y1,
                 GAME_LIN_ACCEL_SWIPE_PORTAL_5_DIRECTION);
        SGUI_drawFrame(GAME_LIN_ACCEL_SWIPE_PORTAL_5_X0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y0,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_X1,
                       GAME_LIN_ACCEL_SWIPE_PORTAL_5_Y1,
                       0, 0, 1, 0x0000);
        gameLevel = PORTAL_5;*/
        break;

      default:
        break;
    }
  }
}
