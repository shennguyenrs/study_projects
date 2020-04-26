"""
Organize IBAN code for modulo

Parameter:
    code (str): IBAN string after convert country code to number
    length (int): The default length of the IBAN string by the country
    digits (int): The first 4 digits needed to move to the end of the string
    ff_digits (str): First 4 digits
    rest (str): The rest of the IBAN string
    new_code (str): The string after organize the order

Return:
    A new string that is moved the first 4 digits to the end
"""
def organizer(code, length):

    digits = 4
    ff_digits = ""
    rest = ""

    for i in range(0, digits):
        ff_digits += code[i]

    for i in range(digits, length - digits):
        rest += code[i]

    new_code = rest + ff_digits

    return new_code
