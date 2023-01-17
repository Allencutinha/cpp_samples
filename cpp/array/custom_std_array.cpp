#include <cstdint>
#include<iostream>

template <typename Contained, std::size_t Size>
struct array {
    Contained _elements[Size];

    constexpr Contained& operator[](std::size_t idx) { return _elements[idx]; }
    constexpr const Contained& operator[](std::size_t idx) const { return _elements[idx]; }

    constexpr Contained* begin() { return _elements; }
    constexpr const Contained* begin() const { return _elements; }
    constexpr const Contained* cbegin() const { return _elements; }

    constexpr Contained* end() { return _elements + Size; }
    constexpr const Contained* end() const { return _elements + Size; }
    constexpr const Contained* ccend() const { return _elements + Size; }

    constexpr const Contained& front() const{return *_elements;}
    constexpr Contained& front(){return *_elements;}
};

int main(int argc, char** argv)
{
    array <int, 5> data{1,2,3,4,5};
    for(auto val: data){
        std::cout<<val<<std::endl;
    }
}