#include <iostream>
#include "modules/instr_mem.h"
#include "modules/reg_file.h"

using namespace std;

int main()
{
    riscie::InstrMem instrMem(1 << 18);
    riscie::RegisterFile regFile;


    return 0;
}
