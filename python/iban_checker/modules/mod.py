def mod(code, length):
    """
    Return modulo of big string number code with divisor.

    Paramaters:
    -----------
        code : str
            IBAN string.
        length : int
            Length of the code by country.

    Returns:
    --------
        rem : int
            Remander of modulo calculation

    Raises:
    -------

    """

    rem = 0
    # By default, divisor is 97 by ISO 7064.
    divisor = 97

    for i in range(0, length):
        rem = (rem*10 + int(code[i]))%divisor

    return rem