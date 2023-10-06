#include <cstdint>

namespace ft
{
	// This is useful to hide signatures on compile time when a particular condition is not met, since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.
	template<bool Condition, typename T = void>
	struct enable_if { }; // enable_if::type is not defined

	template<typename T>
	struct enable_if<true, T> { typedef T type; }; // The type T is enabled as member type enable_if::type if Condition is true.
	// Otherwise, enable_if::type is not defined.


	//The is_integral type trait is often used as a metafunction, which means it is used to determine the type or value of a template argument at compile time. For example, you might use std::is_integral to enable or disable a function template based on the type of its template argument
	// is_integral  a template with a value member that is set to true for integral types and false for non-integral types. The value member can be accessed using the ::value notation
	// default template function
	template<typename T> struct is_integral { static const bool value = false; };

	// specialziations
	template<> struct is_integral<bool> { static const bool value = true; };
	template<> struct is_integral<char> { static const bool value = true; };
	template<> struct is_integral<char16_t> { static const bool value = true; };
	template<> struct is_integral<wchar_t> { static const bool value = true; };
	 template<> struct is_integral<char32_t> { static const bool value = true; };
	template<> struct is_integral<signed char> { static const bool value = true; };
	template<> struct is_integral<short int> { static const bool value = true; };
	template<> struct is_integral<int> { static const bool value = true; };
	template<> struct is_integral<long int> { static const bool value = true; };
	template<> struct is_integral<long long int> { static const bool value = true; };
	template<> struct is_integral<unsigned char> { static const bool value = true; };
	template<> struct is_integral<unsigned short int> { static const bool value = true; };
	template<> struct is_integral<unsigned int> { static const bool value = true; };
	template<> struct is_integral<unsigned long int> { static const bool value = true; };
	template<> struct is_integral<unsigned long long int> { static const bool value = true; };


} // namespace ft

