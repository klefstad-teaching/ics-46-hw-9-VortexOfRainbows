#include <algorithm>
#include <endian.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg)
{
    cout << "Error: (" << word1 << ", " << word2 << ") " << msg;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d)
{
    
}
bool is_adjacent(const string& word1, const string& word2)
{
    int differencesCount = 0;
    int length1 = word1.size();
    int length2 = word2.size();

    if(abs(length1 - length2) > 1)
        return false;

    if(length1 == 0 || length2 == 0)
        return true;

    if(length1 != length2) //different word lengths
    {
        bool firstIsSmaller = true;
        int smaller = length1;
        if(length1 > length2)
        {
            smaller = length2;
            firstIsSmaller = false;
        }
        char char1 = word1[0];
        char char2 = word2[0];
        for(int i = 1; i < smaller; ++i)
        {
            if(char1 != char2)
            {
                ++differencesCount;
            }
            if(firstIsSmaller)
            {
                char1 = word1[i - differencesCount];
                char2 = word2[i];
            }
            else 
            {
                char1 = word1[i];
                char2 = word2[i - differencesCount];
            }
            if(differencesCount > 1)
                return false;
        }
    }
    else 
    {
        for(int i = 0; i < length1; ++i)
        {
            if(word1[i] != word2[i])
            {
                ++differencesCount;
            }
            if(differencesCount > 1)
                return false;
        }
    }
    return true;
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list)
{
    if(end_word == begin_word)
    {
        vector<string> ladder2{begin_word};
        return ladder2;
    }
    queue<vector<string>> ladder_queue{};
    ladder_queue.push({begin_word});
    set<string> visited{};
    visited.insert(begin_word);

    vector<string> ladder{};
    while (!ladder_queue.empty())
    {
        ladder = ladder_queue.front(); ladder_queue.pop();
        string last = ladder[ladder.size() - 1];

        for(auto word : word_list)
        {
            if(is_adjacent(last, begin_word))
            {
                if(visited.find(word) != visited.end())
                {
                    visited.insert(word);
                    ladder.push_back(word);
                    if(word == end_word)
                        return ladder;
                    ladder_queue.push(ladder);
                }
            }
        }
    }
    return ladder;
}
void load_words(set<string> & word_list, const string& file_name)
{
    word_list.clear();
    ifstream in(file_name);
    for(string word; (in >> word);)
        word_list.insert(word);
    in.close();
}
void print_word_ladder(const vector<string>& ladder)
{
    for(auto str : ladder)
        cout << str << ' ';
    cout << endl;
}
void verify_word_ladder()
{
    #define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
