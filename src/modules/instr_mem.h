#ifndef INSTR_MEM_H
#define INSTR_MEM_H

#include <string>
#include "memory.h"

namespace riscie
{
	class InstrMem : public Memory
	{
	private:

	public:
        InstrMem(uint32_t size) : Memory(size) {}
        InstrMem(uint32_t size, const std::string& filename) : Memory(size, filename) {}

        virtual void clockUp();

        virtual inline bool isReadable();
        virtual inline bool isWriteable();
	};
}

#endif // INSTR_MEM_H
