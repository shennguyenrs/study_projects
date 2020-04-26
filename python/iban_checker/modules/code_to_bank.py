"""
Extract bank name and BIC from the IBAN code

Parameters:
    code (int): 3 digits of bank (Finland) in the IBAN code
    bank_arr (array): Array contains bank name, bank number and BIC
    result (array): Array contains bank name and BIC

Return:
    A array with bank name and BIC of that bank
"""
import csv

def toBank(code):

    bank_arr = []
    result = []

    with open("../resources/banks.csv") as file:
        reader = csv.reader(file)
        header = next(reader)

        if header is not None:
            for row in reader:
                bank_arr.append(row)

    for i in bank_arr:
        if int(code) == bank_arr[i][1]:
            result[0] = bank_arr[i][0]
            result[1] = bank_arr[i][2]
            break

    return result
