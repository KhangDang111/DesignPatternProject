from functools import reduce

numbers = [1, 2, 3, 4, 5]
sum_of_numbers = reduce(lambda x, y: x + y, numbers)
print(sum_of_numbers)  # Output: 15


numbers = [1, 2, 3, 4, 5]
product_of_numbers = reduce(lambda x, y: x * y, numbers, 1)
print(product_of_numbers)  # Output: 120

