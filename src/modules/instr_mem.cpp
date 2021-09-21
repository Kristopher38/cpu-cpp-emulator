#include "instr_mem.h"

namespace riscie
{
    void InstrMem::clockUp()
    {
        uint32_t addr = this->addr.getValue();
        if (addr+3 < this->data.size())
        {
            uint32_t instr = this->data[addr] << 24 |
                             this->data[addr+1] << 16 |
                             this->data[addr+2] << 8 |
                             this->data[addr+3];
            this->dataOut.setValue(instr);
        }
    }

    bool InstrMem::isReadable()
    {
        return true;
    }

    bool InstrMem::isWriteable()
    {
        return false;
    }
}
