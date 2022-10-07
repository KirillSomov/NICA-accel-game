
#include "gui_impl.h"
#include "game_detector.h"
#include "stdbool.h"
#include "swipe.h"
#include "Timer.h"


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
extern unsigned short gameMode;
static unsigned short portalMultiplier = 0;


struct ion
{
  unsigned short x;
  unsigned short y;
};


static struct ion ionColumn_1[IONS_ROWS] =
{
  {IONS_COLUMN_1_X, IONS_Y+17},
  {IONS_COLUMN_1_X, IONS_Y+44},
  {IONS_COLUMN_1_X, IONS_Y+100},
  {IONS_COLUMN_1_X, IONS_Y+130}
};

static struct ion ionColumn_2[IONS_ROWS] =
{
  {IONS_COLUMN_2_X, IONS_Y+33},
  {IONS_COLUMN_2_X, IONS_Y+78},
  {IONS_COLUMN_2_X, IONS_Y+106},
  {IONS_COLUMN_2_X, IONS_Y+125}
};

static struct ion ionColumn_3[IONS_ROWS] =
{
  {IONS_COLUMN_3_X, IONS_Y+21},
  {IONS_COLUMN_3_X, IONS_Y+53},
  {IONS_COLUMN_3_X, IONS_Y+93},
  {IONS_COLUMN_3_X, IONS_Y+113}
};

static struct ion *ionBeam[IONS_COLUMNS] =
{
  ionColumn_1,
  ionColumn_2,
  ionColumn_3
};


static void drawIon(unsigned short x, unsigned short y, unsigned short color)
{
  SGUI_printString("*", x, y, FONT_SIZE_48, -1, color);
}


static void drawIonColumn(unsigned short col, unsigned short shift, unsigned short color)
{
  for(int l = 0; l < IONS_ROWS; l++)
  {
    drawIon(ionBeam[col][l].x+shift, ionBeam[col][l].y, color);
  }
}


static void drawIonBeam(unsigned short shift, unsigned short color)
{
  for(int c = 0; c < IONS_COLUMNS; c++)
  {
    for(int l = 0; l < IONS_ROWS; l++)
    {
      drawIon(ionBeam[c][l].x+shift, ionBeam[c][l].y, color);
    }
  }
}


static void ionsAnimation(void)
{
  unsigned short color = 0xFFFF;

  for(int shift = 0; shift < IONS_ANIM_LEN; shift++)
  {
    for(int col = 0; col < IONS_COLUMNS; col++)
    {
      if((shift+col >= IONS_ANIM_PORTAL_START+IONS_COLUMNS-1) && (shift+col <= IONS_ANIM_PORTAL_END))
      {
        color = GAME_DETECTOR_POWER_ON_COLOR;
      }
      else if((shift+col >= IONS_ANIM_DETECTOR_START+IONS_COLUMNS-1)/* && (shift+col <= IONS_ANIM_DETECTOR_END)*/)
      {
        color = GAME_DETECTOR_POWER_OFF_COLOR;
      }
      else
      {
        color = 0xFFFF;
      }
      drawIonColumn(col, shift*IONS_COLUMN_SHIF_X, color);
    }
    for(int col = 0; col < IONS_COLUMNS; col++)
    {
      if(shift+col >= IONS_ANIM_PORTAL_START+IONS_COLUMNS-2)
      {
        color = ION_COLOR_CHARGED;
      }
      else
      {
        color = ION_COLOR_OFF;
      }      
      drawIonColumn(col, (shift+1)*IONS_COLUMN_SHIF_X, color);
    }
    delay_ms(IONS_ANIM_SPEED);
  }
}


static void clearStatusBar(void)
{
  SGUI_drawFilledFrame(GAME_DETECTOR_STATUS_BAR_AREA_X0,
                       GAME_DETECTOR_STATUS_BAR_AREA_Y0,
                       GAME_DETECTOR_STATUS_BAR_AREA_X1,
                       GAME_DETECTOR_STATUS_BAR_AREA_Y1,
                       0, 0, 0, 0xFFFF, 0xFFFF); 
}


static void btn_next(void)
{
  SGUI_idle(DELAY_BETWEEN_PAGES);
  SGUI_showPage(5);
}


static void btn_clear(void)
{
  SGUI_buttonInUsage(GAME_DETECTOR_B_NEXT_P, 1, false);
  SGUI_buttonVisibility(GAME_DETECTOR_B_NEXT_P, 1, false);
  clearStatusBar();
  gameLevel = START;
  portalMultiplier = 0;
  SGUI_buttonSetColor(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, GAME_DETECTOR_POWER_OFF_COLOR);
  drawIonBeam(0, ION_COLOR_OFF);
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
  SGUI_buttonSetFrameColor(GAME_DETECTOR_B_START_P, GAME_DETECTOR_B_START_ID, GAME_DETECTOR_ACTIVE_COLOR);
  setSwipe(GAME_DETECTOR_SWIPE_PORTAL_BIG_X0,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_Y0,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_X1,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_Y1,
         GAME_DETECTOR_SWIPE_PORTAL_BIG_DIRECTION);
  useSwipe(true);
  gameLevel = PORTAL_1;
}


void game_detector_init(void)
{
  SGUI_printString(GAME_DETECTOR_HEADER_1_TEXT, GAME_DETECTOR_HEADER_1_X, GAME_DETECTOR_HEADER_Y, FONT_SIZE_32, -1, 0x0000);
  SGUI_printString(GAME_DETECTOR_HEADER_2_TEXT, GAME_DETECTOR_HEADER_2_X, GAME_DETECTOR_HEADER_Y, FONT_SIZE_32, -1, 0x0000);
  SGUI_printString(GAME_DETECTOR_HEADER_3_TEXT, GAME_DETECTOR_HEADER_3_X, GAME_DETECTOR_HEADER_Y, FONT_SIZE_32, -1, 0x0000);
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
                             GAME_DETECTOR_ACTIVE_COLOR,
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
                             GAME_DETECTOR_ACTIVE_COLOR,
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
                             GAME_DETECTOR_ACTIVE_COLOR,
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
                             GAME_DETECTOR_ACTIVE_COLOR,
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
                             GAME_DETECTOR_ACTIVE_COLOR,
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
                             GAME_DETECTOR_ACTIVE_COLOR,
                             GAME_DETECTOR_POWER_ON_COLOR);
        clearStatusBar();
        SGUI_printString(GAME_DETECTOR_STATUS_BAR_TEXT_ACT,
                         GAME_DETECTOR_STATUS_BAR_TEXT_X,
                         GAME_DETECTOR_STATUS_BAR_TEXT_Y,
                         FONT_SIZE_32, 0xFFFF, 0x0000);
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
        useSwipe(false);
        ionsAnimation();
        SGUI_drawFilledFrame(GAME_DETECTOR_DETECTOR_X0,
                             GAME_DETECTOR_DETECTOR_Y0,
                             GAME_DETECTOR_DETECTOR_X1,
                             GAME_DETECTOR_DETECTOR_Y1,
                             GAME_DETECTOR_DETECTOR_RX,
                             GAME_DETECTOR_DETECTOR_RY,
                             GAME_DETECTOR_DETECTOR_FW,
                             GAME_DETECTOR_ACTIVE_COLOR,
                             GAME_DETECTOR_POWER_ON_COLOR);
        drawIonBeam(IONS_ANIM_LEN*IONS_COLUMN_SHIF_X, ION_COLOR_CHARGED);
        clearStatusBar();
        SGUI_printString(GAME_DETECTOR_STATUS_BAR_TEXT_DETECTOR,
                         GAME_DETECTOR_STATUS_BAR_TEXT_X,
                         GAME_DETECTOR_STATUS_BAR_TEXT_Y,
                         FONT_SIZE_32, 0xFFFF, 0x0000);
        delay_ms(1000);
        if(gameMode == GAME_MODE_GAME)
        {
          SGUI_buttonVisibility(GAME_DETECTOR_B_NEXT_P, 1, true);
          SGUI_buttonInUsage(GAME_DETECTOR_B_NEXT_P, 1, true);
        }
        else
        {
          clearStatusBar();
          SGUI_printString(GAME_DETECTOR_STATUS_BAR_TEXT_FREE,
                           GAME_DETECTOR_STATUS_BAR_TEXT_X,
                           GAME_DETECTOR_STATUS_BAR_TEXT_Y,
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


void game_detector_cleaner(void)
{
  SGUI_setPage(GAME_DETECTOR_PAGE);
  btn_clear();
  SGUI_setPage(GUI.currentPage);
}
