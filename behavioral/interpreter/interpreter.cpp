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

    } // namespace interpreter

} // namespace behavioral

int main()
{
    std::unique_ptr<behavioral::interpreter::Context> c = std::make_unique<behavioral::interpreter::Context>();
    std::unique_ptr<behavioral::interpreter::AbstractExpression> te = std::make_unique<behavioral::interpreter::TerminalExpression>("Hello");
    std::unique_ptr<behavioral::interpreter::AbstractExpression> nte = std::make_unique<behavioral::interpreter::NonterminalExpression>(std::move(te), 2);
    nte->Interpret(c);
    return 0;
}