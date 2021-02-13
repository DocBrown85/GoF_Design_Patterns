#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace interpreter
    {
        class Context
        {
        public:
            Context() {}
            ~Context() {}

        protected:
        private:
        };

        class AbstractExpression
        {
        public:
            virtual ~AbstractExpression() {}
            virtual void Interpret(const std::unique_ptr<Context> &c) = 0;

        protected:
            AbstractExpression() {}

        private:
        };

        class TerminalExpression : public AbstractExpression
        {
        public:
            TerminalExpression(const std::string &statement)
            {
                _statement = statement;
            }
            void Interpret(const std::unique_ptr<Context> &c) override
            {
                std::cout << this->_statement << "TerminalExpression" << std::endl;
            }

        protected:
        private:
            std::string _statement;
        };

        class NonterminalExpression : public AbstractExpression
        {
        public:
            NonterminalExpression(std::unique_ptr<AbstractExpression> expression, int times)
                : _expression(std::move(expression)), _times(times)
            {
            }

            void Interpret(const std::unique_ptr<Context> &c) override
            {
                for (int i = 0; i < _times; i++)
                {
                    this->_expression->Interpret(c);
                }
            }

        protected:
        private:
            std::unique_ptr<AbstractExpression> _expression = nullptr;
            int _times;
        };

        class Client
        {
        public:
            void execute()
            {
                std::unique_ptr<Context> context = std::make_unique<Context>();
                std::unique_ptr<AbstractExpression> terminal_expression = std::make_unique<TerminalExpression>("Hello");
                std::unique_ptr<AbstractExpression> non_terminal_expression = std::make_unique<NonterminalExpression>(std::move(terminal_expression), 2);
                non_terminal_expression->Interpret(context);
            }
        };

    } // namespace interpreter

} // namespace behavioral

int main()
{
    behavioral::interpreter::Client client;
    client.execute();
    return 0;
}