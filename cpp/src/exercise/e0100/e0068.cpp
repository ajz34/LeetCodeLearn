// https://leetcode-cn.com/problems/text-justification/

#include "extern.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto pw = words.begin();
        vector<string> result;
        while (pw != words.end()) {
            string line;
            vector<string> line_words; int curWidth = 0;
            while (pw != words.end() && pw->size() + curWidth <= maxWidth) {
                curWidth += pw->size() + 1;
                line_words.push_back(*(pw++));
            }
            if (line_words.size() == 1) {
                line = line_words[0];
                while (line.size() < maxWidth) line += ' ';
                result.push_back(line);
            }
            else if (pw == words.end()) {
                for (auto& w : line_words) line += w + ' ';
                if (line.size() > maxWidth) line.pop_back();
                else while (line.size() < maxWidth) line += ' ';
                result.push_back(line);
            }
            else {
                int space_count = maxWidth - curWidth + line_words.size();
                vector<int> space_line(line_words.size() - 1, space_count / (line_words.size() - 1));
                for (int i = 0; i < space_count - (line_words.size() - 1) * space_line.back(); ++i) space_line[i] += 1;
                for (int i = 0; i < line_words.size(); ++i) {
                    line += line_words[i];
                    if (i < line_words.size() - 1) line += string(space_line[i], ' ');
                }
                result.push_back(line);
            }
        }
        return result;
    }
};

TEST(e0100, e0068) {
    vector<string> words, ans;

    words = vector<string>{ "This", "is", "an", "example", "of", "text", "justification." };
    ans = vector<string>{
        "This    is    an",
        "example  of text",
        "justification.  "
    };
    ASSERT_THAT(Solution().fullJustify(words, 16), ans);

    words = vector<string>{ "What", "must", "be", "acknowledgment", "shall", "be" };
    ans = vector<string>{
        "What   must   be",
        "acknowledgment  ",
        "shall be        "
    };
    ASSERT_THAT(Solution().fullJustify(words, 16), ans);

    words = vector<string>{
        "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
        "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"
    };
    ans = vector<string>{
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  "
    };
    ASSERT_THAT(Solution().fullJustify(words, 20), ans);
}
