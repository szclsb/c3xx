#pragma once

#include <mutex>
#include <condition_variable>

namespace szclsb::c3xx {
    class CyclicBarrier {
    private:
        size_t m_parties;
        size_t m_waiting;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        explicit CyclicBarrier(size_t parties);
        void await();
        size_t parties() const;
        size_t waiting();
    };
}