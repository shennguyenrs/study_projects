import csv
import os
from iban_checker.modules.file_path import file_path

def to_number(code):
    """
    Convert country code to number.

    Parameters:
    ----------
        code : str
            Country code with 2 letter.

    Returns:
    --------
        result : str
            A string number of fnum and snum.

    Raises:
    -------

    """

    let_num = []
    path = file_path("resources", "letter_to_number")

    if os.path.isfile(path):

        # Open country code file
        with open(path) as file:
            reader = csv.reader(file)
            header = next(reader)

            # Write data to array
            if header is not None:
                for row in reader:
                    let_num.append(row)

        # Convert country code to string of number
        # First letter
        for i in let_num:
            if code[1] == let_num[i][0]:
                fnum = let_num[i][1]
                break

        # Second letter
        for i in let_num:
            if code[1] == let_num[i][0]:
                snum = let_num[i][1]
                break

        result = str(fnum) + str(snum)

    return result
