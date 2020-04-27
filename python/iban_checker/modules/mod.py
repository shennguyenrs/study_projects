def mod(code, length, divisor):
    """
    Return modulo of big string number code with divisor.

    Paramaters:
        code (str): IBAN string.
        length (int): Length of the code by country.
        divisor (int): By default, divisor is 97 by ISO 7064.

    Returns:
        rem (int): Remander of modulo calculation
    """

    rem = 0

    for i in range(0, length):
        rem = (rem*10 + int(code[i]))%divisor

    return rem
