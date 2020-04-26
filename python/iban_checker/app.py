# Import modules

def run():
    print("------------------------------------------------")
    print("-----Welcome to IBAN Checker and Generator------")
    print("------------------------------------------------")
    print("\n")

    while True:
        print("Please choose your tool:")
        print("1. Check your IBAN number")
        print("2. Generate your own IBAN number")
        print("0. Exit")
        print("\n")
        print("Choose your tool:")
        tool = int(input())

        if tool == 0:
            break
        elif tool == 1:
            print("------------------------------------------------")
        elif tool == 2:
            print("------------------------------------------------")
        else:
            print("You enter wrong number! Please enter the tool number again!")
            continue
