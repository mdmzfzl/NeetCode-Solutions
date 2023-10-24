"""
Problem: LeetCode 271 - Encode and Decode Strings
"""


class Codec:
    def encode(self, strs: List[str]) -> str:
        encoded = ""
        for s in strs:
            encoded += str(len(s)) + "#" + s
        return encoded

    def decode(self, s: str) -> List[str]:
        decoded = []
        i = 0
        while i < len(s):
            delimiter_pos = s.find("#", i)
            size = int(s[i:delimiter_pos])
            start_pos = delimiter_pos + 1
            end_pos = start_pos + size
            decoded.append(s[start_pos:end_pos])
            i = end_pos
        return decoded
