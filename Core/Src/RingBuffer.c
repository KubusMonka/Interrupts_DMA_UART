#include "main.h"
#include "RingBuffer.h"



RB_Status_t_e RB_Write (RingBuffer_t *Buffer, uint8_t Value)
{
	uint8_t HeadTmp = (Buffer->Head+1)% RINGBUFFER_SIZE;
	if(HeadTmp == Buffer->Tail)
	{
		return RB_ERROR;
	}
	Buffer-> Buffer[Buffer->Head] = Value;
	Buffer->Head = HeadTmp;
	return RB_OK;
}

RB_Status_t_e RB_Read (RingBuffer_t *Buffer, uint8_t *Value)
{
	if (Buffer->Head == Buffer->Tail)
	{
		return RB_ERROR;
	}
	*Value = Buffer-> Buffer[Buffer->Tail];
	Buffer->Tail =(Buffer->Tail+1)% RINGBUFFER_SIZE;

	return RB_OK;
}

void RB_Flush(RingBuffer_t *Buffer)
{
	Buffer->Head = 0;
	Buffer->Tail = 0;
}
