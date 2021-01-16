#include <cstring>
#include <iostream>
#include <memory>

namespace structural
{
    namespace flyweight
    {
        struct IntrinsicState
        {
            IntrinsicState(const std::string &attribute_a, const std::string &attribute_b, const std::string &attribute_c)
                : _attribute_a(attribute_a),
                  _attribute_b(attribute_b),
                  _attribute_c(attribute_c)
            {
            }

            friend std::ostream &operator<<(std::ostream &os, const IntrinsicState &is)
            {
                return os << "[ " << is._attribute_a << " , " << is._attribute_b << " , " << is._attribute_c << " ]";
            }

            std::string _attribute_a;
            std::string _attribute_b;
            std::string _attribute_c;
        };

        struct ExtrinsicState
        {
            ExtrinsicState(const std::string &attribute_a, const std::string &attribute_b)
                : _attribute_a(attribute_a),
                  _attribute_b(attribute_b)
            {
            }

            friend std::ostream &operator<<(std::ostream &os, const ExtrinsicState &es)
            {
                return os << "[ " << es._attribute_a << " , " << es._attribute_b << " ]";
            }

            std::string _attribute_a;
            std::string _attribute_b;
        };

        /**
         * The Flyweight stores a common portion of the state (also called intrinsic
         * state) that belongs to multiple real business entities. The Flyweight accepts
         * the rest of the state (extrinsic state, unique for each entity) via its
         * method parameters.
         */
        class Flyweight
        {
        public:
            Flyweight(const std::shared_ptr<IntrinsicState> &is) : _intrinsic_state(is)
            {
            }

            Flyweight(const Flyweight &other) : _intrinsic_state(other.intrinsic_state())
            {
            }

            std::shared_ptr<IntrinsicState> intrinsic_state() const
            {
                return _intrinsic_state;
            }

            void operation(const ExtrinsicState &extrinsic_state)
            {
                std::cout << "Flyweight: IntrinsicState(" << *_intrinsic_state << ") and ExtrinsicState(" << extrinsic_state << ")\n";
            }

        private:
            std::shared_ptr<IntrinsicState> _intrinsic_state;
        };

    } // namespace flyweight

} // namespace structural

int main()
{
    return 0;
}