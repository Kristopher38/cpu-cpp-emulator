#ifndef MEMORY_H
#define MEMORY_H

#include <memory>
#include <filesystem>
#include <fstream>
#include "block.h"
#include "port.h"

namespace riscie
{
	class Memory : public Block
	{
    protected:
        InputPort addr;
        OutputPort dataOut;
		std::vector<uint8_t> data;
	public:
        Memory(uint32_t size);
        Memory(uint32_t size, const std::string& filename);
		virtual ~Memory();

        virtual void clockUp();

        virtual inline bool isReadable();
        virtual inline bool isWriteable();
	};
}

#endif // MEMORY_H
