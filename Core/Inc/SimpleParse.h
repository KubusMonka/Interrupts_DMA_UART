/*
 *      Author: jmonk
 */

#ifndef INC_SIMPLEPARSE_H_
#define INC_SIMPLEPARSE_H_

#define ENDLINE '\n'

void Parser_TakeLine(RingBuffer_t *Buffer, uint8_t ReceivedData[]);
void Strcmp_Parse(uint8_t *DataToParse);

#endif /* INC_SIMPLEPARSE_H_ */
