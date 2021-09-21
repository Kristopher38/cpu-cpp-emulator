#ifndef PORT_H
#define PORT_H

#include <string>
#include <vector>
#include <unordered_set>
#include <memory>
#include "block.h"

namespace riscie
{
    class IPort
    {
    private:
        std::unordered_set<IPort*> connections;
        Block* const owner;
        uint8_t bitWidth;
        uint64_t data;
    public:
        IPort(Block* const owner, uint8_t bitWidth = 64, uint64_t data = 0) : owner(owner), bitWidth(bitWidth), data(data) {}
        virtual inline bool isInput() = 0;
        virtual inline bool isOutput() = 0;

        virtual void connect(IPort* port);
        virtual void disconnect(IPort* port);
        virtual bool canConnect(IPort* port);
        virtual uint64_t getValue();
        virtual void setValue(uint64_t data);
        virtual void propagate();
        virtual ~IPort();
    };

    class InputPort : public IPort
    {
    public:
        InputPort(Block* const owner) : IPort(owner) {}
        virtual inline bool isInput() { return true; }
        virtual inline bool isOutput() { return false; }
    };

    class OutputPort : public IPort
    {
    public:
        OutputPort(Block* const owner) : IPort(owner) {}
        virtual inline bool isInput() { return false; }
        virtual inline bool isOutput() { return true; }
    };

}

#endif // PORT_H
