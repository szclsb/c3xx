#include <c3xx/CyclicBarrier.h>

using namespace std;
namespace c = szclsb::c3xx;

c::CyclicBarrier::CyclicBarrier(size_t parties): m_parties(parties), m_waiting(0) {

}

void c::CyclicBarrier::await() {
    unique_lock<mutex> lock(m_mutex);
    if (m_waiting < m_parties - 1) {
        m_waiting++;
        m_cond.wait(lock);
    } else {
        m_waiting = 0;
        m_cond.notify_all();
    }
}

size_t c::CyclicBarrier::parties() const {
    return m_parties;
}

size_t c::CyclicBarrier::waiting() {
    lock_guard<mutex> lock(m_mutex);
    return m_waiting;
}
