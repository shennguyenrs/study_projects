def run():
    """
    IBAN Cheker and Generator

    Parameters:
    -----------

    Returns:
    --------

    Raises:
    -------

    """

    from iban_checker.checker import checker

    print("------------------------------------------------")
    print("-----Welcome to IBAN Checker and Generator------")
    print("------------------------------------------------")
    print("\n")

    control = True

    while control:
        print("Please choose your tool:")
        print("1. Check your IBAN number")
        print("2. Generate your own IBAN number")
        print("0. Exit")
        print("\n")
        print("Choose your tool:")
        tool = int(input())

        if tool == 0:
            control = False

        elif tool == 1:
            print("------------------------------------------------")
            print("\n")

            sub_control = True

            while sub_control:
                print("Input your IBAN number: ")
                iban_code = str(input())
                result = checker(iban_code)

                if result == 0:
                    sub_control = False

                elif result == 1:
                    print("Do you want to input again? (y/n)")
                    sub_control = bool(str(input()).lower() == "y")

                else:
                    print("\n")
                    print(iban_code + " is valid")
                    print("Country:\t{0}".format(result[0]))
                    print("Bank:\t{1}".format(result[1]))
                    print("BIC:\t{2}".format(result[2]))
                    print("\n")
                    sub_control = False
                    print("------------------------------------------------")

        elif tool == 2:
            print("------------------------------------------------")
            print("\n")


            print("\n")
            print("------------------------------------------------")

        else:
            print("You enter wrong number! Please enter the tool number again!")
