/*
** $Id: op_pushf.c,v 1.1 2007-01-26 14:18:38 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction name="pushf" func="op_pushf" opcode="0x9c"/>
*/


int op_pushf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
    new->len += 1;
  new->ptr_instr = opcode;
    new->instr = ASM_PUSHF;
    // new->type = IS_MEM_WRITE;
  return (new->len);
}