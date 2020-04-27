def checker(iban_code):
    """
    Check IBAN number.

    Parameter:
        iban_code (str): IBAN number inputted by user.
        country_code (str): Country code included first 2 letter from IBAN number.
        c_name (str): Country name.
        c_length(int): Default country length of IBAN.
        iban_length (int): The length of inputted IBAN.
        index (int): The number of country code and check digits in IBAN number. Default is 4.
        new_iban (str): New IBAN string re-arraged and prepared for modulo.
        divisor (int): Divisor for modulo. Default is 97 due to ISO 7064.
        valid (int): The result from modulo calculation. 1 is valid, else means not valid.
        result (int or array): If result = 0, IBAN is invalid. Else it will print information of IBAN.

    Return:
        IBAN number is valid or invalid.
        If IBAN number is valid, the information should be printed: Country name, Bank name, BIC.

    """

    # Import modules
    from iban_checker.modules.code_to_country import toCountry
    from iban_checker.modules.code_to_number import toNumber
    from iban_checker.modules.code_to_bank import toBank
    from iban_checker.modules.mod import mod

    # Remove all spaces
    if iban_code.isspace():
        iban_code.replace(" ", "")

    # Extract Country name and default length
    country_code = ""
    country_code = iban_code[0] + iban_code[1]

    c_name = toCountry(country_code)[0]
    c_length = toCountry(country_code)[1]

    iban_length = len(iban_code)

    # Check inputted IBAN length
    if c_length != iban_length:
        print("Your IBAN number is not correct in length! Please enter again!")
        result = 0
    else:
        # Convert Country code to number
        c_number = toNumber(country_code)

        # Merge country_code and re-arrage IBAN to new string
        new_iban = ""
        index = 4

        for i in range(index, c_length - index):
            new_iban += iban_code[i]

        new_iban += c_number

        # Check IBAN Valid or not
        divisor = 97
        valid = mod(new_iban, c_length, divisor)

        if valid == 1:
            result = []
            result[0] = c_name

            # Get Bank name and BIC
            result[1] = toBank(new_iban)[0]
            result[2] = toBank(new_iban)[1]

        else:
            print("Your IBAN number is invalid")
            result = 0

    return result
