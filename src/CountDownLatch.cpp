#include <c3xx/CountDownLatch.h>

using namespace std;
namespace c = szclsb::c3xx;

c::CountDownLatch::CountDownLatch(size_t count): m_count(count) {

}

void c::CountDownLatch::await() {
    unique_lock<mutex> lock(m_mutex);
    if (m_count > 0) {
        m_cond.wait(lock);
    }
}

void c::CountDownLatch::count_down() {
    unique_lock<mutex> lock(m_mutex);
    if (m_count > 1) {
        m_count--;
    } else if (m_count > 0) {
        m_count--;
        m_cond.notify_all();
    }
}

size_t c::CountDownLatch::count() {
    lock_guard<mutex> lock(m_mutex);
    return m_count;
}