
#include "main.h"
#include "RingBuffer.h"
#include "ComplexParse.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

static char MyName[32] = "NO name";

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


}
static void Parser_ParseLED(void)
{
	//we expect 0 or 1
	char *ParsePointer = strtok(NULL,","); //continue last cutting - if we want more led 0,1,1,1

	if(strlen(ParsePointer) > 0)
	{
		if(ParsePointer[0] < '0' || ParsePointer[0] > '1' )
		{
			UartLog("error - LED wrong value. Please type 0 or 1! \r\n");
			return;
		}


		if(ParsePointer[0] == '1')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			UartLog("LED ON \r\n");
		}else if(ParsePointer[0] == '0')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			UartLog("LED OFF \r\n");
		}
	}

}


static void Parser_ParseENV (void)
{
	//we expect x,y,z
	float EnvParameters[3];
	char Message[32];
	for (uint8_t i=0; i<3; i++)
	{
		char *ParsePointer = strtok(NULL,","); //continue last cutting
		if(strlen(ParsePointer)>0)
		{
			//X.XX i=0
			//Y.YY i=1
			//Z.ZZ i=2
			for(uint8_t j = 0; ParsePointer[j] != 0 ;j++ )
			{
				if((ParsePointer[j] < '0' || ParsePointer[j] > '9')&& ParsePointer[j] != '.')
				{
					UartLog("error - ENV Wrong value -don't use letters \r\n");
					return;
				}
			}

			EnvParameters[i] = atof(ParsePointer); //ASCII to float
		}
		else
		{
			UartLog("error - ENV to less value ENV=x,y,z\\n \r\n");
		}
	}
	sprintf (Message, "Value 1: %.2f \r\n",EnvParameters[0]);
	UartLog(Message);

	sprintf (Message, "Value 2: %.2f \r\n",EnvParameters[1]);
	UartLog(Message);

	sprintf (Message, "Value 3: %.2f \r\n",EnvParameters[2]);
	UartLog(Message);
}

static void Parser_ParseNAME(void)
{
	char *ParsePointer = strtok(NULL,",");
	//string - rename device
	//? - introduce yourself
	char Message[64];
	if(strlen(ParsePointer)>0)
	{
		if (strcmp("?",ParsePointer) == 0)
		{
			sprintf (Message, "My name is: %s \r\n",MyName);
			UartLog(Message);
		}
		else
		{
			if(strlen(ParsePointer)>32)
			{
				UartLog("MAX 32 letters! \r\n");
				return;
			}
			else
			{
				strcpy(MyName, ParsePointer);
				sprintf (Message, "My new name is: %s \r\n",MyName);
				UartLog(Message);
			}
		}
	}
	else
	{
		UartLog("Name cannot be empty! \r\n");

	}


}

void Strcmp_Parse(uint8_t *DataToParse)
{
	char *ParsePointer = strtok((char*)DataToParse,"=");

		if (strcmp("LED",ParsePointer) == 0)
		{
			Parser_ParseLED();
		}
		else if (strcmp("ENV",ParsePointer) == 0)
		{
			Parser_ParseENV();
		}
		else if (strcmp("NAME",ParsePointer) == 0)
		{
		Parser_ParseNAME();
		}


//	if (strcmp("LED_ON",(char*)DataToParse) == 0)
//	{
//		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
//	}
//	else if (strcmp("LED_OFF",(char*)DataToParse) == 0)
//	{
//		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
//	}

}



