
#include "gui_impl.h"
#include "game_detector.h"
#include "stdbool.h"
#include "stdlib.h"
#include "swipe.h"


enum gameLinAccelLevel
{
  START = 0,
  PORTAL_1,
  PORTAL_2,
  PORTAL_3,
  PORTAL_4,
  PORTAL_5,
  PORTAL_6,
  PORTAL_7,
  DETECTOR,
  FINISH
};


static unsigned short gameLevel = 0;
static unsigned short portalMultiplier = 0;


static void btn_next(void)
{
  SGUI_showPage(0);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void btn_clear(void)
{
  gameLevel = START;
  portalMultiplier = 0;
  SGUI_buttonSetColor(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, GAME_DETECTOR_POWER_OFF_COLOR);
  for(int i = 0; i < 4; i++)
  {
    SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_SMALL_X0 + i*GAME_DETECTOR_PORTAL_SPACE_X,
                         GAME_DETECTOR_PORTAL_SMALL_Y0,
                         GAME_DETECTOR_PORTAL_SMALL_X1 + i*GAME_DETECTOR_PORTAL_SPACE_X,
                         GAME_DETECTOR_PORTAL_SMALL_Y1,
                         GAME_DETECTOR_PORTAL_SMALL_RX,
                         GAME_DETECTOR_PORTAL_SMALL_RY,
                         GAME_DETECTOR_PORTAL_SMALL_FW,
                         GAME_DETECTOR_PORTAL_SMALL_FC,
                         GAME_DETECTOR_POWER_OFF_COLOR);
  }
  for(int i = 0; i < 3; i++)
  {
    SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_BIG_X0 + i*GAME_DETECTOR_PORTAL_SPACE_X,
                         GAME_DETECTOR_PORTAL_BIG_Y0,
                         GAME_DETECTOR_PORTAL_BIG_X1 + i*GAME_DETECTOR_PORTAL_SPACE_X,
                         GAME_DETECTOR_PORTAL_BIG_Y1,
                         GAME_DETECTOR_PORTAL_BIG_RX,
                         GAME_DETECTOR_PORTAL_BIG_RY,
                         GAME_DETECTOR_PORTAL_BIG_FW,
                         GAME_DETECTOR_PORTAL_BIG_FC,
                         GAME_DETECTOR_POWER_OFF_COLOR);
  }
  SGUI_drawFilledFrame(GAME_DETECTOR_DETECTOR_X0,
                       GAME_DETECTOR_DETECTOR_Y0,
                       GAME_DETECTOR_DETECTOR_X1,
                       GAME_DETECTOR_DETECTOR_Y1,
                       GAME_DETECTOR_DETECTOR_RX,
                       GAME_DETECTOR_DETECTOR_RY,
                       GAME_DETECTOR_DETECTOR_FW,
                       GAME_DETECTOR_DETECTOR_FC,
                       GAME_DETECTOR_POWER_OFF_COLOR);
  SGUI_buttonInUsage(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, true);
}


static void btn_start(void)
{
  SGUI_buttonInUsage(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, false);
  SGUI_buttonSetColor(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, GAME_DETECTOR_POWER_ON_COLOR);
  setSwipe(GAME_DETECTOR_SWIPE_PORTAL_BIG_X0,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_Y0,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_X1,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_Y1,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_DIRECTION);
  useSwipe(true);
  gameLevel = PORTAL_1;
}


static void gameWin(void)
{
  unsigned short x = (unsigned short)(rand() % 100 + 1);
  unsigned short y = (unsigned short)(rand() % 100 + 1);

  //SGUI_printString();
}


void game_detector_init(void)
{
  SGUI_createButton(GAME_DETECTOR_B_NEXT_P,
                    GAME_DETECTOR_B_NEXT_X0,
                    GAME_DETECTOR_B_NEXT_Y0,
                    GAME_DETECTOR_B_NEXT_X1,
                    GAME_DETECTOR_B_NEXT_Y1,
                    GAME_DETECTOR_B_NEXT_RX,
                    GAME_DETECTOR_B_NEXT_RY,
                    GAME_DETECTOR_B_NEXT_FW,
                    GAME_DETECTOR_B_NEXT_BC,
                    GAME_DETECTOR_B_NEXT_FC,
                    GAME_DETECTOR_B_NEXT_T,
                    GAME_DETECTOR_B_NEXT_TS,
                    GAME_DETECTOR_B_NEXT_TC,
                    GAME_DETECTOR_B_NEXT_TMX,
                    GAME_DETECTOR_B_NEXT_TMY,
                    GAME_DETECTOR_B_NEXT_STATE,
                    GAME_DETECTOR_B_NEXT_DELAY,
                    GAME_DETECTOR_B_NEXT_ACT);
  SGUI_buttonVisibility(GAME_DETECTOR_B_NEXT_P, 1, false);
  SGUI_buttonInUsage(GAME_DETECTOR_B_NEXT_P, 1, false);
  SGUI_createButton(GAME_DETECTOR_B_CLEAR_P,
                    GAME_DETECTOR_B_CLEAR_X0,
                    GAME_DETECTOR_B_CLEAR_Y0,
                    GAME_DETECTOR_B_CLEAR_X1,
                    GAME_DETECTOR_B_CLEAR_Y1,
                    GAME_DETECTOR_B_CLEAR_RX,
                    GAME_DETECTOR_B_CLEAR_RY,
                    GAME_DETECTOR_B_CLEAR_FW,
                    GAME_DETECTOR_B_CLEAR_BC,
                    GAME_DETECTOR_B_CLEAR_FC,
                    GAME_DETECTOR_B_CLEAR_T,
                    GAME_DETECTOR_B_CLEAR_TS,
                    GAME_DETECTOR_B_CLEAR_TC,
                    GAME_DETECTOR_B_CLEAR_TMX,
                    GAME_DETECTOR_B_CLEAR_TMY,
                    GAME_DETECTOR_B_CLEAR_STATE,
                    GAME_DETECTOR_B_CLEAR_DELAY,
                    GAME_DETECTOR_B_CLEAR_ACT);
  SGUI_createButton(GAME_DETECTOR_B_START_P,
                    GAME_DETECTOR_B_START_X0,
                    GAME_DETECTOR_B_START_Y0,
                    GAME_DETECTOR_B_START_X1,
                    GAME_DETECTOR_B_START_Y1,
                    GAME_DETECTOR_B_START_RX,
                    GAME_DETECTOR_B_START_RY,
                    GAME_DETECTOR_B_START_FW,
                    GAME_DETECTOR_B_START_BC,
                    GAME_DETECTOR_B_START_FC,
                    GAME_DETECTOR_B_START_T,
                    GAME_DETECTOR_B_START_TS,
                    GAME_DETECTOR_B_START_TC,
                    GAME_DETECTOR_B_START_TMX,
                    GAME_DETECTOR_B_START_TMY,
                    GAME_DETECTOR_B_START_STATE,
                    GAME_DETECTOR_B_START_DELAY,
                    GAME_DETECTOR_B_START_ACT);
  btn_clear();
}


void game_detector_handler(void)
{
  if(isSwipe())
  {
    switch(gameLevel)
    {
      case PORTAL_1:
        gameLevel = PORTAL_2;
        break;

      case PORTAL_2:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_BIG_X0,
                             GAME_DETECTOR_PORTAL_BIG_Y0,
                             GAME_DETECTOR_PORTAL_BIG_X1,
                             GAME_DETECTOR_PORTAL_BIG_Y1,
                             GAME_DETECTOR_PORTAL_BIG_RX,
                             GAME_DETECTOR_PORTAL_BIG_RY,
                             GAME_DETECTOR_PORTAL_BIG_FW,
                             GAME_DETECTOR_PORTAL_BIG_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        portalMultiplier++;
        setSwipe(GAME_DETECTOR_SWIPE_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_DIRECTION);
        gameLevel = PORTAL_3;
        break;

      case PORTAL_3:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y0,
                             GAME_DETECTOR_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y1,
                             GAME_DETECTOR_PORTAL_SMALL_RX,
                             GAME_DETECTOR_PORTAL_SMALL_RY,
                             GAME_DETECTOR_PORTAL_SMALL_FW,
                             GAME_DETECTOR_PORTAL_SMALL_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        setSwipe(GAME_DETECTOR_SWIPE_PORTAL_BIG_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_Y0,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_Y1,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_DIRECTION);
        gameLevel = PORTAL_4;
        break;

      case PORTAL_4:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_BIG_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_BIG_Y0,
                             GAME_DETECTOR_PORTAL_BIG_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_BIG_Y1,
                             GAME_DETECTOR_PORTAL_BIG_RX,
                             GAME_DETECTOR_PORTAL_BIG_RY,
                             GAME_DETECTOR_PORTAL_BIG_FW,
                             GAME_DETECTOR_PORTAL_BIG_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        portalMultiplier++;
        setSwipe(GAME_DETECTOR_SWIPE_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_DIRECTION);
        gameLevel = PORTAL_5;
        break;

      case PORTAL_5:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y0,
                             GAME_DETECTOR_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y1,
                             GAME_DETECTOR_PORTAL_SMALL_RX,
                             GAME_DETECTOR_PORTAL_SMALL_RY,
                             GAME_DETECTOR_PORTAL_SMALL_FW,
                             GAME_DETECTOR_PORTAL_SMALL_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        setSwipe(GAME_DETECTOR_SWIPE_PORTAL_BIG_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_Y0,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_Y1,
                 GAME_DETECTOR_SWIPE_PORTAL_BIG_DIRECTION);
        gameLevel = PORTAL_6;
        break;

      case PORTAL_6:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_BIG_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_BIG_Y0,
                             GAME_DETECTOR_PORTAL_BIG_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_BIG_Y1,
                             GAME_DETECTOR_PORTAL_BIG_RX,
                             GAME_DETECTOR_PORTAL_BIG_RY,
                             GAME_DETECTOR_PORTAL_BIG_FW,
                             GAME_DETECTOR_PORTAL_BIG_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        portalMultiplier++;                             
        setSwipe(GAME_DETECTOR_SWIPE_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_DIRECTION);
        gameLevel = PORTAL_7;

        break;

      case PORTAL_7:
        SGUI_drawFilledFrame(GAME_DETECTOR_PORTAL_SMALL_X0 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y0,
                             GAME_DETECTOR_PORTAL_SMALL_X1 + portalMultiplier*GAME_DETECTOR_PORTAL_SPACE_X,
                             GAME_DETECTOR_PORTAL_SMALL_Y1,
                             GAME_DETECTOR_PORTAL_SMALL_RX,
                             GAME_DETECTOR_PORTAL_SMALL_RY,
                             GAME_DETECTOR_PORTAL_SMALL_FW,
                             GAME_DETECTOR_PORTAL_SMALL_FC,
                             GAME_DETECTOR_POWER_ON_COLOR);
        setSwipe(GAME_DETECTOR_PORTAL_SMALL_X0,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0,
                 GAME_DETECTOR_PORTAL_SMALL_X1 + 2*portalMultiplier*GAME_DETECTOR_PORTAL_WIDTH_X,
                 GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1,
                 SWIPE_RIGHT);
#ifdef GAME_DECETOR_DEBUG
        SGUI_drawFrame(GAME_DETECTOR_PORTAL_SMALL_X0,
                       GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y0,
                       GAME_DETECTOR_PORTAL_SMALL_X1 + 2*portalMultiplier*GAME_DETECTOR_PORTAL_WIDTH_X,
                       GAME_DETECTOR_SWIPE_PORTAL_SMALL_Y1,
                       0, 0, 1, 0x0000);
#endif
        gameLevel = DETECTOR;
        break;

      case DETECTOR:
        SGUI_drawFilledFrame(GAME_DETECTOR_DETECTOR_X0,
                       GAME_DETECTOR_DETECTOR_Y0,
                       GAME_DETECTOR_DETECTOR_X1,
                       GAME_DETECTOR_DETECTOR_Y1,
                       GAME_DETECTOR_DETECTOR_RX,
                       GAME_DETECTOR_DETECTOR_RY,
                       GAME_DETECTOR_DETECTOR_FW,
                       GAME_DETECTOR_DETECTOR_FC,
                       GAME_DETECTOR_POWER_ON_COLOR);
        gameLevel = FINISH;
        break;

      case FINISH:
        SGUI_buttonVisibility(GAME_DETECTOR_B_NEXT_P, 1, true);
        SGUI_buttonInUsage(GAME_DETECTOR_B_NEXT_P, 1, true);
        useSwipe(false);
        gameLevel = START;
        break;

      default:
        break;
    }
  }
}
