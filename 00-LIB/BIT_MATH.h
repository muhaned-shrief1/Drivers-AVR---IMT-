/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BitNo)              REG |= (1<<BitNo)
#define CLR_BIT(REG,BitNo)              REG &= ~(1<<BitNo)
#define ASS_BIT(REG,BitNo,VAL)          (VAL==0)? CLR_BIT(REG,BitNo) : SET_BIT(REG,BitNo)
#define TOG_BIT(REG,BitNo)              REG ^= (1<<BitNo)
#define GET_BIT(REG,BitNo)              ((REG>>BitNo) & 0x01)

#define SET_NIBBLE(REG,NibbleHalf)      (NibbleHalf == LOW)? (REG |= 00001111) : (REG |= 11110000)
#define CLR_NIBBLE(REG,NibbleHalf)      (NibbleHalf == LOW)? (REG &= 11110000) : (REG &= 00001111)
#define ASS_NIBBLE(REG,NibbleHalf,VAL)  (VAL == 0)? (CLR_NIBBLE(REG,NibbleHalf)) : (SET_NIBBLE(REG,NibbleHalf))

#endif