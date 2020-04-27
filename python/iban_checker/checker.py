"""
Checker tool
 
Parameter:

Return:

"""
# Import modules
from iban_checker.modules.code_to_country import toCountry

def checker():

    print("Input IBAN number: ")
    iban_code = str(input())

    # Remove all spaces
    if iban_code.isspace():
        iban_code.replace(" ", "")

    # Check country and default length
    country_code = ""
    country_code = iban_code[0] + iban_code[1]

    c_name = toCountry(country_code)[0]
    c_length = toCountry(country_code)[1]
