
#ifndef DEF_H_
#define DEF_H_

typedef int bool;
typedef unsigned char byte;

#define FALSE 0
#define false 0
#define TRUE !FALSE
#define true !false

typedef union {
    byte Byte;
    struct {
        byte b0  :1;  
        byte b1  :1;  
        byte b2  :1;  
        byte b3  :1;  
        byte b4  :1; 
        byte b5  :1; 
        byte b6  :1; 
        byte b7  :1; 
    } Bits;
} ByteUnion;

// Enable maskable interrupts
#define EnableInterrupts(); asm(" CPSIE i");
// Disable maskable interrupts
#define DisableInterrupts(); asm(" CPSID i");


#endif /* DEF_H_ */
