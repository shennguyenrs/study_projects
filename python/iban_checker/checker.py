def checker(iban_code):
    """
    Check IBAN number.

    Parameters:
    -----------
        iban_code : str
            IBAN number inputted by user.

    Returns:
    --------
        result : int or array
            If result = 0, IBAN is invalid.
            if result = 1, IBAN is wrong length.
            Else it will print information of IBAN: Country, Bank and BIC.

    Raises:
    -------

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

    # Check inputted IBAN length
    if c_length != len(iban_code):
        print("Your IBAN number is not correct in length! Please enter again!")
        result = 1

    else:
        # Re-arrage IBAN to new string
        new_iban = ""
        index = 4

        for i in range(index, c_length - index):
            new_iban += iban_code[i]

        # Add converted country code to new IBAN
        new_iban += toNumber(country_code)

        # Check IBAN Valid or not
        valid = mod(new_iban, c_length)

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
