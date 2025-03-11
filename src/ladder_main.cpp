#include "ladder.h"
#include <cassert>
#include <ostream>

void test()
{
    assert(is_adjacent("cat", "cot"));
    assert(is_adjacent("cat", "rat"));

    assert(is_adjacent("cat", "ca"));
    assert(is_adjacent("cat", "ct"));

    assert(is_adjacent("cat", "chat"));
    assert(is_adjacent("cat", "crat"));

    assert(!is_adjacent("cat", "blat"));
    assert(!is_adjacent("cat", "matt"));
    
    assert(is_adjacent("cat", "cat"));


    assert(!is_adjacent("cat", "Al"));
    assert(!is_adjacent("cat", "dog"));

    assert(!is_adjacent("sleep", "leek"));
    assert(is_adjacent("sleep", "leep"));

    cout << "made it past adjacent tests" << endl;
    verify_word_ladder();
}

int main()
{
    test();
    return 0;
}