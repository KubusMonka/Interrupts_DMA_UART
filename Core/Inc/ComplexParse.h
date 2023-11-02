/*
 *      Author: jmonk
 */

#ifndef INC_COMPLEXPARSE_H_
#define INC_COMPLEXPARSE_H_

#define ENDLINE '\n'

void Parser_TakeLine(RingBuffer_t *Buffer, uint8_t ReceivedData[]);
void Strcmp_Parse(uint8_t *DataToParse);

#endif /* INC_COMPLEXPARSE_H_ */
