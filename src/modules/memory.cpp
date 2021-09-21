#include "memory.h"

namespace fs = std::filesystem;

namespace riscie
{
    Memory::Memory(uint32_t size) : addr(this), dataOut(this), data(size, 0) // fill with zeros on init
	{}

    Memory::Memory(uint32_t size, const std::string& filename) : Memory(size)
	{
		fs::path filepath(filename);
		if (fs::exists(filepath) &&
			fs::is_regular_file(filepath))
		{
			std::ifstream f(filepath);

			for (uint32_t idx = 0; idx < this->data.size(); idx += 4)
			{
				uint32_t val;
				f>>std::hex>>val;

				this->data[idx] = val & 0xff;
				this->data[idx+1] = (val & 0xff00) >> 8;
				this->data[idx+1] = (val & 0xff0000) >> 8;
				this->data[idx+1] = (val & 0xff000000) >> 8;
            }
			f.close();
        }
	}

	Memory::~Memory() {}

    void Memory::clockUp()
    {
        uint32_t addr = this->addr.getValue();
        if (addr < this->data.size())
            this->dataOut.setValue(this->data[addr]);
    }

    bool Memory::isReadable()
    {
        return true;
    }

    bool Memory::isWriteable()
    {
        return true;
    }
}

