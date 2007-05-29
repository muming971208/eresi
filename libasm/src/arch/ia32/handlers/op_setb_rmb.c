/**
 * @file op_setb_rmb.c
 * $Id: op_setb_rmb.c,v 1.4 2007-05-29 00:40:28 heroine Exp $
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setb, opcode 0x0f 0x92
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setb_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_U_LESS;
  new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
  new->len += asm_operand_fetch(&new->op1, opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#else
  new->op1.type = ASM_OTYPE_ENCODED;
  operand_rmb(&new->op1, opcode + 1, len - 1, proc);
  new->len += new->op1.len;
#endif
  return (new->len);
}
