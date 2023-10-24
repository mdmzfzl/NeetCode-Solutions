/*
Problem: LeetCode 271 - Encode and Decode Strings

Description:
Design an algorithm to encode a list of strings to a string and decode the string to the original list of strings. The encoded string should be as compact as possible.

Intuition:
To encode and decode a list of strings, we need a way to separate individual strings and handle any special characters. One approach is to use a delimiter to separate the strings, and escape any occurrences of the delimiter within the strings.

Approach:
Encoding:
1. Iterate through the input list of strings:
   - For each string, append its length followed by a delimiter (e.g., '#') to the encoded string.
   - Append the actual string content to the encoded string.
2. Return the encoded string.

Decoding:
1. Initialize an empty result list of strings.
2. While the encoded string is not empty:
   - Extract the length of the next string from the encoded string until the delimiter.
   - Convert the length string to an integer.
   - Extract the next substring of length characters from the encoded string.
   - Append the substring to the result list.
3. Return the result list.

Time Complexity:
The time complexity for encoding is O(n), where n is the total number of characters in all the strings. For decoding, the time complexity is also O(n), as we need to iterate through the encoded string to extract and reconstruct the original strings.

Space Complexity:
The space complexity is O(n), where n is the total number of characters in all the strings. This is because we need to store the encoded string, which contains all the characters from the input strings.
*/

class Codec {
  public:
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string encodedStr;

        for (const string &str : strs) {
            encodedStr += to_string(str.length()) + "#" + str;
        }

        return encodedStr;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decodedStrs;
        int i = 0;

        while (i < s.length()) {
            int delimiterIndex = s.find("#", i);
            int strLength = stoi(s.substr(i, delimiterIndex - i));
            decodedStrs.push_back(s.substr(delimiterIndex + 1, strLength));
            i = delimiterIndex + strLength + 2;
        }

        return decodedStrs;
    }
};
