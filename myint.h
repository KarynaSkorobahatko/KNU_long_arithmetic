#ifndef MYINT
#define MYINT

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

namespace apa
{
    using namespace std;

    template <typename T>
    class ComparisonOperators
    {
        friend bool operator==(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) == 0;
        }

        friend bool operator!=(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) != 0;
        }

        friend bool operator<(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) < 0;
        }

        friend bool operator>(T const& lhs, T const& rhs)
        {
            return rhs.compare(lhs) < 0;
        }

        friend bool operator<=(T const& lhs, T const& rhs)
        {
            bool result = lhs.compare(rhs) <= 0;
            return result;
        }

        friend bool operator>=(T const& lhs, T const& rhs)
        {
            return rhs.compare(lhs) <= 0;
        }
    };

    class myint : ComparisonOperators<myint>
    {
    public:
        explicit myint(std::string number);

        myint();

        myint(long long number);

        myint(int number);

        myint(double number);

        myint(vector<int> nums, bool is_neg);

        myint(const myint &obj);

        int get_length() const;

        bool is_negative_number() const;

        myint& operator+=(const myint& b);

        myint& operator-=(const myint& b);

        myint& operator*=(const myint& number2);

        myint& operator/=(const myint& b);

        explicit operator bool() const;

        explicit operator int();

        myint operator+() const;

        myint operator-() const;

        int operator[](size_t index) const;

        myint& operator=(const myint& other);

        myint& operator++();

        myint operator++(int);

        myint& operator--();

        myint operator--(int);

        bool cmp(myint const& rhs) const;

        int compare(myint const& rhs) const;

        bool is_zero() const;

        std::string to_string();

    private:
        bool is_negative;
        vector<int> numbers;

        myint abs(myint number) const;

        vector<int> reverse_numbers(vector<int> const& numbers) const;

        void make_equal_length(const myint& b, vector<int> & number1, vector<int> & number2) const;

        void string_to_vector(std::string const& number);

        void integer_to_vector(long long a);
    };

    myint abs(myint number);

    myint pow(myint a, myint b);

    myint sqrt(myint a);
    myint powmod(myint a, myint b, myint c);

    std::ostream& operator<<(std::ostream& os, const myint& obj);

    std::istream& operator>>(std::istream& is, myint& obj);

    myint operator+(const myint& lhs, const myint& rhs);

    myint operator-(const myint& lhs, const myint& rhs);

    myint operator*(const myint& lhs, const myint& rhs);

    myint operator/(const myint& lhs, const myint& rhs);

    myint operator%(const myint& lhs, const myint& rhs);
}

#endif /* MYINT */