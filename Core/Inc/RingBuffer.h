/*
 *      Author: jmonk
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

#define RINGBUFFER_SIZE 64

typedef enum
{
  RB_OK       = 0x00U,
  RB_ERROR    = 0x01U

} RB_Status_t_e;

typedef struct
{

	uint16_t Head;
	uint16_t Tail;
	uint8_t Buffer[RINGBUFFER_SIZE];


}RingBuffer_t;


RB_Status_t_e RB_Write (RingBuffer_t *Buffer, uint8_t Value);
RB_Status_t_e RB_Read (RingBuffer_t *Buffer, uint8_t *Value);
void RB_Flush(RingBuffer_t *Buffer);

#endif /* INC_RINGBUFFER_H_ */
