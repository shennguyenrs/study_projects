"""
Estimate Pi number by using Monte Carlo method
"""

# Import Libraries
from random import uniform
from math import sqrt

def calculate_pi(n):

    in_circle = 0

    for _ in range(n):
        # Get a random point on the coordinate axis with x and y
        x_point = uniform(0, 1)
        y_point = uniform(0, 1)

        # The distance between the point to the O
        distance = sqrt(x_point**2 + y_point**2)

        if distance < 1:
            in_circle += 1

    pi_number = 4*(in_circle/n)

    return pi_number

print(calculate_pi(10000))
