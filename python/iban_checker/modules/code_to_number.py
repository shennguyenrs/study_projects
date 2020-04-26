"""
Convert country code to number

Parameter:
    code (str): Country code with 2 letter
    let_num (array): Array that contains table of letters to numbers
    header (array): Header of csv file
    fnum (int): First number converted from code
    snum (int): Second number converted from the code

Return:
    A string number of fnum and snum
"""
import csv

def toNumber(code):

    let_num = []

    # Open country code file
    with open("../resources/letter_to_number.csv") as file:
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

    return str(fnum) + str(snum)
