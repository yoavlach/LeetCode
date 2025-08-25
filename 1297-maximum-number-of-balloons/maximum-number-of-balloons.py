LETTERS_FOR_BALLOON = {
    'b': 1,
    'a': 1,
    'l': 2,
    'o': 2,
    'n': 1
}


class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        letters_and_amounts = {
            'b': 0,
            'a': 0,
            'l': 0,
            'o': 0,
            'n': 0
        }
        balloons_counter = 2 ** 31 - 1
        for i in text:
            if i in letters_and_amounts.keys():
                letters_and_amounts[i] += 1
        for i in letters_and_amounts:
            if letters_and_amounts[i] // LETTERS_FOR_BALLOON[i] < balloons_counter:
                balloons_counter = letters_and_amounts[i] // LETTERS_FOR_BALLOON[i]
        return balloons_counter