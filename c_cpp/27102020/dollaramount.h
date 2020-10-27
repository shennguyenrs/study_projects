#include <cmath>
#include <cstdint>
#include <string>
using namespace std;

class DollarAmount
{
    private:
        int64_t amount{0};

    public:
        // Initialize amount from an int64_t value
        explicit DollarAmount(int64_t value) : amount{value} {}

        // Add right's amount to this object's amount
        void add(DollarAmount right)
        {
            amount += right.amount;
        }

        // Subtract right's amount to this object's amount
        void subtract(DollarAmount right)
        {
            amount -= right.amount;
        }

        // Calculate interest amount
        // then add with the interest amount
        void AddInterest(int rate, int divisor)
        {
            DollarAmount interest{
                (amount*rate+divisor/2)/divisor
            };

            add(interest);
        }

        string ToString() const
        {
            string dollars{to_string(amount/100)};
            string cents{to_string(abs(amount%100))};
            return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
        }
};
