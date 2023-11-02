#include "main.h"
#include "RingBuffer.h"
#include "SimpleParse.h"
#include "string.h"

void Parser_TakeLine(RingBuffer_t *Buffer, uint8_t ReceivedData[])
{
	uint8_t i=0;
			  do
			  {

				  RB_Read(Buffer, &ReceivedData[i]);
				  i++;
			  }while
			  (ReceivedData[i-1] != ENDLINE);
			  ReceivedData[i-1] = 0; // remove '\n' before strcmp
			  //ReceivedLines--;

}


void Strcmp_Parse(uint8_t *DataToParse)
{
	if (strcmp("LED_ON",(char*)DataToParse) == 0)
	{
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	}
	else if (strcmp("LED_OFF",(char*)DataToParse) == 0)
	{
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}

}


/*

if(ReceivedLines > 0)
	  {
		  uint8_t i=0;
		  do
		  {

			  RB_Read(&RingBuffer, &ReceivedData[i]);
			  i++;
		  }while
		  (ReceivedData[i-1] != ENDLINE);
		  ReceivedData[i-1] = 0; // remove '\n' before strcmp
		  ReceivedLines--;

		  if (strcmp("LED_ON",(char*)ReceivedData) == 0)
		  {
			  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		  }
		  else if (strcmp("LED_OFF",(char*)ReceivedData) == 0)
		  {
			  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		  }

	  }
*/
