def mod(n):
# Return modulo of too big a string number n with divisor
# Paramaters:
#    n (str): IBAN string
# Returns:
#    Rem (int): The remander of modulo calculation

    # Define a remander
    # and length of the string
    rem = 0
    length = len(n)
    divisor = 97

    for i in range(0, length):
        rem = (rem*10 + int(n[i]))%divisor

    return rem
