#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "stm32f1xx_hal.h"
#include "dwt_stm32_delay.h"


class MKeyBoard
{
public:
	MKeyBoard(void);
	void SetRows(GPIO_TypeDef *_ROW0_P,uint16_t _ROW0,GPIO_TypeDef *_ROW1_P,uint16_t _ROW1,GPIO_TypeDef *_ROW2_P,uint16_t _ROW2,GPIO_TypeDef *_ROW3_P,uint16_t _ROW3,GPIO_TypeDef *_ROW4_P,uint16_t _ROW4);
	void SetCols(GPIO_TypeDef *_COL0_P,uint16_t _COL0,GPIO_TypeDef *_COL1_P,uint16_t _COL1,GPIO_TypeDef *_COL2_P,uint16_t _COL2,GPIO_TypeDef *_COL3_P,uint16_t _COL3,GPIO_TypeDef *_COL4_P,uint16_t _COL4);
	uint32_t ReadKeyBoard(void);
private:
//	GPIO_TypeDef *ROW1_P,*ROW2_P,*ROW3_P,*ROW4_P,*ROW5_P,*COL1_P,*COL2_P,*COL3_P,*COL4_P,*COL5_P;
//	uint16_t ROW1,ROW2,ROW3,ROW4,ROW5,COL1,COL2,COL3,COL4,COL5;
	GPIO_TypeDef *ROWS_P[5],*COLS_P[5];
	uint16_t ROWS[5],COLS[5];
};

#endif
