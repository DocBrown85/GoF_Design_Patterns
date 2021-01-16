#include <cstring>
#include <iostream>
#include <memory>
#include <unordered_map>

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

        /**
         * The Flyweight Factory creates and manages the Flyweight objects. It ensures
         * that flyweights are shared correctly. When the client requests a flyweight,
         * the factory either returns an existing instance or creates a new one, if it
         * doesn't exist yet.
         */
        class FlyweightFactory
        {
        public:
            FlyweightFactory(std::initializer_list<IntrinsicState> intrinsic_states)
            {
                for (const IntrinsicState &is : intrinsic_states)
                {
                    const std::shared_ptr<IntrinsicState> intrinsic_state = std::make_shared<IntrinsicState>(is);
                    this->_flyweights.insert(
                        std::make_pair<std::string, std::shared_ptr<Flyweight>>(
                            this->get_key(is), std::make_shared<Flyweight>(intrinsic_state)));
                }
            }

            /**
             * Returns an existing Flyweight with a given state or creates a new one.
             */

        private:
            std::unordered_map<std::string, std::shared_ptr<Flyweight>> _flyweights;

            std::string get_key(const std::shared_ptr<IntrinsicState> &intrinsic_state) const
            {
                return get_key(intrinsic_state->_attribute_a, intrinsic_state->_attribute_b, intrinsic_state->_attribute_c);
            }

            std::string get_key(const IntrinsicState &intrinsic_state) const
            {
                return get_key(intrinsic_state._attribute_a, intrinsic_state._attribute_b, intrinsic_state._attribute_c);
            }

            std::string get_key(const std::string a, const std::string b, const std::string c) const
            {
                return a + "_" + b + "_" + c;
            }
        };

    } // namespace flyweight

} // namespace structural

int main()
{
    return 0;
}