#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace command
    {
        class Command
        {
        public:
            virtual ~Command() {}
            virtual void execute() const = 0;
        };

        /**
         * The Receiver classes contain important business logic.
         */
        class Receiver
        {
        public:
            void method_a(const std::string &a)
            {
                std::cout << "Receiver: working on (" << a << ".)\n";
            }
            void method_b(const std::string &b)
            {
                std::cout << "Receiver: working on (" << b << ".)\n";
            }
        };

        /*
         * Simple commands can carry out work on their own
         */
        class SimpleCommand : public Command
        {
        public:
            explicit SimpleCommand(std::string payload) : _payload(payload)
            {
            }

            void execute() const override
            {
                std::cout << "SimpleCommand: printing (" << this->_payload << ")\n";
            }

        private:
            std::string _payload;
        };

        /*
         * Complex commands can delegate work to other classes
         */
        class ComplexCommand : public Command
        {
        public:
            ComplexCommand(std::unique_ptr<Receiver> receiver, std::string arg0, std::string arg1)
                : _receiver(std::move(receiver)),
                  _arg0(arg0),
                  _arg1(arg1) {}

            void execute() const override
            {
                _receiver->method_a(_arg0);
                _receiver->method_b(_arg1);
            }

        private:
            std::unique_ptr<Receiver> _receiver;
            std::string _arg0;
            std::string _arg1;
        };

        class Invoker
        {
        public:
            void set_on_start(std::unique_ptr<Command> on_start)
            {
                _on_start = std::move(on_start);
            }

            void set_on_complete(std::unique_ptr<Command> on_complete)
            {
                _on_complete = std::move(on_complete);
            }

            void do_something()
            {
                if (_on_start)
                {
                    std::cout << "Invoker: execuing on_start command\n";
                    _on_start->execute();
                }

                std::cout << "Invoker: executing business logic\n";

                if (_on_complete)
                {
                    std::cout << "Invoker: execuing on_complete command\n";
                    _on_complete->execute();
                }
            }

        private:
            std::unique_ptr<Command> _on_start = nullptr;
            std::unique_ptr<Command> _on_complete = nullptr;
        };

    } // namespace command

} // namespace behavioral

int main()
{
    behavioral::command::Invoker invoker;

    std::unique_ptr<behavioral::command::Command> simple_command = std::make_unique<behavioral::command::SimpleCommand>("nice startup message");
    invoker.set_on_start(std::move(simple_command));

    std::unique_ptr<behavioral::command::Receiver> receiver = std::make_unique<behavioral::command::Receiver>();
    std::unique_ptr<behavioral::command::Command> complex_command = std::make_unique<behavioral::command::ComplexCommand>(std::move(receiver), "send notification", "computing statistics");
    invoker.set_on_complete(std::move(complex_command));

    invoker.do_something();
    return 0;
}