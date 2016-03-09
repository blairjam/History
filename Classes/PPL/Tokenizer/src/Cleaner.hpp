#ifndef CLEANER_HPP
#define CLEANER_HPP

#include <vector>

typedef std::vector<char> vchar;

class Cleaner
{
    public:
        Cleaner(vchar _list) : list(_list){}
        ~Cleaner(){}
        void remove_comments();
        vchar get_list() const {return list;}

    private:
        vchar list;
        
        int remove_single_line(int current_char);
        int remove_multi_line(int current_char);
        void replace_comment(int trim_start, int trim_end);
};

#endif
