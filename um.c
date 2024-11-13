/* PROTOTYPE */
#include <stdint.h>
#include <bitpack.h>

typedef uint32_t word;

typedef enum Um_opcode {
        CMOV = 0, SLOAD, SSTORE, ADD, MUL, DIV,
        NAND, HALT, ACTIVATE, INACTIVATE, OUT, IN, LOADP, LV
} Um_opcode;

#define OP_COUNT 13

int program_loaded = 0;

void segmented_load(Um_instruction instr)
{

}

void segmented_store(Um_instruction instr)
{

}

void add(Um_instruction instr)
{

}

void multiply(Um_instruction instr)
{

}

void divide(Um_instruction instr)
{

}

void nand(Um_instruction instr)
{

}

void halt()
{

}

void activate(Um_instruction instr)
{

}

void inactivate(Um_instruction instr)
{

}

void out(Um_instruction instr)
{

}

void in(Um_instruction instr)
{

}

void load_program(Um_instruction instr)
{

}

void load_value(Um_instruction instr)
{

}

void (*operations[OP_COUNT + 1])(void) = {
        NULL,
        segmented_load,
        segmented_store,
        add,
        multiply,
        divide,
        nand,
        halt,
        activate,
        inactivate,
        out,
        in,
        load_program,
        load_value
};

typedef struct Um_instruction {
        Um_opcode opcode;
        int ra;
        int rb;
        int rc;
        unsigned val;
} Um_instruction;

Um_instruction unpack_instruction(Um_instruction word)
{
        Um_instruction instr;
        instr.opcode = Bitpack_getu(word, 4, 28);
        if (instr.opcode == LV) {
                instr.ra = Bitpack_getu(word, 3, 25);
                instr.val = Bitpack_getu(word, 25, 0);
                instr.rb = 0;
                instr.rc = 0;
        } else {
                instr.ra = Bitpack_getu(word, 3, 6);
                instr.rb = Bitpack_getu(word, 3, 3);
                instr.rc = Bitpack_getu(word, 3, 0);
                instr.val = 0;
        }
        return instr;
}

void control_flow() {
        int running = 1;
        int program_counter = 0;
        while (running) {

                /* DUMMY CODE */
                if (!program_loaded) {
                        Sequence_T seg0 = Sequence_get(segments, 0);
                        word instruction = Sequeunce_get(seg0, program_counter);
                } else {
                        uint32_t *seg0[] = Sequence_get(segments, 0);
                        word instruction = seg0[program_counter];
                }

                Um_instruction instr = unpack_instruction(0);
                void *operation = operations[instr.opcode];
                operation(instr);
        }
}