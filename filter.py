def is_even(n):
    return n % 2 == 0

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
even_numbers = filter(is_even, numbers)
print(list(even_numbers))  # Output: [2, 4, 6, 8, 10]

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
odd_numbers = filter(lambda n: n % 2 != 0, numbers)
print(list(odd_numbers))  # Output: [1, 3, 5, 7, 9]

def is_long_string(s):
    return len(s) > 3

strings = ["hi", "hello", "how", "are", "you"]
long_strings = filter(is_long_string, strings)
print(list(long_strings))  # Output: ['hello']

data = [1, None, 2, None, 3, 4, None, 5]
non_none_data = filter(lambda x: x is not None, data)
print(list(non_none_data))  # Output: [1, 2, 3, 4, 5]
