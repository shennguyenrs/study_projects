import csv
import os
from iban_checker.modules.file_path import file_path

def to_country(code):
    """
    Extract Country name and default length of IBAN Number to an array

    Parameters:
    -----------
        code : str
            String of country code with 2 digits.

    Return:
    -------
        result : array
            Return array result with country name and length.

    Raises:
    -------

    """

    country_arr = []
    result = []

    path = file_path("resources", "countries.csv")

    if os.path.isfile(path):

        # Open the file
        with open(path) as file:
            reader = csv.reader(file)
            header = next(reader)

            if header is not None:
                for row in reader:
                    country_arr.append(row)

        # Search for the country code
        for i in country_arr:
            if code == country_arr[i][1]:
                result[0] = country_arr[i][0]
                result[1] = country_arr[i][2]
                break
    
    if len(result) is None:
        raise 

    return result
