#include <cstring>
#include <iostream>
#include <memory>

namespace structural
{
    namespace flyweight
    {
        struct IntrinsicState
        {
            std::string _attribute_a;
            std::string _attribute_b;
            std::string _attribute_c;

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
        };

        struct ExtrinsicState
        {
            std::string _attribute_a;
            std::string _attribute_b;

            ExtrinsicState(const std::string &attribute_a, const std::string &attribute_b)
                : _attribute_a(attribute_a),
                  _attribute_b(attribute_b)
            {
            }

            friend std::ostream &operator<<(std::ostream &os, const ExtrinsicState &es)
            {
                return os << "[ " << es._attribute_a << " , " << es._attribute_b << " ]";
            }
        };

    } // namespace flyweight

} // namespace structural

int main()
{
    return 0;
}