
#include "keypad.h"
#include "main.h"

void keypad_init(void)
{
  HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, GPIO_PIN_RESET);
}

uint8_t keypad_scan(uint16_t GPIO_Pin)
{
    uint8_t key = 0;
    switch (GPIO_Pin)
    {
      case COLUMN_1_Pin:
        if (HAL_GPIO_ReadPin(COLUMN_1_GPIO_Port, COLUMN_1_Pin) == GPIO_PIN_SET) {
          key = 'E';
          break;
        }
        HAL_GPIO_WritePin(ROW_1_GPIO_Port, ROW_1_Pin, GPIO_PIN_SET);
        for (int i = 0; i < 10; i++);
        if (HAL_GPIO_ReadPin(COLUMN_1_GPIO_Port, COLUMN_1_Pin) == GPIO_PIN_SET) {
          key = '1';
          break;
        }
        HAL_GPIO_WritePin(ROW_2_GPIO_Port, ROW_2_Pin, GPIO_PIN_SET);
        for (int i = 0; i < 10; i++);
        if (HAL_GPIO_ReadPin(COLUMN_1_GPIO_Port, COLUMN_1_Pin) == GPIO_PIN_SET) {
          key = '4';
          break;
        }
        HAL_GPIO_WritePin(ROW_3_GPIO_Port, ROW_3_Pin, GPIO_PIN_SET);
        for (int i = 0; i < 10; i++);
        if (HAL_GPIO_ReadPin(COLUMN_1_GPIO_Port, COLUMN_1_Pin) == GPIO_PIN_SET) {
          key = '7';
          break;
        }
        HAL_GPIO_WritePin(ROW_4_GPIO_Port, ROW_4_Pin, GPIO_PIN_SET);
        for (int i = 0; i < 10; i++);
        if (HAL_GPIO_ReadPin(COLUMN_1_GPIO_Port, COLUMN_1_Pin) == GPIO_PIN_SET) {
          key = '*';
          break;
        }
        break;
      case COLUMN_2_Pin:
        break;
      case COLUMN_3_Pin:
        break;
      case COLUMN_4_Pin:
        break;
      case B1_Pin:
        break;
      default:
        break;
    }
    keypad_init();
  return key;
}