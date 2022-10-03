
#include "gui_impl.h"
#include "LCD_api.h"
#include "game_ions.h"
#include "game_linAccel.h"


SGUI_pageStorageCreate(0, 0, 5, 6, 0);
SGUI_pageStorageCreate(1, 1, 3, 1, 1);
SGUI_pageStorageCreate(2, 0, 4, 1, 0);
SGUI_pageStorageCreate(3, 0, 3, 1, 0);
SGUI_pageStorageCreate(4, 0, 3, 1, 0);
SGUI_pagesStorageCreate(5);
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
  GUI.pages[3] = &page_3;
  GUI.pages[4] = &page_4;
}


static void btn_start(void)
{
  SGUI_showPage(1);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}

static void btn_picIonsSource(void)
{
  SGUI_showPage(1);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}

static void btn_picLinearBooster(void)
{
  SGUI_showPage(2);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}

static void btn_picCircleBooster(void)
{
  SGUI_showPage(3);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}

static void btn_picDetector(void)
{
  SGUI_showPage(4);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_printString("Для знакомства с нами\n    ЖМИ НА ИКОНКИ", 350, 140, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("Ускорительный\nкомплекс NICA", 735, 140, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("ОИЯИ", 80, 260, FONT_SIZE_48, 0xFFFF, 0x4BC6);
  SGUI_printString("основан в 1956 г.", 30, 315, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("     Наука\nсближает народы", 30, 390, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("Мы из Дубны =)", 30, 550, FONT_SIZE_24, 0xFFFF, 0x3823);
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
  SGUI_createButton(P0_B_CIRCLE_BOOSTER_P,
                    P0_B_CIRCLE_BOOSTER_X0,
                    P0_B_CIRCLE_BOOSTER_Y0,
                    P0_B_CIRCLE_BOOSTER_X1,
                    P0_B_CIRCLE_BOOSTER_Y1,
                    P0_B_CIRCLE_BOOSTER_RX,
                    P0_B_CIRCLE_BOOSTER_RY,
                    P0_B_CIRCLE_BOOSTER_FW,
                    P0_B_CIRCLE_BOOSTER_BC,
                    P0_B_CIRCLE_BOOSTER_FC,
                    P0_B_CIRCLE_BOOSTER_T,
                    P0_B_CIRCLE_BOOSTER_TC,
                    P0_B_CIRCLE_BOOSTER_TMX,
                    P0_B_CIRCLE_BOOSTER_TMY,
                    P0_B_CIRCLE_BOOSTER_STATE,
                    P0_B_CIRCLE_BOOSTER_DELAY,
                    P0_B_CIRCLE_BOOSTER_ACT);
  SGUI_createButton(P0_B_DETECTOR_P,
                    P0_B_DETECTOR_X0,
                    P0_B_DETECTOR_Y0,
                    P0_B_DETECTOR_X1,
                    P0_B_DETECTOR_Y1,
                    P0_B_DETECTOR_RX,
                    P0_B_DETECTOR_RY,
                    P0_B_DETECTOR_FW,
                    P0_B_DETECTOR_BC,
                    P0_B_DETECTOR_FC,
                    P0_B_DETECTOR_T,
                    P0_B_DETECTOR_TC,
                    P0_B_DETECTOR_TMX,
                    P0_B_DETECTOR_TMY,
                    P0_B_DETECTOR_STATE,
                    P0_B_DETECTOR_DELAY,
                    P0_B_DETECTOR_ACT);
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
  SGUI_idle(DELAY_BETWEEN_PAGES);
}

static void btn_p1Next(void)
{
  SGUI_showPage(2);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void page_1_init(void)
{
  SGUI_LinkPageToLcd(1, PAGE1_START_ADDR);
  SGUI_setPage(1);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_printString("Получение пучка заряженных частиц", 380, 20, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_printString("Жми пальцем внутри области и получай\n      пучок заряженных частиц", 415, 75, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString(" Сверхпроводящий\n  источник ионов\n тяжёлых элементов\n    \"КРИОН-6Т\"", 20, 145, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("  Обеспечивает\n ускорительный\nкомплекс пучками\n ионов тяжелых\n   элементов:\nС, Кr, Ar,\n      Xe, Bi, Au.", 20, 285, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("Разработан в Дубне\n    создатель:\n проф. Е.Д. Донец", 20, 500, FONT_SIZE_24, 0xFFFF, 0x0000);
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
  game_ions_init();
  SGUI_drawPage(1);
}


static void btn_p2Next(void)
{
  SGUI_showPage(3);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void page_2_init(void)
{
  SGUI_LinkPageToLcd(2, PAGE2_START_ADDR);
  SGUI_setPage(2);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_printString("Ускорение пучка заряженных частиц", 380, 20, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_printString("1. Включи питание ускорителя\n2. Запусти ускорительные станции\n3. Проведи пучок через ускоритель", 420, 75, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("Линейный ускоритель\n   тяжелых ионов", 20, 145, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("  Ускоряет пучки\n  ионов тяжелых\n   элементов до\n  промежуточных\n    энергий ~5\nМегаЭлектронвольт.", 20, 230, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("1 МэВ = 1.6E-19 Дж.", 20, 435, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString(" Является частью\n комплекса NICA", 20, 500, FONT_SIZE_24, 0xFFFF, 0x0000);
  SGUI_printString("подключите станции\n к системе питания", 605, 520, FONT_SIZE_24, 0xFFFF, 0x4BC6);
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
  game_linAccel_init();
  SGUI_pageSetActionFunc(2, game_linAccel_handler);
  SGUI_drawPage(2);
}


static void btn_p3Next(void)
{
  SGUI_showPage(4);
  SGUI_idle(DELAY_BETWEEN_PAGES);
}


static void page_3_init(void)
{
  SGUI_LinkPageToLcd(3, PAGE3_START_ADDR);
  SGUI_setPage(3);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_printString("Ускорение пучка заряженных частиц", 380, 20, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_printString("1. Включи питание ускорителя\n2. Запусти ускорительные станции\n    и проведи пучок через станции", 420, 75, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("  Циклический\n    ускоритель\nБустерный синхротрон", 20, 145, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString(" Накапливает и\n ускоряет пучки\n ионов тяжелых\n элементов до\n энергий ~600\n МегаЭлектронвольт.", 20, 235, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("1 МэВ = 1.6E-19 Дж.", 20, 435, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString(" Является частью\n  комплекса NICA", 20, 500, FONT_SIZE_24, 0xFFFF, 0x0000);
  SGUI_createButton(P3_B_BACK_TO_START_P,
                    P3_B_BACK_TO_START_X0,
                    P3_B_BACK_TO_START_Y0,
                    P3_B_BACK_TO_START_X1,
                    P3_B_BACK_TO_START_Y1,
                    P3_B_BACK_TO_START_RX,
                    P3_B_BACK_TO_START_RY,
                    P3_B_BACK_TO_START_FW,
                    P3_B_BACK_TO_START_BC,
                    P3_B_BACK_TO_START_FC,
                    P3_B_BACK_TO_START_T,
                    P3_B_BACK_TO_START_TC,
                    P3_B_BACK_TO_START_TMX,
                    P3_B_BACK_TO_START_TMY,
                    P3_B_BACK_TO_START_STATE,
                    P3_B_BACK_TO_START_DELAY,
                    P3_B_BACK_TO_START_ACT);
  SGUI_createButton(P3_B_NEXT_P,
                    P3_B_NEXT_X0,
                    P3_B_NEXT_Y0,
                    P3_B_NEXT_X1,
                    P3_B_NEXT_Y1,
                    P3_B_NEXT_RX,
                    P3_B_NEXT_RY,
                    P3_B_NEXT_FW,
                    P3_B_NEXT_BC,
                    P3_B_NEXT_FC,
                    P3_B_NEXT_T,
                    P3_B_NEXT_TC,
                    P3_B_NEXT_TMX,
                    P3_B_NEXT_TMY,
                    P3_B_NEXT_STATE,
                    P3_B_NEXT_DELAY,
                    P3_B_NEXT_ACT);
  SGUI_createPicture(P3_PIC_CIRCLE_BOOSTER_P,
                     P3_PIC_CIRCLE_BOOSTER_PIC,
                     P3_PIC_CIRCLE_BOOSTER_X,
                     P3_PIC_CIRCLE_BOOSTER_Y,
                     P3_PIC_CIRCLE_BOOSTER_W,
                     P3_PIC_CIRCLE_BOOSTER_H,
                     P3_PIC_CIRCLE_BOOSTER_RX,
                     P3_PIC_CIRCLE_BOOSTER_RY,
                     P3_PIC_CIRCLE_BOOSTER_FW,
                     P3_PIC_CIRCLE_BOOSTER_FC);
  SGUI_drawPage(3);
}


static void btn_p4Clear(void)
{
  ;
}

static void btn_p4Next(void)
{
  ;
}


static void page_4_init(void)
{
  SGUI_LinkPageToLcd(4, PAGE4_START_ADDR);
  SGUI_setPage(4);
  SGUI_clearPage(White);
  SGUI_drawFilledFrame(270, 0, 275, 599, 0, 0, 0, 0, 0x6BA4);
  SGUI_printString("Детектор элементарных частиц", 400, 20, FONT_SIZE_32, 0xFFFF, 0x4BC6);
  SGUI_printString("1. Подготовь (закрась) фигуры с веществом\n2. Проведи пучок через вещество", 420, 75, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("  Детектор BM@N", 20, 145, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString("Эксперимент BM@N\nявляется нулевой\nфазой мега-сайенс\nпроекта NICA\n(Nuclotron-based Ion\nCollider fAcility) -\nпервым работающим\nэкспериментом на\nфиксированной мишени", 20, 220, FONT_SIZE_24, 0xFFFF, 0x4BC6);
  SGUI_printString(" Является частью\n комплекса NICA", 20, 500, FONT_SIZE_24, 0xFFFF, 0x0000);
  SGUI_createButton(P4_B_BACK_TO_START_P,
                    P4_B_BACK_TO_START_X0,
                    P4_B_BACK_TO_START_Y0,
                    P4_B_BACK_TO_START_X1,
                    P4_B_BACK_TO_START_Y1,
                    P4_B_BACK_TO_START_RX,
                    P4_B_BACK_TO_START_RY,
                    P4_B_BACK_TO_START_FW,
                    P4_B_BACK_TO_START_BC,
                    P4_B_BACK_TO_START_FC,
                    P4_B_BACK_TO_START_T,
                    P4_B_BACK_TO_START_TC,
                    P4_B_BACK_TO_START_TMX,
                    P4_B_BACK_TO_START_TMY,
                    P4_B_BACK_TO_START_STATE,
                    P4_B_BACK_TO_START_DELAY,
                    P4_B_BACK_TO_START_ACT);
  SGUI_createButton(P4_B_CLEAR_P,
                    P4_B_CLEAR_X0,
                    P4_B_CLEAR_Y0,
                    P4_B_CLEAR_X1,
                    P4_B_CLEAR_Y1,
                    P4_B_CLEAR_RX,
                    P4_B_CLEAR_RY,
                    P4_B_CLEAR_FW,
                    P4_B_CLEAR_BC,
                    P4_B_CLEAR_FC,
                    P4_B_CLEAR_T,
                    P4_B_CLEAR_TC,
                    P4_B_CLEAR_TMX,
                    P4_B_CLEAR_TMY,
                    P4_B_CLEAR_STATE,
                    P4_B_CLEAR_DELAY,
                    P4_B_CLEAR_ACT);
  SGUI_createButton(P4_B_NEXT_P,
                    P4_B_NEXT_X0,
                    P4_B_NEXT_Y0,
                    P4_B_NEXT_X1,
                    P4_B_NEXT_Y1,
                    P4_B_NEXT_RX,
                    P4_B_NEXT_RY,
                    P4_B_NEXT_FW,
                    P4_B_NEXT_BC,
                    P4_B_NEXT_FC,
                    P4_B_NEXT_T,
                    P4_B_NEXT_TC,
                    P4_B_NEXT_TMX,
                    P4_B_NEXT_TMY,
                    P4_B_NEXT_STATE,
                    P4_B_NEXT_DELAY,
                    P4_B_NEXT_ACT);
  SGUI_createPicture(P4_PIC_DETECTOR_P,
                     P4_PIC_DETECTOR_PIC,
                     P4_PIC_DETECTOR_X,
                     P4_PIC_DETECTOR_Y,
                     P4_PIC_DETECTOR_W,
                     P4_PIC_DETECTOR_H,
                     P4_PIC_DETECTOR_RX,
                     P4_PIC_DETECTOR_RY,
                     P4_PIC_DETECTOR_FW,
                     P4_PIC_DETECTOR_FC);
  SGUI_drawPage(4);
}


void gui_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
  page_1_init();
  page_2_init();
  page_3_init();
  page_4_init();
  SGUI_showPage(0); 
}



