#include <cstring>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

namespace behavioral
{
    namespace strategy
    {
        class Client
        {
        public:
            void execute()
            {
            }
        };

    } // namespace strategy

} // namespace behavioral

int main()
{
    behavioral::strategy::Client client;

    client.execute();
    return 0;
}