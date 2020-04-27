import csv

def toBank(code):
    """
    Extract bank name and BIC from the IBAN code.

    Parameters:
    -----------
        code : str
            IBAN code after moved country code and check digits to the end.

    Return:
        result : array
            Array contains bank name and BIC.

    Raises:
    -------

    """

    bank_arr = []
    result = []

    with open("../resources/banks.csv") as file:
        reader = csv.reader(file)
        header = next(reader)

        if header is not None:
            for row in reader:
                bank_arr.append(row)

    for i in bank_arr:
        bank_code = ""

        for j in range(0, len(bank_arr[i][1])):
            bank_code += code[j]

        if int(bank_code) == bank_arr[i][1]:
            result[0] = bank_arr[i][0]
            result[1] = bank_arr[i][2]
            break

    if result is None:
        result[0] = "Not found bank name"
        result[1] = "Not found BIC"

    return result
