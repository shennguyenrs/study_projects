import csv
import os
from iban_checker.modules.file_path import file_path

def to_bank(code):
    """
    Extract bank name and BIC from the IBAN code.

    Parameters:
    -----------
        code : str
            IBAN code after moved country code and check digits to the end.

    Return:
    -------
        result : array
            Array contains bank name and BIC.

    Raises:
    -------

    """

    bank_arr = []
    result = []
    path = file_path("resources", "banks.csv")

    if os.path.isfile(path):

        # Open file to read
        with open(path) as file:
            reader = csv.reader(file)
            header = next(reader)

            # Write file to array
            if header is not None:
                for row in reader:
                    bank_arr.append(row)

        # Add bank name and BIC to result
        for i in bank_arr:
            bank_code = ""

            # Split the bank code from IBAN by the length depend on the bank
            for j in range(0, len(bank_arr[i][1])):
                bank_code += code[j]

            # Add the bank name and BIC if the lengths are equal
            if int(bank_code) == bank_arr[i][1]:
                result[0] = bank_arr[i][0]
                result[1] = bank_arr[i][2]
                break

        if result is None:
            result[0] = "Not found bank name"
            result[1] = "Not found BIC"

    return result