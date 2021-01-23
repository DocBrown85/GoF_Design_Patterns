#include <cstring>
#include <iostream>
#include <memory>

namespace structural
{
    namespace proxy
    {
        class Subject
        {
        public:
            virtual void operation() const = 0;
        };

        class RealSubject : public Subject
        {
        public:
            void operation() const override
            {
                std::cout << "RealSubject.operation()"
                          << "\n";
            }
        };

        class Proxy : public Subject
        {
        public:
            Proxy(std::unique_ptr<Subject> real_subject) : _real_subject(std::move(real_subject)) {}

            void operation() const override
            {
                if (!can_access())
                    return;

                log_access();

                _real_subject->operation();
            }

        private:
            bool can_access() const
            {
                std::cout << "Proxy.check_access()\n";
                return true;
            }

            void log_access() const
            {
                std::cout << "Proxy.log_access()\n";
            }

            std::unique_ptr<Subject> _real_subject;
        };

        class Client
        {
        public:
            void execute(const std::unique_ptr<Subject> &subject)
            {
                subject->operation();
            }
        };

    } // namespace proxy

} // namespace structural

int main()
{
    structural::proxy::Client client;

    std::cout << "Executing client code with a real subject:"
              << "\n";
    std::unique_ptr<structural::proxy::Subject> real_subject = std::make_unique<structural::proxy::RealSubject>();
    client.execute(real_subject);
    std::cout << "\n";

    std::cout << "Executing client code with a proxyed subject:"
              << "\n";
    std::unique_ptr<structural::proxy::Subject> proxyed_subject = std::make_unique<structural::proxy::Proxy>(std::move(real_subject));
    client.execute(proxyed_subject);
    std::cout << "\n";

    return 0;
}