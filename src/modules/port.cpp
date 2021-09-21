#include "port.h"

namespace riscie
{
    void IPort::connect(IPort* port)
    {
        port->connections.insert(this);
        connections.insert(port);
    }
    void IPort::disconnect(IPort* port)
    {
        connections.erase(port);
        port->connections.erase(this);
    }
    bool IPort::canConnect(IPort* port = nullptr)
    {
        if (!port)
            return this->isOutput() ||
                   this->isInput() && this->connections.size() == 0;
        else
            return (this->isInput() && port->isOutput() ||
                    this->isOutput() && port->isInput()) &&
                   (this->isInput() && this->connections.size() == 0 ||
                    port->isInput() && port->connections.size() == 0);
    }
    uint64_t IPort::getValue()
    {
        return this->data;
    }
    void IPort::setValue(uint64_t data)
    {
        this->data = data;
        if (this->isOutput())
            this->propagate();
    }
    void IPort::propagate()
    {
        for (auto conn : this->connections)
        {
            if (conn->isInput())
            {
                conn->setValue(data);
                conn->owner->markAsyncUpdate();
            }
        }
    }
    IPort::~IPort()
    {
        for (auto conn = connections.begin(); conn != connections.end(); ++conn)
            (*conn)->connections.erase(this);
    }
}
