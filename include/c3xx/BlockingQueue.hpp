#pragma once

#include <mutex>
#include <condition_variable>
#include <memory>

namespace szclsb::c3xx {
    template<typename T>
    class BlockingQueue {
    private:
        std::mutex m_mutex_put;
        std::mutex m_mutex_pull;
        std::condition_variable m_cond_put;
        std::condition_variable m_cond_pull;
        size_t m_length;
        std::shared_ptr<T> m_start;
        std::shared_ptr<T> m_put;
        std::shared_ptr<T> m_pull;
    public:
        explicit BlockingQueue(size_t length);
        size_t queue_length() const;
        size_t count();
        void put(std::shared_ptr<T> t);
        std::shared_ptr<T> pull();
    };
}

using namespace std;

template<typename T>
inline szclsb::c3xx::BlockingQueue<T>::BlockingQueue(size_t length): m_length(length) {

}

template<typename T>
inline size_t szclsb::c3xx::BlockingQueue<T>::queue_length() const {
    return m_length;
}

template<typename T>
inline size_t szclsb::c3xx::BlockingQueue<T>::count() {
    return 0;
}

template<typename T>
inline void szclsb::c3xx::BlockingQueue<T>::put(shared_ptr<T> t) {

}

template<typename T>
inline shared_ptr<T> szclsb::c3xx::BlockingQueue<T>::pull() {
    return nullptr;
}