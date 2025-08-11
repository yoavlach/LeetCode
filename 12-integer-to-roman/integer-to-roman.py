ROMAN_NUMBERS = {
    1: "I",
    5: "V",
    10: "X",
    50: "L",
    100: "C",
    500: "D",
    1000: "M",
}
ROMAN_NUMBERS_LIST = [1, 5, 10, 50, 100, 500, 1000]

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        str_num = str(num)[::-1]
        list_num = []
        int_in_roman = ""
        for i in range(len(str_num)):
            list_num.append(int(str_num[i] + '0' * i))
        list_num = list_num[::-1]
        for i in list_num:
            if str(i)[0] in ['4', '9']:
                sorted_keys = sorted(ROMAN_NUMBERS.keys())
                smallest_roman_num_that_is_larger_than_i = [n for n in sorted_keys if n > i][0]
                remainder = smallest_roman_num_that_is_larger_than_i - i
                if remainder in ROMAN_NUMBERS.keys():
                    int_in_roman += ROMAN_NUMBERS[remainder] + ROMAN_NUMBERS[smallest_roman_num_that_is_larger_than_i]
            else:
                largest_roman_num_that_is_smaller_than_i = 0
                for n in ROMAN_NUMBERS.keys():
                    if i - n >= 0 and n > largest_roman_num_that_is_smaller_than_i:
                        largest_roman_num_that_is_smaller_than_i = n
                sum = 0
                i_in_roman = ''
                curr_roman_num = largest_roman_num_that_is_smaller_than_i
                while True:
                    while sum < i:
                        if sum + curr_roman_num <= i:
                            sum += curr_roman_num
                            i_in_roman += ROMAN_NUMBERS[curr_roman_num]
                        else:
                            break
                    if sum == i:
                        break
                    curr_roman_num = ROMAN_NUMBERS_LIST[ROMAN_NUMBERS_LIST.index(curr_roman_num) - 1]
                int_in_roman += i_in_roman
        return int_in_roman
        