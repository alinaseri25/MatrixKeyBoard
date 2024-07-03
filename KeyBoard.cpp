#include "KeyBoard.h"

MKeyBoard::MKeyBoard(void)
{
	
}

void MKeyBoard::SetRows(GPIO_TypeDef *_ROW0_P,uint16_t _ROW0,GPIO_TypeDef *_ROW1_P,uint16_t _ROW1,GPIO_TypeDef *_ROW2_P,uint16_t _ROW2,GPIO_TypeDef *_ROW3_P,uint16_t _ROW3,GPIO_TypeDef *_ROW4_P,uint16_t _ROW4)
{
	ROWS_P[0] = _ROW0_P;
	ROWS[0] = _ROW0;
	
	ROWS_P[1] = _ROW1_P;
	ROWS[1] = _ROW1;
	
	ROWS_P[2] = _ROW2_P;
	ROWS[2] = _ROW2;
	
	ROWS_P[3] = _ROW3_P;
	ROWS[3] = _ROW3;
	
	ROWS_P[4] = _ROW4_P;
	ROWS[4] = _ROW4;
}

void MKeyBoard::SetCols(GPIO_TypeDef *_COL0_P,uint16_t _COL0,GPIO_TypeDef *_COL1_P,uint16_t _COL1,GPIO_TypeDef *_COL2_P,uint16_t _COL2,GPIO_TypeDef *_COL3_P,uint16_t _COL3,GPIO_TypeDef *_COL4_P,uint16_t _COL4)
{
	COLS_P[0] = _COL0_P;
	COLS[0] = _COL0;
	
	COLS_P[1] = _COL1_P;
	COLS[1] = _COL1;
	
	COLS_P[2] = _COL2_P;
	COLS[2] = _COL2;
	
	COLS_P[3] = _COL3_P;
	COLS[3] = _COL3;
	
	COLS_P[4] = _COL4_P;
	COLS[4] = _COL4;
}

uint32_t MKeyBoard::ReadKeyBoard(void)
{
	uint32_t RetVal = 0;
	HAL_GPIO_WritePin(ROWS_P[0],ROWS[0],GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROWS_P[1],ROWS[1],GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROWS_P[2],ROWS[2],GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROWS_P[3],ROWS[3],GPIO_PIN_SET);
	HAL_GPIO_WritePin(ROWS_P[4],ROWS[4],GPIO_PIN_SET);
	
	for(uint8_t _Count = 0 ; _Count <= 4 ; _Count++)
	{
		HAL_GPIO_WritePin(ROWS_P[_Count],ROWS[_Count],GPIO_PIN_RESET);
		if(HAL_GPIO_ReadPin(COLS_P[0],COLS[0]) == GPIO_PIN_RESET)
		{
			RetVal |= ((0x00000001)<<((_Count * 5)+ 0));
		}
		
		if(HAL_GPIO_ReadPin(COLS_P[1],COLS[1]) == GPIO_PIN_RESET)
		{
			RetVal |= ((0x00000001)<<((_Count * 5)+ 1));
		}
		
		if(HAL_GPIO_ReadPin(COLS_P[2],COLS[2]) == GPIO_PIN_RESET)
		{
			RetVal |= ((0x00000001)<<((_Count * 5)+ 2));
		}
		
		if(HAL_GPIO_ReadPin(COLS_P[3],COLS[3]) == GPIO_PIN_RESET)
		{
			RetVal |= ((0x00000001)<<((_Count * 5)+ 3));
		}
		
		if(HAL_GPIO_ReadPin(COLS_P[4],COLS[4]) == GPIO_PIN_RESET)
		{
			RetVal |= ((0x00000001)<<((_Count * 5)+ 4));
		}
		HAL_GPIO_WritePin(ROWS_P[_Count],ROWS[_Count],GPIO_PIN_SET);
	}
	return RetVal;
}
