list=['spotify','terminal','vscode','fusion360','kicad','reddit','github','linkdln','youtube']

with open("output.txt", "w") as file:
    # Write each item on a new line
    for item in list:
        file.write(item + "\n")
# with open("output.txt", "r") as file:
#     lines = file.readlines()
# # Remove newline characters
# lines = [line.strip() for line in lines]
# print(lines)
