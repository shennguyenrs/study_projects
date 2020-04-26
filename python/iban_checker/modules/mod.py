"""
Return modulo of big string number n with divisor

Paramaters:
    n (str): IBAN string

Returns:
    rem (int): Remander of modulo calculation
"""

def mod(n):
    # Define a remander
    # and length of the string
    # divisor is 97 according to ISO 7064
    rem = 0
    length = len(n)
    divisor = 97

    for i in range(0, length):
        rem = (rem*10 + int(n[i]))%divisor

    return rem
