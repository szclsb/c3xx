#pragma once

#include <mutex>
#include <condition_variable>
#include <memory>

namespace szclsb::c3xx {
    template<typename T>
    class Exchanger {
    private:
        std::shared_ptr<T> m_data;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        Exchanger() = default;

        std::shared_ptr<T> exchange(std::shared_ptr<T> data);
    };
}

using namespace std;

template<typename T>
inline shared_ptr<T> szclsb::c3xx::Exchanger<T>::exchange(shared_ptr<T> data) {
    unique_lock<mutex> lock(m_mutex);
    if (m_data == nullptr) {
        m_data = data;
        m_cond.wait(lock);
        auto result = m_data;
        m_data = nullptr;
        return result;
    } else {
        auto result = m_data;
        m_data = data;
        m_cond.notify_one();
        return result;
    }
}