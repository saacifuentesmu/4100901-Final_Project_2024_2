
#include "keypad.h"
#include "main.h"

const uint8_t keypad_map[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void keypad_init(void)
{
  HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, GPIO_PIN_RESET);
}

static uint8_t keypad_scan_rows(GPIO_TypeDef* COLUMN_x_GPIO_Port, uint16_t COLUMN_x_Pin)
{
    if (HAL_GPIO_ReadPin(COLUMN_x_GPIO_Port, COLUMN_x_Pin) == GPIO_PIN_SET) {
        return 0;
    }
    HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, GPIO_PIN_SET);
    for (int i = 0; i < 10; i++);
    if (HAL_GPIO_ReadPin(COLUMN_x_GPIO_Port, COLUMN_x_Pin) == GPIO_PIN_SET) {
        return 1;
    }
    HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, GPIO_PIN_SET);
    for (int i = 0; i < 10; i++);
    if (HAL_GPIO_ReadPin(COLUMN_x_GPIO_Port, COLUMN_x_Pin) == GPIO_PIN_SET) {
        return 2;
    }
    HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, GPIO_PIN_SET);
    for (int i = 0; i < 10; i++);
    if (HAL_GPIO_ReadPin(COLUMN_x_GPIO_Port, COLUMN_x_Pin) == GPIO_PIN_SET) {
        return 3;
    }
    HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, GPIO_PIN_SET);
    for (int i = 0; i < 10; i++);
    if (HAL_GPIO_ReadPin(COLUMN_x_GPIO_Port, COLUMN_x_Pin) == GPIO_PIN_SET) {
        return 4;
    }
    return 0;
}

uint8_t keypad_scan(uint16_t GPIO_Pin)
{
    uint8_t key = 0;
    uint8_t row = 0;
    switch (GPIO_Pin)
    {
      case COLUMN_1_Pin:
        row = keypad_scan_rows(COLUMN_1_GPIO_Port, COLUMN_1_Pin);
        key = keypad_map[row - 1][0];
        break;
      case COLUMN_2_Pin:
        row = keypad_scan_rows(COLUMN_2_GPIO_Port, COLUMN_2_Pin);  
        key = keypad_map[row - 1][1];
        break;
      case COLUMN_3_Pin:
        row = keypad_scan_rows(COLUMN_3_GPIO_Port, COLUMN_3_Pin);
        key = keypad_map[row - 1][2];
        break;
      case COLUMN_4_Pin:
        row = keypad_scan_rows(COLUMN_4_GPIO_Port, COLUMN_4_Pin);
        key = keypad_map[row - 1][3];
        break;
      case B1_Pin:
        break;
      default:
        break;
    }
    keypad_init();
  return key;
}