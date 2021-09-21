#ifndef INSTRUCTION_H
#define INSTRUCTION_H

union RVInstr
{
    uint32_t u32;
    struct
    {
        unsigned opcode : 7;
        unsigned rd : 5;
        unsigned funct3 : 3;
        unsigned rs1 : 5;
        unsigned rs2 : 5;
        unsigned funct7 : 7;
    };
    struct
    {
        unsigned : 20;
        unsigned imm12 : 12;
    };
    struct
    {
        unsigned : 7;
        unsigned imm5 : 5;
        unsigned : 13;
        unsigned imm7 : 7;
    };
    struct
    {
        unsigned : 12;
        unsigned imm20 : 20;
    };
};

#endif // INSTRUCTION_H
