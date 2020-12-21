#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

namespace creational
{
    namespace singleton
    {
        class Singleton
        {
        public:
            Singleton(Singleton &other) = delete;
            void operator=(const Singleton &other) = delete;

            static std::shared_ptr<Singleton> instance();

            void operation()
            {
                std::cout << "executing some business logic\n";
            }

            std::string value() const
            {
                return _value;
            }

        protected:
            Singleton(const std::string value) : _value(value){};

        private:
            static std::shared_ptr<Singleton> _singleton;
            std::string _value;
        };

        std::shared_ptr<Singleton> Singleton::_singleton = nullptr;

        std::shared_ptr<Singleton> Singleton::instance()
        {
            if (_singleton == nullptr)
            {
                _singleton = std::shared_ptr<Singleton>{new Singleton("SINGLETON")};
            }
            return _singleton;
        }

        class Client
        {
        public:
            void execute()
            {
                // This call will create an instance of Singleton
                std::shared_ptr<Singleton> singleton1 = Singleton::instance();

                // This call will not create a new instance, rather will return the one
                // created earlier
                std::shared_ptr<Singleton> singleton2 = Singleton::instance();

                std::cout << "We got the same instance:"
                          << "\n";
                std::cout << "singleton1 raw address is: " << (void *)singleton1.get() << "\n";
                std::cout << "singleton2 raw address is: " << (void *)singleton2.get() << "\n";
            }
        };

    } // namespace singleton

} // namespace creational

int main()
{
    creational::singleton::Client client;
    client.execute();
    return 0;
}