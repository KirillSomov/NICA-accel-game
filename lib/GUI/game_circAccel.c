
#include "game_circAccel.h"
#include "stdbool.h"
#include "swipe.h"


static unsigned short gameLevel = 0;


static void btn_circAccelPower(void)
{
  /*SGUI_buttonSetColor(2, 2, GAME_CIRC_ACCEL_POWER_ON_COLOR);
  SGUI_buttonInUsage(2, 2, false);

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
  gameLevel = PORTAL_1;*/
}


static void btn_clear(void)
{
  /*SGUI_buttonSetColor(2, 2, GAME_CIRC_ACCEL_POWER_OFF_COLOR);
  SGUI_buttonInUsage(2, 2, true);
  useSwipe(false);
  gameLevel = 0;
  
  SGUI_drawLine(GAME_CIRC_ACCEL_SWIPE_CIRCE_PORTAL_1_X0,
                GAME_CIRC_ACCEL_SWIPE_CIRCE_PORTAL_1_Y0,
                GAME_CIRC_ACCEL_SWIPE_CIRCE_PORTAL_1_X1,
                GAME_CIRC_ACCEL_SWIPE_CIRCE_PORTAL_1_Y1,
                4, 0xFFFF);*/
}


void game_circAccel_init(void)
{
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
      /*case PORTAL_1:
        break;*/

      default:
        break;
    }
  }
}
