#ifndef BLOCK_H
#define BLOCK_H

namespace riscie
{
	class Block
	{
    private:
        bool shouldAsyncUpdate;
	public:
        Block() : shouldAsyncUpdate(false) {}
		virtual ~Block() {}

        virtual void asyncUpdate()
        {
            this->shouldAsyncUpdate = false;
        }
        virtual void clockUp() {}
        virtual void clockDown() {}

        void markAsyncUpdate()
        {
            this->shouldAsyncUpdate = true;
        }
    };
}

#endif // BLOCK_H
