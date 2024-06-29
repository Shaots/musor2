
#include "Singleton.h"


Singleton* Singleton::m_Singleton = nullptr;


Singleton* Singleton::getInstance(const std::string& value) {
    if (m_Singleton == nullptr) {
        m_Singleton = new Singleton(value);
    }
    return m_Singleton;
}

void Singleton::releaseInstance() {
    if (m_Singleton != nullptr)
        delete m_Singleton;
}

/*Singleton& Singleton::operator=(Singleton&& other) {

}*/

Singleton2& Singleton2::getInstance(const std::string& value) {
    static Singleton2 singleton2(value);
    return singleton2;
}
