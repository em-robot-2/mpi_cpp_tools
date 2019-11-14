/**
 * @file infix_iterator.h
 * originally from Jerry Coffin et al, copied directly from
 https://codereview.stackexchange.com/questions/13176/infix-iterator-code
 * @license CC BY-SA 4.0 license https://creativecommons.org/licenses/by-sa/4.0/
 */

#if !defined(INFIX_ITERATOR_H_)
#define  INFIX_ITERATOR_H_
#include <ostream>
#include <iterator>
#include <string>

/**
* @brief To print delimiters between elements.
*
* Use the infix_iterator to write successive objects of a type with the
* delimiter *between* each of them. By contrast, the std::ostream_iterator
* writes the delimiter *after* every successive object.
*/

template <class T, class charT=char, class traits=std::char_traits<charT> >
class infix_ostream_iterator :
    public std::iterator<std::output_iterator_tag, void, void, void, void>
{
    std::basic_ostream<charT,traits> *os;
    std::basic_string<charT> delimiter;
    std::basic_string<charT> real_delim;

public:

    typedef charT char_type;
    typedef traits traits_type;
    typedef std::basic_ostream<charT, traits> ostream_type;

    infix_ostream_iterator(ostream_type &s)
        : os(&s)
    {}

    infix_ostream_iterator(ostream_type &s, charT const *d)
        : os(&s),
          real_delim(d)
    {}

    infix_ostream_iterator<T, charT, traits> &operator=(T const &item)
    {
        *os << delimiter << item;
        delimiter = real_delim;
        return *this;
    }

    infix_ostream_iterator<T, charT, traits> &operator*() {
        return *this;
    }

    infix_ostream_iterator<T, charT, traits> &operator++() {
        return *this;
    }

    infix_ostream_iterator<T, charT, traits> &operator++(int) {
        return *this;
    }
};

#endif 
