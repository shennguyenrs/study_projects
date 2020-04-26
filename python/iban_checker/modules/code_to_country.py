"""
Extract Country name and default length of IBAN Number to an array

Parameters:
    code (str): String of country code with 2 digits
    country_arr (array): Array of country with headers: Country name, country code and length of IBAN

Return:
    Return array result with country name and length

"""
import csv

def toCountry(code):

    country_arr = []
    result = []

    with open("../resources/countries.csv") as file:
        reader = csv.reader(file)
        header = next(reader)

        if header is not None:
            for row in reader:
                country_arr.append(row)

    for i in country_arr:
        if code == country_arr[i][1]:
            result[0] = country_arr[i][0]
            result[1] = country_arr[i][2]
            break

    return result
