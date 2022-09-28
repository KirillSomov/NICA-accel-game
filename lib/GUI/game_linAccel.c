
#include "game_linAccel.h"


static void btn_linAccelPower(void)
{
  SGUI_buttonSetColor(2, 3, 0x6DCA);
}


void game_LinAccel_init(void)
{
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
}


