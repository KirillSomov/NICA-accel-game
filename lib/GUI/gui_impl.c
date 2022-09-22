
#include "gui_impl.h"
#include "LCD_api.h"


SGUI_pageStorageCreate(0, 0, 5, 6);
SGUI_pageStorageCreate(1, 0, 3, 1);
SGUI_pageStorageCreate(2, 0, 3, 1);
SGUI_pagesStorageCreate(3);
SGUI_guiStorageCreate();


extern const unsigned char circle_booster_8bpp;
extern const unsigned char detector_8bpp;
extern const unsigned char ions_source_8bpp;
extern const unsigned char linear_booster_8bpp;
extern const unsigned char jinr_building_main_8bpp;
extern const unsigned char nica_logo_8bpp;


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  GUI.pages[1] = &page_1;
  GUI.pages[2] = &page_2;
}


static void btn_start(void)
{
  SGUI_showPage(1);
}

static void btn_picIonsSource(void)
{
  SGUI_showPage(1);
}

static void btn_picLinearBooster(void)
{
  SGUI_showPage(2);
}


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_createButton(P0_B_START_P,
                    P0_B_START_X0,
                    P0_B_START_Y0,
                    P0_B_START_X1,
                    P0_B_START_Y1,
                    P0_B_START_RX,
                    P0_B_START_RY,
                    P0_B_START_FW,
                    P0_B_START_BC,
                    P0_B_START_FC,
                    P0_B_START_T,
                    P0_B_START_TC,
                    P0_B_START_TMX,
                    P0_B_START_TMY,
                    P0_B_START_STATE,
                    P0_B_START_DELAY,
                    P0_B_START_ACT);
  SGUI_createButton(P0_B_IONS_SOURCE_P,
                    P0_B_IONS_SOURCE_X0,
                    P0_B_IONS_SOURCE_Y0,
                    P0_B_IONS_SOURCE_X1,
                    P0_B_IONS_SOURCE_Y1,
                    P0_B_IONS_SOURCE_RX,
                    P0_B_IONS_SOURCE_RY,
                    P0_B_IONS_SOURCE_FW,
                    P0_B_IONS_SOURCE_BC,
                    P0_B_IONS_SOURCE_FC,
                    P0_B_IONS_SOURCE_T,
                    P0_B_IONS_SOURCE_TC,
                    P0_B_IONS_SOURCE_TMX,
                    P0_B_IONS_SOURCE_TMY,
                    P0_B_IONS_SOURCE_STATE,
                    P0_B_IONS_SOURCE_DELAY,
                    P0_B_IONS_SOURCE_ACT);
  SGUI_createButton(P0_B_LINEAR_BOOSTER_P,
                    P0_B_LINEAR_BOOSTER_X0,
                    P0_B_LINEAR_BOOSTER_Y0,
                    P0_B_LINEAR_BOOSTER_X1,
                    P0_B_LINEAR_BOOSTER_Y1,
                    P0_B_LINEAR_BOOSTER_RX,
                    P0_B_LINEAR_BOOSTER_RY,
                    P0_B_LINEAR_BOOSTER_FW,
                    P0_B_LINEAR_BOOSTER_BC,
                    P0_B_LINEAR_BOOSTER_FC,
                    P0_B_LINEAR_BOOSTER_T,
                    P0_B_LINEAR_BOOSTER_TC,
                    P0_B_LINEAR_BOOSTER_TMX,
                    P0_B_LINEAR_BOOSTER_TMY,
                    P0_B_LINEAR_BOOSTER_STATE,
                    P0_B_LINEAR_BOOSTER_DELAY,
                    P0_B_LINEAR_BOOSTER_ACT);
  SGUI_createPicture(P0_PIC_JINR_P,
                     P0_PIC_JINR_PIC,
                     P0_PIC_JINR_X,
                     P0_PIC_JINR_Y,
                     P0_PIC_JINR_W,
                     P0_PIC_JINR_H,
                     P0_PIC_JINR_RX,
                     P0_PIC_JINR_RY,
                     P0_PIC_JINR_FW,
                     P0_PIC_JINR_FC);
  SGUI_createPicture(P0_PIC_NICA_P,
                     P0_PIC_NICA_PIC,
                     P0_PIC_NICA_X,
                     P0_PIC_NICA_Y,
                     P0_PIC_NICA_W,
                     P0_PIC_NICA_H,
                     P0_PIC_NICA_RX,
                     P0_PIC_NICA_RY,
                     P0_PIC_NICA_FW,
                     P0_PIC_NICA_FC);
  SGUI_createPicture(P0_PIC_IONS_SOURCE_P,
                     P0_PIC_IONS_SOURCE_PIC,
                     P0_PIC_IONS_SOURCE_X,
                     P0_PIC_IONS_SOURCE_Y,
                     P0_PIC_IONS_SOURCE_W,
                     P0_PIC_IONS_SOURCE_H,
                     P0_PIC_IONS_SOURCE_RX,
                     P0_PIC_IONS_SOURCE_RY,
                     P0_PIC_IONS_SOURCE_FW,
                     P0_PIC_IONS_SOURCE_FC);
  SGUI_createPicture(P0_PIC_LINEAR_BOOSTER_P,
                     P0_PIC_LINEAR_BOOSTER_PIC,
                     P0_PIC_LINEAR_BOOSTER_X,
                     P0_PIC_LINEAR_BOOSTER_Y,
                     P0_PIC_LINEAR_BOOSTER_W,
                     P0_PIC_LINEAR_BOOSTER_H,
                     P0_PIC_LINEAR_BOOSTER_RX,
                     P0_PIC_LINEAR_BOOSTER_RY,
                     P0_PIC_LINEAR_BOOSTER_FW,
                     P0_PIC_LINEAR_BOOSTER_FC);
  SGUI_createPicture(P0_PIC_CIRCLE_BOOSTER_P,
                     P0_PIC_CIRCLE_BOOSTER_PIC,
                     P0_PIC_CIRCLE_BOOSTER_X,
                     P0_PIC_CIRCLE_BOOSTER_Y,
                     P0_PIC_CIRCLE_BOOSTER_W,
                     P0_PIC_CIRCLE_BOOSTER_H,
                     P0_PIC_CIRCLE_BOOSTER_RX,
                     P0_PIC_CIRCLE_BOOSTER_RY,
                     P0_PIC_CIRCLE_BOOSTER_FW,
                     P0_PIC_CIRCLE_BOOSTER_FC);
  SGUI_createPicture(P0_PIC_DETECTOR_P,
                     P0_PIC_DETECTOR_PIC,
                     P0_PIC_DETECTOR_X,
                     P0_PIC_DETECTOR_Y,
                     P0_PIC_DETECTOR_W,
                     P0_PIC_DETECTOR_H,
                     P0_PIC_DETECTOR_RX,
                     P0_PIC_DETECTOR_RY,
                     P0_PIC_DETECTOR_FW,
                     P0_PIC_DETECTOR_FC);
  SGUI_createPicture(P0_PIC_JINR_P,
                     P0_PIC_JINR_PIC,
                     P0_PIC_JINR_X,
                     P0_PIC_JINR_Y,
                     P0_PIC_JINR_W,
                     P0_PIC_JINR_H,
                     P0_PIC_JINR_RX,
                     P0_PIC_JINR_RY,
                     P0_PIC_JINR_FW,
                     P0_PIC_JINR_FC);
  SGUI_createPicture(P0_PIC_NICA_P,
                     P0_PIC_NICA_PIC,
                     P0_PIC_NICA_X,
                     P0_PIC_NICA_Y,
                     P0_PIC_NICA_W,
                     P0_PIC_NICA_H,
                     P0_PIC_NICA_RX,
                     P0_PIC_NICA_RY,
                     P0_PIC_NICA_FW,
                     P0_PIC_NICA_FC);
  SGUI_drawPage(0);
}


static void btn_backToStart(void)
{
  SGUI_showPage(0);
}

static void btn_p1Clear(void)
{
  ;
}

static void btn_p1Next(void)
{
  SGUI_showPage(2);;
}


static void page_1_init(void)
{
  SGUI_LinkPageToLcd(1, PAGE1_START_ADDR);
  SGUI_setPage(1);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_createButton(P1_B_BACK_TO_START_P,
                    P1_B_BACK_TO_START_X0,
                    P1_B_BACK_TO_START_Y0,
                    P1_B_BACK_TO_START_X1,
                    P1_B_BACK_TO_START_Y1,
                    P1_B_BACK_TO_START_RX,
                    P1_B_BACK_TO_START_RY,
                    P1_B_BACK_TO_START_FW,
                    P1_B_BACK_TO_START_BC,
                    P1_B_BACK_TO_START_FC,
                    P1_B_BACK_TO_START_T,
                    P1_B_BACK_TO_START_TC,
                    P1_B_BACK_TO_START_TMX,
                    P1_B_BACK_TO_START_TMY,
                    P1_B_BACK_TO_START_STATE,
                    P1_B_BACK_TO_START_DELAY,
                    P1_B_BACK_TO_START_ACT);
  SGUI_createButton(P1_B_CLEAR_P,
                    P1_B_CLEAR_X0,
                    P1_B_CLEAR_Y0,
                    P1_B_CLEAR_X1,
                    P1_B_CLEAR_Y1,
                    P1_B_CLEAR_RX,
                    P1_B_CLEAR_RY,
                    P1_B_CLEAR_FW,
                    P1_B_CLEAR_BC,
                    P1_B_CLEAR_FC,
                    P1_B_CLEAR_T,
                    P1_B_CLEAR_TC,
                    P1_B_CLEAR_TMX,
                    P1_B_CLEAR_TMY,
                    P1_B_CLEAR_STATE,
                    P1_B_CLEAR_DELAY,
                    P1_B_CLEAR_ACT);
  SGUI_createButton(P1_B_NEXT_P,
                    P1_B_NEXT_X0,
                    P1_B_NEXT_Y0,
                    P1_B_NEXT_X1,
                    P1_B_NEXT_Y1,
                    P1_B_NEXT_RX,
                    P1_B_NEXT_RY,
                    P1_B_NEXT_FW,
                    P1_B_NEXT_BC,
                    P1_B_NEXT_FC,
                    P1_B_NEXT_T,
                    P1_B_NEXT_TC,
                    P1_B_NEXT_TMX,
                    P1_B_NEXT_TMY,
                    P1_B_NEXT_STATE,
                    P1_B_NEXT_DELAY,
                    P1_B_NEXT_ACT);
  SGUI_createPicture(P1_PIC_IONS_SOURCE_P,
                     P1_PIC_IONS_SOURCE_PIC,
                     P1_PIC_IONS_SOURCE_X,
                     P1_PIC_IONS_SOURCE_Y,
                     P1_PIC_IONS_SOURCE_W,
                     P1_PIC_IONS_SOURCE_H,
                     P1_PIC_IONS_SOURCE_RX,
                     P1_PIC_IONS_SOURCE_RY,
                     P1_PIC_IONS_SOURCE_FW,
                     P1_PIC_IONS_SOURCE_FC);
  SGUI_drawPage(1);
}


static void btn_p2Clear(void)
{
  ;
}

static void btn_p2Next(void)
{
  ;
}


static void page_2_init(void)
{
  SGUI_LinkPageToLcd(2, PAGE2_START_ADDR);
  SGUI_setPage(2);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_createButton(P2_B_BACK_TO_START_P,
                    P2_B_BACK_TO_START_X0,
                    P2_B_BACK_TO_START_Y0,
                    P2_B_BACK_TO_START_X1,
                    P2_B_BACK_TO_START_Y1,
                    P2_B_BACK_TO_START_RX,
                    P2_B_BACK_TO_START_RY,
                    P2_B_BACK_TO_START_FW,
                    P2_B_BACK_TO_START_BC,
                    P2_B_BACK_TO_START_FC,
                    P2_B_BACK_TO_START_T,
                    P2_B_BACK_TO_START_TC,
                    P2_B_BACK_TO_START_TMX,
                    P2_B_BACK_TO_START_TMY,
                    P2_B_BACK_TO_START_STATE,
                    P2_B_BACK_TO_START_DELAY,
                    P2_B_BACK_TO_START_ACT);
  SGUI_createButton(P2_B_CLEAR_P,
                    P2_B_CLEAR_X0,
                    P2_B_CLEAR_Y0,
                    P2_B_CLEAR_X1,
                    P2_B_CLEAR_Y1,
                    P2_B_CLEAR_RX,
                    P2_B_CLEAR_RY,
                    P2_B_CLEAR_FW,
                    P2_B_CLEAR_BC,
                    P2_B_CLEAR_FC,
                    P2_B_CLEAR_T,
                    P2_B_CLEAR_TC,
                    P2_B_CLEAR_TMX,
                    P2_B_CLEAR_TMY,
                    P2_B_CLEAR_STATE,
                    P2_B_CLEAR_DELAY,
                    P2_B_CLEAR_ACT);
  SGUI_createButton(P2_B_NEXT_P,
                    P2_B_NEXT_X0,
                    P2_B_NEXT_Y0,
                    P2_B_NEXT_X1,
                    P2_B_NEXT_Y1,
                    P2_B_NEXT_RX,
                    P2_B_NEXT_RY,
                    P2_B_NEXT_FW,
                    P2_B_NEXT_BC,
                    P2_B_NEXT_FC,
                    P2_B_NEXT_T,
                    P2_B_NEXT_TC,
                    P2_B_NEXT_TMX,
                    P2_B_NEXT_TMY,
                    P2_B_NEXT_STATE,
                    P2_B_NEXT_DELAY,
                    P2_B_NEXT_ACT);
  SGUI_createPicture(P2_PIC_LINEAR_BOOSTER_P,
                     P2_PIC_LINEAR_BOOSTER_PIC,
                     P2_PIC_LINEAR_BOOSTER_X,
                     P2_PIC_LINEAR_BOOSTER_Y,
                     P2_PIC_LINEAR_BOOSTER_W,
                     P2_PIC_LINEAR_BOOSTER_H,
                     P2_PIC_LINEAR_BOOSTER_RX,
                     P2_PIC_LINEAR_BOOSTER_RY,
                     P2_PIC_LINEAR_BOOSTER_FW,
                     P2_PIC_LINEAR_BOOSTER_FC);
  SGUI_drawPage(2);
}


void gui_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
  page_1_init();
  page_2_init();
  SGUI_showPage(0); 
}



