def square(x):
    return x * x

numbers = [1, 2, 3, 4, 5]
squared_numbers = map(square, numbers)
print(list(squared_numbers))  # Output: [1, 4, 9, 16, 25]

numbers = [1, 2, 3, 4, 5]
squared_numbers = map(lambda x: x * x, numbers)
print(list(squared_numbers))  # Output: [1, 4, 9, 16, 25]

def add(x, y):
    return x + y

numbers1 = [1, 2, 3]
numbers2 = [4, 5, 6]
summed_numbers = map(add, numbers1, numbers2)
print(list(summed_numbers))  # Output: [5, 7, 9]

def to_upper(s):
    return s.upper()

strings = ('hello', 'world', 'python')
upper_strings = map(to_upper, strings)
print(list(upper_strings))  # Output: ['HELLO', 'WORLD', 'PYTHON']

