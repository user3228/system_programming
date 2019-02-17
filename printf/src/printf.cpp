#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
 
using namespace std;
 
 
 
template<class T> string make_string(const T &t)
{
    stringstream ss;
    ss << t;
    return ss.str();
}
 
 
string format_str_impl(const string &fmt, const vector<std::string> &strs)
{
 
    static const char FORMAT_SYMBOL = '%';
 
    string res;
 
    int current_arg = 0;
 
    for (int i = 0; i <= static_cast<int>(fmt.size()); ++i)
    {
        char ch = fmt[i];
 
        if (ch == FORMAT_SYMBOL && current_arg < static_cast<int>(strs.size()))
        {
            res += strs[current_arg];
            ++current_arg;
        } else {
            res += ch;
        }
    }
 
    return res;
}
 
template<class Arg, class ... Args>
string format_str_impl(const string& fmt, vector<string>& strs, Arg&& arg, Args&& ... args)
{
    strs.push_back(make_string(forward<Arg>(arg)));              
    return format_str_impl(fmt, strs, forward<Args>(args) ...);
}
 
 
 
 
template<class Arg, class ... Args>
string format_str(const string& fmt, Arg&& arg, Args&& ... args)
{
    vector<string> strs;
    return format_str_impl(fmt, strs, forward<Arg>(arg), forward<Args>(args) ...);
}
 
string format_str(const string& fmt)
{
    return fmt;
}
 
 
template<class ... Args>
void message(ostream &out_stream, const string &tplt_str, Args&& ... args) {
 
    out_stream << format_str(tplt_str, forward<Args>(args) ...);
}
