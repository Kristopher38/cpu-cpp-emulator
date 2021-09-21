#ifndef REG_FILE_H
#define REG_FILE_H

#include <array>
#include "block.h"
#include "port.h"

namespace riscie
{
	class RegisterFile : public Block
	{
	private:
		InputPort readReg1;
        InputPort readReg2;
        InputPort writeReg;
        InputPort store;
        InputPort load;

        OutputPort dataReg1;
        OutputPort dataReg2;

		std::array<uint32_t, 32> regs;
	public:
        RegisterFile() : regs({0}), readReg1(this), readReg2(this), writeReg(this), store(this), load(this), dataReg1(this), dataReg2(this) {}

		virtual void clockUp();
		virtual void clockDown();

		void write();
		void read();
	};
}


#endif // REG_FILE_H
